using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace ExamQuestion6
{
    class Program
    {
        static void Main(string[] args)
        {
            string filePath;
            Console.WriteLine("Enter the path of the text file:");
            filePath = Console.ReadLine();
            
            string text = "";
            text = File.ReadAllText(filePath);
            string[] words = text.Split(new[] { ' ', '\t', '\n' }, StringSplitOptions.RemoveEmptyEntries);
            int countA = 0; 
            Console.WriteLine("\n\nResponse for Question 4: palindromic words check\n");    
     
            // Find and output all palindromic words
            Console.WriteLine("Palindromic words:");
            foreach (string word in words)
            {
                // prevent repeating 'a' input 
                if (IsPalindrome(word) && word.Length > 1)
                {
                    Console.WriteLine(word);
                }
            }

            foreach (string word in words)
            {
                if (word.Length == 1 && word.Equals("a"))
                {
                    countA++;
                }
            }
            
            Console.WriteLine("And, palindromic words include {0} letter 'a'.\n", countA);
        }

        static bool IsPalindrome(string str)
        {
            return str.SequenceEqual(str.Reverse());
        }
    }
}
