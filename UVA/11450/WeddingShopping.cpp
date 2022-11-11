#include <iostream>
#include <vector>
#include <cstring>

#define MAX_K 20
#define MAX_C 20
#define MAX_W 200

using namespace std;

int garments[MAX_C][MAX_K + 1];
bool mem[MAX_C][MAX_W];

void clear_vec() {
    for (int i = 0; i < MAX_C; i++) {
	    for (int j = 0; j < MAX_K + 1; j++) {
	        garments[i][j] = 0;
	    }
	}
}

int main(int argc, char *argv[]) {
	int N, M, C, i, j, k;
	
	cin >> N;
	while (N--) {
	    clear_vec();
	    cin >> M >> C;
	    for (j = 0; j < C; j++) {
	        cin >> garments[j][0];
	        for (k = 1; k <= garments[j][0]; k++) {
	            cin >> garments[j][k];
	        }
	    }
	    memset(mem, false, sizeof(mem[0][0]) * MAX_C * MAX_W);
	    for (i = 1; i <= garments[0][0]; i++) {
	        if ((M - garments[0][i]) >= 0) {
                mem[0][M - garments[0][i]] = true;
	        }
	    }
	    for (i = 1; i < C; i++) {
	        for (j = 0; j < M; j++) {
	            if (mem[i - 1][j]) {
	                for (k = 1; k <= garments[i][0]; k++) {
	                    if (j - garments[i][k] >= 0) {
	                        mem[i][j - garments[i][k]] = true;
	                    }
	                }
	            }
	        }
	    }
	    for (j = 0; j <= M && !mem[C - 1][j]; j++);
	    if (j > M) cout << "no solution" << endl;
	    else cout << M - j << endl;
	}
    return 0;
}
