#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int ask(int i, int j, int k) {
    cout << i << " " << j << " " << k << endl;
    int x; cin >> x;
    return x;
}

int main() {
    int t, n, q; cin >> t >> n >> q;
    while (t--) {
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) a[i] = i;
        
        for (int i = 3; i <= n; i++) {
            int lo = 1, hi = i;
            while (lo < hi) {
                int m1 = lo + (hi - lo)/3;
                int m2 = hi - (hi - lo + 1)/3;
                if (m2 == i) m1--, m2--;
                int x = ask(a[m1], a[m2], a[i]);
                if (x == -1) return 0;
                if (x == a[m1]) {
                    hi = m1;
                } else if (x == a[m2]) {
                    lo = m2 + 1;
                } else {
                    lo = m1 + 1;
                    hi = m2;
                }
            }
            int x = a[i];
            for (int j = i; j > lo; j--) a[j] = a[j - 1];
            a[lo] = x;
        }
        
        for (int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << endl;
        int x; cin >> x;
        if (x == -1) return 0;
    }
    return 0;
}
