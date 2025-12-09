#include <iostream>

void PrintArray(const int* begin, const int* end, size_t limit = 0) {
    if (begin == end) {
        std::cout << "[]\n";
        return;
    }
    
    bool forward = (end > begin);
    
    const int* current = begin;
    
    std::cout << '[';
    
    size_t count_in_line = 0;
    
    bool first_element = true;
    
    while (true) {
        if (!first_element) {
            std::cout << ", ";
        }
        std::cout << *current;
        first_element = false;
        
        count_in_line++;
        
        const int* next = nullptr;
        if (forward) {
            next = current + 1;
        } else {
            next = current - 1;
        }
        
        bool has_more_elements = (forward && next < end) || (!forward && next > end);
        
        if (limit > 0 && count_in_line >= limit && has_more_elements) {
            std::cout << ", ...\n ";
            count_in_line = 0;
        }
        
        if (!has_more_elements) {
            break;
        }
        
        current = next;
    }
    
    std::cout << "]\n";
}
