using System;

namespace intergerParse
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Please input the interger string seperated by commas:");
            string input = Console.ReadLine();

            string[] inputArray = input.Split(','); // split to string by comma
            int[] numbers = new int[inputArray.Length]; // define int array

            for (int i = 0; i < inputArray.Length; i++) 
            {
                numbers[i] = Int32.Parse(inputArray[i].Trim()); // convert string to interger and store in int array
            }

            int evenSum = 0;
            string output = "";
            foreach (int number in numbers) 
            {
                if (number % 2 == 0) {
                    evenSum += number;
                    output += number.ToString() + "^2 = " + (number * number).ToString() + ", ";
                }
            }
            if (output != "") 
            {
                output = output.Substring(0, output.Length-2);
                Console.WriteLine(output);
                Console.WriteLine("even sum is: " + evenSum.ToString());
            } 
            else 
            {
                Console.WriteLine("there is not even numbers.");
            }
        }
    }
}