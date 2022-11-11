#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

int w[22], f[202];

int main(int argc, char *argv[]) {
	int n;
	char ch;
	while (~scanf("%d%c", &n, &ch)) {
		while (n--) {
			int count = 0, sum = 0;
			while (~scanf("%d%c", &w[count], &ch) && ch == ' ')
				sum += w[count++];
			sum += w[count++];
			for (int i = 0; i <= sum; ++i)
				f[i] = 0;
			f[0] = 1;
			for (int i = 0; i < count; ++i) {
				for (int j = sum; j >= w[i]; -- j) {
					if (f[j-w[i]])
						f[j] = 1;
				}
			}
			if (sum%2 || !f[sum/2])
				printf("NO\n");
			else printf("YES\n");
		}
	}
    return 0;
}
