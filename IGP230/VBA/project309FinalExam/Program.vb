Imports System.IO

' Class to represent a property
Class [Property]
    Public PropertyID As Integer
    Public Address As String
    Public PropertyType As String
    Public Price As Double
    Public Status As String

    ' Constructor
    Public Sub New(id As Integer, addr As String, type As String, price As Double, status As String)
        PropertyID = id
        Address = addr
        PropertyType = type
        Price = price
        Status = status
    End Sub
End Class

' Class to manage the real estate properties
Class RealEstateManagementSystem
    Private Properties As List(Of [Property])

    ' Constructor
    Public Sub New()
        Properties = New List(Of [Property])()
    End Sub

    ' Add a new property
    Public Sub AddProperty(address As String, type As String, price As Double, status As String)
        Dim newProperty As New [Property](GenerateUniqueID(), address, type, price, status)
        Properties.Add(newProperty)
    End Sub

    ' Generate a unique identifier for each property
    Private Function GenerateUniqueID() As Integer
        ' Code to generate a unique ID
        Return Properties.Count + 1
    End Function

    ' Update existing property information
    Public Sub UpdateProperty(propertyID As Integer, address As String, type As String, price As Double, status As String)
        Dim propertyToUpdate As [Property] = Properties.Find(Function(prop) prop.PropertyID = propertyID)

        If propertyToUpdate IsNot Nothing Then
            propertyToUpdate.Address = address
            propertyToUpdate.PropertyType = type
            propertyToUpdate.Price = price
            propertyToUpdate.Status = status
            Console.WriteLine("Property updated successfully.")
        Else
            Console.WriteLine("Property not found.")
        End If
    End Sub

    ' Delete a property
    Public Sub DeleteProperty(propertyID As Integer)
        Dim propertyToDelete As [Property] = Properties.Find(Function(prop) prop.PropertyID = propertyID)

        If propertyToDelete IsNot Nothing Then
            Properties.Remove(propertyToDelete)
            Console.WriteLine("Property deleted successfully.")
        Else
            Console.WriteLine("Property not found.")
        End If
    End Sub

    ' Search properties based on criteria
    Public Function SearchProperties(propertyType As String, minPrice As Double, maxPrice As Double, status As String) As List(Of [Property])
        Dim searchResults As List(Of [Property]) = Properties.FindAll(Function(prop) prop.PropertyType = propertyType AndAlso
                                                                                  prop.Price >= minPrice AndAlso
                                                                                  prop.Price <= maxPrice AndAlso
                                                                                  prop.Status = status)
        Return searchResults
    End Function

    ' Calculate property statistics
    Public Function CalculateStatistics() As Statistics
        Dim statistics As New Statistics()

        statistics.TotalProperties = Properties.Count
        statistics.AveragePrice = Properties.Average(Function(prop) prop.Price)

        For Each propertyItem As [Property] In Properties
            If statistics.PropertyTypeDistribution.ContainsKey(propertyItem.PropertyType) Then
                statistics.PropertyTypeDistribution(propertyItem.PropertyType) += 1
            Else
                statistics.PropertyTypeDistribution(propertyItem.PropertyType) = 1
            End If
        Next

        Return statistics
    End Function

    ' Generate property reports
    Public Sub GenerateReports()
        Dim availableProperties As List(Of [Property]) = Properties.FindAll(Function(prop) prop.Status = "Available")
        Dim soldProperties As List(Of [Property]) = Properties.FindAll(Function(prop) prop.Status = "Sold")

        Console.WriteLine("Available Properties:")
        For Each propertyItem As [Property] In availableProperties
            Console.WriteLine("ID: " & propertyItem.PropertyID & ", Address: " & propertyItem.Address & ", Price: " & propertyItem.Price)
        Next

        Console.WriteLine("Sold Properties:")
        For Each propertyItem As [Property] In soldProperties
            Console.WriteLine("ID: " & propertyItem.PropertyID & ", Address: " & propertyItem.Address & ", Price: " & propertyItem.Price)
        Next
    End Sub

    ' Handle property booking
    Public Sub BookProperty(propertyID As Integer, bookingPeriod As Date)
        Dim propertyToBook As [Property] = Properties.Find(Function(prop) prop.PropertyID = propertyID)

        If propertyToBook IsNot Nothing Then
            If propertyToBook.Status = "Available" Then
                propertyToBook.Status = "Booked"
                Console.WriteLine("Property booked successfully.")
            Else
                Console.WriteLine("Property is not available for booking.")
            End If
        Else
            Console.WriteLine("Property not found.")
        End If
    End Sub



    ' Save property data to a file
    Public Sub SaveDataToFile(filename As String)
        Using writer As New StreamWriter(filename)
            For Each propertyItem As [Property] In Properties
                writer.WriteLine(propertyItem.PropertyID & "," & propertyItem.Address & "," &
                                 propertyItem.PropertyType & "," & propertyItem.Price & "," & propertyItem.Status)
            Next
        End Using

        Console.WriteLine("Data saved to file: " & filename)
    End Sub

    ' Load property data from a file
    Public Sub LoadDataFromFile(filename As String)
        Properties.Clear()

        Using reader As New StreamReader(filename)
            Dim line As String
            While (InlineAssignHelper(line, reader.ReadLine())) IsNot Nothing
                Dim propertyData As String() = line.Split(","c)
                If propertyData.Length = 5 Then
                    Dim propertyID As Integer = Integer.Parse(propertyData(0))
                    Dim address As String = propertyData(1)
                    Dim propertyType As String = propertyData(2)
                    Dim price As Double = Double.Parse(propertyData(3))
                    Dim status As String = propertyData(4)

                    Dim loadedProperty As New [Property](propertyID, address, propertyType, price, status)
                    Properties.Add(loadedProperty)
                End If
            End While
        End Using

        Console.WriteLine("Data loaded from file: " & filename)
    End Sub

    ' Helper function for inline assignment
    Private Function InlineAssignHelper(Of T)(ByRef target As T, ByVal value As T) As T
        target = value
        Return value
    End Function
