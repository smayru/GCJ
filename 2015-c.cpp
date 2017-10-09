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
int calmax(string S,int n){
    int z[n];
    for(int i=0;i<n;i++){
        z[i]=S[i]-'0';
    }
    int *mx = max_element(z, z+n);
    return *mx;
}
int cal(int n,string S, int thres){
    int time =thres;
    int max=calmax(S, n);
    if(max<=thres){
        time=time;
    }
    else{
        while(max>thres){
            for(int i=0;i<n;i++){
                if(S[i]-'0'>thres){
                    S[i]=(S[i]-thres);
                    time +=1;
                }
            }
            max=calmax(S, n);
        }
    }
    return time;
}


int main() {
    int  n=4;
    string S="3434";
    
 
    int tmp=max_num;
    for(int thres=1;thres<100;thres++){
        int tmp_val=cal(n,S,thres);
        if(tmp>tmp_val){
            tmp=tmp_val;
        }
    }
    cout<<tmp<<"\n";

    return 0;
}
