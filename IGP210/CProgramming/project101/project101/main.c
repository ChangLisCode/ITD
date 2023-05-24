//
//  main.c
//  project101
//
//  Created by Chang on 2023-05-05.
//

#include <iostream>
using namespace std;

class MyClass{
public:
    int value;
    void printValue(){
        cout <<"The value is:" << value << std::endl;
    }
};

int main() {
    MyClass *myObject = new MyClass();
    
    myObject->value = 5;
    myObject->printValue();
    
    delete myObject;
    return 0;
}
