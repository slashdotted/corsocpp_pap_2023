#include "lecturerresearcher.h"
#include <iostream>


int main() {
    LecturerResearcher lr{"Guglielmo", "ISIN", 1291, "CS", "OS", "Networks", 0.5};

    std::cout << "&lr= " << &lr << std::endl;
    Lecturer& lrl{lr};
    std::cout << "&lrl=" << &lrl << std::endl;
    Researcher& lrr{lr};
    std::cout << "&lrr=" << &lrr << std::endl;
    Employee& lre{lr};
    std::cout << "&lre=" << &lre << std::endl;

    std::cout << "&lr= " << &lr << std::endl;
    Lecturer* plrl{&lr};
    std::cout << "plrl=" << plrl << std::endl;
    Researcher* plrr{&lr};
    std::cout << "plrr=" << plrr << std::endl;
    Employee* plre{&lr};
    std::cout << "plre=" << plre << std::endl;

    std::cout << "Percentuale ricerca " << lr.researchpercentage() << '\n'
        << "Corso: " << lr.course() << '\n'
              << "Area di ricerca: " << lr.researcharea() << '\n';

    std::cout << "Nome:" << lr.name() << '\n';
}
