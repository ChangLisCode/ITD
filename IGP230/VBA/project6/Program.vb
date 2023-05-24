moorts Systen
Imports System.Collections.Generic
Module DataStructureFyannle
    Sub Main o
        Dim employeeDictionary As New Dictionary (Of Integer, String) 
        employeeDictionary.Add(1, "Mike Yun") employeeDictionary.Add (2, "Mike Banville")
        Add an employee with ID 1 and name "Mike Yun" to the dictionary


        kev: Ilt as a unique identifier that is used to access or retrieve the associated value
        Value: It is the data or information associated with the key
        Console.WriteLine("Dictionary Example:")

        For tach kVD AS KeWValuePairot Integer. Strind In emoloveeDrotionary
        "Iterate througn each key-value parr
        Console. Writeline. ID:
        sakvo.Value}
        Print the ID and Na
        Next
        Console. ReadLine ()

        Dim myDictionary As New Dictionary(Of Integer, String) ()
        "Adding items to the dictionary myDictionary.Add(1, "Iten 1")
        myDictionarv. Add 2.

        
        Dim item As Strinas mDictionarvian
        Console Writel ine"Tten with key 1: " & item
        Removing an item from the dictionan myDictionary. Remove (2)
        Checking if a key exists in the dictionary

        Dim containsKey As Boolean erDictionary.ContainsKey?
        Console.WriteLine("Contains key 2:


        Dim itemcount As intener s mvdictionarv.ount
        Console Writel ine"Ttes count.
       
       
       
        Dim kvp1 As New KeyValuePair(Of Integer. String) (1, "Value 1")
        Create a KeyValuePair with a String key and a Double value
        Dim kyo? As New KeyValuePairlof String. Double ("Key 2". 3.14)
        Create a KeyValuePair with a Boolean key and a Char value

        Dim kvp3 As New KeyValuePair(Of Boolean, (har) (True, "C"c)

        "Access and display the values of kup1
        Console.WriteLine("Key 1: " & kvp1.Key & ", Value 1: " & kvp1. Value)
        Outout: Kev 1: 1. Value 1: Value 1
        Access and display the values of kyp2
        Console.WriteLine("Key 2: " & kvp2. Key & ", Value 2: " & kvp2. Value)
        Outout: Key >• Key 2. Value 29 3 14

        Console Writeline("Key 3: " & kyoB. Key & " Valve 3: " & kyo? Value)
        Outout: Kev 3: True. Value 3:


        Dim kvpList As New List (Of KeyValuePair (Of Integer, String)) 0)
        KVOLISt.AdO KVDI)
        kvoList Add (New KeyValuePair(of Integer. String) (2. "Value 2"77 kvpList.Add (New KeyValuePair(Of Integer. String) (3. "Value 3")

        Console .WriteLine("List of KeyValuePairs:")
        For Each kvp As KeyValuePair(Of Integer, String) In kypList
        Console Writeline"Key:
  
        
        Dim kynDictionary As New Dictionary Of integer. String o kunDictionary Add kyn1 Key. kyn1 Value kvpDictionary.Add(kvp2.Key. Lenath, "Another Value")
        Access and display values from the Dictionary
        Concole Writel inel"Values from the Dictionary")
        " & kroDictionary(kvol.Kevin
        Console Writeline[ Key 2 Lenothe
        " & kvoDictionary (kyo2 Key Lenath))

        Console.ReadLine()
    End Sub
End Module