End Class

' Class to hold property statistics
Class Statistics
    Public TotalProperties As Integer
    Public AveragePrice As Double
    Public PropertyTypeDistribution As Dictionary(Of String, Integer)

    ' Constructor
    Public Sub New()
        PropertyTypeDistribution = New Dictionary(Of String, Integer)()
    End Sub
End Class

' Handle user authentication
Public Class Authenticator
    Private ReadOnly _username As String
    Private ReadOnly _password As String

    Public Sub New(ByVal username As String, ByVal password As String)
        _username = username
        _password = password
    End Sub

    Public Function Authenticate(ByVal enteredUsername As String, ByVal enteredPassword As String) As Boolean
        If enteredUsername = _username AndAlso enteredPassword = _password Then
            Return True
        Else
            Return False
        End If
    End Function
End Class

' Main program
Module MainModule
    Sub Main()
        ' Create an instance of the real estate management system
        Dim realEstateSystem As New RealEstateManagementSystem()

        ' Use the system's methods to perform various operations
        realEstateSystem.AddProperty("123 Main St", "House", 200000, "Available")
        realEstateSystem.AddProperty("456 Elm St", "Apartment", 1500, "Rented")
        ' ...

        ' Save and load data to/from a file
        realEstateSystem.SaveDataToFile("/Users/Chang/Desktop/property_data.txt")
        realEstateSystem.LoadDataFromFile("/Users/Chang/Desktop/property_data.txt")

        Console.WriteLine("Welcome use Real Estate Management System!")
        Console.WriteLine("Please login in your account: ")

        Dim username As String
        Dim password As String

        Console.WriteLine("input your user name: ")
        username = Console.ReadLine()

        Console.WriteLine("input your user password: ")
        password = Console.ReadLine()

        Dim enteredUsername As String = Console.ReadLine()
        Dim enteredPassword As String = Console.ReadLine()

        Dim isAuthenticated As New Authenticator(username, password)

        If isAuthenticated Then
            Console.WriteLine("Authentication successful!")
        Else
            Console.WriteLine("Authentication failed!")
        End If

        ' Authenticate user
        If isAuthenticated Then
            ' Perform operations available to authenticated users
            realEstateSystem.UpdateProperty(1, "456 Oak St", "House", 250000, "Available")
            realEstateSystem.DeleteProperty(2)
            ' ...
        End If

        ' Generate property reports
        realEstateSystem.GenerateReports()

        ' Calculate and display property statistics
        Dim statistics As Statistics = realEstateSystem.CalculateStatistics()
        Console.WriteLine("Total properties: " & statistics.TotalProperties)
        Console.WriteLine("Average price: " & statistics.AveragePrice)
        Console.WriteLine("Property type distribution:")
        For Each kvp As KeyValuePair(Of String, Integer) In statistics.PropertyTypeDistribution
            Console.WriteLine(kvp.Key & ": " & kvp.Value)
        Next

        ' Perform property search
        Dim searchResults As List(Of [Property]) = realEstateSystem.SearchProperties("House", 100000, 300000, "Available")
        For Each propertyItem As [Property] In searchResults
            Console.WriteLine(propertyItem.Address & " - " & propertyItem.Price)
        Next

        ' Book a property
        realEstateSystem.BookProperty(1, DateTime.Now.AddDays(7))

    End Sub
End Module
