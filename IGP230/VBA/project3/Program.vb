Imports System
Imports System.Collection.Generic

Module DataStructureExample
    Sub Main(args As String())
        Dim fruitList As New List(Of String)()

        fruitList.Add("Pineapple")
        fruitList.Add("Watermelon")

        Console.WriteLine("List Example: ")
        For Each fruit As String In fruitList
            Console.WriteLine(fruit)
        Next
        Console.ReadLine()
        
Dim myList As New List(Of String)
    myList.Add("Item 1")
    myList.Add("Item 2")
    myList.Add("Item 3")

    Dim item As String = myList(0)
    Console.WriteLine("Item at index 0: " & item)

    myList.Remove(0)

    Dim containsItem As Boolean = myList.Contains("Item 2")
    Console.WriteLine("Contains 'Item 2': " & containsItem)

    myList.Clear()

    Dim itemCount As Integer = myList.Count
    Console.WriteLine("Item count: " & itemCount)
    
    Console.ReadLine()

    End Sub
End Module
