using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BinarySearch
{
    public class Binary
    {
        public bool BinarySearch(int[] data, int searchElement)
        {
            int low = 0;
            int high = data.Length - 1;
            int middle = (low + high) / 2;

            while (low < high)
            {
                if (searchElement == data[middle])
                {
                    return true;
                }
                else if (searchElement < data[middle])
                {
                    high = middle - 1;
                }
                else if (searchElement > data[middle])
                {
                    low = middle + 1;
                }
                middle = (low + high) / 2;
            }
            return false;
        }
    }
}
