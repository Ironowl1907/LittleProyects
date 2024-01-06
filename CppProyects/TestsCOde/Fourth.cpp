#include <iostream>

void addOne(int* num) {
    (*num)++;
}

int main() {
    int num = 5;
    std::cout << "Before: " << num << std::endl;

    addOne(&num);

    std::cout << "After: " << num << std::endl;

    return 0;
}
