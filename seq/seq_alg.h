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

#endif