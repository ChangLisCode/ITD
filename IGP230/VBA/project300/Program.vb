Imports System

Module Program
    Sub Main(args As String())
        Dim input As String = "Hi Everyone! Welcome to my Visual Basic Class at ITD canada!"

        Dim substring1 As String = input. Substring(0, 1)
        Dim substring2 As String = input. Substring(0, 2)
        Dim substring3 As String = input. Substring(0, 3)
        Console.WriteLine()

        Dim substring4 As String = input. Substring(1, 0)
        Dim substring5 As String = input. Substring(1, 1)
        Dim substring6 As String = input. Substring(1, 2)
        Dim substring7 As String = input. Substring(1, 3)

        Dim substring8 As String = input. Substring(2, 1)
        Dim substring9 As String = input. Substring(2, 2)
        Dim substring10 As String = input. Substring(2, 3)



        Dim substring11 As String = input. Substring(8, 2)
        Dim substring12 As String = input. Substring(14)

        Console.WriteLine("SubString 1: " & substring1)
        Console.WriteLine("SubString 2: " & substring2)
        Console.WriteLine("SubString 3: " & substring3)
        Console.WriteLine("SubString 4: " & substring4)
        Console.WriteLine("SubString 5: " & substring5)
        Console.WriteLine("SubString 6: " & substring6)
        Console.WriteLine("SubString 7: " & substring7)
        Console.WriteLine("SubString 8: " & substring8)
        Console.WriteLine("SubString 9: " & substring9)
        Console.WriteLine("SubString 10: " & substring10)
        Console.WriteLine("SubString 11: " & substring11)
        Console.WriteLine("SubString 12: " & substring12)

        Dim modifiedString As String = input.SubString(0, 7) & "in vancouver" & input.Substring(14)
        Console.WriteLine("Modified String: " & modifiedString)

        Console.ReadLine()
        
    End Sub
End Module
