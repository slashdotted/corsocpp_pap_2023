#include "employee.h"
#include "researcher.h"
#include "lecturer.h"
#include <iostream>

void foo(const Employee& e) {
}

void foo(Employee* e) {
}

void bar(Employee e) {
}

int main() {    
    Researcher aldo{"Aldo", "ISIN", 123, "Programming Languages"};
    Lecturer giovanni{"Giovanni", "ISEA", 456, "Electronics", "Signal Processing"};
    Employee giacomo{"Giacomo", "DTI", 789};

    foo(aldo);
    foo(giovanni);
    foo(giacomo);

    foo(&aldo);
    foo(&giovanni);
    foo(&giacomo);

    giacomo = giovanni; // Attenzione: slicing!
    // aldo = giacomo; // Errore
    bar(aldo); // Attenzione: slicing!
    bar(giovanni); // Attenzione: slicing!
    bar(giacomo);

    Employee& a{aldo};
    Employee& g{giovanni};

    std::cout << "Aldo: " << &aldo << ","  << aldo.name() << "," << aldo.institute()
        << "," << aldo.employeenr() << "," << aldo.researcharea()
              << "," << aldo.classname() << std::endl;

    std::cout << "Aldo (attraverso Employee&): " << &a << ","  << a.name() << "," << a.institute()
              << "," << a.employeenr() << "," << a.classname() << std::endl;

    std::cout << "Giovanni: " << &giovanni << "," << giovanni.name() << "," << giovanni.institute()
              << "," << giovanni.employeenr() << "," << giovanni.course()
              << ","  << giovanni.studies()
              << "," << giovanni.classname() << std::endl;

    std::cout << "Giovanni (attraverso Employee&): " << &g << ","  << g.name() << "," << g.institute()
              << "," << g.employeenr() << "," << g.classname() << std::endl;

    Employee* aptr{&aldo};
    Employee* gptr{&giovanni};

    std::cout << "Aldo (attraverso Employee*): " << aptr << ","  << aptr->name()
              << "," << aptr->institute()
              << "," << aptr->employeenr() << "," << aptr->classname() << std::endl;

    std::cout << "Giovanni (attraverso Employee*): " << gptr << ","  << gptr->name()
              << "," << gptr->institute()
              << "," << gptr->employeenr() << "," << gptr->classname() << std::endl;


}
