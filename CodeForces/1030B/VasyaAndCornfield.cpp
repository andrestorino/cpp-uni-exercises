#include <cstdio>

int main() {
    int n, d, m;
    scanf("%d%d%d", &n, &d, &m);
    while (m--) {
        int x, y;
        scanf("%d%d", &x, &y);
        if ((x+y) >= d && y <= (x+d) && y >= (x-d) && x+y <= (2*n-d)) printf("YES\n");
        else {
            printf("NO\n");
        }
    } 
    return 0;
}
