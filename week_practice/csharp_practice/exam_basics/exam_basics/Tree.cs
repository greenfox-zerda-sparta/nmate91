using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExamBasics
{
	public class Tree : Plants
	{
		public Tree()
		{
			current_water_amount = 20;
			min_water_amount = 5;
			effectiveness = 0.4;
		}
	}
}
