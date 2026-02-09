#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
        for(int i = n - 1; i >= 0; i--) {
            if(i == n - 1) a[i] = max(a[i], b[i]);
            else a[i] = max(max(a[i], a[i+1]), b[i]);
        }
        for(int i = 0; i < n - 1; i++) {
            a[i+1] += a[i];
        }
        while(q--) {
            int l, r, sum = 0;
            cin >> l >> r;
            l--;
            r--;
            if(l > 0) sum = a[r] - a[l-1];
            else sum = a[r];
            cout << sum << " ";

        }
        cout << endl;
    }
}
