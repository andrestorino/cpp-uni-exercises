#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

typedef map<string, int> M;

bool comp(M::value_type &i1, M::value_type &i2) {
    return i1.second<i2.second;
}

int main(int argc, char *argv[]) {
    int N;
    string input;
    M m;
    
    while (cin >> N >> input) {
        for (int i = 0; i < input.length() - N + 1; i++) {
            m[input.substr(i, N)]++;
        }
        M::iterator it = max_element(m.begin(), m.end(), comp);
        cout << it->first << endl;
        m.clear();
    }
    
    return 0;
}
