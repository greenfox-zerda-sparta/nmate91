using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BullsAndCows
{
	class NumberGenerator
	{
		private Random rnd = new Random();
		private string generatedNumber;

		public NumberGenerator()
		{
			generatedNumber = "";
		}
		public string getGeneratedNumber
		{
			get { return generatedNumber;  }
		}
		public void generateNumber()
		{
			generatedNumber += (rnd.Next(1, 10).ToString());
			for (int i = 1; i < 4; i++)
			{
				string generatedChar = (rnd.Next(0, 10).ToString());
				if (generatedNumber.Contains(generatedChar)) {
					i--;
				}
				else
				{
					generatedNumber += generatedChar;
				}
			}
		}
	}
}
