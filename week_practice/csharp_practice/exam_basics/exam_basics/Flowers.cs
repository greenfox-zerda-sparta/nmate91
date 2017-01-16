namespace ExamBasics
{
	public class Flower : Plants
	{
		public Flower(string color)
		{
			planttype = "flower";
			this.color = color;
			currentwateramount = 0;
			minimumwateramount = 5;
			effectiveness = 0.75;
		}
	}
}
