using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestingFactoryPattern
{
    public abstract class FetcherDecorator : DbReader
    {
        protected DbReader dbreader;

        FetcherDecorator(string Connectioninfo)
        {

        }
    }
}
