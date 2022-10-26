#include <iostream>
#include <vector>
#include <list>

template <typename IteratorType, typename elemType>
IteratorType find(IteratorType first, IteratorType last, const elemType &value)
{
    for (; first != last; ++first)
        if (value == *first)
            return first;
    return last;
}

int main()
{
    const int maxSize = 8;
    int ia[maxSize] = {1, 1, 2, 3, 5, 8, 13, 21};
    std::vector<int> ivec(ia, ia + maxSize);
    std::list<int> ilist(ia, ia + maxSize);
    {
        int *pia = find(ia, ia + maxSize, 1024);
        if (pia != ia + maxSize)
            std::cout << "Find element:" << 1024 << std::endl;
    }
    {
        std::vector<int>::iterator itv;
        itv = find(ivec.begin(), ivec.end(), 1024);
        if (itv != ivec.end())
            std::cout << "Find element:" << 1024 << std::endl;
    }
    {
        std::list<int>::iterator itl;
        itl = find(ilist.begin(), ilist.end(), 1024);
        if (itl != ilist.end())
            std::cout << "Find element:" << 1024 << std::endl;
    }
    return 0;
}