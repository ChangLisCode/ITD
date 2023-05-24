Imports System.IO

Public Class Department
    Public Property Name As String
    Public Property Courses As List(Of Course)

    Public Sub New(name As String)
        Me.Name = name
        Me.Courses = New List(Of Course)()
    End Sub

    Public Sub AddCourse(course As Course)
        Courses.Add(course)
    End Sub
End Class

Public Class Student
    Public Property ID As Integer
    Public Property FirstName As String
    Public Property LastName As String
    Public Property Address As String
    Public Property Major As String
    Public Property DateOfBirth As DateTime

    Public Sub New(id As Integer, firstName As String, lastName As String, address As String, major As String, dateOfBirth As DateTime)
        Me.ID = id
        Me.FirstName = firstName
        Me.LastName = lastName
        Me.Address = address
        Me.Major = major
        Me.DateOfBirth = dateOfBirth
    End Sub
End Class

Public Class Course
    Public Property ID As Integer
    Public Property Title As String
    Public Property CreditHours As Integer
    Public Property EnrolledStudents As List(Of Student)

    Public Sub New(id As Integer, title As String, creditHours As Integer)
        Me.ID = id
        Me.Title = title
        Me.CreditHours = creditHours
        Me.EnrolledStudents = New List(Of Student)()
    End Sub
End Class

Public Class Enrollment
    Public Property Student As Student
    Public Property Major As String
    Public Property Courses As List(Of Course)
    Public Property EnrollmentDate As DateTime
    Public Property GraduationExpectationDate As DateTime

    Public Sub New(student As Student, major As String, courses As List(Of Course), enrollmentDate As DateTime, graduationExpectationDate As DateTime)
        Me.Student = student
        Me.Major = major
        Me.Courses = courses
        Me.EnrollmentDate = enrollmentDate
        Me.GraduationExpectationDate = graduationExpectationDate
    End Sub
End Class

