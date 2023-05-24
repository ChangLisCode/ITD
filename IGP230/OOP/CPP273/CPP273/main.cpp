//
//  main.cpp
//  CPP273
//
//  Created by Chang on 2023-05-11.
//

#include <iostream>

using namespace std;

class Animal{
public:
    void Eat(){
        cout << " The animal is eating." << endl;
    }
};

class Mammal : public Animal{
public:
    void GiveBirth(){
        cout << "The mammal is giving birth." << endl;
    }
};

class Dog: public Mammal{
public:
    void Bark(){
        cout << "The dog is barking. " << endl;
    }
};

int main(){
    Dog dog;
    dog.Eat();
    dog.GiveBirth();
    dog.Bark();
    return 0;
}
