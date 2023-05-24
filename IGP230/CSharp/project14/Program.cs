using System;
using System.Text;

namespace Builder
{
    class Program
    {
        static void Main(string[] args)
        {
            StringBuilder sb = new StringBuilder("Initial String. ", 200);

            int jumpCount = 10;
            string[] animals = {"goats", "cats", "pigs"};

            Console.WriteLine($"Capacity: {sb.Capacity}; Length:{sb.Length}");

            sb.Append("The quick brown fox.");
            sb.Append("jumps over the lazy dog.");

            sb.AppendLine();

            sb.AppendFormat("He did this {0} times.", jumpCount);
            sb.AppendLine();

            sb.AppendFormat("He also jumped over");
            sb.AppendJoin(",", animals);

            sb.Replace("fox", "cat");

            sb.Insert(0, "The is is the ");
            sb.Insert(1, "The is is the ");
            sb.Insert(2, "The is is the ");
            sb.Insert(3, "The is is the ");
            sb.Insert(4, "The is is the ");
            sb.Insert(5, "The is is the ");
            sb.Insert(10, "The is is the ");

            Console.WriteLine($"Capacity:{sb.Capacity}; Length: {sb.Length}");
            Console.WriteLine(sb.ToString());
        }
    }
}