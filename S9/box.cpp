#include "box.h"

const std::string& NonPimplBox::getLabel() const {
    return m_label;
}

struct Box::BoxPrivate {
    int m_index;
    std::string m_label;
    int m_counter;
    std::vector<std::string> m_contents;
};

Box::Box() : pimpl{new BoxPrivate}
{
}

Box::Box(const Box &o) : pimpl{new BoxPrivate{*o.pimpl}}
{

}

Box &Box::operator=(const Box &o)
{
    *pimpl = *o.pimpl;
    return *this;
}

Box::~Box()
{
    delete pimpl;
}


const std::string &Box::getLabel() const
{
    return pimpl->m_label;
}


// Unique Box

struct UniqueBox::UniqueBoxPrivate {
    int m_index;
    std::string m_label;
    int m_counter;
    std::vector<std::string> m_contents;
};

UniqueBox::UniqueBox() : pimpl{std::make_unique<UniqueBoxPrivate>()}
{
}


UniqueBox::~UniqueBox()
{
}


const std::string &UniqueBox::getLabel() const
{
    return pimpl->m_label;
}
