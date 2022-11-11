#include <iostream>
#include <algorithm>
#include <utility>
#include <map>
#include <set>

int main(int argc, char *argv[]){
    int n = 1, c, maximum;
    std::map<std::set<int>, int> myMap;
    std::map<std::set<int>, int>::iterator res;
    std::set<int> mySet;

    std::cin >> n;
    while(n != 0){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 5; j++){
                std::cin >> c;
                mySet.insert(c);
            }
            myMap[mySet]++;
            mySet.clear();
        }
        res = std::max_element(myMap.begin(), myMap.end(),
                               [](const std::pair<std::set<int>, int> &p1, const std::pair<std::set<int>, int> &p2) {
                                return p1.second < p2.second; });
        maximum = res->second;
        for(res = myMap.begin(), c = 0; res != myMap.end(); ++res){
            if(res->second == maximum) c += maximum;
        }
        std::cout << c << "\n";
        myMap.clear();
        std::cin >> n;
    }
    return 0;
}
