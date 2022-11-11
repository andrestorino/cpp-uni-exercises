#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 505

char str[MAXN];
int sta[MAXN], stop, cnt[MAXN];

int main(int argc, char *argv[]) {
    int ncase;
	
    scanf("%d", &ncase);
    for (int hh = 1; hh <= ncase; ++hh) {
        scanf("%s", str);
        stop = 0;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; str[i]; ++i) {
            if (stop == 0 || sta[stop - 1] != str[i]) {
                ++cnt[stop ? sta[stop-1] : 0];
				sta[stop++] = str[i];
				++cnt[sta[stop - 1]];
			}
            else --stop;
        }
        --cnt[sta[0]];
        printf("Case %d\n", hh);
        for (int i = 'A'; i <= 'Z'; ++i)
            if (cnt[i])
                printf("%c = %d\n", i, cnt[i]);
    }
    return 0;
}
