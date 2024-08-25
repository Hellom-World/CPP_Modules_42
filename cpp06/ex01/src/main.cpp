#include <iostream>
#include "../include/Data.h"
#include "../include/Serializer.hpp"

int main() {
    Data data;
    data.s1 = "Hello";
    data.n = 42;
    data.s2 = "World";

    uintptr_t serialized = Serializer::serialize(&data);
    Data* deserialized = Serializer::deserialize(serialized);

    std::cout << "data.s1: " << data.s1 << std::endl;
    std::cout << "data.n: " << data.n << std::endl;
    std::cout << "data.s2: " << data.s2 << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "adrss data: " << &data << std::endl;
    std::cout << "adress serialized: " << serialized << std::endl;
    std::cout << "adress deserialized: " << deserialized << std::endl;
    std::cout << "data == deserialized: " << (&data == deserialized) << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "deserialized->s1: " << deserialized->s1 << std::endl;
    std::cout << "deserialized->n: " << deserialized->n << std::endl;
    std::cout << "deserialized->s1: " << deserialized->s2 << std::endl;

    return 0;
}