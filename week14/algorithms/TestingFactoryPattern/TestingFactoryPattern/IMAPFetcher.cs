using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestingFactoryPattern
{
    public class IMAPFetcher : FetcherDecorator
    {
        private DbReader dbreader;
        public IMAPFetcher(DbReader dbreader)
        {
            this.dbreader = dbreader;
        }

        public override string GetFolders()
        {
            return dbreader.GetFolders() + " letoltottEmail";
        }
    }
}
