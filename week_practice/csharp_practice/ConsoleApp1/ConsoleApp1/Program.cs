using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        private static void printStringElements(string[] myarray)
        {
            foreach (string element in myarray)
            {
                Console.WriteLine(element);
            }
        }
        static void Main(string[] args)
        {
            Class1 newclass = new Class1();
			newclass.Name = "anyad";
			newclass.writesomething();
			string[] myarray = new string[] { "bela", "sanyi" };
            printStringElements(myarray);
        }
    }
}
