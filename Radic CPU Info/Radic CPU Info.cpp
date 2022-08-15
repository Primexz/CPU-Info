#include <iostream>
#include <intrin.h>


int main()
{
    int registers[4];

    __cpuid(registers, 0);

    uint32_t maximum_eax = registers[0];



    if (maximum_eax >= 1U)
    {
        __cpuid(registers, 1);
        uint32_t ecx = registers[2];
        uint32_t edx = registers[3];

        std::cout << "FPU: " << ((edx & (1 << 0)) != 0) << "\n";
        std::cout << "MMX: " << ((edx & (1 << 23)) != 0) << "\n";
        std::cout << "SSE: " << ((edx & (1 << 25)) != 0) << "\n";
        std::cout << "SSE2: " << ((ecx & (1 << 0)) != 0) << "\n";
        std::cout << "SSSE3: " << ((ecx & (1 << 9)) != 0) << "\n";
        std::cout << "SSE4_1: " << ((ecx & (1 << 19)) != 0) << "\n";
        std::cout << "SSE4_2: " << ((ecx & (1 << 20)) != 0) << "\n";
        std::cout << "PCLMULQDQ: " << ((ecx & (1 << 1)) != 0) << "\n";
        std::cout << "AVX: " << ((ecx & (1 << 28)) != 0) << "\n";
        std::cout << "F16: " << ((ecx & (1 << 29)) != 0) << "\n";
    }

    //skip avx2 check on old cpu's
    if (maximum_eax >= 7U)
    {
        __cpuidex(registers, 7, 0);
        uint32_t ebx = registers[1];

        std::cout << "AVX2: " << ((ebx & (1 << 5)) != 0) << "\n";
    }
    else {
        std::cout << "AVX2: " << 0 << "\n";
    }
}
