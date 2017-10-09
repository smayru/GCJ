#include <iostream>
#include <utility>      // std::swap
#include <math.h>
using namespace std;
typedef long long ll;
#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>


int main() {
    int  K=110011;
    string S=to_string(K);
    int n=S.length();
    int count=0; //ans
    int num=0;
    for(int i=0;i<n;i++){
        if(i>num){
            count+=i-num;
            num+=i-num;
        }
        int tmp=S[i]-'0';
        num+=tmp;
       
    }
    cout<<count<<"\n";
    return 0;
}
