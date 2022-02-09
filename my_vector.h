#include <iostream>

class ivector
{
private:
    int m_size;
    int m_capacity;
    int* m_buffer;
    void copy(int*);

public:
    ivector();
    ivector(const ivector&);
    ivector(int,ivector&);
    ~ivector();

    ivector& operator= (const ivector&);

    int size();
    bool empty();
    void push_back(int);
    int pop_back();
    void push_front(int);
    int pop_front();
    void reserve(int);

};