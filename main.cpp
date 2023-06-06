#include <iostream>
#include <string>
#include <cctype>
#include "decrypt.h"
#include "vigenere.h"
#include "caesar.h"
#include "test-ascii.h"
// To decrypt a string, call the function "solve(std::string encrypted_string)" and enter...
// the string you wish to decrypt as a parameter
// to compile and run, in your terminal type "make main" and then "./main"
// Be sure to use "make clean" when done !
int main()
{
    // EXAMPLE:
    std::cout << solve("Guvf vf ubj lbh eha gur cebtenz") << "\n";
}