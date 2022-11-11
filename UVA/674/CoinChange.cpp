#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

int dp[8000];
int coin[5] = {1, 5, 10, 25, 50};

int main(int argc, char *argv[]) {
    int n;
    while (scanf("%d", &n) != EOF) {
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 0; i < 5; i++) {
            for (int j = coin[i]; j <= n; j++) {
                if (dp[j - coin[i]]) {
                    dp[j] += dp[j - coin[i]];
                }
            }
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}
