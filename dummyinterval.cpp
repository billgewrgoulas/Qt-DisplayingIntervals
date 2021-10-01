#include "dummyinterval.h"

dummyInterval::dummyInterval()
{

}

dummyInterval::dummyInterval(int left, int right)
{
    init();

    m_leftVal = left;
    m_rightVal = right;
}

std::string dummyInterval::nameLabel() const
{
    return m_nameLabel;
}

void dummyInterval::setNameLabel(const std::string &nameLabel)
{
    m_nameLabel = nameLabel;
}

void dummyInterval::init()
{
    m_rightVal = -1;
    m_leftVal = -1;
    m_nameLabel = "empty";
}
