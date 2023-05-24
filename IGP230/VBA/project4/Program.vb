Imports System

Module DataStructureExamples
    Sub Main(args As String())
        Dim nameCollection As New Collection()

        nameCollection.Add("Vanessa")
        nameCollection.Add("Chang")
        nameCollection.Add("Mohanmed")
        nameCollection.Add("Alice")
        nameCollection.Add("Bob")

        Console.WriteLine("Collection Example: ")
        For Each name As String In nameCollection
            Console.WriteLine(name)
        Next
        Console.ReadLine()

        Dim myCollection As New Collection()
        myCollection.Add("Item 1")
        myCollection.Add("Item 2")
        myCollection.Add("item 3")
        myCollection.Add("item 4")
        myCollection.Add("item 5")
        myCollection.Add("item 6")

        Dim item As String = myCollection.Item(1)
        Console.WriteLine("Item at index 1: " &item)

        myCollection.Clear()

        Dim itemCount As Integer = myCollection.Count
        Console.WriteLine("Item count: " & itemCount)
    End Sub
End Module
