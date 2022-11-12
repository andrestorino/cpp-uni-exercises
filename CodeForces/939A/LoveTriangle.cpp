#include <iostream>

using namespace std;

int main() {
    int n;
    
    int planes[5001];
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> planes[i];
    }
    for (int i = 1; i <= n; i++) {
        if (i == planes[planes[planes[i]]]) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
