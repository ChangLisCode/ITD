Imports System.IO

Module Program_FileIOExample
    Sub Main()
        Dim inputFilePath As String = "/Users/Chang/Desktop/input.txt"
        Dim outputFilePath As String = "/Users/Chang/Desktop/output.txt"

        If File.Exists(outputFilePath) Then
            Console.WriteLine("The output file already exists.")
            Console.Write("Do you want to delete it before ending the program? (Y/N): ")
            Dim responseOutput As String = Console.ReadLine().Trim().ToUpper()

            If responseOutput = "Y" Then
                Using stream As New FileStream(outputFilePath, FileMode.Open, FileAccess.ReadWrite, FileShare.None)
                    stream.Close()
                End Using

                File.Delete(outputFilePath)
                Console.WriteLine("Output file deleted.")
            End If
        End If

        If File.Exists(inputFilePath) Then
            Console.WriteLine("The input file already exists.")
            Console.Write("Do you want to delete it before ending the program? (Y/N): ")
            Dim responseInput As String = Console.ReadLine().Trim().ToUpper()
            If responseInput = "Y" Then
                Using stream As New FileStream(inputFilePath, FileMode.Open, FileAccess.ReadWrite, FileShare.None)
                    stream.Close()
                End Using

                File.Delete(inputFilePath)
                Console.WriteLine("Input file deleted.")
            End If
        End If

        WriteToInputFile(inputFilePath)

        Dim lines As List(Of String) = ReadFile(inputFilePath)
        Dim processedLines As List(Of String) = ProcessData(lines)

        WriteToOutputFile(outputFilePath, processedLines)
        Console.WriteLine("File processing complete.")

        ' Ask the user
        Console.Write("Do you want to delete the output file before ending the program? (Y/N): ")
        Dim responseEndOutput As String = Console.ReadLine().Trim().ToUpper()

        If responseEndOutput = "Y" Then
            If File.Exists(outputFilePath) Then
                File.Delete(outputFilePath)
                Console.WriteLine("Output file deleted before ending the program.")
            End If
        End If

        Console.Write("Do you want to delete the input file before ending the program? (Y/N): ")
        Dim responseEndInput As String = Console.ReadLine().Trim().ToUpper()

        If responseEndInput = "Y" Then
            If File.Exists(inputFilePath) Then
                File.Delete(inputFilePath)
                Console.WriteLine("Input file deleted before ending the program.")
            End If
        End If
    End Sub

    Function ReadFile(filePath As String) As List(Of String)
        Dim lines As New List(Of String)()

        If File.Exists(filePath) Then
            lines.AddRange(File.ReadAllLines(filePath))
        Else
            Console.WriteLine("Input file not found.")
        End If

        Return lines
    End Function

    Function ProcessData(lines As List(Of String)) As List(Of String)
        Dim processedLines As New List(Of String)()

        For Each line As String In lines
            processedLines.Add(line.ToUpper())
        Next

        Return processedLines
    End Function

    Sub WriteToInputFile(filePath As String)
        Try
            Using writer As New StreamWriter(filePath)
                writer.WriteLine("Hello and good morning")
                writer.WriteLine("This is an example of writing in the files.")
                writer.WriteLine("If you can read me in the file it means I am working perfectly!")
            End Using

            Console.WriteLine("Input file created: " & filePath)

        Catch ex As Exception
            Console.WriteLine("Error writing to the input file: " & ex.Message)
        End Try
    End Sub

    Sub WriteToOutputFile(filePath As String, lines As List(Of String))
        Try
            Using writer As New StreamWriter(filePath)
                For Each line As String In lines
                    writer.WriteLine(line)
                Next
            End Using

            Console.WriteLine("Output file created: " & filePath)
        Catch ex As Exception
            Console.WriteLine("Error writing to the output file: " & ex.Message)
        End Try
    End Sub
End Module
