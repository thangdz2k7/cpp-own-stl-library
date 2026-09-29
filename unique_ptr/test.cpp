#include <iostream>
#include <utility>
#include "unique_ptr.hpp"

class Person {
public:
    Person() {
        std::cout << "Person created\n";
    }

    ~Person() {
        std::cout << "Person destroyed\n";
    }

    void say_hello() const {
        std::cout << "Hello from person\n";
    }
};

int main() {
    unique_ptr<Person> first(new Person());

    std::cout << "first owns the object: "
              << (first.get() != nullptr) << '\n';

    unique_ptr<Person> second = std::move(first);

    std::cout << "first owns the object after move: "
              << (first.get() != nullptr) << '\n';

    std::cout << "second owns the object after move: "
              << (second.get() != nullptr) << '\n';

    unique_ptr<Person> person(new Person());

    if (person) {
        person->say_hello();
    }

    if (person) {
        (*person).say_hello();
    }

    return 0;
}