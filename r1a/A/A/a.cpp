#include <string>
#include <fstream>
#include <iostream>
using namespace std;

void REDIRECT_STD_IO_TO_FILES(const string &in, const string &out) {
    static ifstream f(in); cin.rdbuf(f.rdbuf());
    static ofstream g(out); cout.rdbuf(g.rdbuf());
}

int fix(string &x, string &y) {
    if (x.size() < y.size()) return 0;
    
    int cnt = 0;
    if (x.size() > y.size()) {
        if (y > x.substr(0, y.size())) {
            while (y.size() < x.size()) {
                y.push_back('0'); cnt++;
            }
        } else if (y == x.substr(0, y.size())) {
            int ny = int(y.size());
            while (y.size() < x.size()) y.push_back('*');
            int i = (int)y.size() - 1;
            while (y[i] == '*' && x[i] == '9') {
                y[i] = x[i]; cnt++; i--;
            }
            if (y[i] == '*') {
                y[i] = x[i] + 1; cnt++;
                for (int j = i + 1; j < y.size(); j++) y[j] = '0';
                i--;
            }
            while (y[i] == '*') {
                y[i] = x[i]; cnt++; i--;
            }
            if (y <= x) {
                for (int j = ny; j < y.size(); j++) y[j] = '0';
            }
        } else {
            while (y.size() < x.size()) {
                y.push_back('0'); cnt++;
            }
        }
    }
    
    if (x >= y) {
        y.push_back('0'); cnt++;
    }
    
    return cnt;
}

int main() {
    REDIRECT_STD_IO_TO_FILES("in.txt", "out.txt");
    int nTests; cin >> nTests;
    for (int test = 1; test <= nTests; test++) {
        int n, cnt = 0; cin >> n;
        string x; cin >> x;
        for (int i = 2; i <= n; i++) {
            string y; cin >> y;
            cnt += fix(x, y);
            x = y;
        }
        cout << "Case #" << test << ": " << cnt << endl;
    }
    return 0;
}
