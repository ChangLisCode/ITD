using System;
    namespace ConditionalsOps
    {
        class Program
        {
            static void Main(string[] args)
            {
                int theVal = 50;
                switch(theVal)
                {
                    case 50:                  
                        Console.WriteLine("theVal Value is 50.");
                        break;
                    case 51:
                        Console.WriteLine("theVal is 51.");
                        break;
                    case 52:
                        Console.WriteLine("theVal value is 52.");
                        break;
                    default:
                        Console.WriteLine("theVal has other values.");
                        break;
                }
            }
        }
    }