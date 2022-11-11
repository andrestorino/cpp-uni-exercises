#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
    int input;
    int N, T;

    while(std::cin >> N) {
        std::vector<int> tracks(50);
        std::vector<std::vector<int>> progDin(50, std::vector<int>(10000));
        std::vector<std::vector<bool>> r(50, std::vector<bool>(10000));
        std::vector<int> solution;
        std::cin >> T;
        for (int i = 1; i <= T; i++) {
            std::cin >> input;
            tracks[i] = input;
        }
        for (int i = 1; i <= T; i++) {
			for (int j = 0; j <= N; j++) {
				progDin[i][j] = progDin[i-1][j];
				if (j >= tracks[i]) {
					if (progDin[i][j] < progDin[i-1][j - tracks[i]] + tracks[i]) {
                        progDin[i][j] = progDin[i-1][j - tracks[i]] + tracks[i];
						r[i][j] = true;
					}
				}
			}
		}
		int aux = N;
		for (int i = T; i > 0; i--) {
			if(r[i][aux]) {
                solution.push_back(tracks[i]);
				aux -= tracks[i];
			}
		}
		for (std::vector<int>::reverse_iterator it = solution.rbegin() ; it != solution.rend(); ++it)
            std::cout << *it << " ";
		std::cout << "sum:" << progDin[T][N] << std::endl;
	}
	return 0;
}
