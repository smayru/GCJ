
#include <iostream>
#include <utility>      // std::swap
#include <math.h>
using namespace std;
typedef long long ll;
#include <string>
#include <stdio.h>
#include <iostream>

int main() {
    
    int n=3;
    
    int digit=0;
    int tmp_num=n;
    while(tmp_num!=0){
        tmp_num=tmp_num/10;
        digit+=1;
    }
    int value_n[digit];
    int tmp;
    tmp_num=n;
    for(int i=0;i<digit;i++){
        tmp=tmp_num%10;
        value_n[digit-i-1]=tmp;
        tmp_num=tmp_num/10;
        
    }
    int Flag[digit];
    for(int i=0;i<digit;i++){
        Flag[i]=0;
    }
    Flag[0]=1;
    for(int i=1;i<digit;i++){
        if(value_n[i]>value_n[i-1]){
            Flag[i]=1;
        }
        else if(value_n[i]<value_n[i-1]){
            Flag[i]=-1;
        }
    }
    int wh_flag=0;
    int tmp_flag=0;
    for(int i=0;i<digit;i++){
        if(Flag[i]>0){
            wh_flag=1;
            tmp_flag=i;
        }
        else if(Flag[i]==-1){
            break;
        }
    }
    int prod =1;
    for(int i=0;i<digit;i++){
        prod*=Flag[i];
    }
    if(wh_flag==1 and prod<0){
        value_n[tmp_flag]-=1;
    }
    for(int i=tmp_flag+1;i<digit;i++){
        value_n[i]=9;
    }
    int ans=0,tmp_digit=1;
    for(int i=0;i<digit;i++){
        ans+=tmp_digit*value_n[digit-i-1];
        tmp_digit*=10;
    }
    cout << ans << "\n";
    
    
    return 0;
}