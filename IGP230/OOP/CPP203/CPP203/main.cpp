//
//  main.cpp
//  CPP203
//
//  Created by Chang on 2023-05-08.
//

#include <iostream>
#include <string>
using namespace std;

class Student;

class Lecturer{
public:
    string name;
    int age;
    string department;

private:
    double salary;
    
protected:
    string researchArea;
    
public:
    
    void Teach(Student& student);
    void setDetails(){
        cout << "Enter lecturer 's name: ";
        getline(cin, name);
        
        cout <<"Enter lecturer 's salary: ";
        cin >> salary;
        cin.ignore();
        
        cout << "Enter lecturer 's department: ";
        getline(cin, researchArea);
    }
};

class Student{
public:
    string name;

private:
    int idStudent;
    
protected:
    string major;
    
public:
    
    void GetLecturerName(Lecturer& lecturer);

    void setDetails()
    {
        cout << "Enter lecturer 's name: ";
        getline(cin, name);
        
        cout <<"Enter lecturer 's salary: ";
        cin >> idStudent;
        cin.ignore();
        
        cout << "Enter student 's major: ";
        getline(cin, major);
    }
};

void Student::GetLecturerName(Lecturer& lecturer){
    cout << "Enter lecturer 's name";
    getline(cin, lecturer.name);
}

void Lecturer::Teach(Student& student){
    cout << "Lecturer" << name << " is teaching " << student.name << "." << endl;
}

int main() {
    
    Student student;
    Lecturer lecturer;
    
    student.setDetails();
    lecturer.setDetails();
    
    student.GetLecturerName(lecturer);
    lecturer.Teach(student);
    
    return 0;
}
