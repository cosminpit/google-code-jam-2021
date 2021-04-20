#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstdint>
using namespace std;

void REDIRECT_STD_IO_TO_FILES(const string &in, const string &out) {
    static ifstream f(in); cin.rdbuf(f.rdbuf());
    static ofstream g(out); cout.rdbuf(g.rdbuf());
}

bool canSplit(const vector<int64_t> &p, vector<int64_t> c, int64_t sum, int64_t prod) {
    for (int i = 0; i < p.size(); i++) {
        while (prod % p[i] == 0) {
            prod /= p[i], c[i]--, sum -= p[i];
            if (c[i] < 0 || sum < 0) return false;
        }
    }
    return (sum == 0) && (prod == 1);
}

int main() {
    REDIRECT_STD_IO_TO_FILES("in.txt", "out.txt");
    int nTests; cin >> nTests;
    for (int test = 1; test <= nTests; test++) {
        int             n; cin >> n;
        vector<int64_t> p(n), c(n);
        
        uint64_t sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> p[i] >> c[i];
            sum += c[i]*p[i];
        }
        
        int64_t best = 0;
        for (int s = 2; s < min<int64_t>(63*500, sum); s++) {
            if (canSplit(p, c, s, sum - s)) {
                best = sum - s;
                break;
            }
        }
        cout << "Case #" << test << ": " <<  best << "\n";
    }
    return 0;
}
