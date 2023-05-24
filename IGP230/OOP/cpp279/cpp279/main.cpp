//
//  main.cpp
//  cpp279
//
//  Created by Chang on 2023-05-12.
//

#include <iostream>
using namespace std;

class Honda{
private:
    string model;
    int year;
    double price;
    
public:
    Honda(const string& m, int y, double p): model(m), year(y), price(p){}
    
    string getModel(){
        return model;
    }
    
    int getYear(){
        return year;
    }
    
    void setYear(int y){
        year = y;
    }
    
    double getPrice(){
        return price;
    }
    
    void setPrice(double p){
        price = p;
    }
    
    void printDetails(){
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Price: " << price << endl;
    }
    
    void applyDiscount(double percentage){
        double discountAmount = price * percentage / 100.0;
        price -= discountAmount;
    }
};

int main() {
    Honda civic("Civic", 2022, 25000.0);
    Honda accord("Accord", 2021, 22000.0);
    Honda crv("crv", 2023, 32000.0);
    
    cout << "Initial Data: " << endl;
    cout << "" << endl;
    
    civic.printDetails();
    cout << "------" << endl;
    accord.printDetails();
    cout << "------" << endl;
    crv.printDetails();
    cout << endl;
    
    civic.setPrice(26000.0);
    accord.setPrice(29000.0);
    crv.setPrice(31000.0);
    
    cout << " ---------------------- " << endl;
    cout << " update data: " << endl;
    civic.printDetails();
    cout << " ---------------------- " << endl;
    crv.printDetails();
    
    return 0;
}
