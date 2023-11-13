#pragma once
#include <string>

class AbstractEmployee
{
public:
    virtual std::string name() const = 0;
};
