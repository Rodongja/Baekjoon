using System;

namespace CodeTest
{
    class Program
    {
        static void Main(string[] args)
        {
            string str;
            string[] strSplit;
            int a, b;
            str = Console.ReadLine();
            strSplit = str.Split();
            a = int.Parse(strSplit[0]);
            b = int.Parse(strSplit[1]);

            if (a > b)
            {
                Console.WriteLine(">");
            }
            else if(a < b)
            {
                Console.WriteLine("<");
            }
            else
            {
                Console.WriteLine("==");
            }
        }
    }
}
