#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#pragma optimize ("", on)
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

int main(int argc, char *argv[]) {
    int m, l, r, i, counter, output, len = 0;
    char input = 0;
    char s[100002];
    int hash[100002];
    int dot[100002];
    
    do {
        input = fgetc(stdin);
        s[len++] = input;
    } while (input != '\n');
    s[len] = '\0';
    scanf("%d", &m);
    hash[0] = 0;
    dot[0] = 0;
    counter = 0;
    for (int i = 0; i < len - 1; ++i) {
        if (s[i + 1] == s[i] && s[i] == '#') {
            hash[i + 1] = ++counter;
        }
        else {
            hash[i + 1] = counter;
        }
    }
    counter = 0;
    for (int i = 0; i < len - 1; ++i) {
        if (s[i + 1] == s[i] && s[i] == '.') {
            dot[i + 1] = ++counter;
        }
        else {
            dot[i + 1] = counter;
        }
    }
    while (m--) {
        output = 0;
        scanf("%d %d", &l, &r);
        --l;
        --r;
        output = hash[r] - hash[l] + dot[r] - dot[l];
        printf("%d\n", output);
    }

    return 0;
}
