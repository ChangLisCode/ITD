using System;

namespace StringInterpolation
{
    class Program
    {
        static void Main(string[] args)
        {
            string make = "BMW";
            string model = "330";
            int year = 2023;
            float miles =8_440.27f;
            decimal price = 60_275.0m;

            Console.WriteLine("This car is {0} {1} {2}, with {3} miles and costs ${4}.", year, make, model, miles, price);
            Console.WriteLine($"This car is {year} {make} {model}, with {miles} miles and ${price}.");
            Console.WriteLine($"This car is {year} {make} {model}, with {miles} and {price:C2}.");
            Console.WriteLine($"This car is {year} {make} {model}, with {miles *1.6:F2} kilometers and costs ${price}.");
        }
    }
}