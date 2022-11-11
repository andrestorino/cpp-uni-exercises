#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <climits>
#include <cstdlib>

int main(int argc, char *argv[]) {
    int M, i, j, maxDistance;
    std::vector<std::pair<int, int>> threes;
    std::vector<std::pair<int, int>> ones;

    while (std::cin >> M) {
        std::getchar();
        for (i = 0; i < M; i++) {
            std::string input;
            std::getline(std::cin, input);
            for (j = 0; j < M; j++) {
                if (input[j] == '3') threes.push_back(std::make_pair(i, j));
                else if (input[j] == '1') ones.push_back(std::make_pair(i, j));
            }
        }
        maxDistance = 0;
        for (i = 0; i < ones.size(); i++) {
            int localMax = INT_MAX;
            for (j = 0; j < threes.size(); j++) {
                int MH = std::abs(ones[i].first - threes[j].first) +
                        std::abs(ones[i].second - threes[j].second);
                    if (MH < localMax) localMax = MH;
            }
            if (localMax > maxDistance) maxDistance = localMax;
        }
        std::cout << maxDistance << std::endl;
        ones.clear();
        threes.clear();
    }
    return 0;
}
