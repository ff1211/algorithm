#ifndef _RAND_PERM_H
#define _RAND_PERM_H

#include <vector>
#include <random>

using namespace std;

//output random permutation
void ran_perm0(vector<int> & permutation);
void ran_perm1(vector<int> & permutation);
void ran_perm2(vector<int> & permutation);

// search integer in an sorted sequence(incresing)
// returns index where item is found or -1 if not found.
// binary_search = O(logN)
int binary_search(int x, const vector<int> & seq);

// A majority element in an array, A, of size N is an element that appears more than 
// N/2 times (thus, there is at most one).
// find majority element
// If found return 1, else return 0. The value of majority element will be stored in major_e.
vector<int> major_ele_candi(const vector<int> & a);
vector<int> major_ele(const vector<int> & a);

// Find if x in N*N matrix.
// Each individual row is increasing from left to right. 
// Each individual column is increasing from top to bottom.
// search_matrix1 = O(N)
bool search_matrix1(int x, unsigned int N, const vector<int> & a);

// Take an array of positive numbers a.
// max_value0, determine the maximum value of a[j]+a[i], with j ≥ i.
// max_value1, determine the maximum value of a[j]-a[i], with j ≥ i.

// max_value0 = O()
int max_value0(const vector<int> & a);
int max_value1(const vector<int> & a);

#endif