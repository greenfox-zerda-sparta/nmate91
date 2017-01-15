using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace exam_basics
{
	public class Tree : Plants
	{
		private double current_water_amount;
		private const double max_water_amount = 40;
		private bool needs_water;

		public Tree()
		{
			current_water_amount = 70;
		}

		public override double water
		{
			get { return current_water_amount; }
			set { current_water_amount += value * 0.4; }
		}
	}
}
