
#include <iostream>
#include <utility>      // std::swap
#include <math.h>
using namespace std;
typedef long long ll;
#include <string>
#include <stdio.h>
#include <iostream>
ll solve(ll M){
    bool check[10];
    for(int i=0;i<10;i++){
        check[i]=false;
    }
    for(int i=1;i<100000;i++){
        ll tmp=M*i;
        while(tmp!=0){
            int w=tmp%10;
            tmp=tmp/10;
            check[w]=true;
        }
        for(int j=0;j<10;j++){
            if(check[j]!=true){
                break;
            }
            if(j==9){
                return M*i;
            }
        }
    }
    return -1;
    
}
int main() {
    
    int N=1692;
    if(N==0){
        cout << "INSOMNIA" << "\n";
    }
    else if (solve(N)==-1){
        cout << "INSOMNIA" << "\n";
    }
    else;
        cout << solve(N) << "\n";
    
    return 0;
}