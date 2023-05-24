using System;

namespace Operation
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] quarters = {1, 2, 3, 4};
            int[] sales ={1111, 2222, 2323,44444};
            double[] intlMixPct = {.343, .434, .532, .921};
            string str1 = "TestStr";
            int val1 = 1234;
            decimal val2 = 1234.5665m;

            Console.WriteLine("{0}", str1);
            Console.WriteLine("{0:E}, {0:N}, {0:F}, {0:G}", val1);
            Console.WriteLine("{0:E}, {0:N}, {0:F}, {0:G}", val2);
            Console.WriteLine("{0:D4}, {0:N5}, {0:F3}, {0:G3}", val1);

            Console.WriteLine("Sales by Quarter:");
            Console.WriteLine("{0,12} {1,12} {2,12} {3,12}", quarters[0], quarters[1], quarters[2], quarters[3]);
            Console.WriteLine("{0,12:C0} {1,12:C0}{2,12:C0}{3,12:C0}", sales[0], sales[1], sales[2],sales[3]);
            Console.WriteLine("International Sales: ");
            Console.WriteLine("{0,12:P0} {1,12:P0} {2,12:P0} {3,12:P0}", intlMixPct[0], intlMixPct[1], intlMixPct[2], intlMixPct[3]);




        }
    }
}