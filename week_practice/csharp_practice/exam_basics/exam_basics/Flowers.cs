using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExamBasics
{
	public class Flower : Plants
	{
		public Flower(string _color)
		{
			type = "flower";
			color = _color;
			current_water_amount = 9;
			min_water_amount = 10;
			effectiveness = 0.75;
		}
	}
}
