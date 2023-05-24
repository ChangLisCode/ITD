//
//  main.cpp
//  CPP276
//
//  Created by Chang on 2023-05-11.
//

#include <iostream>
using  namespace std;

class Instrument{
public:
    virtual void play(){
        cout << "Play an instrument." << endl;
    }
};

class Piano : public Instrument{
public:
    void play() override {
        cout << "Play the piano." << endl;
    }
};

class Guitar : public Instrument{
public:
    void play() override {
        cout << " Play the guita." << endl;
    }
};

int main(int argc, const char * argv[]) {
    Instrument* instrument1 = new Piano();
    Instrument* instrument2 = new Guitar();
    
    instrument1->play();
    instrument2->play();
    
    delete instrument1;
    delete instrument2;
    
    return 0;
}
