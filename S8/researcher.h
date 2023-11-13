#pragma once
#include <string>
#include "employee.h"
#include "printable.h"

struct Researcher : public virtual Employee, public Printable
{
public:
    Researcher(std::string name, std::string institute, int nr, std::string researcharea);
    ~Researcher();
    const std::string &researcharea() const;
    std::string classname() const;

    void print() const override {

    }

protected:
    std::string m_researcharea;
};
