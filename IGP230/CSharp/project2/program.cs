// See https://aka.ms/new-console-template for more information
using System;

namespace HelloWorld
{
    class Program
    {static void Main(string[] args)
        {
            int a = 11;
            int b = 22;
            float m = 11.53f;
            float n = 22.89f;
            decimal d = 10.02m;
            bool b = true;
            char c = 'c';

            string str = "a string";

            var x = 10;
            var z = "Hello";

            int[] vals = new int[5];
            string[] strs ={"one", "Two", "Three"};

            Console.WriteLine("{0}, {1}, {2}, {3}, {4}, {5}", a, b, m, str, false, d, x);

            object obj = null;
            Console.WriteLine(obj);

            string str = Console.ReadLine();         
        }   
    }
}