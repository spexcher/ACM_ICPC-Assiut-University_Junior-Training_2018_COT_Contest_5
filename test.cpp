#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

unordered_map<pair<int, int>, int> memo;

int mex(unordered_set<int>& s) {
    int i = 0;
    while (s.find(i) != s.end()) {
        i++;
    }
    return i;
}

int Nimber(int R, int G) {
    if (R == 0 && G == 0) return 0;
    if (memo.find({R, G}) != memo.end()) return memo[{R, G}];
    
    unordered_set<int> moves;
    for (int r = 0; r < R; r++) {
        moves.insert(Nimber(r, G));
    }
    for (int g = 0; g < G; g++) {
        moves.insert(Nimber(R, g));
    }
    for (int r = 0; r < R; r++) {
        for (int g = 0; g < G; g++) {
            moves.insert(Nimber(r, g) ^ Nimber(R-r-1, G-g-1));
        }
    }
    int result = mex(moves);
    memo[{R, G}] = result;
    return result;
}

string winner(int R, int G) {
    if (Nimber(R, G) == 0) {
        return "Barkat";
    } else {
        return "Abou Trika";
    }
}

int main() {
    int R = 3;
    int G = 2;
    cout << winner(R, G) << endl;
    return 0;
}
