#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

template <typename InputIterator, typename OutputIterator, typename ElemType, typename Comp>
OutputIterator filter(InputIterator first, InputIterator last, OutputIterator at, const ElemType &val, Comp pred)
{
    while ((first = std::find_if(first, last, std::bind2nd(pred, val))) != last)
    {
        std::cout << "Found value: " << *first << std::endl;
        *at++ = *first++;
    }
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
        filter(ia, ia + elemSize, ia2, elemSize, std::less<int>());
    }
    {
        std::vector<int> ivec2;
        std::cout << "Filtering integer array for values greater than 8\n";
        filter(ivec.begin(), ivec.end(), std::back_inserter(ivec2), elemSize, std::greater<int>());
    }
    return 0;
}