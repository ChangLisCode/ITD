Public MustInherit Class Program
    Protected name As String
    Protected age As integer
    Protected height As Double
    Protected weight As Double

    Public Sub New(name As String, age As integer, height As Double, weight As Double)
        Me.name = name
        Me.age = age
        Me.height = height
        Me.weight =weight
    End Sub

    Public MustOverride Function CalculateBMI() As Double
    Public MustOverride Function GetHealthStatus As String

    Public Sub DisplayInformation()
        Console.WriteLine("Name: " & name)
        Console.WriteLine("Age: " & age)
        Console.WriteLine("height: " & height & " cm")
        Console.WriteLine("Weight: " & weight & " kg")
        Console.WriteLine("BIMI: " & CalculateBMI())
        Console.WriteLine("Healthy Status: " & GetHealthStatus)
        Console.WriteLine()
    End Sub
End Class

Public Class Child 
    Inherits Person
    Public Sub New(name As String, age As Integer, height As Double, weight As Double)
        MyBase.New(name, age, height, weight)
    End Sub

    Public Override Function CalculateBMI() As Double
        Dim heightInMeters As Double = height / 100
        Return weight / (heightInMeters*heightInMeters)
    End Function
End Class

Public Class Program
    Public Shared Sub Main()
        Dim children As New List(Of child)()

        for i As Integer = 1 To 2
            Console.WriteLine("Enter information for child" & i & ":")
            Console.Write("name: ")
            Dim name As String = Console.ReadLine()

            Console.Write("Age: ")
            Dim age As Integer = Integer.Parse(Console.ReadLine)

            
            Console.Write("Age: ")
            Dim age As Integer = Integer.Parse(Console.ReadLine)

            
            Console.Write("Age: ")
            Dim age As Integer = Integer.Parse(Console.ReadLine)

            
            Console.Write("Age: ")
            Dim age As Integer = Integer.Parse(Console.ReadLine)

        Next

        Dim studentName() As String = ("John", "John","John","John","John","John","John","John","John")

        Dim studentAge() As Integer = ( 10,10,10,10,10,10,10,10,10,10,10)
        Dim studentHeight() As Double = (10,10,10,10,10,10,10,10,10,10,10)
        Dim studentWeights() As Double = (10,10,10,10,10,10,10,10,10,10,10)

        For i A integer = 0 To 17
            Dim Child As New Child(studentName(i), studentAge(i), studentHeight(i), studentWeights(i))
            childrenAdd(child)
        Next
        For Each child As Child In children
            child.DisplayInformation()
        Next
        
    End Sub
End Module
