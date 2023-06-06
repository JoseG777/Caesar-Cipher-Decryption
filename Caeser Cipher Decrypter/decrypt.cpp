#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <cmath>
#include "caesar.h"
#include "vigenere.h"

std::string decryptCaesar(std::string ciphertext, int rshift)
{
    std::string plain;
    int shift = 26 - rshift;
    for (int i = 0; i < ciphertext.length(); i++)
    {
        if (isalpha(ciphertext[i]))
        {
            plain += shiftChar(ciphertext[i], shift);
        }
        else
        {
            plain += ciphertext[i];
        }
    }
    return plain;
}

std::string decryptVigenere(std::string ciphertext, std::string keyword)
{
    std::string plain1;
    int j = 0;
    for (int i = 0; i < ciphertext.length(); i++)
    {
        if (j > keyword.length() - 1)
        {
            j = 0;
        }
        if (isalpha(ciphertext[i]))
        {
            plain1 += shiftChar(ciphertext[i], 26 - (keyword[j] - 97));
            j += 1;
        }
        else
        {
            plain1 += ciphertext[i];
        }
    }
    return plain1;
}

double letterFreq(char letter, std::string encrypted_string)
{
    double frequency = 0;
    for (int l = 0; l < encrypted_string.length(); l++)
    {
        if (tolower(encrypted_string[l]) == letter)
        {
            frequency += 1;
        }
    }
    frequency /= encrypted_string.length();
    return frequency;
}

std::vector<double> allFreq(std::string encrypted_string)
{
    std::vector<char> englishAlphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    std::vector<double> lFreq = {};
    for (int f = 0; f < englishAlphabet.size(); f++)
    {
        lFreq.push_back(letterFreq(englishAlphabet[f], encrypted_string));
    }
    return lFreq;
}

double vDistance(std::vector<double> encryptedFreq)
{
    std::vector<double> englishFreq = {8.2, 1.5, 2.8, 4.3, 13, 2.2, 2, 6.1, 7, 0.15, 0.77, 4, 2.4, 6.7, 7.5, 1.9, 0.095, 6, 6.3, 9.1, 2.8, 0.98, 2.4, 0.15, 2, 0.074};
    double distance;
    for (int n = 0; n < 26; n++)
    {
        distance += (pow((englishFreq[n] - encryptedFreq[n]), 2.0));
    }
    return sqrt(distance);
}

std::string solve(std::string encrypted_string)
{
    std::vector<double> freqV;

    std::string decrypted_string;
    std::string final;

    double least;
    double distance;

    decrypted_string = decryptCaesar(encrypted_string, 0);
    freqV = allFreq(decrypted_string);
    distance = vDistance(freqV);
    least = distance;

    for (int d = 1; d < 26; d++)
    {
        decrypted_string = decryptCaesar(encrypted_string, d);
        freqV = allFreq(decrypted_string);
        distance = vDistance(freqV);
        if (distance < least)
        {
            least = distance;
            final = decrypted_string;
        }
    }
    return final;
}

/* int main()
{

    std::string solved = solve("Dof kvu'a fvb dhua av svvr ha aol jolyyf isvzzvtz dpao tl :(");

    std::cout << solved << "\n";
} */