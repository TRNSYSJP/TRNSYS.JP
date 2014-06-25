using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AirlinkToDot
{
    public class DataItem
    {
        /// <param name="keyword">キーワード</param>
        /// <param name="data">データ</param>
        public DataItem(string keyword, string data)
        {
            this.Keyword = keyword;
            this.Data = data;
        }
        /// <summary>
        /// キーワード
        /// </summary>
        public string Keyword { get; set; }


        /// <summary>
        /// データのリスト
        /// </summary>
        public string Data {get; set;}

        /// <summary>
        /// 数値型の値のリスト
        /// </summary>
        public List<double> Values
        {
            get
            {
                string[] data = this.Data.Split(' ', ',');
                List<double> vals = new List<double>();

                foreach (string str in data)
                {
                    // 空の値以外
                    if (!(str == ""))
                    {
                        vals.Add(double.Parse(str));
                    }
                }
                return vals;

            }
            //set
            //{
            //}
        }

        /// <summary>
        /// Type型の値のリスト
        /// </summary>
        public List<string> TYPEs
        {
            get
            {
                string[] data = this.Data.Split(' ', ',');
                List<string> types = new List<string>();

                foreach (string str in data)
                {
                    // 空の値以外
                    if (!(str.Trim() == ""))
                    {
                        types.Add(str.Trim());
                    }
                }
                return types;
            }
            //set
            //{
            //}
        }



        public override string ToString()
        {

            if(string.IsNullOrEmpty(this.Data))
            {
                return this.Keyword;
            }
            else
            {
                return this.Keyword + " = " + this.Data;
            }
        }

    }
}
