Imports System

Module Program
    
    Sub Main(args As String())
        Dim list As New ArrayList()
        list.Add(10)
        list.Add("Hello")
        list.Add(True)

        list(1) = "World"

        Dim value1 As Integer = CInt(list(0))
        Dim value2 As String = CString(list(1))
        Dim value3 As Boolean = CBool(list(2))


        Console.WriteLine("Value 1: " & value1)
        Console.WriteLine("Value 2: " & value2)
        Console.WriteLine("Value 3: " & value3)

        Dim searchValue As String = "World"
        Dim index As Integer = list.IndexOf(searchValue)

        If index <> -1 Then
            Console.WriteLine("Element '{0}' found at index {1}", searchValue, index)
        Else
            Console.WriteLine("Element '{0}' not found in the ArrayList", searchValue)
        End if
        Console.ReadLine()

        Dim carList As New List(Of String)
        carList.Add("Toyota Corolla")
        carList.Add("Honda Accord")
        carList.Add("Ford Mustang")
        carList.Add("Cheveolet Camaro")

        Console.WriteLine("List of Cars")
        For Each car As String In carList
            Console.WriteLine(car)
        Next

        Console.WriteLine("Total cars in list", & carList.Count)
        Console.WriteLine("List contains 'Honda Accord': ", & carList.Contains("Honda Accord"))

        Console.WriteLine("")
        Console.WriteLine("")


        Dim carArrayList As New ArrayList()
        
        carArrayList.Add("Toyoat")
        carArrayList.Add("Honda")
        carArrayList.Add("Ford")
        carArrayList.Insert(1, "Chev Silver")
        Console.WriteLine("Array in list: ")
        
        For Each car As Object In carArrayList
            Console.WriteLine(car)
        Next
           
        Console.WriteLine("Total cars in list", & carArrayList.Count)
        Console.WriteLine("List contains 'Honda Accord': ", & carArrayList.Contains("Honda Accord"))

        Console.ReadLine()

        ' List Example
        list.Add(10)
        list.Add("Twenty")
        list.Add(30)

        Console.WriteLine("List: ")

        For Each item As Object In list1:
            Console.WriteLine(item)
        Next


        Dim carArrayList As New ArrayList()
        arrayList.Add(10)
        arrayList.Add("Honda")
        arrayList.Add(30)
        
        Console.WriteLine("Array in list: ")
        
        For Each item As Object In arrayList
            Console.WriteLine(item)
        Next
           
        Console.ReadLine()

        End Sub
End Module
