#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int,int> pii;
const int maxn = 1005;
const int maxm = 105;
const int inf = 0x3f3f3f3f;

int N, M, P[maxn], D[maxn][maxm], vis[maxn][maxm];
vector<pii> G[maxn];

struct State {
	int u, l, d;
	State(int u = 0, int l = 0, int d = 0) : u(u), l(l), d(d) {}
	bool operator < (const State& a) const { return d > a.d; }
};

void init() {
	for (int i = 0; i < N; i++) {
		G[i].clear();
		scanf("%d", &P[i]);
	}

	int u, v, w;
	while (M--) {
		scanf("%d%d%d", &u, &v, &w);
		G[u].push_back(make_pair(v, w));
		G[v].push_back(make_pair(u, w));
	}
}

int dijkstra(int s, int e, int c) {
	memset(D, inf, sizeof(D));
	memset(vis, 0, sizeof(vis));

	D[s][0] = 0;
	priority_queue<State> Q;
	Q.push(State(s, 0, D[s][0]));

	while (!Q.empty()) {
		State cur = Q.top();
		Q.pop();
		int u = cur.u;
		int l = cur.l;
		if (vis[u][l]) continue;
		vis[u][l] = 1;

		for (int i = 0; i < G[u].size(); i++) {
			int v = G[u][i].first, w = G[u][i].second;
			if (w > l) continue;
			if (D[v][l-w] > D[u][l]) {
				D[v][l-w] = D[u][l];
				Q.push(State(v, l-w, D[v][l-w]));
			}
		}

		if (l < c && D[u][l+1] > D[u][l] + P[u]) {
			D[u][l+1] = D[u][l] + P[u];
			Q.push(State(u, l + 1, D[u][l+1]));
		}
	}
	return D[e][0];
}

int main (int argc, char *argv[]) {
	while (scanf("%d%d", &N, &M) == 2) {
		init();
		int q, s, e, c;
		scanf("%d", &q);
		while (q--) {
			scanf("%d%d%d", &c, &s, &e);
			int ans = dijkstra(s, e, c);
			if (ans == inf) printf("impossible\n");
			else printf("%d\n", ans);
		}
	}
	return 0;
}
