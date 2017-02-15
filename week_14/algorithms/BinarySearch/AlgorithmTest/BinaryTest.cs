using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Xunit;
using BinarySearch;

namespace AlgorithmTest
{
    public class BinaryTest
    {
        [Fact]
        public void ReturnsTrueForFindingTenInArray()
        {
            int[] numberArray = new int[100];
            for(int i = 0; i < numberArray.Length; i++)
            {
                numberArray[i] = i;
            }

            Binary binary = new Binary();
            Assert.Equal(binary.BinarySearch(numberArray, 20), true);
        }

        [Fact]
        public void DoesntContainsNumber()
        {
            int[] numberArray = new int[100];
            for (int i = 0; i < numberArray.Length; i++)
            {
                numberArray[i] = 10*i;
            }

            Binary binary = new Binary();
            Assert.Equal(binary.BinarySearch(numberArray, 97), false);
            Assert.Equal(binary.BinarySearch(numberArray, 5), false);
            Assert.Equal(binary.BinarySearch(numberArray, 2), false);
            Assert.Equal(binary.BinarySearch(numberArray, 22), false);
            Assert.Equal(binary.BinarySearch(numberArray, 50), true);
            Assert.Equal(binary.BinarySearch(numberArray, 99), false);

        }
    }
}
