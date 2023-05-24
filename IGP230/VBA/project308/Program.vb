Imports System.IO

' Define the Department class
Class Department
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

' Define the Course class
Class Course
    Public Property ID As Integer
    Public Property Title As String
    Public Property CreditHours As Integer

    Public Sub New(id As Integer, title As String, creditHours As Integer)
        Me.ID = id
        Me.Title = title
        Me.CreditHours = creditHours
    End Sub
End Class

' Define the Student class
Class Student
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

' Define the Enrollment class
Class Enrollment
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

' Define the DepartmentA class
Class DepartmentA
    Inherits Department

    Public Sub New()
        MyBase.New("Department A")
        AddCourse(New Course(1, "Course A1", 3))
        AddCourse(New Course(2, "Course A2", 4))
        AddCourse(New Course(3, "Course A3", 4))
    End Sub
End Class

' Define the DepartmentB class
Class DepartmentB
    Inherits Department

    Public Sub New()
        MyBase.New("Department B")
        AddCourse(New Course(1, "Course B1", 3))
        AddCourse(New Course(2, "Course B2", 4))
        AddCourse(New Course(3, "Course B3", 4))
    End Sub
End Class

' Define the DepartmentC class
Class DepartmentC
    Inherits Department

    Public Sub New()
        MyBase.New("Department C")
        AddCourse(New Course(1, "Course C1", 3))
        AddCourse(New Course(2, "Course C2", 4))
        AddCourse(New Course(3, "Course C3", 4))
    End Sub
End Class

