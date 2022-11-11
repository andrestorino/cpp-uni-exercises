#include <cstdio>
#include <cstring>
#include <cctype>
#include <map>

using namespace std;

int main(int argc, char *argv[]) {
    map<char, char> m;
    m[']'] = 'p';
    m['['] = 'o';
    m['p'] = 'i';
    m['o'] = 'u';
    m['i'] = 'y';
    m['u'] = 't';
    m['y'] = 'r';
    m['t'] = 'e';
    m['r'] = 'w';
    m['e'] = 'q';
    m['\''] = 'l';
    m[';'] = 'k';
    m['l'] = 'j';
    m['k'] = 'h';
    m['j'] = 'g';
    m['h'] = 'f';
    m['g'] = 'd';
    m['f'] = 's';
    m['d'] = 'a';
    m['.'] = 'm';
    m[','] = 'n';
    m['m'] = 'b';
    m['n'] = 'v';
    m['b'] = 'c';
    m['v'] = 'x';
    m['c'] = 'z';
    m[' '] = ' ';
    char input[1000000] = { 0 };
    scanf("%[^\n]", input);
    for (int i = 0; i < strlen(input); i++) {
        input[i] = m[tolower(input[i])];
    }
    printf("%s\n", input);
    
    return 0;
}
