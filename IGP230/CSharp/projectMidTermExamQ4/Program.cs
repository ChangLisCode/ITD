using System;

namespace RockPaperScissors
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] moves = {"rock", "paper", "scissor"};

            int playerWins = 0;
            int computerWins = 0;
            int roundsPlayed = 0;

            while (true)
            {
                Console.Write("Input your guess by word: rock, paper, or scissor: \n");
                string playerMove = Console.ReadLine().ToLower();

                Random rand = new Random();
                int computer = rand.Next(0, 3);
                string computerMove = moves[computer];

                string result;
                if (playerMove == computerMove)
                {
                    result = "tie";
                }
                else if 
                ((playerMove == "rock" && computerMove == "scissor") || 
                (playerMove == "paper" && computerMove == "rock") || 
                (playerMove == "scissor" && computerMove == "paper"))
                {
                    result = "win";
                    playerWins++;
                }
                else
                {
                    result = "lose";
                    computerWins++;
                }

                Console.WriteLine($"You {result}! You chose {playerMove} and the computer chose {computerMove}.");
                Console.WriteLine($"Score: You {playerWins} - {computerWins} Computer");

                roundsPlayed++;
                if (playerWins == 3)
                {
                    Console.WriteLine("You win!");
                    break;
                }
                else if (computerWins == 3)
                {
                    Console.WriteLine("computer wins!");
                    break;
                }
                else if (roundsPlayed > 2 && result == "tie")
                {
                    Console.WriteLine("Starting again");
                    playerWins = 0;
                    computerWins = 0;
                    roundsPlayed = 0;
                }
            }

            Console.Write("any key to exit");
            Console.ReadKey();
        }
    }
}
