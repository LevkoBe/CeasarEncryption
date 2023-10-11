#include <iostream>
#include <windows.h>

typedef std::string(*EncryptFunction)(const std::string, int);
typedef std::string(*DecryptFunction)(const std::string, int);

int main()
{
    HINSTANCE handle = LoadLibrary(TEXT("CeasarLibrary.dll"));
    if (handle == nullptr || handle == INVALID_HANDLE_VALUE)
    {
        std::cout << "Library not found" << std::endl;
        return 1;
    }

    EncryptFunction encrypt = (EncryptFunction)GetProcAddress(handle, "encrypt");
    DecryptFunction decrypt = (DecryptFunction)GetProcAddress(handle, "decrypt");

    if (encrypt == nullptr || decrypt == nullptr)
    {
        std::cout << "Functions not found" << std::endl;
        FreeLibrary(handle);
        return 1;
    }

    std::string greetings = "Hello, I'm encrypted text!";
    for (int i = 0; i < 10; i++)
    {
        std::string encrypted = encrypt(greetings, i);
        std::cout << encrypted << std::endl;
        std::cout << decrypt(encrypted, i) << std::endl;
        std::cout << decrypt(encrypted, i + 1) << std::endl;
        std::cout << std::endl;
    }

    FreeLibrary(handle);
    return 0;
}
