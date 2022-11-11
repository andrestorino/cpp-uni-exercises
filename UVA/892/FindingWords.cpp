#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
    int i, j, len;
    string input, aux;
    char c;
    
    input.reserve(61);
    aux.reserve(61);
    getline(cin, input);
    while (input != "#") {
        if (input[input.length() - 1] != '-') {
            len = input.length();
        }
        else {
            for (i = input.length() - 2, j = 0; input[i] != ' '; i--, j++); //i -> ' ', j = 3
            len = input.length() - j - 1;
            aux = input.substr(i + 1, j);   // hyp
            cin.get(c);
            while (c != ' ') {
                aux += c;
                cin.get(c);
            }
        }
        for (i = 0; i < len; i++) {
            if ((input[i] >= 'a' && input[i] <= 'z') ||
                (input[i] >= 'A' && input[i] <= 'Z') ||
                input[i] == ' ')
                cout << input[i];
        }
        cout << endl;
        if (len != input.length()) {
            cout << aux << endl << ' ';
        }
        getline(cin, input);
    }
    
    return 0;
}
