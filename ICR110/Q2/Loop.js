Console.WriteLine();
Console.WriteLine("----------------------------------------");
Console.WriteLine("Prime Number 1-100");
int count = 0;
for (int i = 2; i <= 100; i++)
{
    for (int j = 1; j <= i; j++)
    {
        if (i % j == 0) 
            count++;
        if (count == 2) 
            Console.WriteLine(i);
    }
    count = 0;
}