#include <iostream>
#include <string>


void test(std::string &str);

int main() {
    std::string str = "hello,Alice";
    std::cout << "str = " << str << std::endl;
    test(str);
    std::cout << "str = " << str << std::endl;
    return 0;
}

void test(std::string &str) {
    std::cout << "str = " << str << std::endl;
    str = str + "aa";
    std::cout << "str = " << str << std::endl;
}
