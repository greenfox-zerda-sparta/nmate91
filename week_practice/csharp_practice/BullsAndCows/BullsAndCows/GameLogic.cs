using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BullsAndCows
{
	class GameLogic
	{
		private NumberGenerator randomnumber;
		private string _userguess;

		public GameLogic()
		{
			randomnumber = new NumberGenerator();
			randomnumber.generateNumber();
		}
		public string userguess
		{
			get { return _userguess; }
			set { _userguess = value; }
		}
		public bool isCow(char digit, int index)
		{
			for(int i = 0; i < randomnumber.getGeneratedNumber.Length; i++)
			{
				if (digit == randomnumber.getGeneratedNumber[i] && index != i)
				{
					return true;
				}
			}
			return false;
		}
		public bool isBull(char digit, int index)
		{
			for (int i = 0; i < randomnumber.getGeneratedNumber.Length; i++)
			{
				if (digit == randomnumber.getGeneratedNumber[i] && index == i)
				{
					return true;
				}
			}
			return false;
		}
		public bool isWon()
		{
			return randomnumber.getGeneratedNumber == _userguess;
		}
		public int countBulls()
		{
			int counter = 0;
			int index = 0;
			foreach(char c in _userguess)
			{
				if (isBull(c, index))
				{
					counter++;
				}
				index++;
			}
			return counter;
		}
		public int countCows()
		{
			int counter = 0;
			int index = 0;
			foreach (char c in _userguess)
			{
				if (isCow(c, index))
				{
					counter++;
				}
				index++;
			}
			return counter;
		}
	}
}
