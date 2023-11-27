#ifndef BOX_H
#define BOX_H
#include <string>
#include <vector>
#include <memory>

class NonPimplBox
{
public:
    const std::string& getLabel() const;

private:
    int m_index;
    std::string m_label;
    int m_counter;
    std::vector<std::string> m_contents;
};


class Box
{
public:
    Box();
    Box(const Box&);
    Box& operator=(const Box&);
    ~Box();
    const std::string& getLabel() const;

private:
    struct BoxPrivate;
    BoxPrivate *pimpl;
};

class UniqueBox
{
public:
    UniqueBox();
    ~UniqueBox();
    const std::string& getLabel() const;

private:
    struct UniqueBoxPrivate;
    std::unique_ptr<UniqueBoxPrivate> pimpl;
};


#endif // BOX_H
