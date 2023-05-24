using System;

namespace ForLoops
{
    class Program
    {
        static void Main(string[] args)
        {
            int myVal = 15;
            int[] nums = new int[] {3,14,15,3,4};
            string str = "the quick brown fox jumps over the lazy dog.";

            for(int i=0; i<myVal; i++){
                Console.WriteLine("the value of i is currently {0}.", i);
            }
            Console.WriteLine();
            Console.WriteLine("the foreach loop output:");
            foreach(int i in nums){
                Console.WriteLine("the value of i is currently {0}", i);
            }

            var count = 0;
            foreach (char c in str){
                if (c == '0'){
                    count++;
                }
            }
            Console.WriteLine("I have counted {0} letter o in the given string.", count);
        }
    }
}