Public Class StudentManagementSystem
    Public Property Departments As List(Of Department)
    Public Property Students As List(Of Student)
    Public Property Enrollments As List(Of Enrollment)

    Public Sub New()
        Me.Departments = New List(Of Department)()
        Me.Students = New List(Of Student)()
        Me.Enrollments = New List(Of Enrollment)()
    End Sub

    Public Sub AddStudent(student As Student)
        Students.Add(student)
        Console.WriteLine($"Student with ID {student.ID} added successfully.")
    End Sub

    Public Sub UpdateStudent(student As Student)
        Dim existingStudent As Student = Students.Find(Function(s) s.ID = student.ID)
        If existingStudent IsNot Nothing Then
            existingStudent.FirstName = student.FirstName
            existingStudent.LastName = student.LastName
            existingStudent.Address = student.Address
            existingStudent.Major = student.Major
            existingStudent.DateOfBirth = student.DateOfBirth
            Console.WriteLine($"Student with ID {student.ID} updated successfully.")
        Else
            Console.WriteLine($"Student with ID {student.ID} not found.")
        End If
    End Sub

    Public Sub DeleteStudent(studentID As Integer)
        Dim student As Student = Students.Find(Function(s) s.ID = studentID)
        If student IsNot Nothing Then
            Students.Remove(student)
            Console.WriteLine($"Student with ID {studentID} deleted successfully.")
        Else
            Console.WriteLine($"Student with ID {studentID} not found.")
        End If
    End Sub

    Public Sub AddCourse(course As Course, departmentName As String)
        Dim department As Department = Departments.Find(Function(d) d.Name = departmentName)
        If department IsNot Nothing Then
            department.AddCourse(course)
            Console.WriteLine($"Course with ID {course.ID} added successfully to department {departmentName}.")
        Else
            Console.WriteLine($"Department {departmentName} not found.")
        End If
    End Sub

    Public Sub UpdateCourse(course As Course, departmentName As String)
        Dim department As Department = Departments.Find(Function(d) d.Name = departmentName)
        If department IsNot Nothing Then
            Dim existingCourse As Course = department.Courses.Find(Function(c) c.ID = course.ID)
            If existingCourse IsNot Nothing Then
                existingCourse.Title = course.Title
                existingCourse.CreditHours = course.CreditHours
                Console.WriteLine($"Course with ID {course.ID} updated successfully.")
            Else
                Console.WriteLine($"Course with ID {course.ID} not found in department {departmentName}.")
            End If
        Else
            Console.WriteLine($"Department {departmentName} not found.")
        End If
    End Sub

    Public Sub DeleteCourse(courseID As Integer, departmentName As String)
        Dim department As Department = Departments.Find(Function(d) d.Name = departmentName)
        If department IsNot Nothing Then
            Dim course As Course = department.Courses.Find(Function(c) c.ID = courseID)
            If course IsNot Nothing Then
                department.Courses.Remove(course)
                Console.WriteLine($"Course with ID {courseID} deleted successfully from department {departmentName}.")
            Else
                Console.WriteLine($"Course with ID {courseID} not found in department {departmentName}.")
            End If
        Else
            Console.WriteLine($"Department {departmentName} not found.")
        End If
    End Sub

    Public Sub EnrollStudent(studentID As Integer, major As String, courseIDs As List(Of Integer), enrollmentDate As DateTime, graduationExpectationDate As DateTime)
        Try
            Dim student As Student = Students.Find(Function(s) s.ID = studentID)
            If student IsNot Nothing Then
                Dim courses As New List(Of Course)()
                Dim enrollmentConflict As Boolean = False

                For Each courseID As Integer In courseIDs
                    Dim course As Course = Departments.SelectMany(Function(d) d.Courses).FirstOrDefault(Function(c) c.ID = courseID)
                    If course IsNot Nothing Then
                        If IsCourseAvailable(course) Then
                            If IsStudentEligible(student, course) Then
                                If Not IsMaxEnrollmentReached(course) Then
                                    If Not course.EnrolledStudents.Contains(student) Then
                                        courses.Add(course)
                                        course.EnrolledStudents.Add(student)
                                    Else
                                        enrollmentConflict = True
                                        Console.WriteLine($"Enrollment failed: Student {student.FirstName} {student.LastName} is already enrolled in course {course.Title}.")
                                        Exit For
                                    End If
                                Else
                                    enrollmentConflict = True
                                    Console.WriteLine($"Enrollment failed: Maximum enrollment limit reached for course {course.Title}.")
                                    Exit For
                                End If
                            Else
                                enrollmentConflict = True
                                Console.WriteLine($"Enrollment failed: Student {student.FirstName} {student.LastName} is not eligible for course {course.Title}.")
                                Exit For
                            End If
                        Else
                            enrollmentConflict = True
                            Console.WriteLine($"Enrollment failed: Course {course.Title} is not available.")
                            Exit For
                        End If
                    Else
                        enrollmentConflict = True
                        Console.WriteLine($"Enrollment failed: Course with ID {courseID} not found.")
                        Exit For
                    End If
                Next

                If Not enrollmentConflict Then
                    Dim enrollment As New Enrollment(student, major, courses, enrollmentDate, graduationExpectationDate)
                    Enrollments.Add(enrollment)
                    Console.WriteLine($"Student {student.FirstName} {student.LastName} enrolled successfully in {courses.Count} courses.")
                End If
            Else
                Console.WriteLine($"Student with ID {studentID} not found.")
            End If
        Catch ex As Exception
            Console.WriteLine($"An error occurred while enrolling student: {ex.Message}")
        End Try
    End Sub

    Public Function IsCourseAvailable(course As Course) As Boolean
        ' Implement your logic to check course availability
        Return True
    End Function

    Public Function IsStudentEligible(student As Student, course As Course) As Boolean
        ' Implement your logic to check student eligibility for the course
        Return True
    End Function

    Public Function IsMaxEnrollmentReached(course As Course) As Boolean
        ' Implement your logic to check if the course has reached its maximum enrollment limit
        Return False
    End Function

    Public Sub ExportDataToCSV(filePath As String)
        Try
            Using writer As New StreamWriter(filePath)
                ' Write student data to the file
                For Each student As Student In Students
                    writer.WriteLine($"{student.ID},{student.FirstName},{student.LastName},{student.Address},{student.Major},{student.DateOfBirth.ToString("yyyy-MM-dd")}")
                Next

                writer.WriteLine() ' Add empty line as separator

                ' Write course data to the file
                For Each department As Department In Departments
                    For Each course As Course In department.Courses
                        writer.WriteLine($"{department.Name},{course.ID},{course.Title},{course.CreditHours}")
                    Next
                Next

                writer.WriteLine() ' Add empty line as separator

                ' Write enrollment data to the file
                For Each enrollment As Enrollment In Enrollments
                    Dim courseIDs As String = String.Join(",", enrollment.Courses.Select(Function(c) c.ID))
                    writer.WriteLine($"{enrollment.Student.ID},{enrollment.Major},{courseIDs},{enrollment.EnrollmentDate.ToString("yyyy-MM-dd")},{enrollment.GraduationExpectationDate.ToString("yyyy-MM-dd")}")
                Next
            End Using

            Console.WriteLine("Data exported successfully to CSV.")
        Catch ex As Exception
            Console.WriteLine($"An error occurred while exporting data: {ex.Message}")
        End Try
    End Sub

    Public Sub ImportDataFromCSV(filePath As String)
        Try
            Departments.Clear()
            Students.Clear()
            Enrollments.Clear()

            Using reader As New StreamReader(filePath)
                ' Read student data from the file
                Dim line As String = reader.ReadLine()
                While Not String.IsNullOrEmpty(line)
                    Dim values As String() = line.Split(","c)
                    If values.Length = 6 Then
                        Dim studentID As Integer = Integer.Parse(values(0))
                        Dim firstName As String = values(1)
                        Dim lastName As String = values(2)
                        Dim address As String = values(3)
                        Dim major As String = values(4)
                        Dim dateOfBirth As DateTime = DateTime.ParseExact(values(5), "yyyy-MM-dd", Nothing)

                        If Students.All(Function(s) s.ID <> studentID) Then
                            Students.Add(New Student(studentID, firstName, lastName, address, major, dateOfBirth))
                        End If
                    End If
                    line = reader.ReadLine()
                End While

                line = reader.ReadLine() ' Skip the empty line separator

                ' Read course data from the file
                line = reader.ReadLine()
                While Not String.IsNullOrEmpty(line)
                    Dim values As String() = line.Split(","c)
                    If values.Length = 4 Then
                        Dim departmentName As String = values(0)
                        Dim courseID As Integer = Integer.Parse(values(1))
                        Dim title As String = values(2)
                        Dim creditHours As Integer = Integer.Parse(values(3))

                        Dim department As Department = Departments.FirstOrDefault(Function(d) d.Name = departmentName)
                        If department Is Nothing Then
                            department = New Department(departmentName)
                            Departments.Add(department)
                        End If

                        Dim course As Course = department.Courses.FirstOrDefault(Function(c) c.ID = courseID)
                        If course Is Nothing Then
                            department.AddCourse(New Course(courseID, title, creditHours))
                        End If
                    End If
                    line = reader.ReadLine()
                End While

                line = reader.ReadLine() ' Skip the empty line separator

                ' Read enrollment data from the file
                line = reader.ReadLine()
                While Not String.IsNullOrEmpty(line)
                    Dim values As String() = line.Split(","c)
                    If values.Length = 5 Then
                        Dim studentID As Integer = Integer.Parse(values(0))
                        Dim major As String = values(1)
                        Dim courseIDs As Integer() = values(2).Split(","c).Select(Function(id) Integer.Parse(id)).ToArray()
                        Dim enrollmentDate As DateTime = DateTime.ParseExact(values(3), "yyyy-MM-dd", Nothing)
                        Dim graduationExpectationDate As DateTime = DateTime.ParseExact(values(4), "yyyy-MM-dd", Nothing)

                        Dim student As Student = Students.FirstOrDefault(Function(s) s.ID = studentID)
                        If student IsNot Nothing Then
                            Dim courses As New List(Of Course)()
                            Dim enrollmentConflict As Boolean = False

                            For Each courseID As Integer In courseIDs
                                Dim department As Department = Departments.FirstOrDefault(Function(d) d.Courses.Any(Function(c) c.ID = courseID))
                                If department IsNot Nothing Then
                                    Dim course As Course = department.Courses.FirstOrDefault(Function(c) c.ID = courseID)
                                    If course IsNot Nothing Then
                                        If IsCourseAvailable(course) AndAlso IsStudentEligible(student, course) AndAlso Not IsMaxEnrollmentReached(course) Then
                                            courses.Add(course)
                                            course.EnrolledStudents.Add(student)
                                        Else
                                            enrollmentConflict = True
                                            Console.WriteLine($"Enrollment failed: Invalid enrollment data found for student with ID {studentID}.")
                                            Exit For
                                        End If
                                    Else
                                        enrollmentConflict = True
                                        Console.WriteLine($"Enrollment failed: Course with ID {courseID} not found.")
                                        Exit For
                                    End If
                                Else
                                    enrollmentConflict = True
                                    Console.WriteLine($"Enrollment failed: Department not found for course with ID {courseID}.")
                                    Exit For
                                End If
                            Next

                            If Not enrollmentConflict Then
                                Dim enrollment As New Enrollment(student, major, courses, enrollmentDate, graduationExpectationDate)
                                Enrollments.Add(enrollment)
                            End If
                        Else
                            Console.WriteLine($"Enrollment failed: Student with ID {studentID} not found.")
                        End If
                    End If
                    line = reader.ReadLine()
                End While
            End Using

            Console.WriteLine("Data imported successfully from CSV.")
        Catch ex As Exception
            Console.WriteLine($"An error occurred while importing data: {ex.Message}")
        End Try
    End Sub
