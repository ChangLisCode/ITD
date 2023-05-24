using System;
using System.Linq;

namespace game{
    class Program
    {
        public static int randomNumber(int a, int b)
        {
            Random rnd = new Random();
            int temp = rnd.Next(a, b);
            return temp;
        }
        public static bool guessProcess(int number, int timeLimit)
        {
            int guessTimeCount = 0;
            bool returnValue = false;

            Console.WriteLine("Now we have Target number, let us start the game!\n");
            // Console.WriteLine("Guess the number, input start!\n");

            for (int i = 0; i < timeLimit; i++)
            {      
                int guessNumber = int.Parse(Console.ReadLine());              
                if (guessNumber < number)
                {
                    Console.WriteLine("Lower than this number\n");
                    guessTimeCount++;
                    returnValue = false;
                    continue;
                }
                else if (guessNumber > number)
                {
                    Console.WriteLine("Higher than this number\n");
                    guessTimeCount++;
                    returnValue = false;
                    continue;
                }
                else
                {
                    Console.WriteLine("Got it! You win!\n");
                    guessTimeCount++;
                    Console.WriteLine("You guess time is {0}\n", guessTimeCount);
                    returnValue = true;
                    break;
                }    
                Console.WriteLine("Guess the number, input again!\n");          
            }
            return returnValue;
        }

        static void Main()
        {
            int timeLimit = 1000;

            Console.WriteLine("Please input the number range, the Min and Max:");

            int a = int.Parse(Console.ReadLine());
            int b = int.Parse(Console.ReadLine());

            // Console.WriteLine("The random number is :{0}", number);

            // Level 1 for begginer, no guess time limit, fixed range
            Console.WriteLine("For begginer level, the guess number is between {0} and {1}.", a, b);
            int number1 = randomNumber(a, b);
            guessProcess(number1, timeLimit);     

            // Level 2 for intermediate, no guess time limit, variable range, 
            Console.WriteLine("Congratulation! You are intermediate player now!\n");
            Console.WriteLine("For intermediate level, there is no range notice. Let us start!\n");
            int number2 = randomNumber(a, b);

            guessProcess(number2, timeLimit);

            // Level 3 for master, win 2 times out of 3. guess times max = 5
            Console.WriteLine("Congratulation! You are master player now!");
            Console.WriteLine("For master level, there is no range notice. And guess time is 5! You will win finally when you win 2 times out of the 3! Let us start!");
            int number3 = randomNumber(a, b);

            timeLimit = 5;
            int playScore = 0;

            for(int i = 0; i<3; i++)
            {
                if(guessProcess(number3, timeLimit) == true)
                {
                    Console.WriteLine("You Win the round!\n");
                    playScore++; 
                    break;                    
                }
                else
                {
                    Console.WriteLine("You lose this round! You have {0} chance!\n", 3-i-1);
                }
            }
            
            if(playScore >= 2)
            {
                Console.WriteLine("Congratulation! You win the game!\n");
            }
            else
            {
                Console.WriteLine("Sorry! You lose the game! \nWelcome try again!\n\n");
            }
        }
    }
}


