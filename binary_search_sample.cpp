#include <algorithm>
#include <iostream>
#include <vector>
#include <binary_search.h>

int
main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cerr << "usage: " << argv[0] << " value elem1 [elem2 ...]" << std::endl;
        return -1;
    }

    const auto value = std::stoi(argv[1]);
    std::vector<int> vec;
    for (int i = 2; i < argc; ++i)
    {
        const auto elem = std::stoi(argv[i]);
        vec.push_back(elem);
    }
    
    std::sort(std::begin(vec), std::end(vec));
    std::cout << "Sorted input: ";
    for (const auto& i : vec)
    {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    std::cout << "Searching for " << value << std::endl;

    const auto it = alg::binary_search(value, std::begin(vec), std::end(vec));

    if (it != std::end(vec))
    {
        std::cout << "Element has found, iterator value = " << *it << std::endl;
    }
    else
    {
        std::cout << "Element has not found" << std::endl;
    }

    return 0;
}
