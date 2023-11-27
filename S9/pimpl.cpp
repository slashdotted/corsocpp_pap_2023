#include "box.h"
#include <iostream>

void foo(Box b) {

}

int main() {
    std::cout << "sizeof(std::string)=" << sizeof(std::string) << '\n';
    std::cout << "sizeof(std::vector<std::string>)=" << sizeof(std::vector<std::string>) << '\n';
    std::cout << "sizeof(NonPimplBox)=" << sizeof(NonPimplBox) << '\n';
    std::cout << "sizeof(Box)=" << sizeof(Box) << '\n';
    std::cout << "sizeof(UniqueBox)=" << sizeof(UniqueBox) << '\n';
}
