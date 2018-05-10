#include <string>
#include <iostream>

int main()
{
    std::wcout << L"Hello world" << std::endl;

    std::wcout << L"Press any key to exit..." << std::endl;
    std::cin.get();
    return 0;
}