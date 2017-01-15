using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BullsAndCows
{
	class UserInterface
	{
		private readonly int maxguess;
		private GameLogic game;
		private string guess;
		private int guesscounter;

		public UserInterface()
		{
			game = new GameLogic();
			guesscounter = 0;
			maxguess = 10;
		}
		public bool askPlayAgain()
		{
			Console.WriteLine("Wanna play again? Type yes/no");
			string input;
			input = Console.ReadLine();
			return input == "yes";
		}
		public void run()
		{
			do
			{
				Console.WriteLine("Take a guess! You have " + (maxguess - guesscounter).ToString() + " guesses left");
				guess = Console.ReadLine();
				game.userguess = guess;
				if (game.isWon())
				{
					if(askPlayAgain())
					{
						game = new GameLogic();
						run();
					}
					else
					{
						Console.WriteLine("BYE!!!");
						break;
					}
				}
				if (maxguess - guesscounter <= 1)
				{
					Console.WriteLine("You lost.");
					break;
				}
				if (game.userguess.Length != 4)
				{
					guesscounter--;
					Console.WriteLine("Invalid guess.");
				}
				Console.WriteLine("Bulls: " + game.countBulls().ToString());
				Console.WriteLine("Cows: " + game.countCows().ToString());
				guesscounter++;
			}
			while (true);
		}
	}
}
