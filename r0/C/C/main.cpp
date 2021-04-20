#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

void REDIRECT_STD_IO_TO_FILES(const string &in, const string &out) {
    static ifstream f(in); cin.rdbuf(f.rdbuf());
    static ofstream g(out); cout.rdbuf(g.rdbuf());
}

bool solve(vector<int> &a, int i, int c) {
    if (i == a.size() - 1) {
        a[i] = i + 1;
        return c == 0;
    }
    int n = (int)a.size();
    int j = i + min(n - i, c - (n - i - 2)) - 1;
    if (j < i) return false;
    a[j] = i + 1;
    reverse(a.begin() + i, a.begin() + j + 1);
    if (!solve(a, i + 1, c - (j - i + 1))) return false;
    reverse(a.begin() + i, a.begin() + j + 1);
    return true;
}

int main() {
    REDIRECT_STD_IO_TO_FILES("in.txt", "out.txt");
    int nTests; cin >> nTests;
    for (int test = 1; test <= nTests; test++) {
        int n, c; cin >> n >> c;
        vector<int> a(n);
        cout << "Case #" << test << ": ";
        if (solve(a, 0, c)) {
            for (auto x: a) cout << x << " ";
        } else {
            cout << "IMPOSSIBLE";
        }
        cout << "\n";
    }
    return 0;
}
