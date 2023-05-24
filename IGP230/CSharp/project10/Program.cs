using System;

namespace Exceptions
{
    class Program
    {
        static void Main(string[] args)
        {
            int x = 10000;
            int y = 0;
            int result;

            try {
                if (x > 1000){
                    throw new ArgumentOutOfRangeException("x", " the x value must be 1000or less");
                    }
                result = x / y;
                Console.WriteLine("The result output is: {0}", result);
            }    
            catch(DivideByZeroException e){
                Console.WriteLine("WhileLoops! there is a problem with y value.");
                Console.WriteLine(e.Message);    
            }
            catch(ArgumentOutOfRangeException e){
                Console.WriteLine("Sorry, 1000 is the limit.");
                Console.WriteLine(e.Message);
            }
            finally {
                Console.WriteLine("I have considered 100% of the poosibilities and I am sure the code always run.");
            }
        }           
    }
}