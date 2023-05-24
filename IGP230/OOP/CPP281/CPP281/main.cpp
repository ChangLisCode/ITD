//
//  main.cpp
//  CPP281
//
//  Created by Chang on 2023-05-12.
//

#include <iostream>
using namespace std;

class Food {
protected:
    string name;
    int calories;
public:
    Food(const string& n, int c) : name(n), calories(c) {}
    void display() {
        cout << "Name: " << name << endl;
        cout << "Calories: " << calories << endl;
    }
};

class Fruit : public Food {
protected:
    string color;
public:
    Fruit(const string& n, int c, const string& col) : Food(n, c), color(col) {}
    void ripen() {
        cout << "The fruit is ripening." << endl;
    }
};

class CitrusFruit : public Fruit {
private:
    string citrusType;
public:
    CitrusFruit(const string& n, int c, const string& col, const string& type) : Fruit(n, c, col), citrusType(type) {}
    void extractJuice() {
        cout << "Juice is being extracted from the citrus fruit." << endl;
    }
};

class Berry : public Fruit {
public:
    Berry(const string& n, int c, const string& col) : Fruit(n, c, col) {}
    void eatWithCream() {
        cout << "The berry is being eaten with cream." << endl;
    }
};

class Vegetable : public Food {
public:
    Vegetable(const string& n, int c) : Food(n, c) {}
    void cook() {
        cout << "The vegetable is being cooked." << endl;
    }
};

class LeafyVegetable : public Vegetable {
public:
    LeafyVegetable(const string& n, int c) : Vegetable(n, c) {}
    void tossSalad() {
        cout << "The leafy vegetable is being used to toss a salad." << endl;
    }
};

class RootVegetable : public Vegetable {
public:
    RootVegetable(const string& n, int c) : Vegetable(n, c) {}
    void roast() {
        cout << "The root vegetable is being roasted." << endl;
    }
};

int main() {
    Fruit orange("Orange", 62, "Orange");
    Fruit strawberry("Strawberry", 32, "Red");
    Vegetable spinach("Spinach", 23);
    RootVegetable potato("Potato", 77);

    orange.display();
    orange.ripen();
    CitrusFruit citrusFruit("Lemon", 29, "Yellow", "Lime");
    citrusFruit.display();
    citrusFruit.ripen();
    citrusFruit.extractJuice();

    cout << endl;

    strawberry.display();
    strawberry.ripen();
    Berry berry("Blueberry", 42, "Blue");
    berry.display();
    berry.ripen();
    berry.eatWithCream();

    cout << endl;

    spinach.display();
    spinach.cook();
    LeafyVegetable leafyVegetable("Lettuce", 15);
    leafyVegetable.display();
    leafyVegetable.cook();
    leafyVegetable.tossSalad();

    cout << endl;

    potato.display();
    potato.cook();
    potato.roast();
    potato.display();

    return 0;
}
