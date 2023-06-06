#include <iostream>
#include <string>
#include <cctype>
#include "decrypt.h"
#include "vigenere.h"
#include "caesar.h"
#include "test-ascii.h"

int main()
{
    /* std::cout<<shiftChar('a', 25)<<"\n";
    std::cout<<shiftChar('z', 25)<<"\n";

    std::cout<<encryptCaesar("Hello, World!", 10)<<"\n";
    std::cout<<encryptCaesar("What a sentence", 10)<<"\n";

    std::cout<<decryptCaesar("Rovvy, Gybvn!", 10)<<"\n";
    std::cout<<decryptCaesar("Grkd k coxdoxmo", 10)<<"\n";

    std::cout<<encryptVigenere("Hello, World!", "cake")<<"\n";
    std::cout<<encryptVigenere("What a sentence", "power")<<"\n";

    std::cout<<decryptVigenere("Jevpq, Wyvnd!", "cake")<<"\n";
    std::cout<<decryptVigenere("Lvwx r hsjxvcqa", "power")<<"\n";

    ascii("Wow what a sentence");
    ascii("A real test"); */

    std::string test0 = "Aopz pz qbza h alza.";
    std::string test1 = "Le tlt texq x qbpq";
    std::string test2 = "Rxewtgts pcs Strxewtgts";
    std::string test3 = "Aopz pz qbza h alza jhzl.";

    std::vector<double> t0;
    std::vector<double> t1;
    std::vector<double> t2;
    std::vector<double> t3;

    t0 = allFreq(test0);
    t1 = allFreq(test1);
    t2 = allFreq(test2);

    std::cout << letterFreq('a', test0) << "\n";
    std::cout << letterFreq('l', test1) << "\n";
    std::cout << letterFreq('t', test2) << "\n";

    std::cout << vDistance(t0) << "\n";
    std::cout << vDistance(t1) << "\n";
    std::cout << vDistance(t2) << "\n";

    std::cout << solve(test0) << "\n";
    std::cout << solve(test1) << "\n";
    std::cout << solve(test2) << "\n";
    std::cout << solve(test3) << "\n";
}