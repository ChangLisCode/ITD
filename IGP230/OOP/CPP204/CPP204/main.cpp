//
//  main.cpp
//  CPP204
//
//  Created by Chang on 2023-05-09.
//


#include <iostream>
#include <string>
using namespace std;

class Student{
public:
    string name;

private:
    int idStudent;
    
protected:
    string major;
    
public:
    
    void GetLecturerName(string& lecturerName);

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

void Student::GetLecturerName(string& lecturerName){
    cout << "Enter lecturer 's name";
    getline(cin, lecturerName);
}

class GraduateStudent: public Student
{
    public:
    string researchTopic;
    void setDetails(){
        Student::setDetails();
        cout << "Enter research topic:";
        getline(cin, researchTopic);
    }
};

int main() {
    
    GraduateStudent gradStudent;
    
    gradStudent.setDetails();
    
    string lecturerName;
    gradStudent.GetLecturerName(lecturerName);
    
    return 0;
}
