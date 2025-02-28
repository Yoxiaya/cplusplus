#include <iostream>
#include <string>
#include <vector>
struct A {

    int a;
    int b;
    A(int thisA, int thisB) : a(thisA), b(thisB) {}
};
class Person {
  private:
    int age;
    std::string name;

  public:
    Person(int thisAge, std::string thisName) : age(thisAge), name(thisName) {}
    std::string getName() const { return name; }
    void setName(std::string thisName) { name = thisName; }
};





void printPerson(std::vector<Person*> persons) {
    
    for (auto person : persons) {
        std::cout << person->getName() << std::endl;
    }
}


int main() {

    Person* yoi = new Person(18, "yoi");
    Person* yoi2 = new Person(20, "yoi2");

    std::vector<Person *> people = {yoi, yoi2};
    printPerson(people);
}