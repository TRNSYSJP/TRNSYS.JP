using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace AirlinkToDot
{
    public class BuiFile
    {
        // Airlinkのリストを格納する
        private LinkList linkList;
        public LinkList LinkList
        {
            get
            {
                return this.linkList;
            }
            set
            {
                this.linkList = value;
            }
        }

        /// <summary>
        /// コンストラクタ
        /// </summary>
        public BuiFile()
        {
            
            
        }

        /// <summary>
        /// ファイル名
        /// </summary>
        public string FileName {get;set;}
       

        /// <summary>
        /// 文字列データから"ID"の部分を取り出す
        /// </summary>
        /// <param name="curLine"></param>
        /// <returns></returns>
        private static string getID(string curLine, string keyword)
        {
            curLine = curLine.Trim();
            keyword = keyword.Trim();

            string id = curLine.Substring(keyword.Length).Trim();
            return id;
        }


        /// <summary>
        /// Buiファイルを読み込んでBuiクラスのインスタンスに展開する
        /// </summary>
        /// <param name="filePath">Buiファイル名</param>
        public void Load(string filePath)
        {
            // Buiクラスの初期化
            this.linkList = new LinkList();
            this.FileName = filePath;

            // 作業用の一時ファイルを生成する
            string tempBuiFile = createTempBuiFile(filePath);

            #region "ファイルの読み込みと解析"
            using (StreamReader reader = new StreamReader(tempBuiFile, Encoding.GetEncoding("shift_jis")))
            {

                //-------------------------------------------------------------------------------------------
                #region "Buiファイル本体(EXTENTIONを除く)"
                string curLine;
                while ((curLine = reader.ReadLine()) != null)
                {
                    if (curLine.Trim().StartsWith("END"))
                    {
                        break; // ループ終了してEXTENTIONの処理へ移る
                    }

                    // 前処理として読み込んだ行の前後のスペースを取り除く。
                     curLine = curLine.Trim();

                    // コメント行の処理
                    if (curLine.StartsWith("*"))
                    {
                        #region "コメント行処理"

                        // なにもしない

                        #endregion
                    }
 
                    //-----------------------------------------------
                    // TRNFlow
                    //-----------------------------------------------

                    // AIRLINK_NETWORK
                    if (curLine.Trim().StartsWith("LINK "))
                    {
                        #region "LINKの解析処理"
                        try
                        {
                            parseAirlinkNetwork(reader, ref curLine);
                        }
                        catch (Exception ex)
                        {
                            string msg = "AIRLINK_NETWORKの解析中にエラーが発生しました。\n";
                            msg += ex.Message + "\n";
                            msg += curLine;

                            throw new FormatException(msg, ex);

                        }
                        #endregion
                    }
                }
                #endregion
                //-------------------------------------------------------------------------------------------
                
                // 解析処理終了

            }
            #endregion

#if DEBUG


#else

                // 一時ファイルの削除
                System.IO.File.Delete(tempBuiFile);
#endif

        }
        /// <summary>
        /// TRNFlow AIRLINK_NETWORK(LINK)の解析処理
        /// </summary>
        /// <param name="reader">読み込みファイル</param>
        /// <param name="curLine">処理中の行</param>
        private void parseAirlinkNetwork(StreamReader reader, ref string curLine)
        {
            #region "LINK"
            List<string> rawStrings = new List<string>(); // 一時Buiファイル

            // ひとまず"*---"の行までループで読み込む
            while (!(curLine.ToUpper().StartsWith("*---".ToUpper())))
            {
                rawStrings.Add(curLine); // 一行読み込み
                curLine = reader.ReadLine();

            }

            // "LINK"をクラスへ展開する
            foreach (string str in rawStrings)
            {
                string row = str.Trim().ToUpper();
                if (row.StartsWith("LINK"))
                {
                    // "LINK DS_001       : ID= 1 : FRNODE= KITCHEN    : TONODE= AN_001     : FRHEIGHT=       0 : TOHEIGHT=        0 : WIOWNHF=       0 : FSCALE= 1"
                    DataItemList dataItemList = new DataItemList(row);
                    DataItem dataItem = dataItemList.DataItems[0];
                    //LINK
                    string linkType;
                    linkType = dataItem.TYPEs[0];
                    //ID
                    int id = (int)dataItemList.DataItems[1].Values[0];
                    //FRNODE
                    string fnode = dataItemList.DataItems[2].TYPEs[0];
                    //TONODE
                    string tnode = dataItemList.DataItems[3].TYPEs[0];
                    
                    //FRHEIGHT
                    double frheight = dataItemList.DataItems[4].Values[0];
                    //TOHEIGHT
                    double toheight = dataItemList.DataItems[5].Values[0];
                    //WIOWNHF
                    double wiownhf = dataItemList.DataItems[6].Values[0];
 
                    //-----------------------------------------
                    // Airlinkクラスを生成してリストに追加する
                    //-----------------------------------------
                    Link link = new Link(id.ToString(), linkType, fnode, tnode);
                    this.LinkList.Add(link);


                }
            }
            // 終了処理
            rawStrings.Clear(); // 作業用に作成した生データのテキストを削除する

            #endregion
        }


        /// <summary>
        /// 文字列の先頭のコメントのヘッダー部("*#C ")を削除する
        /// </summary>
        /// <param name="curLine"></param>
        /// <returns></returns>
        private string removeCommentHeader(string curLine)
        {
            string temp = curLine.Remove(0, 3); // 先頭から3文字（"*#C"）を削除する
            return temp;
        }


        /// <summary>
        /// 複数行で構成されるデータを一行へまとめる
        /// </summary>
        /// <param name="filePath">複数行のデータを含むBuiファイル</param>
        /// <returns>作業用の一時ファイルのパス</returns>
        private static string createTempBuiFile(string filePath)
        {
            string tempBuiFile = filePath;

            // 一時ファイルを作成して処理を行う
            tempBuiFile = Path.GetTempFileName();

            // ファイルの前処理
            List<string> stringList = new List<string>(); // 一時Buiファイル

            using (StreamReader reader = new StreamReader(filePath, Encoding.GetEncoding("shift_jis")))
            {
                string curLine;
                while ((curLine = reader.ReadLine()) != null)
                {
                    // " ;"で複数行で構成されるデータを一行にまとめる
                    string buff = "";
                    while (curLine.EndsWith(" ;"))
                    {
                        buff += curLine.Remove(curLine.Length - 2).TrimEnd(); // " ;"の削除

                        curLine = reader.ReadLine();
                    }

                    buff += curLine;
                    stringList.Add(buff);
                }
            }
            // 一時ファイルの書き出し処理
            using (StreamWriter writer = new StreamWriter(tempBuiFile, false, Encoding.GetEncoding("shift_jis")))　//Shift_JIS
            {
                foreach (string buff in stringList)
                {
                    writer.WriteLine(buff);
                }
            }
            return tempBuiFile;
        }

    }
}
