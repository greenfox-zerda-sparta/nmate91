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
        static bool IsPrime(double number)
        {
            for(double i = 2; i < number; i++)
            {
                if(number % i == 0)
                {
                    return false;
                }
            }
            return true;
        }

        static double ReturnLargestPrimeFactor(double number)
        {
            double i;
            double largest = number;
            for (i = 2; i < Math.Sqrt(number) / 2; i++)
            {
                if(number % i == 0 && IsPrime(i))
                {
                    largest = i;
                }
            }
            return largest;
        }
        static void Main(string[] args)
        {
            //Console.WriteLine(SmallestMultiple());
            Console.WriteLine(ReturnLargestPrimeFactor(600851475143));
        }
    }
}