' Define the StudentManagementSystem class
Class StudentManagementSystem
    Public Departments As List(Of Department)
    Public Students As List(Of Student)
    Public Enrollments As List(Of Enrollment)

    Public Sub New()
        Departments = New List(Of Department)()
        Departments.Add(New DepartmentA())
        Departments.Add(New DepartmentB())
        Departments.Add(New DepartmentC())

        Students = New List(Of Student)()
        Enrollments = New List(Of Enrollment)()
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
            Console.WriteLine($"Course with ID {course.ID} added to department {department.Name} successfully.")
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
                Console.WriteLine($"Course with ID {course.ID} updated successfully in department {department.Name}.")
            Else
                Console.WriteLine($"Course with ID {course.ID} not found in department {department.Name}.")
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
                Console.WriteLine($"Course with ID {courseID} deleted successfully from department {department.Name}.")
            Else
                Console.WriteLine($"Course with ID {courseID} not found in department {department.Name}.")
            End If
        Else
            Console.WriteLine($"Department {departmentName} not found.")
        End If
    End Sub

    Public Sub EnrollStudent(student As Student, major As String, courses As List(Of Course), enrollmentDate As DateTime, graduationExpectationDate As DateTime)
        Try
            Dim existingStudent As Student = Students.Find(Function(s) s.ID = student.ID)
            If existingStudent IsNot Nothing Then
                Dim existingEnrollment As Enrollment = Enrollments.Find(Function(e) e.Student.ID = student.ID)
                If existingEnrollment Is Nothing Then
                    Dim enrollment As New Enrollment(student, major, courses, enrollmentDate, graduationExpectationDate)
                    Dim enrollmentConflict As Boolean = False

                    For Each course As Course In courses
                        If IsCourseAvailable(course) Then
                            If IsStudentEligible(student, course) Then
                                If Not IsMaxEnrollmentReached(course) Then
                                    course.EnrolledStudents.Add(student)
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
                    Next

                    If Not enrollmentConflict Then
                        Enrollments.Add(enrollment)
                        Console.WriteLine($"Student {student.FirstName} {student.LastName} enrolled successfully.")
                    End If
                Else
                    Console.WriteLine($"Enrollment failed: Student {student.FirstName} {student.LastName} is already enrolled in a course.")
                End If
            Else
                Console.WriteLine($"Enrollment failed: Student with ID {student.ID} not found.")
            End If
        Catch ex As Exception
            Console.WriteLine($"An error occurred while enrolling the student: {ex.Message}")
        End Try
    End Sub

    Private Function IsCourseAvailable(course As Course) As Boolean
        Dim department As Department = Departments.Find(Function(d) d.Courses.Contains(course))
        Return department IsNot Nothing
    End Function

    Private Function IsStudentEligible(student As Student, course As Course) As Boolean
        Return student.Major = course.Title
    End Function

    Private Function IsMaxEnrollmentReached(course As Course) As Boolean
        Return course.EnrolledStudents.Count >= 10
    End Function

    Public Sub ExportDataToCSV(filePath As String)
        Try
            Using writer As New StreamWriter(filePath)
                ' Write student data to the file
                For Each student As Student In Students
                    writer.WriteLine($"{student.ID},{student.FirstName},{student.LastName},{student.Address},{student.Major},{student.DateOfBirth.ToString("yyyy-MM-dd")}")
                Next

                writer.WriteLine() ' Add an empty line as separator

                ' Write course data to the file
                For Each department As Department In Departments
                    For Each course As Course In department.Courses
                        writer.WriteLine($"{department.Name},{course.ID},{course.Title},{course.CreditHours}")
                    Next
                Next

                writer.WriteLine() ' Add an empty line as separator

                ' Write enrollment data to the file
                For Each enrollment As Enrollment In Enrollments
                    Dim courseIDs As String = String.Join(",", enrollment.Courses.Select(Function(c) c.ID))
                    writer.WriteLine($"{enrollment.Student.ID},{enrollment.Major},{courseIDs},{enrollment.EnrollmentDate.ToString("yyyy-MM-dd")},{enrollment.GraduationExpectationDate.ToString("yyyy-MM-dd")}")
                Next
            End Using

            Console.WriteLine("Data exported successfully.")
        Catch ex As Exception
            Console.WriteLine($"An error occurred while exporting data: {ex.Message}")
        End Try
    End Sub

    Public Sub ImportDataFromCSV(filePath As String)
        Try
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
                        Students.Add(New Student(studentID, firstName, lastName, address, major, dateOfBirth))
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

                        Dim department As Department = Departments.Find(Function(d) d.Name = departmentName)
                        If department IsNot Nothing Then
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
                        Dim courseIDs As String() = values(2).Split(","c)
                        Dim enrollmentDate As DateTime = DateTime.ParseExact(values(3), "yyyy-MM-dd", Nothing)
                        Dim graduationExpectationDate As DateTime = DateTime.ParseExact(values(4), "yyyy-MM-dd", Nothing)

                        Dim student As Student = Students.Find(Function(s) s.ID = studentID)
                        Dim courses As New List(Of Course)()
                        For Each courseID As String In courseIDs
                            Dim course As Course = Departments.SelectMany(Function(d) d.Courses).FirstOrDefault(Function(c) c.ID = Integer.Parse(courseID))
                            If course IsNot Nothing Then
                                courses.Add(course)
                                course.EnrolledStudents.Add(student)
                            End If
                        Next

                        Enrollments.Add(New Enrollment(student, major, courses, enrollmentDate, graduationExpectationDate))
                    End If
                    line = reader.ReadLine()
                End While
            End Using

            Console.WriteLine("Data imported successfully.")
        Catch ex As Exception
            Console.WriteLine($"An error occurred while importing data: {ex.Message}")
        End Try
    End Sub
End Class

Module Program
    Sub Main()
        Dim system As New StudentManagementSystem()

        ' Example usage:
        Dim student As New Student(1, "John", "Doe", "123 Main St", "Course A1", New DateTime(2000, 1, 1))
        system.AddStudent(student)

        Dim course As New Course(4, "New Course", 3)
        system.AddCourse(course, "Department A")

        Dim enrollmentDate As DateTime = DateTime.Now
        Dim graduationExpectationDate As DateTime = DateTime.Now.AddYears(4)
        system.EnrollStudent(student, "Course A1", New List(Of Course) From {course}, enrollmentDate, graduationExpectationDate)

        ' Export data to CSV file
        system.ExportDataToCSV("data.csv")

        ' Import data from CSV file
        system.ImportDataFromCSV("data.csv")

        Console.ReadLine()
    End Sub
End Module
