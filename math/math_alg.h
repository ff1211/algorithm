#ifndef _MATH_ALG_H
#define _MATH_ALG_H

#include <vector>
using namespace std;

//calcuate base raised to the power exponent
//power_int1 = O(N), power_int2 = O(logN)
long power_int1 (long base, unsigned int power);
long power_int2 (long base, unsigned int power);

//calcuate a0 + a1*x + a2*x^2 + ... + an*x^n
//horner_rule = O()
long horner_rule (long x, const vector<int> a);

#endif