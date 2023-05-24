using System;

namespace Operation
{
    class Program
    {
        static void Main(string[] args)
        {
            string outstr;
            string str1 = "The quick throw box jumps over the lazy dog..";
            string str2 = "This is a string.";
            string str3 = "This is a STRING.";
            string[] strs = {"one", "two","three","four"};

            Console.WriteLine(str1.Length);

            Console.WriteLine(str1[0]);
            Console.WriteLine(str1[13]);
            Console.WriteLine(str1[14]);
            Console.WriteLine(str1[15]);

            foreach (Char ch in str1);
            {
                Console.WriteLine(ch);
                if (ch == 'b'){
                    Console.WriteLine();
                    break;
                }
            }
         
            outstr = String.Concat(strs);
            Console.WriteLine(outstr);

            outstr = String.Join(".", strs);
            Console.WriteLine(outstr);

            outstr = String.Join("--", strs);
            Console.WriteLine(outstr);

            int result = String.Compare(str2, "This is a string");           
            Console.WriteLine("{0}", result);

            bool isEqual = str2.Equals(str3);
            Console.WriteLine("{0}", isEqual);

            Console.WriteLine("{0}", str1.IndexOf('e'));
            Console.WriteLine("{0}", str1.IndexOf("fox"));

            Console.WriteLine("{0}", str1.LastIndexOf('e'));
            Console.WriteLine("{0}", str1.LastIndexOf("the"));

            outstr = String.Concat(strs);
            Console.WriteLine("{0}", outstr);
            Console.WriteLine("{0}", outstr.IndexOf("fox"));
        }
    }
}



