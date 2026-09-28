#include <iostream>
#include "unique_ptr.hpp"

class Person {

public:
    Person() {
        std::cout << "Person created\n";
    }

    ~Person() {
        std::cout << "Person destroyed\n";
    }

};

int main() {
    {
        unique_ptr<Person> person(new Person());

        std::cout << "Inside scope\n"; 
    }

    std::cout << "Outside scope\n";
    
    return 0;
}