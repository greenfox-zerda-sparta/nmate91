using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RefType
{
    class Program
    {
        static void Quad(int i)
        {
            i = i * i;
        }
        static void QuadbyRef(ref int i)
        {
            i = i * i;
        }
        static void Main(string[] args)
        {
            int i = 2;
            object b = i;

            Quad(i);
            Console.WriteLine("Without reference:");
            Console.WriteLine(i);

            QuadbyRef(ref i);
            Console.WriteLine("With reference:");
            Console.WriteLine(i);
        }
    }
}
