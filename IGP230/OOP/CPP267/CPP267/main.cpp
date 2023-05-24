//
//  main.cpp
//  CPP267
//
//  Created by Chang on 2023-05-10.
//
#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string brand;
    string model;
    
public:
    
    Car (const string& carBrand, const string& carModel)
    :brand(carBrand), model(carModel)
    {
        cout << "Car object created:" << brand << "" << model << endl;
    }
    
    ~Car()
    {
        cout << "Car object destroyed:" << brand << "" << model << endl;
    }
    void Drive()
    {
        cout << "Driving the car: " << brand << "" << model << endl;
    }
    void Stop()
    {
        cout << "Stopping the car: " << brand << "" << model << endl;
    }

};

int main(int argc, const char * argv[]) {
    Car car1("Toyota", "Camry");
    Car car2("Honda", "Civic");

    car1.Drive();
    car2.Drive();
    
    car1.Stop();
    car2.Stop();
        
    return 0;
}
