//
//  main.cpp
//  CPP264
//
//  Created by Chang on 2023-05-10.
//

#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    string name;
    int age;
    
    Person(string n, int a): name(n), age(a){}
};

int main(int argc, char * argv[]) {
    Person person("John", 30);
    
    cout << "Name: " << person.name << endl;
    cout << "Age: " << person.age << endl;

    person.name = "Alice";
    person.age = 20;
    
    cout << "Name: " << person.name << endl;
    cout << "Age: " << person.age << endl;

    
        
    return 0;
}
