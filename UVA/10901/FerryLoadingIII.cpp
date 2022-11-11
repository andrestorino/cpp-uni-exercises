#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <tuple>
#include <utility>

int main(int argc, char *argv[]) {
  int c, n, t, m, a;
  std::string lr;
  // id, arrival time, left or right
  std::vector<std::tuple<int, int, char>> input;
  // id, finish time
  std::vector<std::pair<int, int>> output;
  // id
  std::vector<int> ferry;

  input.reserve(10000);
  output.reserve(10000);
  ferry.reserve(10000);
  std::cin >> c;
  for (int i = 0; i < c; ++i) {
    input.clear();
    std::cin >> n >> t >> m;
    for (int j = 0; j < m; ++j) {
      std::cin >> a >> lr;
      if (lr.compare("left") == 0)
        input[j] = std::make_tuple(j, a, 'L');
      else
        input[j] = std::make_tuple(j, a, 'R');
    }
    ferry.clear();
    output.clear();
    std::queue<int> left, right;
    int time = std::get<1>(input[0]);
    char pos = 'L';
    int j = 0;
    while (output.size() < m) {
      if (j < m && time >= std::get<1>(input[j])) {  // Process input
        if (std::get<2>(input[j]) == 'L')
          left.push(std::get<0>(input[j++]));
        else
          right.push(std::get<0>(input[j++]));
      }
      else {  // Attempt to unload/load and Travel or Wait
        if (!ferry.empty()) {  // Load
          for (int k = 0; k < ferry.size(); ++k)
            output.push_back(std::make_pair(ferry[k], time));
          ferry.clear();
        }
        if (pos == 'L') {  // Unload
          if (!left.empty()) {
            int cnt = std::min((int)left.size(), n);
            for (int k = 0; k < cnt ; ++k) {
              ferry.push_back(left.front());
              left.pop();
            }
          }
        }
        else {
          if (!right.empty()) {
            int cnt = std::min((int)right.size(), n);
            for (int k = 0; k < cnt ; ++k) {
              ferry.push_back(right.front());
              right.pop();
            }
          }
        }
        // Travel
        if (!ferry.empty() || !left.empty() || !right.empty()) {
          time += t;
          if (pos == 'L') pos = 'R';
          else pos = 'L';
        }
        else {  // Wait
          time = std::get<1>(input[j]);
        }
      }
    }
    std::sort(output.begin(), output.end());
    for (int k = 0; k < output.size(); ++k)
      std::cout << output[k].second << std::endl;
    if (i < c - 1) std::cout << std::endl;
  }
  return 0;
}
