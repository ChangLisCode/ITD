Imports System

Module Program
    Sub Main(args As String())
        Dim num As Integer = 10
        UpdateValueByVal(num)
        Console.WriteLine("After ByVal: " & num)
        UpdateValueByRef(num)
        Console.WriteLine("After ByRef: " & num)
        Console.ReadLine()
            Dim number As Integer = 12

        Console.WriteLine("Before Squaring: " & number)
        SquaringNumberByVal(number)
        Console.WriteLine("After Squaring: " & number)

        Console.WriteLine()

        Console.WriteLine("Before Squaring: " & number)
        SquaringNumberByRef(number)
        Console.WriteLine("After Squaring: " & number)
    End Sub

    Sub UpdateValueByVal(ByVal value As Integer)
        value = 20
    End Sub

    Sub UpdateValueByRef(ByRef value As Integer)
        value = value * value
        Console.WriteLine("Inside UpdateValueByRef: " & value)
    End Sub

    Sub SquaringNumberByVal(ByVal num As Integer)
        num = num * num
        Console.WriteLine("Inside SquaringNumberByVal: " & num)
    End Sub

    Sub SquaringNumberByRef(ByRef num As Integer)
        num = num * num
        Console.WriteLine("Inside SquaringNumberByRef: " & num)
    End Sub
End Module
