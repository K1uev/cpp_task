#include "numbers.h"
#include <vector>

int main(int argc, char* argv[])
{
    std::vector<double> readNumbers = ReadNumbers(argc, argv);
    ProcessNumbers(readNumbers);
    PrintSortedNumbers(readNumbers);

    return 0;
}