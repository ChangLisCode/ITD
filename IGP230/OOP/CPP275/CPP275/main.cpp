//
//  main.cpp
//  CPP275
//
//  Created by Chang on 2023-05-11.
//

#include <iostream>
using namespace std;

class Book {
protected:
    string title;
    int pageCount;
    
public:
    Book(const string& t, int pc): title(t), pageCount(pc){}
    
    virtual void display(){
        cout << "Title: " << title << endl;
        cout << "Page Count:" << pageCount << endl;
    }
};

class FictionBook : public Book {
private:
    string genre;
    
public:
    FictionBook(const string& t, int pc, const string& g):Book(t, pc), genre(g){}
    void display(){
        cout << "Title: " << title << endl;
        cout << "Page Count: " << pageCount << endl;
        cout << "Genre: " << genre << endl;
    }
};

int main(int argc, const char * argv[]) {
    Book book("introduction", 300);
    book.display();
    
    cout << endl;
    
    FictionBook fictionBook("Happ new year", 200, "fantasy");
    fictionBook.display();
}
