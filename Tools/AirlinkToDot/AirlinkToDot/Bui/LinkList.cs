using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace AirlinkToDot
{
    public class LinkList
    {
        /// <summary>
        /// LINKのリスト
        /// List for LINK
        /// </summary>
        private List<Link> links = new List<Link>();

        /// <summary>
        /// Linkクラスのリスト
        /// The list of LINK classes
        /// </summary>
        public List<Link> Links
        {
            get
            {
                return this.links;
            }
        }

        /// <summary>
        /// LINKをリストへ追加する
        /// Add a LINK in the list.
        /// </summary>
        /// <param name="link">レイヤークラス</param>
        /// <returns>成功:true, 失敗：false</returns>
        public bool Add(Link link)
        {
            bool ret = false;


            if (this.Search(link.ID) == null)
            {
                this.links.Add(link);
                ret = true;
            }
            else
            {
                // エラー
               // string msg = "指定されたLINK(" + link.ID + ")と同じIDのLINKがすでに登録されています\n";
                string msg = "The specified LINK(" + link.ID + ") already exits in the list. \n";

                throw new ArgumentOutOfRangeException(msg);

            }

            return ret;
        }

        /// <summary>
        /// ID を指定して、登録済みのLINKを検索する
        /// Search a LINK in the list by the ID.
        /// </summary>
        /// <param name="id">ID</param>
        /// <returns>LINK、NULL</returns>
        public Link Search(string id)
        {
            foreach (Link link in this.links)
            {
                if (link.ID == id) return link;
            }
            return null;
        }

    }
}
