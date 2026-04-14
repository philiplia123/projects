#include <iostream> 
#include <string> 

using namespace std; 

class Person {
public: 
    string name; 
    int age; 
    double weight; 

    Person(string name, int age, double weight) {
        this->name = name; 
        this->age = age;
        this->weight = weight; 
    }

    void display() {
        cout << "Name: " << name << endl; 
        cout << "Age: " << age << endl; 
        cout << "Weight: " << weight << endl; 
    }

    void examMessage() {
        cout << "This is an exam" << endl; 
    }
}; 

int main() {
    Person p("Emmmmmmmmmmmma", 19, 200); 
    p.display();    
    p.examMessage(); 
    return 0; 
}