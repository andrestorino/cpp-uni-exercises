#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
    int r1, c1, r2, c2;
    int rook = 0, bishop = 0, king = 0;
    
    cin >> r1 >> c1 >> r2 >> c2;
    if (r1 == r2 || c1 == c2) rook = 1; // rook
    else rook = 2;
    if ((r1 + c1) % 2 != (r2 + c2) % 2) bishop = 0; // bishop
    else if (abs(r1 - r2) == abs(c1 - c2)) bishop = 1;
    else bishop = 2;
    king = min(abs(r2 - r1), abs(c2 - c1)) + abs(abs(r2 - r1) - abs(c2 - c1)); // king
    
    cout << rook << " " << bishop << " " << king << endl;
    return 0;
}
