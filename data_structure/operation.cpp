#include "operation.h"

// Print the elements in L that are in positions specified by P.
void printLots(const List<int> & L, const List<size_t> & P) {
    List<int>::const_iterator it_l = L.begin();
    int it_times = 0;
    for (List<size_t>::const_iterator it_p = P.begin(); it_p != P.end(); ++it_p){
        while (it_times != *it_p) {
            ++it_l;
            ++it_times;
        }
        std::cout << *it_l << std::endl;
    }
}

// The Josephus problem. N people, M pass per time.
size_t Josephus(size_t N, size_t M) {
    List<size_t> people(N);
    size_t i = 1;
    for (List<size_t>::iterator it = people.begin(); it != people.end(); ++it) {
        *it = i;
        ++i;
    }

    List<size_t>::iterator pass_it = people.begin();
    size_t j = 0;
    while(people.size() != 1){ 
        if(j == M) {
            pass_it = people.erase(pass_it);
            j = 0;
        } else {
            if(pass_it != people.end())
                ++pass_it;
            else
                pass_it = people.begin();
            // last node to tail is not a valid pass, an extra operation is needed to pass the potato to the beginning.
            if(pass_it != people.end())
                j++;
        }
    }
    return *people.begin();
}

// If byte is symbol, return location. 
// Even location stands for opening symbols.
// Odd location stands for closing symbols.
// If not, return -1.
int check_symb_type(char byte) {
    for(int i = 0; &balance_symb[i] != NULL; ++i){
        if(byte == balance_symb[i])
            return i;
    }
    return -1;
}

// Cheak if symbols are balancing.
// If balancing, return 1.
// If not, return negetive number.
// -1 : Missing opening symbol.
// -2 : Missing clonsing symbol.

int balancing_symb(std::string file_name) {
    List<char> stack;
    char byte = 0;
    std::ifstream input_file(file_name);
    while (input_file.get(byte)) {
        int type = check_symb_type(byte);
        if(type >= 0) {
            if(type & 1) // odd
                if( *(--stack.end()) == balance_symb[type-1])
                    stack.pop_back();
                else
                    return stack.size()? -2 : -1;
            else // even
                stack.push_back(byte);
        }
    }    
    input_file.close();
    return stack.size()? -2 : 1;
};