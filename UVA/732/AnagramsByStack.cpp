#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

std::string source;
std::string target;
std::vector<char> comp;
std::vector<char> ans;

void permutate(int s, int t) {
    if (t == target.size()) {
        int i;
        for(i = 0; i < ans.size() - 1; i++) {
            std::cout << ans[i] << " ";
        }
        std::cout << ans[i] << std::endl;
        return;
    }

    if (s < source.size()) {
        comp.push_back(source[s]);
        ans.push_back('i');
		permutate(s + 1, t);
		ans.pop_back();
		comp.pop_back();
	}

    if (!comp.empty() && target[t] == comp.back()) {
        char aux = comp.back();
		comp.pop_back();
		ans.push_back('o');
		permutate(s, t + 1);
		ans.pop_back();
		comp.push_back(aux);
    }
}

int main(int argc, char *argv[]) {
    while (std::getline(std::cin, source)) {
        std::getline(std::cin, target);
        if (source.size() != target.size()) {
            std::cout << "[\n]" << std::endl;
        }
        else {
            std::map<char, int> nSource, nTarget;
            for(int i = 0; i < source.size(); i++) {
                nSource[source[i]]++;
                nTarget[target[i]]++;
            }
            if (nSource == nTarget) {   // Ok
                std::cout << "[" << std::endl;
                permutate(0, 0);
                std::cout << "]" << std::endl;
            }
            else {
                std::cout << "[\n]" << std::endl;
            }
        }
    }

    return 0;
}
