#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
    int i, j, len;
    bool isValid;
    string input, aux;
    
    cin >> input;
    while (input != ".") {
        len = input.length();
        for (i = 1, isValid = false; i < len; i++) {
            if ((len % i) == 0) {
                isValid = true;
                aux = input.substr(0, i);
                for (j = i; j < len && isValid == true; j += i) {
                    if (input.substr(j, i) != aux)
                        isValid = false;
                }
            }
            if (isValid) break;
        }
        cout << len / i << endl;
        cin >> input;
    }
    return 0;
}
