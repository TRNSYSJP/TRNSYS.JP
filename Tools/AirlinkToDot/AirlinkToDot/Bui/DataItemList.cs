using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AirlinkToDot
{
    public class DataItemList
    {
        /// <summary>
        /// 一行分の
        /// </summary>
        /// <param name="str">一行分のデータからDataItemのリストを生成する</param>
        public DataItemList(string str)
        {
            List<DataItem> dataItems = new List<DataItem>();

            // コロン(:)区切りの行の判定
            if (str.Contains(':'))
            {
                // コロンで分割して、DataItemを生成する。
                string[] items = str.Split(':');
                foreach (string item in items)
                {
                    // 文字列が空でなければ処理を行う
                    string item2 = item.Trim();
                    if (!(item2 == ""))
                    {
                        if (item2.Contains('='))
                        {
                            string[] strs = item2.Split('=');
                            DataItem dataItem = new DataItem(strs[0].Trim(), strs[1].Trim());
                            dataItems.Add(dataItem);
                        }
                        else if (item2.Contains(" "))
                        {
                            //LINK DS_001       : ID= 1 : FRNODE= KITCHEN    : TONODE= AN_001     : FRHEIGHT=       0 : TOHEIGHT=        0 : WIOWNHF=       0 : FSCALE= 1

                            string[] strs2 = item2.Split(' ');
                            DataItem dataItem = new DataItem(strs2[0].Trim(), strs2[1].Trim());
                            dataItems.Add(dataItem);

                        }
                        else
                        {
                            // EXTERNALなど単独のkeyword
                            DataItem dataItem = new DataItem(item2.Trim(), null);
                            dataItems.Add(dataItem);
                        }
                    }
                }
            }
            else
            {
                // DataItemが一つしかない

                
                if (str.Contains('='))
                {
                    // '='で区切られているDataItem　　例：HOURS =0.000 8.000 10.000 12.000 14.000 17.000 22.000 24.0
                    string[] strs = str.Trim().Split('=');
                    DataItem dataItem = new DataItem(strs[0].Trim(), strs[1].Trim());
                    dataItems.Add(dataItem);


                }
                else
                {
                    // ' 'で区切られているDataItem　例：LAYER GYPSUM

                    // セパレータ' 'で分割
                    string[] strs = str.Trim().Split(' ');

                    // 空のデータを取り除く
                    List<string> dataList = removeBlankLine(strs);
                    if (dataList.Count < 2)
                    {
                        string msg = "データ項目が少なすぎます\n" + "データ :\t" + str;
                        throw new FormatException(msg);
                    }

                    string keyword = dataList[0];
                    string rawData = "";
                    for (int i = 1; i < dataList.Count; i++)
                    {
                        rawData = rawData + " " + dataList[i];
                    }

                    dataItems.Add(new DataItem(keyword, rawData));
                }
                
            }

            this.DataItems = dataItems;
        }


        /// <summary>
        /// 文字列配列から空の行を除いたリストを生成する。
        /// </summary>
        /// <param name="strs">文字列配列</param>
        /// <returns>文字列のリスト</returns>
        private static List<string> removeBlankLine(string[] strs)
        {
            List<string> dataList = new List<string>();
            foreach (string str2 in strs)
            {
                if (str2.Trim() != "")
                {
                    dataList.Add(str2.Trim());
                }
            }
            return dataList;
        }
        /// <summary>
        /// DataItemリスト
        /// </summary>
        public List<DataItem> DataItems {get;set;}

        /// <summary>
        /// 指定されたKeywordのDataItemを返す。
        /// 指定されたKeywordのDataItemがなければnullを返す。
        /// </summary>
        /// <param name="keyword">Keyword</param>
        public DataItem GetDataItem(string keyword)
        {
            foreach (DataItem item in this.DataItems)
            {
                if (item.Keyword == keyword) return item;
            }
            return null;
        }
    }
}
