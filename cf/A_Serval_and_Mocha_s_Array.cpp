#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    if(!b) return a;
    return gcd(b, a % b);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(gcd(a[i], a[j]) <= 2) {
                    cout << "Yes";
                    goto end;
                } 
            }
        }
        
        cout << "No" << endl;
        continue;
        end:
        cout << endl;
    }
}