using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QuickUnion
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] myArray = new int[10];
            for(int i = 0; i < myArray.Length; i++)
            {
                myArray[i] = i;
            }

            Algorithm quickUniion = new Algorithm(myArray);
            Console.WriteLine(quickUniion.Find(1, 3).ToString());
            quickUniion.Unite(1, 3);
            Console.WriteLine(quickUniion.Find(1, 3).ToString());
            quickUniion.Unite(4, 1);
            Console.WriteLine(quickUniion.Find(4, 3).ToString());
        }
    }
}