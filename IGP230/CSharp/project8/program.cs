using System;

namespace WhileLoops
{
    class Program
    {
        static void Main(string[] args)
        {
            string inputStr = "";
            Console.WriteLine("Basic While() loop output:");
            while (inputStr != "exit"){
                inputStr = Console.ReadLine();
                Console.WriteLine("You inserted:{0}", inputStr);
            }
            Console.WriteLine();
            Console.WriteLine("The do-While Loop output:");;
            
            do{
                inputStr = Console.ReadLine();
                Console.WriteLine("You inserted:{0}", inputStr);
            }while(inputStr !="exit");
            Console.WriteLine();      
        }
    }
}