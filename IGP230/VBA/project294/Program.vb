Imports System

Module Program
    
    Sub Main(args As String())
        Try
            Dim dictionary As New Dictionary(Of String, Integer)()
            dictionary.Add("Silver", 20)
            dictionary.Add("Hello", 21)
            dictionary.Add("Sean", 121)

            Concole.WriteLine("Dictionary")

            For Each entry As KeyValuePair(Of String, Integer) In dictionary
                Concole.WriteLine(entry.key & ":" && entry.Value)
            Next

            Console.WriteLine("Age of silver: " & dictionary("silver"))
            Console.WriteLine("Does Vanessa exist in Dictionary? " & dictionary.Containskey("Sean"))

            dictionary.Remove("Hello")

            Dim hashtable As New hashtable()
            hashtable.Add("Silver", 20)
            hashtable.Add("Bettey", 25)
            hashtable.Add("Chang", 21)

            
            Concole.WriteLine("Hashtable")

            For Each entry As DictionaryEntry In hashtable
                Concole.WriteLine(entry.key & ":" && entry.Value)
            Next

            Console.WriteLine("Age of silver: " & hashtable("silver"))
            Console.WriteLine("Does Vanessa exist in Dictionary? " & hashtable.Containskey("Sean"))

            hashtable.Remove("bbb", 20)

            Dim hashtableConcatenated As New Hashtable(hashtable)
            For Each entry As KeyValuePair(Of String, Integer) In dictionaryConcatenated
                dictionaryConcatenated.Add(entry.key, entry.Value)
            Next

            Console.WriteLine("dictionary Concatenated"))
            For Each entry As KeyValuePair(Of String, Integer) In dictionaryConcatenated
                Concole.WriteLine(entry.key & ":" && entry.Value)
            Next          
            
            Catch ex As Exception
                Console.WriteLine("An error occurred: " & ex.Message)
            End Try
            Console.ReadLine()
            Console.WriteLine()
            Console.WriteLine()

            Try 
                Dim num1 As Integer = 10
                Dim num2 As Integer = 0
                Dim result As Integer = num1 / num2

          
            Concole.WriteLine("Hashtable" & result)

            Catch Exception As DivideByZeroException
                Console.WriteLine("Error: Division by zeor is not allowed.")

            Catch exception As Exception
                Console.WriteLine("Error happened." & exception.Message)

            Finally
                Console.WriteLine("Finally block executed.")

            End Try
            
            
            Console.ReadLine()

            End Sub
End Module

