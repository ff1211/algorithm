#ifndef _RAND_PERM_H
#define _RAND_PERM_H

#include <vector>
#include <random>

using namespace std;

//output random permutation
void ran_perm1(vector<int> & permutation);
void ran_perm2(vector<int> & permutation);
void ran_perm3(vector<int> & permutation);

//search integer in an sorted sequence(incresing)
//returns index where item is found or -1 if not found.
int binary_search(int x, const vector<int> & seq);

// A majority element in an array, A, of size N is an element that appears more than 
// N/2 times (thus, there is at most one).
// find majority element
// If found return 1, else return 0. The value of majority element will be stored in major_e.
bool major_e(const vector<int> & a, int & major_e);

// Find if x in N*N matrix.
// Each individual row is increasing from left to right. 
// Each individual column is increasing from top to bottom.
bool search_matrix1(int x, unsigned int N, const vector<int> & a);

#endif