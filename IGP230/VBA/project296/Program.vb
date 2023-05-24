Imports System

Module Program
    Sub Main(args As String())
        Dim messageQueue As new Queue(Of String)()
        messageQueue.Enqueue("This is my first message to my students in the queue.")
        messageQueue.Enqueue("This is my second message to my students in the queue.")
        messageQueue.Enqueue("This is my third message to my students in the queue.")
        messageQueue.Enqueue("This is my fourth message to my students in the queue.")

        Console.WriteLine("Queue Example")

        While messageQueue.Count > 0
            Dim message As String = messageQueue.Dequeue()
            Console.WriteLine("Dequeue message: " &message)
        End While

        Dim myQueue As New Queue(Of Integer)()
        myQueue.Enqueue(1)
        myQueue.Enqueue(2)
        myQueue.Enqueue(3)

        Console.WriteLine("Front element: " & myQueue.Peek())

        Dim dequeueElement As Integer = myQueue.Dequeue()
        Console.WriteLine(" Dequeued element: " & dequeueElement)

        While myQueue.Count> 0
            dim intQueue As Integer = myQueue.Dequeue()
            Console.WriteLine("Dequeue element; " & intQueue)
        End While

        Dim containsElement As Boolean = myQueue.Contains(2)
        Console.WriteLine("Contains 2: " & containsElement)

        myQueue.Clear()
        Console.WriteLine("Element count: " & myQueue.Count)

        Console.WriteLine(" ")
    End Sub
End Module
