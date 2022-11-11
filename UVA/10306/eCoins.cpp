#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int x[42], y[42];
int dp[302][302];

int main(int argc, char *argv[]) {
	int n, m, s;
	while (cin >> n) {
		while (n --) {
			cin >> m >> s;
			for (int i = 0; i <= s; ++i) {
				for (int j = 0; j <= s; ++j) {
					dp[i][j] = 100000;
				}
			}
			for (int i = 1; i <= m; ++i) {
				cin >> x[i] >> y[i];
				dp[x[i]][y[i]] = 1;
			}
			
			for (int i = 1; i <= m; ++i) {
				for (int j = x[i]; j <= s; ++j) {
					for (int k = y[i]; k <= s; ++k) {
						if (dp[j][k] > dp[j - x[i]][k - y[i]] + 1)
							dp[j][k] = dp[j - x[i]][k - y[i]] + 1;
					}
				}
			}
			int max = 100000;
			for (int i = 0; i <= s; ++i) {
				for (int j = 0; j <= s; ++j) {
					if (i*i+j*j == s*s && max > dp[i][j])
						max = dp[i][j];
				}
			}
			
			if (max == 100000)
				printf("not possible\n");
			else printf("%d\n", max);
		}
	}
	return 0;
}
