using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestingFactoryPattern
{
    class Program
    {
        static void Main(string[] args)
        {
            DbReader dbreader = new DbReader();
            IMAPFetcher fetcher = new IMAPFetcher(dbreader);
            Console.WriteLine(fetcher.GetFolders());
        }
    }
}
