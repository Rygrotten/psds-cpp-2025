#include <stdexcept>

void SwapPtr(int*& a, int*& b) {
    int* temp = a;
    a = b;
    b = temp;
}
