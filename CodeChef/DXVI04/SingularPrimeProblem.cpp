#include <iostream>

using namespace std;
bool isPrime(int N) {
    if (N > 2 && N % 2 == 0) return false;
    for (int i = 3; i * i <= N; i += 2)
        if (N % i == 0) return false;
    return true;
}

int singleDigit(int n) {
    int d = 0;
    while (n / 10 > 0) {
        d += n % 10;
        n /= 10;
    }
    d += n;
    if (d >= 10) d = singleDigit(d);
    return d;
}

int previousPrime(int n) {
    if (n == 1) return 2;
    if (n % 2 == 0) n -= 1;
    while (!isPrime(n)) n -= 2;
    return n;
}

int main(int argc, char *argv[]) {
    int T, L, U;
    int primes[1230];
    int counter;

    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> L >> U;
        counter = 0;
        for (int p = L; p <= U; p++) {
            if (isPrime(p)) primes[counter++] = p;
        }
        for (int i = 0; i < counter; i++) {
            primes[i] = singleDigit(primes[i]);
            if (primes[i] == 1) primes[i] = 2;
            if (!isPrime(primes[i]))
                primes[i] = previousPrime(primes[i]);
            cout << primes[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
