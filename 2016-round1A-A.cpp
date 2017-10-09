#include <iostream>
#include <utility>      // std::swap
#include <math.h>
using namespace std;
typedef long long ll;
#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>

#define max_num 1000


int main() {
    string S="CABCBBABC";
    int n=S.size();
    string ans;
    ans=S[0];
    char tmp=ans[0];
    for(int i=1;i<n;i++){
        if(S[i]>=tmp){
            string tmp_string;
            tmp_string=S[i];
            ans=S[i]+ans;
        }
        else{
            ans=ans+S[i];
        }
    }
    
    cout << ans << "\n";
    return 0;
}
