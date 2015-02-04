using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AirlinkToDot
{
    /// <summary>
    /// TRNFlow LINKクラス
    /// </summary>
    public class Link
    {
        /// <param name="id">ID</param>
        /// <param name="linkType">Crack,Fan,LO,etc...</param>
        /// <param name="fromNode">From node</param>
        /// <param name="toNode">to node</param>
        public Link(string id, string linkType, string fromNode, string toNode)
        {
            this.ID = id;
            this.LinkType = linkType;
            this.FromNode = fromNode;
            this.ToNode = toNode;

        }
        private string id;
        public string ID
        {
            get
            {
                return this.id;
            }
            set
            {
                this.id = value;
            }
        }


        private string linkType;

        public string LinkType
        {
            get
            {
                return this.linkType;
            }
            set
            {
                this.linkType = value;
            }
        }

        private string fromNode;

        public string FromNode
        {
            get
            {
                return this.fromNode;
            }
            set
            {
                this.fromNode = value;
            }
        }

        private string toNode;

        public string ToNode
        {
            get
            {
                return this.toNode;
            }
            set
            {
                this.toNode = value;
            }
        }

    }
}
