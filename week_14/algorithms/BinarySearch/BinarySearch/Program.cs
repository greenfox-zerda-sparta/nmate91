using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BinarySearch
{
    class Program
    {

        static void Main(string[] args)
        {
            int size = 100;
            int[] data = new int[size];
            for (int i = 0; i < size; i++)
            {
                data[i] = i*2;
            }
            Array.Sort(data);

            Binary binary = new Binary();
            bool isFound = binary.BinarySearch(data, 97);
            switch (isFound)
            {
                case false:
                    Console.WriteLine("Number not found.");
                    break;
                case true:
                    Console.WriteLine("Number found." );
                    break;
            }
        }
    }
}
