using System;
using System.Globalization;

namespace Parsing
{
    class Program
    {
        static void Main(string[] args)
        {
            string numStr1 = "1";
            string numStr2 = "2.00";
            string numStr3 = "3,000";
            string numStr4 = "3,000.00";

            int targetNum;

            try{
                targetNum = int.Parse(numStr1);
                Console.WriteLine($"{targetNum}");

                targetNum = int.Parse(numStr2, NumberStyles.Float);
                Console.WriteLine($"{targetNum}");

                targetNum = int.Parse(numStr3, NumberStyles.AllowThousands);
                Console.WriteLine($"{targetNum}");

                targetNum = int.Parse(numStr4, NumberStyles.AllowThousands | NumberStyles.Float );
                Console.WriteLine($"{targetNum}");

                Console.WriteLine($"{bool.Parse("True")}");
                Console.WriteLine($"{bool.Parse("False")}");

                Console.WriteLine($"{float.Parse("1.235"):F2}");
                Console.WriteLine($"{float.Parse("1.235"):F3}");
                Console.WriteLine($"{float.Parse("1.235"):F4}");
                Console.WriteLine($"{float.Parse("1.235"):F5}");
                Console.WriteLine($"{float.Parse("1.235"):F6}");
            }

            catch{
                Console.WriteLine("Conversion Failed");
            }

            bool succeeded = false;

            succeeded = Int32.TryParse(numStr1, out targetNum);
            if(succeeded){
                Console.WriteLine($"{targetNum}");
            }    
        }
    }
}
