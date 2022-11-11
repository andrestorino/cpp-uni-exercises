#include <iostream>
#include <cstdlib>

using namespace std;

int F[20001];
int C[101];

int main(int argc, char *argv[]) {
	int t, p, n, sum;
	
	while (cin >> t) {
    	while (t--) {
    		cin >> p >> n;
    		sum = 0;
    		for (int i = 0 ; i < n ; ++i) {
    			cin >> C[i];
    			if (sum < p) sum += C[i];
    		}
    		for (int i = 1 ; i <= sum ; ++i)
    			F[i] = n;
    		F[0] = 0;
    		for (int i = 0 ; i < n ; ++i) {
        		for (int j = sum ; j >= C[i] ; --j) {
        			if (F[j] > F[j - C[i]] + 1) {
        			    F[j] = F[j - C[i]] + 1;
        			}
        		}
    		}
    		int s = p;
    		while (s < sum && F[s] == n) s++;
    		cout << s << " " << F[s] << endl;
    	}
	}
	
	return 0;
}
