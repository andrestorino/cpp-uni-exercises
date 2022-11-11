#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 9
int n, a[maxn];
int h() {
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] + 1 != a[i + 1]) cnt++;
    }
    if (a[n - 1] != n) cnt++;
    return cnt;
}
bool is_sorted(){
    for (int i = 0; i < n; i++) {
        if (a[i] != i + 1) return false;
    }
    return true;
}
bool dfs(int d, int maxd) {
    if (3 * d + h() > 3 * maxd) return false;
    if (is_sorted()) return true;
    int b[maxn], olda[maxn];
    memcpy(olda, a, sizeof(a));
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int cnt = 0;
            for (int k = 0; k < n; k++) {
                if (k < i || k > j) {
                    b[cnt++] = a[k];
                }
            }
            for (int k = 0; k <= cnt; k++) {
                int cnt2 = 0;
                for (int p = 0; p < k; p++) {
                    a[cnt2++] = b[p];
                }
                for (int p = i; p <= j; p++) {
                    a[cnt2++] = olda[p];
                }
                for (int p = k; p < cnt; p++) {
                    a[cnt2++] = b[p];
                }
                if (dfs(d + 1, maxd)) return true;
                memcpy(a, olda, sizeof(olda));
            }
        }
    }
    return false;
}
int solve() {
    if (is_sorted()) return 0;
    int ans = 5;
    for (int maxd=1; maxd < ans; maxd++) {
        if (dfs(0, maxd)) {
            return maxd;
        }
    }
    return ans;
}
int main(int argc, char *argv[]) {
    int k = 0;
    while (scanf("%d",&n) == 1 && n) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        printf ("Case %d: %d\n", ++k, solve());
    }
    return 0;
}
