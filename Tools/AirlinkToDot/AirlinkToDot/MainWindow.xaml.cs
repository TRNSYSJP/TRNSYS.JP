﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

using Microsoft.Win32; //追加
using System.IO;
using System.Collections.ObjectModel;

using System.Diagnostics;
using GraphVizWrapper.Queries;
using GraphVizWrapper;
using System.Drawing;
using GraphVizWrapper.Commands;

namespace AirlinkToDot
{
    /// <summary>
    /// MainWindow.xaml の相互作用ロジック
    /// </summary>
    public partial class MainWindow : System.Windows.Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void btnLoadBui_Click(object sender, RoutedEventArgs e)
        {
            BuiFile buiFile = new BuiFile();

            OpenFileDialog ofd = new OpenFileDialog();
            ofd.FileName = "";
            ofd.DefaultExt = "*.b*";
            ofd.Filter = "TRNBuld File (*.bui;*.b17)|*.bui;*.b17";
            if (ofd.ShowDialog() == true)
            {
                buiFile.Load(ofd.FileName);
                convertBuiToDot(buiFile);
            }
        }

        /// <summary>
        /// Bui to Dot
        /// </summary>
        /// <param name="buiFile">BuiFile class</param>
        private void convertBuiToDot(BuiFile buiFile)
        {
            var filename = System.IO.Path.ChangeExtension(buiFile.FileName, ".gv");
            bool append = false; // overwrite

            // convert bui to gv
            var strList = buiToDot(buiFile);

            // display 
            string gv = "";
            foreach (string str in strList)
            {
                gv += str + "\n";
            }
            this.txtBox.Text = gv;

            // save the .gv file
            using (StreamWriter writer = new StreamWriter(filename, append, Encoding.GetEncoding("shift_jis")))　//Shift_JIS
            {
                foreach (string str in strList)
                {
                    writer.WriteLine(str);
                }
            }

            var imgFile = System.IO.Path.ChangeExtension(filename, ".png");

            // generate a image using Graphviz/Dot

            try
            {
                generateGraphImage(gv, imgFile);
            }catch(System.ComponentModel.Win32Exception ex)
            {
                var msg = @"Graphvizの実行プログラムが見つかりません。"+"\n";
                msg += @"このプログラムのインストールフォルダ"+"\n";
                msg += @"'C:\Program Files (x86)\TRNSYS.JP\AirlinkToDot\GraphViz'を確認して下さい。" + "\n";
                msg += "\n";
                msg += @"このフォルダにGraphvizのプログラムがない場合は、コピーしてください。" + "\n";
                msg += @"詳しくは、上記フォルダの'ReadMe.txt'を参照してください。";
                MessageBox.Show(msg);
                return;
            }

            // start the paint app
            Process.Start(imgFile);

        }


        /// <summary>
        /// convert Bui to Dot format
        /// </summary>
        /// <param name="buiFile"></param>
        /// <returns></returns>
        private static List<string> buiToDot(BuiFile buiFile)
        {
            List<string> strList = new List<string>();

            strList.Add("digraph {");
            strList.Add("    rankdir=LR;");

            string zones = "";
            string extNodes = "";
            string auxNodes = "";

            foreach (Link link in buiFile.LinkList.Links)
            {
                string node;
                node = link.FromNode;
                parseNode(ref zones, ref extNodes, ref auxNodes, node);
                node = link.ToNode;
                parseNode(ref zones, ref extNodes, ref auxNodes, node);
            }
            strList.Add("    node [shape = doublecircle]; " + zones + ";");
            strList.Add("    node [shape = circle]; " + extNodes + ";");
            strList.Add("    node [shape = rectangle]; " + auxNodes + ";");
            foreach (Link link in buiFile.LinkList.Links)
            {
                string str = "    " + link.FromNode + " -> " + link.ToNode + "[ label = \"" + link.LinkType + "\" ];";
                strList.Add(str);
            }
            strList.Add("}  ");

            return strList;
        }

        /// <summary>
        /// generate an image from .gv strings
        /// </summary>
        /// <param name="diagraph"></param>
        /// <param name="imgFile"></param>
        private static void generateGraphImage(string diagraph, string imgFile)
        {
            var getStartProcessQuery = new GetStartProcessQuery();
            var getProcessStartInfoQuerty = new GetProcessStartInfoQuery();
            var registerLayoutPluginCommand = new RegisterLayoutPluginCommand(getProcessStartInfoQuerty, getStartProcessQuery);

            var wrapper = new GraphGeneration(
                getStartProcessQuery,
                getProcessStartInfoQuerty,
                registerLayoutPluginCommand);

           // wrapper.RenderingEngine = Enums.RenderingEngine.Fdp;
            wrapper.RenderingEngine = Enums.RenderingEngine.Sfdp;

            byte[] output = wrapper.GenerateGraph(diagraph, Enums.GraphReturnType.Png);

            // byte[] to Image
            System.Drawing.Image img = byteArrayToImage(output);

            // save the image
            img.Save(imgFile, System.Drawing.Imaging.ImageFormat.Png);

            img.Dispose();
        }

        /// <summary>
        /// convert byte[] to an image
        /// </summary>
        /// <param name="b"></param>
        /// <returns></returns>
        private static System.Drawing.Image byteArrayToImage(byte[] b)
        {
            ImageConverter imgconv = new System.Drawing.ImageConverter();
            System.Drawing.Image img = (System.Drawing.Image)imgconv.ConvertFrom(b);
            return img;
        }

        /// <summary>
        /// Parse the node type 
        /// </summary>
        /// <param name="zones"></param>
        /// <param name="extNodes"></param>
        /// <param name="auxNodes"></param>
        /// <param name="node"></param>
        private static void parseNode(ref string zones, ref string extNodes, ref string auxNodes, string node)
        {
            if (node.StartsWith("EN_") )
            {
                if (extNodes.IndexOf(node) < 0) extNodes += node + " ";
                return;
            }
            else if (node.StartsWith("AN_"))
            {
                if (auxNodes.IndexOf(node) < 0) auxNodes += node + " ";
                return;
            }
            else if (zones.IndexOf(node) < 0)
            {
                zones += node + " ";
            }
        }


        /// <summary>
        /// Version Info
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void HelpAbout_Click(object sender, RoutedEventArgs e)
        {
            AboutDlg aboutDlg = new AboutDlg();
            aboutDlg.Owner = this;
            aboutDlg.WindowStartupLocation = System.Windows.WindowStartupLocation.CenterOwner;
            aboutDlg.ShowDialog();
        }

        /// <summary>
        /// Exit
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void menuItem_Clicked(object sender, RoutedEventArgs e)
        {
            this.Close();
            
        }

        /// <summary>
        /// Drag&Drop
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Window_Drop(object sender, DragEventArgs e)
        {
            DroppedFiles list = this.DataContext as DroppedFiles;
            string[] files = e.Data.GetData(DataFormats.FileDrop) as string[];
            if (files != null)
            {
                BuiFile buiFile = new BuiFile();
                buiFile.Load(files[0]);
                convertBuiToDot(buiFile);
            }

        }

        public class DroppedFiles
        {
            public DroppedFiles()
            {
                FileNames = new ObservableCollection<string>();
            }
            public ObservableCollection<string> FileNames
            {
                get;
                private set;
            }
        }

        private void Window_PreviewDragOver(object sender, DragEventArgs e)
        {
            if (e.Data.GetDataPresent(DataFormats.FileDrop, true))
                e.Effects = DragDropEffects.Copy;
            else
                e.Effects = DragDropEffects.None;
            e.Handled = true;
        }

    }
}
