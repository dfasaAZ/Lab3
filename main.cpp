#include <iostream>
#include "src/QuickSort.h"
int main() {
int array[10] = {1, 8, 3, 5, 4, 6, 7, 2, 9, 10};
    sort(std::begin(array), std::end(array));
    return 0;
}