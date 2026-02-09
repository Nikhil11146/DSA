#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x, y;
        cin >> n >> x >> y;
        vector<ll> a(n);
        ll sum = 0, res = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += (a[i]/x)*y;
        }

        for(int i = 0; i < n; i++) {
            res = max(res, a[i] + sum - (a[i]/x)*y);
        }
        cout << res << endl;
    }
}