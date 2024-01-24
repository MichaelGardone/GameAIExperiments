#pragma once

#include <random>

inline double RandomBinomial()
{
	return (double)rand() - rand();
}

inline double RandomRange(int min, int max)
{
	return (((double)rand()) / (double)RAND_MAX * max - min) + min;
}
