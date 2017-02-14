using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;



namespace Unsafe
{
    class Program
    {
        public static long Measure()
        {
            Stopwatch stopwatch = new Stopwatch();
            int[] myArray = new int[20000];
            stopwatch.Start();
            for (int i = 0; i < 20000; i++)
            {
                for (int j = 0; j < 20000; j++)
                {
                    myArray[j] = j;
                }
            }
            stopwatch.Stop();
            return stopwatch.ElapsedMilliseconds;
        }

        //I allocate the array on stack, so it will be run faster
        public static long MeasureUnsafe()
        {
            Stopwatch stopwatch = new Stopwatch();
            unsafe
            {
                int* myArray = stackalloc int[20000];
                stopwatch.Start();
                for (int i = 0; i < 20000; i++)
                {
                    for (int j = 0; j < 20000; j++)
                    {
                        myArray[j] = j;
                    }
                }
                stopwatch.Stop();
            }
            return stopwatch.ElapsedMilliseconds;
        }

        static void Main(string[] args)
        {
            Console.WriteLine(Measure());
            Console.WriteLine(MeasureUnsafe());
            //output will be:
            //Measure: 1200 ms
            //MeasureUnsafe: 1050 ms
        }
    }
}
