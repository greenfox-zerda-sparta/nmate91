using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExamBasics
{
	public class Garden
	{
		private Tree tree;
		private Flowers flower;

		public Garden()
		{
			tree = new Tree();
			flower = new Flowers();
		}

		public double wateringTree
		{
			set
			{
				if(tree.needsWater)
				{
					tree.water = value;
					Console.WriteLine("Watering tree with " + value.ToString());
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
				if(flower.needsWater)
				{
					flower.water = value;
					Console.WriteLine("Watering flower with " + value.ToString());
				}
				else
				{
					Console.WriteLine("Tree doesnt need water.");
				}
			}
		}
	}
}
