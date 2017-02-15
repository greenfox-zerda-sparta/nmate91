using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestingFactoryPattern
{
    public class DbReader : MailService
    {
        public string GetFolders()
        {
            return "database emailek";
        }
    }
}