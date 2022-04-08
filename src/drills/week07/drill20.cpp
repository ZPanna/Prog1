#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <algorithm>

using namespace std;

template<class T>
void printContents(T container) {
    std::for_each(container.begin(), container.end(), [](int param){std::cout << param << " ";});
    std::cout << std::endl;
}

template<class T>
void increment(T& container, int amount) {
    for (auto& element : container)
        element += amount;
}

template<class I, class O>
O custom_copy(I start, I end, O target) {
    for (I p = start; p != end; ++p) {
        *target++ = *p;
    }
    return target;
}


int main() {
    constexpr int size = 10;
    int nums[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    
    std::array<int, size> ai;
    std::copy(nums, nums + size, ai.begin());

    std::vector<int> vi(size);
    std::copy(nums, nums + size, vi.begin());

    std::list<int> li(size);
    std::copy(nums, nums + size, li.begin());

    std::cout << "array: " << std::endl;
    printContents(ai);
    std::cout << "vector: " << std::endl;
    printContents(vi);
    std::cout << "list: " << std::endl;
    printContents(li);

    std::array<int, size> aClone = ai;
    std::vector<int> vClone = vi;
    std::list<int> lClone = li;

    std::cout << "clones: " << std::endl;
    printContents(aClone);
    printContents(vClone);
    printContents(lClone);
    std::cout << std::endl;

    increment(aClone, 2);
    increment(vClone, 3);
    increment(lClone, 5);

    std::cout << "increments: " << std::endl;
    printContents(aClone);
    printContents(vClone);
    printContents(lClone);
    std::cout << std::endl;

    std::vector<int> dummy(size);
    custom_copy(aClone.begin(), aClone.end(), dummy.begin());
    std::cout << "custom copy: ";
    printContents(dummy);
    std::cout << std::endl;

    int searched = 3;
    std::vector<int>::iterator vit;
    vit = std::find(dummy.begin(), dummy.end(), searched);
    if (vit != dummy.end()) {
        cout << "Found " << searched << " on index: " << std::distance(dummy.begin(), vit) << endl;
    } else {
        cout << searched << " not found" << endl;
    }
}