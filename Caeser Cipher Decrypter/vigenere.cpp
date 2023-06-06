#include <iostream>
#include <string>
#include <cctype>
#include "caesar.h"

std::string encryptVigenere(std::string plaintext, std::string keyword)
{
    std::string encrypted;
    int j = 0;
    for (int i = 0; i < plaintext.length(); i++)
    {
        if (j > keyword.length() - 1)
        {
            j = 0;
        }
        if (isalpha(plaintext[i]))
        {
            encrypted += shiftChar(plaintext[i], int(keyword[j]) - 97);
            j = j + 1;
        }
        else
        {
            encrypted += plaintext[i];
        }
    }
    return encrypted;
}