using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExamBasics
{
	public abstract class Plants
	{
		protected double current_water_amount = 0;
		protected double min_water_amount = 0;
		protected double effectiveness = 0;

		public Plants() { }
		public bool needsWater
		{
			get { return current_water_amount <= min_water_amount; }
		}
		public double water
		{
			get { return current_water_amount; }
			set { current_water_amount += value * effectiveness; }
		}
	}
}
