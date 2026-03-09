#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n, k, x;
        cin >> n >> k >> x;
        // cout << k*(k-1)/2 << endl;
        if(x <= k*(k-1)/2 || x > n*(n+1)/2) cout << "NO" << endl;
        else cout << "YES" << endl;
        // cout << endl;
    }
}