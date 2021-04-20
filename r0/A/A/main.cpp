#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

void REDIRECT_STD_IO_TO_FILES(const string &in, const string &out) {
    static ifstream f(in); cin.rdbuf(f.rdbuf());
    static ofstream g(out); cout.rdbuf(g.rdbuf());
}

int main() {
    REDIRECT_STD_IO_TO_FILES("in.txt", "out.txt");
    int nTests; cin >> nTests;
    for (int test = 1; test <= nTests; test++) {
        int n, ans = 0; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n - 1; i++) {
            int j = (int)(min_element(a.begin() + i, a.end()) - a.begin() + 1);
            reverse(a.begin() + i, a.begin() + j);
            ans += j - i;
        }
        cout << "Case #" << test << ": " << ans << "\n";
    }
    return 0;
}
