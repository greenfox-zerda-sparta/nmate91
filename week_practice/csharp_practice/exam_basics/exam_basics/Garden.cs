using System;
using System.Collections.Generic;

namespace ExamBasics
{
	public class Garden
	{
		private Tree yellowtree;
		private Tree orange;
		private Flower purpleflower;
		private Flower blueflower;
		private int waterneedcounter;
		private List<Plants> plants = new List<Plants>();  

		public Garden()
		{
			waterneedcounter = 0;
			yellowtree = new Tree("Yellow");
			plants.Add(yellowtree);

			orange = new Tree("Orange");
			plants.Add(orange);

			purpleflower = new Flower("Purple");
			plants.Add(purpleflower);

			blueflower = new Flower("Blue");
			plants.Add(blueflower);
		}
		public void CountPlantsThatNeedWater()
		{
			waterneedcounter = 0;
			foreach (Plants element in plants)
			{
				if (element.NeedsWater())
				{
					waterneedcounter++;
				}
			}
			return;
		}
		public void WaterPlantsThatNeedWater(double wateramount)
		{
			foreach (Plants element in plants)
			{
				if (element.NeedsWater())
				{
					element.Watering(wateramount / waterneedcounter);
				}
			}
		}
		public void PrintNeedsToConsole()
		{
			foreach (Plants element in plants)
				{
				if (element.NeedsWater())
				{
					Console.WriteLine(element.GetColor() + " " + element.GetPlantType() + " needs water.");
				}
				else
				{
					Console.WriteLine(element.GetColor() + " " + element.GetPlantType() + " doesnt need water.");
				}
			}
			Console.WriteLine();
		}
		public void WaterThGarden(double wateramount)
		{
			try
			{
				if (wateramount > 0)
				{
					Console.WriteLine("Watering with " + wateramount.ToString());
				}
				CountPlantsThatNeedWater();
				WaterPlantsThatNeedWater(wateramount);
				PrintNeedsToConsole();
			}
			catch (DivideByZeroException)
			{
				Console.WriteLine("You can't water zero plants...");
			}
		}
	}
}
