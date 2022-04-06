#ifndef OPERATION
#define OPERATION

#include <iostream>
#include <fstream>
#include "List.h"
#include "Vector.h"

static char balance_symb[] = {'(', ')', '[', ']','{', '}'};

void printLots(const List<int> & L, const List<size_t> & P);

// Find first x
template <typename iterator, typename obj_t>
iterator Find(iterator start, iterator end, const obj_t & x) {
    for (; start != end; ++start)
        if(*start == x)
            return start;
    return start;
}

// Compute intersection of L1 and L2. L1 and L2 are pre-sorted.
template <typename obj_t>
List<obj_t> Intersect(const List<obj_t> & L1, const List<obj_t> & L2) {
    bool long_list = L1.size() < L2.size();
    List<obj_t> ans;
    const List<obj_t> * pt_long_list = long_list? &L1 : &L2;
    const List<obj_t> * pt_short_list = long_list? &L2 : &L1;
    auto long_it = pt_long_list->begin();
    auto short_it = pt_short_list->begin();

    while (short_it != pt_short_list->end() && long_it != pt_long_list->end()) {
        if(*short_it < *long_it)
            ++short_it;
        else if(*short_it == *long_it) {
            ans.push_back(*short_it);
            ++short_it;
            ++long_it;
        }
        else
            ++long_it;
    }
    return ans;
}

// Compute union set of L1 and L2. L1 and L2 are pre-sorted.
template <typename obj_t>
List<obj_t> Union(const List<obj_t> & L1, const List<obj_t> & L2) {
    bool long_list = L1.size() < L2.size();
    List<obj_t> ans;
    const List<obj_t> * pt_long_list = long_list? &L1 : &L2;
    const List<obj_t> * pt_short_list = long_list? &L2 : &L1;
    auto long_it = pt_long_list->begin();
    auto short_it = pt_short_list->begin();

    while ( long_it != pt_long_list->end() ) {
        if( short_it != pt_short_list->end() ) {
            if(*short_it < *long_it) {
                ans.push_back(*short_it);
                ++short_it;
            } else if(*short_it == *long_it) {
                ans.push_back(*short_it);
                ++short_it;
                ++long_it;
            } else {
                ans.push_back(*long_it);
                ++long_it;
            }        
        } else {
            ans.push_back(*long_it);
            ++long_it;            
        }
    }
    return ans;
}

// The Josephus problem. N people, M pass per time.
size_t Josephus(size_t N, size_t M);

// Check balacing symbols.
int check_symb_type(char byte);
int balancing_symb(std::string file_name);

// Infix to Postfix Conversion.
int check_priority(char op);
Vector<char> Infix2Postfix(const Vector<char> & infix);

#endif