/*
Another way of implement Filter.
*/

#include <vector>
#include <algorithm>
#include <iostream>

template <typename InputIterator, typename OutputIterator, typename ElemType, typename Comp>
OutputIterator subvec(InputIterator first, InputIterator last, OutputIterator at, ElemType &val, Comp pred)
{
    std::sort(first, last, pred);
    last = std::find_if(first, last, std::not1(std::bind2nd(pred, val)));
    while (first != last)
    {
        std::cout << *first << ' ';
        *at++ = *first++;
    }
    std::cout << std::endl;
    return at;
}

int main()
{
    const int elemSize = 8;
    int ia[elemSize] = {12, 8, 43, 0, 6, 21, 3, 7};
    std::vector<int> ivec(ia, ia + elemSize);
    {
        int ia2[elemSize];
        std::cout << "Filtering integer array for values less than 8\n";
        subvec(ia, ia + elemSize, ia2, elemSize, std::less<int>());
    }
    {
        std::vector<int> ivec2;
        std::cout << "Filtering integer array for values greater than 8\n";
        subvec(ivec.begin(), ivec.end(), std::back_inserter(ivec2), elemSize, std::greater<int>());
    }
    return 0;
}