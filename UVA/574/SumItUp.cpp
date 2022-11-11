#include <iostream>
#include <memory.h>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

vector<int> _stack;
vector<vector<int>> sol;
int t, n, nums[13];

void backtraking(int pos, int sum) {
	if (sum == t) {
		vector<int> aux = _stack;
		sort(aux.begin(), aux.end(), greater<int>());
		sol.push_back(aux);
		return;
	} else if (sum > t) return;
    else if (pos == n) return;
	_stack.push_back(nums[pos]);
	backtraking(pos + 1, sum + nums[pos]);
	_stack.pop_back();
	backtraking(pos + 1, sum);
}

int main(int argc, char *argv[]) {
	while (cin >> t >> n && n) {
        std::cout << "Sums of " << t << ":" << endl;
		sol.clear();
		for (int i = n - 1; i >= 0; --i) cin >> nums[i];
		backtraking(0, 0);
		sort(sol.begin(), sol.end(), greater<vector<int>>());
		sol.erase(unique(sol.begin(), sol.end()), sol.end());
		if (sol.size()) {
			for (int i = 0; i < sol.size(); ++i) {
				for (int j = 0; j < sol[i].size(); ++j) {
					if (j > 0) printf("+");
					printf("%d", sol[i][j]);
				}
				printf("\n");
			}
		} else {
			printf("NONE\n");
		}
	}
	return 0;
}