End Class

Module Program
    Sub Main()
        Dim system As New StudentManagementSystem()

        ' Add sample departments
        system.Departments.Add(New Department("Department SDE"))
        system.Departments.Add(New Department("Department QA"))
        system.Departments.Add(New Department("Department iCloud"))

        ' Add sample courses to departments
        system.AddCourse(New Course(1, "Course 1", 3), "Department SDE")
        system.AddCourse(New Course(2, "Course 2", 4), "Department SDE")
        system.AddCourse(New Course(3, "Course 3", 3), "Department QA")
        system.AddCourse(New Course(4, "Course 4", 4), "Department iCloud")

        ' Add sample students
        system.AddStudent(New Student(1, "John", "Doe", "Address 1", "Major 1", New DateTime(2000, 1, 1)))
        system.AddStudent(New Student(2, "Jane", "Smith", "Address 2", "Major 2", New DateTime(2000, 2, 2)))
        system.AddStudent(New Student(3, "Bob", "Johnson", "Address 3", "Major 3", New DateTime(2000, 3, 3)))

        ' Enroll sample students in courses
        system.EnrollStudent(1, "Major 1", New List(Of Integer)() From {1, 2}, New DateTime(2023, 1, 1), New DateTime(2027, 1, 1))
        system.EnrollStudent(2, "Major 2", New List(Of Integer)() From {3}, New DateTime(2023, 2, 2), New DateTime(2027, 2, 2))
        system.EnrollStudent(3, "Major 3", New List(Of Integer)() From {4}, New DateTime(2023, 3, 3), New DateTime(2027, 3, 3))

        ' Export data to CSV
        system.ExportDataToCSV("/Users/Chang/Desktop/output/doc2.csv")

        ' Clear existing data
        system.Departments.Clear()
        system.Students.Clear()
        system.Enrollments.Clear()

        ' Import data from CSV
        system.ImportDataFromCSV("/Users/Chang/Desktop/input/doc1.csv")

        Console.ReadLine()
    End Sub
End Module
