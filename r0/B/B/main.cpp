#include <fstream>
#include <iostream>
using namespace std;

void REDIRECT_STD_IO_TO_FILES(const string &in, const string &out) {
    static ifstream f(in); cin.rdbuf(f.rdbuf());
    static ofstream g(out); cout.rdbuf(g.rdbuf());
}

int cost(string &s, int i, int j, int x, int y) {
    int res = 0;
    if (i) i--;
    if (j == s.size()) j--;
    while (i < j) {
        if (s[i] != s[i + 1]) {
            res += (s[i] == 'C') ? x : y;
        }
        i++;
    }
    return res;
}

int best_cost(string &s, int i, int j, int x, int y) {
    char v;
    int c1, c2, c3, c4;
    
    for (int k = i; k < j; k++) s[k] = 'C';
    c1 = cost(s, i, j, x, y);
    
    for (int k = i; k < j; k++) s[k] = 'J';
    c2 = cost(s, i, j, x, y);
    
    v = 'C';
    for (int k = i; k < j; k++) s[k] = v, v = 'C' + 'J' - v;
    c3 = cost(s, i, j, x, y);
    
    v = 'J';
    for (int k = i; k < j; k++) s[k] = v, v = 'C' + 'J' - v;
    c4 = cost(s, i, j, x, y);
    
    return min(min(c1, c2), min(c3, c4));
}

int main() {
    REDIRECT_STD_IO_TO_FILES("in.txt", "out.txt");
    int nTests; cin >> nTests;
    for (int test = 1; test <= nTests; test++) {
        int x, y, ans = 0; cin >> x >> y;
        string s; cin >> s;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '?') {
                int j = i;
                while (j < s.size() && s[j] == '?') j++;
                ans += best_cost(s, i, j, x, y);
                i = j - 1;
            } else if (i + 1 < s.size() && s[i] != s[i + 1] && s[i + 1] != '?') {
                ans += (s[i] == 'C') ? x : y;
            }
        }
        cout << "Case #" << test << ": " << ans << "\n";
    }
    return 0;
}
