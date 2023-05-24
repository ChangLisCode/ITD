using System;

namespace BreakContinue
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] values = {14, 43, 23,6,36, 54, 32};

            Console.WriteLine("Break and Continue Example Output:");
            foreach (int val in values)
            {
                if (val >= 20 && val <=20){
                    continue;
                }
            Console.WriteLine($"val is currently {val}");

            if (val >= 40){
                break;
                }
            }
        }
    }
}