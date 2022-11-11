#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

char maps[30][30], buf[30];
int dxy[8][2] = {1, -1,
				 1, 0,
				 1, 1,
				 0, -1,
				 0, 1,
				 -1, -1,
				 -1, 0,
				 -1, 1};
int dfs(int x, int y) {
	if (x < 0 || y < 0) return 0;
	if (maps[x][y] != '1') return 0;
	maps[x][y] = '0';
	int sum = 1;
	for (int k = 0; k < 8; ++ k)
		sum += dfs(x + dxy[k][0], y + dxy[k][1]);
	return sum;
}

int main(int argc, char *argv[]) {
	int n;
	scanf("%d", &n);
	gets(buf);
	gets(buf);
	while (n--) {
		int count = 0;
		while (gets(maps[count]))
			if(!maps[count++][0]) break;
		int Max = 0;
		for (int i = 0; i < count; ++i)
		for (int j = 0; maps[i][j]; ++j)
			if (maps[i][j] == '1')
				Max = max(Max, dfs(i, j));
		printf("%d\n", Max);
		if (n) printf("\n");
	}
	return 0;
}
