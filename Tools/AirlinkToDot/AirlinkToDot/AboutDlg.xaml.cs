using System;
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
using System.Windows.Shapes;

namespace AirlinkToDot
{
    /// <summary>
    /// Window1.xaml の相互作用ロジック
    /// </summary>
    public partial class AboutDlg : Window
    {
        public AboutDlg()
        {
            InitializeComponent();

            InitializeComponent();
            //  アセンブリ情報からの製品情報を表示する情報ボックスを初期化します。
            //  アプリケーションのアセンブリ情報設定を次のいずれかにて変更します:
            //  - [プロジェクト] メニューの [プロパティ] にある [アプリケーション] の [アセンブリ情報]
            //  - AssemblyInfo.cs


            this.labelProductName.Content = AssemblyProduct;

            string msg = labelVersion.Content + " {0}";
            this.labelVersion.Content = String.Format(msg, AssemblyVersion);
            this.labelCopyright.Content = AssemblyCopyright;
            this.labelCompanyName.Content = AssemblyCompany;
            this.txtBoxDescription.Content = AssemblyDescription;

        }


        #region アセンブリ属性アクセサ

        /// <summary>
        /// タイトル
        /// </summary>
        public string AssemblyTitle
        {
            get
            {
                // このアセンブリ上のタイトル属性をすべて取得します
                object[] attributes = System.Reflection.Assembly.GetExecutingAssembly().GetCustomAttributes(typeof(System.Reflection.AssemblyTitleAttribute), false);
                // 少なくとも 1 つのタイトル属性がある場合
                if (attributes.Length > 0)
                {
                    // 最初の項目を選択します
                    System.Reflection.AssemblyTitleAttribute titleAttribute = (System.Reflection.AssemblyTitleAttribute)attributes[0];
                    // 空の文字列の場合、その項目を返します
                    if (titleAttribute.Title != "")
                        return titleAttribute.Title;
                }
                // タイトル属性がないか、またはタイトル属性が空の文字列の場合、.exe 名を返します
                return System.IO.Path.GetFileNameWithoutExtension(System.Reflection.Assembly.GetExecutingAssembly().CodeBase);
            }
        }

        /// <summary>
        /// バージョン
        /// </summary>
        public string AssemblyVersion
        {
            get
            {
                return System.Reflection.Assembly.GetExecutingAssembly().GetName().Version.ToString();
            }
        }

        /// <summary>
        /// 説明属性
        /// </summary>
        public string AssemblyDescription
        {
            get
            {
                // このアセンブリ上の説明属性をすべて取得します
                object[] attributes = System.Reflection.Assembly.GetExecutingAssembly().GetCustomAttributes(typeof(System.Reflection.AssemblyDescriptionAttribute), false);
                // 説明属性がない場合、空の文字列を返します
                if (attributes.Length == 0)
                    return "";
                // 説明属性がある場合、その値を返します
                return ((System.Reflection.AssemblyDescriptionAttribute)attributes[0]).Description;
            }
        }

        /// <summary>
        /// 製品名
        /// </summary>
        public string AssemblyProduct
        {
            get
            {
                // このアセンブリ上の製品属性をすべて取得します
                object[] attributes = System.Reflection.Assembly.GetExecutingAssembly().GetCustomAttributes(typeof(System.Reflection.AssemblyProductAttribute), false);
                // 製品属性がない場合、空の文字列を返します
                if (attributes.Length == 0)
                    return "";
                // 製品属性がある場合、その値を返します
                return ((System.Reflection.AssemblyProductAttribute)attributes[0]).Product;
            }
        }

        /// <summary>
        /// 著作権表記
        /// </summary>
        public string AssemblyCopyright
        {
            get
            {
                // このアセンブリ上の著作権属性をすべて取得します
                object[] attributes = System.Reflection.Assembly.GetExecutingAssembly().GetCustomAttributes(typeof(System.Reflection.AssemblyCopyrightAttribute), false);
                // 著作権属性がない場合、空の文字列を返します
                if (attributes.Length == 0)
                    return "";
                // 著作権属性がある場合、その値を返します
                return ((System.Reflection.AssemblyCopyrightAttribute)attributes[0]).Copyright;
            }
        }
        /// <summary>
        /// 会社名
        /// </summary>
        public string AssemblyCompany
        {
            get
            {
                // このアセンブリ上の会社属性をすべて取得します
                object[] attributes = System.Reflection.Assembly.GetExecutingAssembly().GetCustomAttributes(typeof(System.Reflection.AssemblyCompanyAttribute), false);
                // 会社属性がない場合、空の文字列を返します
                if (attributes.Length == 0)
                    return "";
                // 会社属性がある場合、その値を返します
                return ((System.Reflection.AssemblyCompanyAttribute)attributes[0]).Company;
            }
        }
        #endregion

        /// <summary>
        /// Windowを閉じる
        /// </summary>
        /// <param _name="sender"></param>
        /// <param _name="e"></param>
        private void btnOk_Click(object sender, RoutedEventArgs e)
        {
            DialogResult = true;
        }
    }
}
