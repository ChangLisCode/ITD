using System;

namespace MultiValues{
    class Program
    {
        static void Main(string[] args){
            (int a, int b) tup1 = (5, 10);
            var tup2 = ("Some text", 10.5);

            tup1.b = 20;
            // This line will result in a compilation error because Item1 is read-only.
            //tup2.Item1 = "New String";

            Console.WriteLine($"{tup1.a},{tup1.b}");
            Console.WriteLine($"{tup2.Item1}");

            (int, int) result = PlusTimes(6,12);
            Console.WriteLine($"the sum value is: {result.Item1}, The product value is: {result.Item2}");

        }

        static (int, int) PlusTimes(int a, int b){
            return(a+b, a*b);
        }          
        
    }
}
