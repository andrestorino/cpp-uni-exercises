#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<cmath>
#include<stdio.h>
using namespace std;
long long n, k;
long long ans;
long long a[1000000];
int main(int argc, char *argv[]) {
    scanf("%lld %lld", &n, &k);
    ans = -1;
    long long top = 0;
    long long nn = sqrt(double(n));
    long long i;
    for (i = 1; i <= nn; i++) {
        if (n % i == 0) {
            a[top++] = i;
        }
        if (top == k) {
            ans = i;
            break;
        }
    }
    if (ans == -1) {
        bool f = 0;
        long long top1 = top;
        if (nn * nn == n) top1--;
        for (i = top - 1; i >= 0; i--) {
            top1++;
            if (top1 == k) {
                f = 1;
                break;
            }
        }
        if (f) ans = n / a[i];
    }
    printf("%lld", ans);
    return 0;
}
