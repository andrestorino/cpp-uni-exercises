#include <iostream>

using namespace std;

int main() {
    int n, s;
    bool forward[1001], backward[1001];
    
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> forward[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> backward[i];
    }
    if (!forward[1] || (!forward[s] && !backward[s])) {
        cout << "NO" << endl;
        return 0;
    }
    if (forward[s]) cout << "YES" << endl;
    else {  // backward[s] = true
        bool isThereAWay = false;
        for (int i = s; i <= n && !isThereAWay; i++) {
            if (forward[i] && backward[i])
                isThereAWay = true;
        }
        if (isThereAWay) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
