namespace ExamBasics
{
	public abstract class Plants
	{
		protected string color;
		protected string planttype;
		protected double currentwateramount = 0;
		protected double minimumwateramount = 0;
		protected double effectiveness = 0;

		public bool NeedsWater()
		{
			return currentwateramount <= minimumwateramount;
		}
		public void Watering(double water)
		{
			currentwateramount += (water * effectiveness);
			return;
		}
		public string GetColor()
		{
			return color;
		}
		public string GetPlantType()
		{
			return planttype;
		}
	}
}
