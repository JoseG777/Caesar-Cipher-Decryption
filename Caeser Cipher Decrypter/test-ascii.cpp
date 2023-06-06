#include <iostream>
#include <string>


void ascii(std::string text){
    for(int i = 0; i < text.length(); i++){
        std::cout<<text[i]<<"\t"<<(int)text[i]<<"\n";
    }
}