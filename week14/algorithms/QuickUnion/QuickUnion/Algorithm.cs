using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QuickUnion
{
    public class Algorithm
    {
        private int[] localArray;

        private int Root(int i)
        {
            while (i != localArray[i])
            {
                localArray[i] = localArray[localArray[i]];
                i = localArray[i];
            }
            return i;
        }

        public Algorithm(int[] inputArray)
        {
            localArray = inputArray;
        }

        public bool Find(int p, int q)
        {
            return Root(p) == Root(q);
        }

        public void Unite(int p, int q)
        {
            int i = Root(p);
            int j = Root(q);
            localArray[i] = j;
        }
    }
}
