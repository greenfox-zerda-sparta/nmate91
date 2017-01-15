using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExamBasics
{
	public abstract class Plants
	{
		protected string color;
		protected string type;
		protected double current_water_amount = 0;
		protected double min_water_amount = 0;
		protected double effectiveness = 0;

		public Plants() { }

		public bool needsWater()
		{
			return current_water_amount <= min_water_amount;
		}
		public double watering
		{
			get { return current_water_amount; }
			set { current_water_amount += value * effectiveness; }
		}
		public string getColor()
		{
			return color;
		}
		public string getType()
		{
			return type;
		}
	}
}
