using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Class1
    {

		private string _name;
		public string Name
		{
			get { return _name; }
			set { _name = value; }
		}
		public void writesomething()
		{
			Console.WriteLine(_name);
		}
	}
}
