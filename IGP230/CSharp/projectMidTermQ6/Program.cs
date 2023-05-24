using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static List<Tuple<string, int, string>> inputParse(string input)
    {
        List<Tuple<string, int, string>> tuples = new List<Tuple<string, int, string>>();
        string[] tupleStrings = input.Split(',');
        foreach (string tupleStr in tupleStrings)
        {
            string[] values = tupleStr.Trim().Split(';');
            string name = values[0];
            int score = int.Parse(values[1]);
            string date = values[2];
            tuples.Add(Tuple.Create(name, score, date));
        }
        return tuples;
    }

    static List<Tuple<string, int, string>> FilterTuples(List<Tuple<string, int, string>> tuples)
    {
        List<Tuple<string, int, string>> filteredResult = new List<Tuple<string, int, string>>();
        DateTime today = DateTime.Today;
        foreach (var tuple in tuples)
        {
            DateTime date = DateTime.ParseExact(tuple.Item3, "yyyy-MM-dd", null);

            if (date >= today.AddYears(-1))
            {
                filteredResult.Add(tuple);
            }
        }
        return filteredResult;
    }

    static string outputResult(List<Tuple<string, int, string>> tuples)
    {
        List<string> outputStr = new List<string>();
        foreach (var tuple in tuples.OrderBy(t => t.Item1))
        {
            string outputStr2 = $"{tuple.Item1} ({tuple.Item2}, {tuple.Item3})";
            outputStr.Add(outputStr2);
            // Console.WriteLine(outputStr2);
        }
        return string.Join(", ", outputStr);
    }

    static void Main(string[] args)    
        {
        string input = "Alice;85;2022-04-01, Bob;95;2021-10-01, Charlie;90;2022-05-01, Dave;80;2021-08-01";
        // input = Console.ReadLine();

        Console.WriteLine("test");
        List<Tuple<string, int, string>> tuples = inputParse(input);
        List<Tuple<string, int, string>> filteredResult = FilterTuples(tuples);
        string output = outputResult(filteredResult);
        Console.WriteLine(output);
    }
}
