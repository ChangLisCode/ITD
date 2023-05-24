//
//  main.cpp
//  CPP205
//
//  Created by Chang on 2023-05-10.
//

#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    const string name;
    const int age;
    
    Person(const string& personName, int personAge): name(personName), age(personAge){}
    
    void displayInfo()const{
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

int main(int argc, const char * argv[]) {
    Person person("John", 30);
    
    person.displayInfo();
        
    return 0;
}
