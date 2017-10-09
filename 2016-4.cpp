#include <iostream>
#include <utility>      // std::swap
#include <math.h>
using namespace std;
typedef long long ll;
#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>

void solve(int K, int C, int S) {
    if (C*S < K) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    vector<ll> ans;
    for (int i = 0; i < K; i += C) {
        ll t[min(K-i,C)];
        for (int j = 0; j < min(K-i,C); j++) {
            t[j]=i+j;
        }
        int tmp=0;
        for (int j = 0; j < min(K-i,C); j++) {
            tmp+=(t[j])*pow(K,C-j-1);
            cout<<(t[j])*pow(K,C-j-1)<<'b'<<"\n";
        }
        ans.push_back(tmp);
    }
    int sz = ans.size();
    for (int i = 0; i < sz; i++) {
        cout << ans[i];
        if (i < sz-1) cout << " ";
    }
    cout << endl;
}

int main() {
    int K=3;
    int C=2;
    int S=3;
    
    solve(K, C, S);
    return 0;
}
