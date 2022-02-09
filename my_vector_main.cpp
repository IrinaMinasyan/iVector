#include <iostream>
#include "my_vector.h"

int main()
{
    ivector obj;
    obj.push_back(49);
    obj.push_front(16);
    obj.push_back(23);
    int a = obj.pop_back();
    std::cout << obj.size() << std::endl;
    return 0;
}