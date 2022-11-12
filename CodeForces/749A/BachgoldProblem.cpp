#include <iostream>

int main(int argc, const char *argv[]){
    int n;
    std::cin >> n;
    std::cout << n/2 << std::endl;
    if (n % 2 == 0) {
        for(int i = 0; i < (n/2)-1; i++)
            std::cout << 2 << " ";
        std::cout << 2 << std::endl;
    }
    else {
        for(int i = 0; i < (n/2)-1; i++)
            std::cout << 2 << " ";
        std::cout << 3 << std::endl;
    }
    
}
