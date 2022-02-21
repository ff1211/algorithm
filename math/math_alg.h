#ifndef _MATH_ALG_H
#define _MATH_ALG_H

#include <vector>
#include <string>
using namespace std;

//calcuate base raised to the power exponent
//power_int1 = O(N), power_int2 = O(logN), power_int3 = O(logN),
long power_int1 (long base, unsigned int power);
long power_int2 (long base, unsigned int power);
//Using binary present power. for example, 77 = 1001101. 
//Search from LSB, when comes 1, times corresponding power of the base.
long power_int3 (long base, unsigned int power);

//calcuate a0 + a1*x + a2*x^2 + ... + an*x^n
//horner_rule = O(N)
long horner_rule (long x, const vector<int> a);

//gcd algorithm, return gcd
long gcd(long a, long b);

//Return a + b. String only contain '0'~'9'
//adder = O(N)
string adder_str(const string & a, const string & b);

//Determineing if a positive integer, N, is prime.
//Return 1 if N is prime, return 0 if N is not prime.
bool if_prime(unsigned int n);
#endif

