Imports System

Module Program
    Sub Main(args As String())

        Dim numberStack As New Stack(Of Integer)()

        numberStack.Push(10)
        numberStack.Push(20)
        numberStack.Push(30)
        numberStack.Push(40)
        numberStack.Push(50)
        numberStack.Push(60)
        numberStack.Push(70)
       
        Console.WriteLine("Stack Example")
        While numberStack.Count > 0
            Dim number As Integer = numberStack.Pop()
            Console.WriteLine(number)
        End While

        Console.ReadLine()

        Dim myStack As New Stack(Of Integer)()
        myStack.Push(1)
        myStack.Push(2)
        myStack.Push(3)

        Dim topElement As Integer = myStack.Peek()
        Console.WriteLine("Top element: " & topElement)

        Console.WriteLine("My Stack Elements")
        While myStack.Count > 0
            Dim number As Integer = myStack.Pop()
            Console.WriteLine(number)
        End While

        Dim containsElement As Boolean = myStack.Contains(2)
        Console.WriteLine("Contains 2: " & containsElement)

        myStack.Clear()

        Dim count As Integer = myStack.Count
        Console.WriteLine("Element count: " & count)
        Console.ReadLine()

        Dim personStack As New Stack(Of Dictionary(Of String, Object))()
        Dim person1 As New Dictionary(Of String, Object)() From{
            {"Name", "Chang"},
            {"Age", 20}
        }
        Dim person2 As New Dictionary(Of String, Object)() From{
            {"Name", "Sean"},
            {"Age", 22}
        }
        Dim person3 As New Dictionary(Of String, Object)() From{
        {"Name", "Sed"},
        {"Age", 22}
        }

        personStack.Push(person1)
        personStack.Push(person2)
        personStack.Push(person3)

        For Each person As Dictionary(Of String, Object) In personStack
            Console.WriteLine("Name: " & person("Name") & ", Age: " & person ("age"))
        Next

        Dim poppedPerson As Dictionary(Of String, Object) = personStack.Pop()
        Console.WriteLine("Popped Person: " & poppedPerson("Name"))
        Console.WriteLine("Current Stack: ")
        

        For Each person As Dictionary(Of String, Object) In personStack
            Console.WriteLine("Name: " & person("Name") & ", Age: " & person ("age"))
        Next

        Console.ReadLine()
    End Sub
End Module
