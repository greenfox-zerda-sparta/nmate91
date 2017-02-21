using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Smallest_multiple
{
    class Program
    {
        static bool IsDivisible(int number, int to)
        {
            for(int i = to; i > 1; i--)
            {
                if(number % i != 0)
                {
                    return false;
                }
             }
            return true;
        }
        static int SmallestMultiple()
        {
            int count = 10;
            while (true)
            {
                if(IsDivisible(count, 20))
                {
                    return count;
                }
                count++;
            }
        }
        static void Main(string[] args)
        {
            Console.WriteLine(SmallestMultiple());
        }
    }
}
