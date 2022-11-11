#include <iostream>
#include <algorithm>
#include <cstring>

int main(int argc, char *argv[]) {
    char input[51];

    std::cin >> input;
    while (std::strcmp(input, "#") != 0) {
        if (std::next_permutation(input, input + (std::strlen(input))))
            std::cout << input << std::endl;
        else
            std::cout << "No Successor" << std::endl;
        std::cin >> input;
    }
    return 0;
}
