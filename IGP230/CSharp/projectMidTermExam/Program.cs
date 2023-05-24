using System;
using System.Linq;

namespace palindromeCheck{
    class Program
{
        public static bool IsPalindrome(string str)
        {
            // Convert string to lowercase and remove punctuation
            string cleanStr = new string(str.ToLower().Where(c => Char.IsLetter(c)).ToArray());
            
            // Compare string with reversed version of itself
            return cleanStr == new string(cleanStr.Reverse().ToArray());
        }
        static void Main()
        {
            while (true)
            {
                Console.WriteLine("Please input a word, input'exit' to end the program:");
                string input = Console.ReadLine();

                if (input.ToLower() == "exit")
                {
                    break;
                }

                if (IsPalindrome(input))
                {
                    Console.WriteLine($"'{input}' is a palindrome!");
                }
                else
                {
                    Console.WriteLine($"'{input}' is not a palindrome.");
                }
            }
        } 
    }
}

