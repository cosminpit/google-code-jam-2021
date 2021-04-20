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
        
        int k = n;
        while (k >= 3) {
            int x = ask(a[1], a[2], a[3]);
            if (x == -1) return 0;
            int i = (x == a[1]) ? 1 : ((x == a[2]) ? 2 : 3);
            swap(a[i], a[3]);
            swap(a[3], a[k--]);
        }
        
        random_shuffle(a.begin() + 3, a.end());
        swap(a[2], a[n]);

        for (int i = 3; i < n; i++) {
            int lo = 2, hi = i;
            while (lo < hi) {
                int mid = (lo + hi)/2;
                int x = ask(a[1], a[mid], a[i]);
                if (x == -1) return 0;
                if (x == a[mid]) {
                    lo = mid + 1;
                } else {
                    hi = mid;
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
