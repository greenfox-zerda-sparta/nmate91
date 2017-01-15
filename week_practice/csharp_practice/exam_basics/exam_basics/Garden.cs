using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExamBasics
{
	public class Garden
	{
		private Tree yellowtree;
		private Tree redtree;
		private Flower purpleflower;
		private Flower blueflower;
		private List<Plants> plants = new List<Plants>();  

		public Garden()
		{
			yellowtree = new Tree("yellow");
			plants.Add(yellowtree);

			redtree = new Tree("red");
			plants.Add(redtree);

			purpleflower = new Flower("purple");
			plants.Add(purpleflower);

			blueflower = new Flower("blue");
			plants.Add(blueflower);
		}

		public double wateringTree
		{
			set
			{
				if(yellowtree.needsWater())
				{
					yellowtree.watering = value;
					Console.WriteLine("Watering " + yellowtree.getColor() +  " tree with " + value.ToString());
				}
				else
				{
					Console.WriteLine("Tree doesnt need water.");
				}
			}

		}

		public double wateringFlower
		{
			set
			{
				if(purpleflower.needsWater())
				{
					purpleflower.watering = value;
					Console.WriteLine("Watering " + purpleflower.getColor() + " flower with " + value.ToString());
				}
				else
				{
					Console.WriteLine("Tree doesnt need water.");
				}
			}
		}

		public double wateringEverything
		{
			set
			{
				foreach (Plants element in plants)
				{
					if(element.needsWater())
					{
						element.watering = value;
						Console.WriteLine("Watering " + element.getColor() + " " + element.getType() +  " with " + value.ToString());
					}
					else
					{
						Console.WriteLine("Tree doesnt need water.");
					}
				}
			}
		}
	}
}
