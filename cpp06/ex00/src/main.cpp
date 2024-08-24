#include "../include/ScalarConvert.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./scalarConvert <input>" << std::endl;
        return 1;
    }
    //ScalarConvert scalarConvert(argv[1]);
    //ScalarConvert.convert(argv[1]);
    ScalarConvert::convert(argv[1]);
    return 0;
}
