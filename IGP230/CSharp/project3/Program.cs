// See https://aka.ms/new-console-template for more information
using System;

namespace Operators
{
    class Program
    {static void Main(string[] args)
        {
            int x = 11, y = 5;
            string a = "dakd", b = "eghg";

            Console.WriteLine("--------- Basic Math --------");
            Console.WriteLine((x/y) * x);
            Console.WriteLine(a + b);

            Console.WriteLine("--------- Shorthand ---------");
            x++;
            y--;
            Console.WriteLine(y);
            Console.WriteLine(x);

            a += b;
            Console.WriteLine(a);
            Console.WriteLine(b);

            Console.WriteLine("--------- Logical Operators ---------");
            Console.WriteLine(x > y && y >= 5);
            Console.WriteLine(x > y || y >= 5);

            Console.WriteLine("--------- ?? Operators ---------");
            string str = null;

            Console.WriteLine(str ?? "Sample String");

            Console.WriteLine("--------- ??= Operators ---------");

            str ??= "New String";
            Console.WriteLine(str);

            str = Console.ReadLine();   
        }   
    }
}