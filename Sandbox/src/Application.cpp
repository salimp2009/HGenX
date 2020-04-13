#include <iostream>

namespace HGenx {

    __declspec(dllexport) void Print();

}

void main()
{
    std::cout << "First attemp for the game  engine..\n";
    HGenx::Print();
}