#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <cmath>

/* TEST_CASE("TESTS")
{
    CHECK(shiftChar('a', 25) == 'z');
    CHECK(shiftChar('z', 25) == 'y');

    CHECK(encryptCaesar("Hello, World!", 10) == "Rovvy, Gybvn!");
    CHECK(encryptCaesar("What a sentence", 10) == "Grkd k coxdoxmo");

    CHECK(decryptCaesar("Rovvy, Gybvn!", 10) == "Hello, World!");
    CHECK(decryptCaesar("Grkd k coxdoxmo", 10) == "What a sentence");

    CHECK(encryptVigenere("Hello, World!", "cake") == "Jevpq, Wyvnd!");
    CHECK(encryptVigenere("What a sentence", "power") == "Lvwx r hsjxvcqa");

    CHECK(decryptVigenere("Jevpq, Wyvnd!", "cake") == "Hello, World!");
    CHECK(decryptVigenere("Lvwx r hsjxvcqa", "power") == "What a sentence");
} */
/* std::string test0 = "Aopz pz qbza h alza.";
std::string test1 = "Le tlt texq x qbpq";
std::string test2 = "Rxewtgts pcs Strxewtgts";

std::vector<double> t0;
std::vector<double> t1;
std::vector<double> t2; */

std::string test0 = "Aopz pz qbza h alza.";
std::string test1 = "Le tlt texq x qbpq";
std::string test2 = "Rxewtgts pcs Strxewtgts";
std::string test3 = "Aopz pz qbza h alza jhzl.";

std::vector<double> t0 = {0.2, 0.05, 0, 0, 0, 0, 0, 0.05, 0, 0, 0, 0.05, 0, 0, 0.05, 0.1, 0.05, 0, 0, 0, 0, 0, 0, 0, 0, 0.2};

std::vector<double> t1 = {0, 0.0555556, 0, 0, 0.111111, 0, 0, 0, 0, 0, 0, 0.111111, 0, 0, 0, 0.0555556, 0.166667, 0, 0, 0.166667, 0, 0, 0, 0.111111, 0, 0};

std::vector<double> t2 = {0, 0, 0.0434783, 0, 0.0869565, 0, 0.0869565, 0, 0, 0, 0, 0, 0, 0, 0, 0.0434783, 0, 0.0869565, 0.173913, 0.217391, 0, 0, 0.0869565, 0.0869565, 0, 0};

std::vector<double> t3 = {0.16, 0.04, 0, 0, 0, 0, 0, 0.08, 0, 0.04, 0, 0.08, 0, 0, 0.04, 0.08, 0.04, 0, 0, 0, 0, 0, 0, 0, 0, 0.2};

TEST_CASE("LETTER FREQUENCY")
{
    CHECK(letterFreq('a', test0) == doctest::Approx(0.2));
    CHECK(letterFreq('l', test1) == doctest::Approx(0.111111));
    CHECK(letterFreq('t', test2) == doctest::Approx(0.217391));
}

TEST_CASE("ALL FREQUENCY")
{
    CHECK(allFreq(test0) == t0);
    CHECK(allFreq(test3) == t3);
}

TEST_CASE("Distance")
{
    CHECK(vDistance(t1) == doctest::Approx(25.6308));
    CHECK(vDistance(t2) == doctest::Approx(25.5648));
}

TEST_CASE("SOLVE")
{
    CHECK(solve("Aopz pz qbza h alza.") == "This is just a test.");
    CHECK(solve("Le tlt texq x qbpq") == "Oh wow what a test");
    CHECK(solve("Rxewtgts pcs Strxewtgts") == "Ciphered and Deciphered");
    CHECK(solve("Aopz pz qbza h alza jhzl.") == "This is just a test case.");
}
