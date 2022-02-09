#include <iostream>
#include "my_vector.h"

void ivector::copy(int *ptr = nullptr)
{
    if (ptr == nullptr)
    {
        ptr = new int[m_capacity];
        for(int i=0; i<m_size; ++i)
        {
            ptr[i] = m_buffer[i];
        }
        delete [] m_buffer;
        m_buffer = ptr;
    }
    else
    {
        m_buffer = new int[m_capacity];
        for(int i=0; i<m_size; ++i)
        {
            m_buffer[i] = ptr[i];
        }

    }
}
ivector::ivector()
{
    m_size = 0;
    m_capacity = 1;
    m_buffer = new int[m_capacity];
}
ivector::~ivector()
{
    delete[] m_buffer;
}
ivector::ivector(const ivector &ive)
{
    m_size = ive.m_size;
    m_capacity = ive.m_capacity;
    m_buffer = new int[m_capacity];
    copy(ive.m_buffer);
}
ivector& ivector::operator= (const ivector& ive)
{
    if(this == &ive)
    {
        return *this;
    }
    m_size = ive.m_size;
    m_capacity = ive.m_capacity;
    copy(ive.m_buffer);
    return *this;
}
bool ivector::empty()
{
    return !(m_size);
}
int ivector::size()
{
    return m_size;
}
void ivector::push_back(int element)
{
    if(m_size == m_capacity)
    {
        m_capacity *= 2;
        copy();
    }
    m_buffer[m_size] = element;
    ++m_size;
}
int ivector::pop_back()
{
    if(m_size <= m_capacity/2)
    {
        m_capacity = m_capacity/2 + m_capacity%2;
        copy();
    }
    --m_size;
    return m_buffer[m_size];
}
void ivector::push_front(int element)
{

    if(m_size == m_capacity)
    {
        m_capacity *=2 ;
        int* ptr = new int[m_capacity];
        ptr[0] = element;
        for (int i=1; i<= m_size; ++i)
        {
            ptr[i] = m_buffer[i-1];
        }
        delete [] m_buffer;
        m_buffer = ptr;
    }
    for(int i=m_size-1; i>0; --i)
    {
        m_buffer[i+1]=m_buffer[i];
    }
    m_buffer[0]=element;
}
int ivector::pop_front()
{
    if(this->empty())
    {
        return -1;
    }
    int tmp = m_buffer[0];
    for(int i=0; i<m_size; ++i)
    {
        m_buffer[i] = m_buffer[i+1];
    }
    if(m_size <= m_capacity/2)
    {
        m_capacity = m_capacity/2 + m_capacity%2;
        copy();
    }
    --m_size;
    return tmp;

}
void ivector::reserve(int count)
{
    m_capacity = count;
    copy();
}