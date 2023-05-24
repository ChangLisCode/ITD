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

            // Question 1
            if (File.Exists(filePath))
            {
                Console.WriteLine("\n\nResponse for Question 1\n");
                int[] counts = question_1_Count(filePath);
                Console.WriteLine("Line count: {0}\nWord count: {1}\nCharacter count: {2}", counts[0], counts[1], counts[2]);            
            }
            else
            {
                Console.WriteLine("The file does not exist.");
            }

            // Question 2
            Console.WriteLine("\n\nResponse for Question 2\n");
            Tuple<string, int> longestWord = question_2_FindLongestWord(words);
            Console.WriteLine("Longest word: {0} ({1} characters)", longestWord.Item1, longestWord.Item2);

            Tuple<string, int> shortestWord = question_2_FindShortestWord(words);
            Console.WriteLine("Shortest word: {0} ({1} characters)", shortestWord.Item1, shortestWord.Item2);
            
            // Question 3
            Console.WriteLine("\n\nResponse for Question 3\n");

            int topN = 10; // top N value by user set
            // Console.WriteLine("Please input N value for most frequnt word.");
            // topN = Console.ReadLine();

            Dictionary<string, int> wordFrequency = ComputeWordFrequencies(words);
            List<string> topWords = GetTopNWords(wordFrequency, topN);
            Console.WriteLine($"Top {topN} most frequent words:");

            foreach (string word in topWords)
            {
                Console.WriteLine($"{word}: {wordFrequency[word]}");
            }

            // Question 4
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


            // Question 5
            Console.WriteLine("\n\nResponse for Question 5\n");
       
            // Prompt the user to enter the frequency threshold
            Console.WriteLine("Enter the frequency threshold:");
            int threshold = int.Parse(Console.ReadLine());

            // Find and output all word pairs with frequency greater than the threshold
            Console.WriteLine("Word pairs with frequency greater than {0}:", threshold);
            Dictionary<string, int> pairs = FindWordPairs(words);
            OutputFrequentPairs(pairs, threshold);   

            Console.ReadLine();
        }

    // Question 1
        static int[] question_1_Count(string filePath)
        {
            string[] lines = File.ReadAllLines(filePath);
            int lineCount = lines.Length;
            int wordCount = 0;
            int charCount = 0;

            foreach (string line in lines)
            {
                charCount += line.Length;
                string[] words = line.Split(' ', StringSplitOptions.RemoveEmptyEntries);
                wordCount += words.Length;
            }

            int[] counts = new int[3];
            counts[0] = lineCount;
            counts[1] = wordCount;
            counts[2] = charCount;

            return counts;
        }

    // Question 2
        static Tuple<string, int> question_2_FindLongestWord(string[] words)
        {
            var longest = words.OrderByDescending(w => w.Length).First();
            return Tuple.Create(longest, longest.Length);
        }

        static Tuple<string, int> question_2_FindShortestWord(string[] words)
        {
            var shortest = words.OrderBy(w => w.Length).First();
            return Tuple.Create(shortest, shortest.Length);
        }

    // Question 3
        static Dictionary<string, int> ComputeWordFrequencies(string[] words)
        {
            Dictionary<string, int> wordFrequency = new Dictionary<string, int>();
            foreach (string word in words)
            {
                if (wordFrequency.ContainsKey(word))
                {
                    wordFrequency[word]++;
                }
                else
                {
                    wordFrequency[word] = 1;
                }
            }
            return wordFrequency;
        }
        static List<string> GetTopNWords(Dictionary<string, int> wordFrequency, int n)
        {
            // sort dictionary by value (frequency) and return top N keys (words)
            return wordFrequency.OrderByDescending(x => x.Value).Take(n).Select(x => x.Key).ToList();
        }

        // Question 4
        static bool IsPalindrome(string str)
        {
            return str.SequenceEqual(str.Reverse());
        }

        // Question 5
        static Dictionary<string, int> FindWordPairs(string[] words)
        {
            // Create a dictionary to store the frequency of each word pair
            Dictionary<string, int> pairs = new Dictionary<string, int>();

            // Iterate through the words and count the frequency of each word pair
            for (int i = 0; i < words.Length - 1; i++)
            {
                string pair = words[i] + " " + words[i + 1];
                if (!pairs.ContainsKey(pair))
                {
                    pairs[pair] = 1;
                }
                else
                {
                    pairs[pair]++;
                }
            }
            return pairs;
        }

        static void OutputFrequentPairs(Dictionary<string, int> pairs, int threshold)
        {
            // Find and output all word pairs with frequency greater than the threshold
            foreach (KeyValuePair<string, int> pair in pairs)
            {
                if (pair.Value > threshold)
                {
                    Console.WriteLine("{0} ({1})", pair.Key, pair.Value);
                }
            }
        }
    }
}

