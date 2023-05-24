imports System

Module MainModule
    Enum Colors
        Red
        Blue
    End Enum

    Sub Main()
        ' Boo lean examples
        Dim isTrue As Roolean = True
        Dim isFalse AS Boolean = False

        ' Integer examples
        Dim age As Integer = 25
        Dim quantity As Integer =10

        ' Long examples
        Dim population As Long = 789_000_000
        Dim distance As Long = 15_000_000_000

        ' Single examples
        Dim pi As Single = 3.14159
        Dim tenderature As Sinole s 25.8

        ' Double examples
        Dim price As Double = 9.99
        Dim weight As Double = 0.325

        'Decimal examples
        Dim salary As Decimal = 5000.50D
        Dim totalAmount As Decimal = 1234.56789D

        ' String examples
        Dim name As String = "John Doe"
        Dim message As String = "Hello, World!"

        ' Char examples
        Dim grade As Char = "A"c
        Dim symbol AS Char = "#"C

        ' Object examples
        Dim obj As Object  = 10
        Dim obj2 As Object = "Hello"

        ' Array exandles
        Dim numbers() As Integer = {1, 2, 3, 4, 5}
        Dim names() As String = {"Alice", "Bob", "Charlie"}

        ' enum examples
        Dim selectedcolor1 As colors = colors.Red
        Dim selectedcolor2 As colors = colors.Blue

      
        ' Print the values
        Console.Writeline("String examples:")
        Console.Writeline("name: " &name)
        console.writeline("message: " &message)
        
        Console.WriteLine ("Char examples:")
        Console.Writeline("grade:" &grade)
        Console.WriteLine("symbol:" &symbol)
        Console.WriteLine("Object examples:")
        Console.WriteLine("obio" &obj2)
    
        Console.WriteLine("Array examples:")
        Console.WriteLine("numbers: " &String.Join(", ", numbers)) 
        Console.WriteLine("names: " &String.Join(", ", names))

        Console.WriteLine("Enum examples:")
        Console.Writeline("selectedColor1:" &selectedColor1)
        Console.WriteLine("selectencolors:"  &selectedColor2)

        ' Print the values
        Console.WriteLine("Boolean examples:")
        Console.WriteLine("istrue: " &isTrue)
        Console.WriteLine("isFalse: " &isFalse)

        Console.WriteLine("Integer examples:")
        console.WriteLine("age:"  &age)
        Console.WriteLine("qanantity", &quantity)

        Console.WriteLine(Long examples:)
        Console.writeLine("populations: " &population)
        console.WriteLine("distance" &distance)
        
        Console.WriteLine ("Single examples:")
        Console.WriteLine("pi: ", &pi)
        console.writeline("temperature: "&temperature)

        console.writeline("Double example")
        Console.WriteLline("price" &price)
        Console.WriteLine("weight:" & weight)
       
        Console.WriteLine ("Decimal examples:")   
        Console.WriteLine("salary: " &salary)    
        Console.WriteLine("totalamount: " &totalAmount)
    End Sub
End Module