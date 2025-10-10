#pragma once
#include <vector>

std::vector<double> ReadNumbers(int argc, char* argv[]);
void ProcessNumbers(std::vector<double>& dValue);
void PrintSortedNumbers(std::vector<double>& dValue);