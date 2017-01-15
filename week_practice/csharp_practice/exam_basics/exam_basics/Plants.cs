using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace exam_basics
{
	public abstract class Plants
	{
		private double current_water_amount;
		private const double max_water_amount = 70;
		private bool needs_water;

		public Plants()
		{
			current_water_amount = 70;
		}

		public bool needsWater
		{
			get { return current_water_amount < 6; }
			set { needs_water = value; }
		}

		public virtual double water { get; set; }
	}
}
