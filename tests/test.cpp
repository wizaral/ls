#include <algorithm>
#include <iostream>
#include <cstring>

int main() {
    // std::string flags = "1@ACFGORSTUacefghilmnpqrstuvwx1";
    // std::string flags = "1Clmx";
    // std::string flags = "Aa";
    // std::string flags = "qvw";
    // std::string flags = "Fp";
    // std::string flags = "lUcu"; && flags[0] == 'l'
    // std::string flags = "Sfrt";
    // std::string flags = "Sft";
    // std::string flags = "Srt";
    // std::string flags = "St";
    // std::string flags = "l@e";
    // std::string flags = "gn";
    // std::string flags = "nisTOGfFqh@e";
    // std::string flags = "AF@eGisTOnh Makefile ../Makefile / /dev /dev/fd /tmp/";
    // std::string flags = "Aaf";
    std::string flags = "privet";

    do {
        std::cout << "zsh compare.sh <(ls -" << flags << " 2>&1) <(./uls -" << flags << " 2>&1) \"-" << flags << "\"" << std::endl;
    } while(std::next_permutation(flags.begin(), flags.end()));
}
