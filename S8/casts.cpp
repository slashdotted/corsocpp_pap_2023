#include "employee.h"
#include "researcher.h"
#include "lecturer.h"
#include "lecturerresearcher.h"
#include <iostream>

int main() {
    {
    // Static Cast
    Employee giacomo{"Giacomo", "DTI", 789};
    Researcher aldo{"Aldo", "ISIN", 123, "Programming Languages"};
    Lecturer giovanni{"Giovanni", "ISEA", 456, "Electronics", "Signal Processing"};
    LecturerResearcher ada{"Ada", "ISIN", 525, "Informatics", "Operating Environments", "Databases", 0.7};
    // upcast
    Lecturer ada_lecturer = static_cast<Lecturer>(ada); // cast di un valore
    Lecturer ada_lecturer2 = ada; // cast di un valore
    // upcast
    Lecturer& ref_ada_lecturer = static_cast<Lecturer&>(ada); // cast di riferimento
    Lecturer* ptr_ada_lecturer = &ada; // cast di un puntatore
    // downcast
    LecturerResearcher& ref_ada = static_cast<LecturerResearcher&>(ref_ada_lecturer);
    LecturerResearcher* ptr_ada = static_cast<LecturerResearcher*>(ptr_ada_lecturer);
    // cast tra rami (che static_cast mi impedisce di fare)
    // Researcher& ref_ada_researcher = static_cast<Researcher&>(ref_ada_lecturer);
    // Researcher* ptr_ada_researcher = static_cast<Researcher*>(ptr_ada_lecturer);
    // cast non validi (che static_cast mi PERMETTE di fare)
    LecturerResearcher& ref_lr_giovanni = static_cast<LecturerResearcher&>(giovanni);
    LecturerResearcher* prt_lr_giovanni = static_cast<LecturerResearcher*>(&giovanni);
    std::cout << "Percentuale: " << ref_lr_giovanni.researchpercentage() << '\n';
    // Upcast da researcher a employee
    Employee* aldo_empl = static_cast<Employee*>(&aldo);
    // Il downcast attraverso una derivazione virtual non è possibile
    // Researcher* aldo_research = static_cast<Researcher*>(aldo_empl);
    }
    {
    // Dynamic Cast
    Employee giacomo{"Giacomo", "DTI", 789};
    Researcher aldo{"Aldo", "ISIN", 123, "Programming Languages"};
    Lecturer giovanni{"Giovanni", "ISEA", 456, "Electronics", "Signal Processing"};
    LecturerResearcher ada{"Ada", "ISIN", 525, "Informatics", "Operating Environments", "Databases", 0.7};
    // upcast
    // Lecturer ada_lecturer = dynamic_cast<Lecturer>(ada); // cast di un valore non permesso
    Lecturer ada_lecturer2 = ada; // cast di un valore
    // upcast
    Lecturer& ref_ada_lecturer = dynamic_cast<Lecturer&>(ada); // cast di riferimento
    Lecturer* ptr_ada_lecturer = &ada; // cast di un puntatore
    // downcast
    LecturerResearcher& ref_ada = dynamic_cast<LecturerResearcher&>(ref_ada_lecturer);
    LecturerResearcher* ptr_ada = dynamic_cast<LecturerResearcher*>(ptr_ada_lecturer);
    // cast tra rami (che static_cast mi impedisce di fare)
    Researcher& ref_ada_researcher = dynamic_cast<Researcher&>(ref_ada_lecturer);
    std::cout << "ref_ada_researcher.researcharea():"  << ref_ada_researcher.researcharea() << '\n';
    Researcher* ptr_ada_researcher = dynamic_cast<Researcher*>(ptr_ada_lecturer);
    std::cout << "ptr_ada_researcher->researcharea():"  << ptr_ada_researcher->researcharea() << '\n';
    // cast non validi
    try {
        LecturerResearcher& ref_lr_giovanni = dynamic_cast<LecturerResearcher&>(giovanni);
    } catch (...) {
        std::cout << "Cast non valido\n";
    }
    LecturerResearcher* prt_lr_giovanni = dynamic_cast<LecturerResearcher*>(&giovanni);
    std::cout << "prt_lr_giovanni=" << prt_lr_giovanni << '\n';

    // Upcast da researcher a employee
    Employee* aldo_empl = dynamic_cast<Employee*>(&aldo);
    // Il downcast attraverso una derivazione virtual è possibile
    Researcher* aldo_research = dynamic_cast<Researcher*>(aldo_empl);
    }
}
