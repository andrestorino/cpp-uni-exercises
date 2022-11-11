#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

class UnionFind {
    private:
        vi p;
        vi rank;
    
    public:
        UnionFind(int N) {
            rank.assign(N, 0);
            p.assign(N, 0);
            for (int i = 0; i < N; i++)
                p[i] = i;
        }
        
        int findSet(int i) {
            if (p[i] == i) return i;
            return (findSet(p[i]));
        }
        
        bool isSameSet(int i, int j) {
            return (findSet(i) == findSet(j));
        }
        
        void unionSet(int i, int j) {
            if (!isSameSet(i, j)) {
                int x = findSet(i);
                int y = findSet(j);
                
                if (x > y) swap(x, y);
                p[y] = x;
                /*
                if (rank[x] > rank[y])
                    p[y] == x;
                else {
                    p[x] == y;
                    if (rank[x] == rank[y])
                        rank[y] = rank[y] + 1;
                }*/
            }
        }
};

int main(int argc, char *argv[]) {
    int n, m, u, v, w;
    vector<pair<int, ii>> edges;
    edges.reserve(1000000);
    while (cin >> n >> m, n || m) {
        UnionFind uf(n);
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            edges.push_back(make_pair(w, ii(u, v)));
        }
        sort(edges.begin(), edges.end());
       /* for (int i = 0; i < m; i++) {
            cout << edges[i].first << ":" << edges[i].second.first << " " << edges[i].second.second << endl;
        }*/
        int mst = 0, count = 0;
        for (int i = 0; i < m && count < n - 1; i++) {
            pair<int, ii> front = edges[i];
            if (!uf.isSameSet(front.second.first, front.second.second)) {
                uf.unionSet(front.second.first, front.second.second);
                //cout << "adding " << front.second.first << " " << front.second.second << ":" << front.first << endl;
                mst = max(mst, front.first);
                count++;
                
            }
        }
        if (count == n - 1)
            cout << mst << endl;
        else
            cout << "IMPOSSIBLE" << endl;
        edges.clear();
    }
    return 0;
}
