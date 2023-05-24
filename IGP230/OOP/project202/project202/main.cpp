//
//  main.cpp
//  project202
//
//  Created by Chang on 2023-05-05.
//

#include <iostream>
#include <cmath>
using  namespace std;

class Rectangle{
public:
    int width;
    int height;
    
    int getArea(){
        return width * height;
    }
    
    int getPerimeter(){
        return  2 * (width * height);
    }
    
    double getDiagonal(){
        return sqrt(pow(width, 2) + pow(height, 2));
    }
};

int main(){
    
    Rectangle rect;
    
    rect.width = 5;
    rect.height =10;
    
    int area = rect.getArea();
    int perimeter = rect.getPerimeter();
    double diagonal = rect.getDiagonal();
    
    cout<<"The area of the rectangle (first object) is: "<< area << endl;
    cout<<"The area of the rectangle (first object) is: "<< perimeter << endl;
    cout<<"The area of the rectangle (first object) is: "<< diagonal << endl;

    
    
    Rectangle rect1;
    rect1.width = 6;
    rect1.height = 11;
    int area1 = rect1.getArea();
    int perimeter1 = rect1.getPerimeter();
    double diagonal1 = rect1.getDiagonal();
    cout<<"The area of the rectangle (second object) is: " << area1 << endl;
    cout<<"The area of the rectangle (first object) is: "<< perimeter1 << endl;
    cout<<"The area of the rectangle (first object) is: "<< diagonal1 << endl;
    
    Rectangle rect2;
    rect1.width = 77;
    rect1.height = 123;
    int area2 = rect2.getArea();
    int perimeter2 = rect2.getPerimeter();
    double diagonal2 = rect2.getDiagonal();
    cout<<"The area of the rectangle (second object) is: " << area2 << endl;
    cout<<"The area of the rectangle (first object) is: "<< perimeter2 << endl;
    cout<<"The area of the rectangle (first object) is: "<< diagonal2 << endl;
    
}
