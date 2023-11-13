#pragma once
#include <string>
#include "abstractemployee.h"

class Employee : public AbstractEmployee
{
public:
    Employee(std::string name, std::string institute, int nr);
    Employee() = default;
    ~Employee();
    std::string name() const override;
    std::string institute() const;
    int employeenr() const;
    virtual std::string classname() const;

protected:
    std::string m_name;
    std::string m_institute;
    int m_employeenr;
};
