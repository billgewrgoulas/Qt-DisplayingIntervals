#ifndef DUMMYINTERVAL_H
#define DUMMYINTERVAL_H

#include <string>

class dummyInterval
{
public:
    dummyInterval();
    dummyInterval(int left, int right);

    int right() {return m_rightVal;}
    int left() {return m_leftVal;}

    std::string nameLabel() const;
    void setNameLabel(const std::string &nameLabel);

private:
    void init();

    int m_rightVal;
    int m_leftVal;
    std::string m_nameLabel;
};

#endif // DUMMYINTERVAL_H
