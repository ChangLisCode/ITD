using System;
    namespace Conditionals
    {
        class Program
        {
            static void Main(string[] args)
            {
                int theVal = -54;
                if (theVal == 50)
                {
                    Console.WriteLine("theVal Value is 50.");
                }
                else if(theVal >=51 && theVal <= 60)
                {
                    Console.WriteLine("theVal is between 51 and 60.");
                }
                else
                {
                    Console.WriteLine("theVal has other values.");
                }

                int theVall = -504;

                if (theVall == 50)
                {
                    Console.WriteLine("theVal value is 50.");
                }
                else
                {
                    Console.WriteLine("theVal has other values.");
                }        
            }
        }
    }