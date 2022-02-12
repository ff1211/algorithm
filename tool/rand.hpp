#ifndef _RAND_H
#define _RAND_H

#include <random>
using namespace std;

random_device   dev;
mt19937         rng(dev());

#endif