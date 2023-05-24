Imports System

Module StringConcatenationExample
    Sub Main()

    Dim firstName As String = "firstName"
    Dim lastName As String = "lastName"
    Dim fullName As String = firstName & " " & lastName
    Console.WriteLine("Full name: " & fullName)

    Dim age As Integer = 23
    Dim greeting As String = " I am " & age & " years old."
    Console.WriteLine(greeting)

    Dim line1 As string = "This is my line1."
    Dim line2 As String = "This is my line2."

    Dim multilineText As String = line1 & vbCrLf & line2
    Console.WriteLine(multilineText)

    Console.ReadLine()
    End Sub
End Module
