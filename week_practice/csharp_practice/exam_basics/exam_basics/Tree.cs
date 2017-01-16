namespace ExamBasics
{
	public class Tree : Plants
	{
		public Tree(string color)
		{
			planttype = "tree";
			this.color = color;
			currentwateramount = 0;
			minimumwateramount = 10;
			effectiveness = 0.4;
		}
	}
}
