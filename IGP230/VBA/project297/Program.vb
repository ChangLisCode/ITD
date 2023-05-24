Imports System

Module Program
    Sub Main()
        Dim stack As New Stack(Of Dictionary(Of String, String))()
        stack.Push(CreateDictionary("Product A", "Description A"))
        stack.Push(CreateDictionary("Product B", "Description B"))
        stack.Push(CreateDictionary("Product C", "Description C"))
        stack.Push(CreateDictionary("Product D", "Description D"))
        stack.Push(CreateDictionary("Product E", "Description E"))

        Console.WriteLine("Stack Output: ")
        PrintDataStructureContents(stack)

        Dim queue As New Queue(Of Dictionary(Of String, String))()
        queue.Enqueue(CreateDictionary("Product A", "Description A"))
        queue.Enqueue(CreateDictionary("Product B", "Description B"))
        queue.Enqueue(CreateDictionary("Product C", "Description C"))
        queue.Enqueue(CreateDictionary("Product D", "Description D"))
        queue.Enqueue(CreateDictionary("Product E", "Description E"))

        Console.WriteLine("Queue Output: ")
        PrintDataStructureContents(queue)

        Console.ReadLine()
    End Sub

    Sub PrintDataStructureContents(ByVal dataStructure As Object)
        Console.WriteLine("Contents: ")
        For Each item In dataStructure
            PrintDictionary(item)
        Next

        Console.WriteLine()
    End Sub

    Function CreateDictionary(ByVal key As String, ByVal value As String) As Dictionary(Of String, String)
        Dim dictionary As New Dictionary(Of String, String)()
        dictionary.Add("Name", key)
        dictionary.Add("Description", value)
        Return dictionary
    End Function

    Sub PrintDictionary(ByVal dictionary As Dictionary(Of String, String))
        For Each kvp As KeyValuePair(Of String, String) In dictionary
            Console.WriteLine(kvp.Key & ": " & kvp.Value)
        Next
        Console.WriteLine()
    End Sub
End Module
