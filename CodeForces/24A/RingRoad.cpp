#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <vector>
using namespace std;
vector<pair<int, int>> a[105];
vector<pair<int, int>> b[105];
int n;
int num;
int now;
void dfs(int x, int pre) {
    if (x == now)
        return;
    if (a[x].size() > 0 && a[x][0].first != pre)
        dfs(a[x][0].first, x);
    else if (a[x].size() > 1 && a[x][1].first != pre)
        dfs(a[x][1].first, x);
    else if (b[x].size() > 0 && b[x][0].first != pre) {
        num += b[x][0].second;
        dfs(b[x][0].first, x);
    }
    else if (b[x].size() > 1 && b[x][1].first != pre) {
        num += b[x][1].second;
        dfs(b[x][1].first, x);
    }
}
int main() {
    int x,y,z;
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y >> z;
        a[x].push_back(make_pair(y, z));
        b[y].push_back(make_pair(x, z));
    }
    int ans = 999999;
    for (int i = 1; i <= n; i++) {
        num = 0;
        now = i;
        if (a[i].size() > 0) {
			num = 0;
			now = i;
            dfs(a[i][0].first, i);
            ans = min(ans, num);
        }
        if(a[i].size() > 1) {
			num = 0;
			now = i;
            dfs(a[i][1].first, i);
            ans = min(ans, num);
        }
        if(b[i].size() > 0) {
            num = 0;
            now = i;
            num += b[i][0].second;
            dfs(b[i][0].first, i);
            ans = min(ans, num);
        }
        if(b[i].size()>1) {
            num = 0;
            now = i;
            num += b[i][1].second;
            dfs(b[i][1].first, i);
            ans = min(ans, num);
        }
    }
    cout << ans << endl;
    
    return 0;
}
