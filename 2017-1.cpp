#include <iostream>
#include <utility>      // std::swap
#include <math.h>
using namespace std;
typedef long long ll;
#include <string>
#include <stdio.h>
#include <iostream>


string flip(string tmp,int K,string plus, string minus){
    for(int i=0;i<K;i++){
        if(tmp[i]==plus[0]){
            tmp[i]=minus[0];
        }
        else{
            tmp[i]=plus[0];
        }
    }
    
    return tmp;
}
int main() {
    string  str="-+-+-";
    int K=4;
    
    
    int count=0;
    string plus="+";
    string minus="-";
    
    string tmp;
    string tmp_str;
    int flag=1;
    int g;
    g=str.size();
    for(int i=0;i<g-K+1;i++){
        tmp=str.substr(i,K);
        if(tmp[0]==minus[0]){
            count+=1;
            tmp_str=flip(tmp,K,plus,minus);
            for(int j=0;j<K;j++){
                str[i+j]=tmp_str[j];
            }
        }
    }
    for(int i=0;i<g;i++){
        if(str[i]==plus[0]){
            flag=flag*1;
        }
        else{
            flag=flag*0;
        }
    }
    if(flag==1){
        cout<<str <<"\n";
    }
    else{
        cout<<"IMPOSSIBLE" <<"\n";
    }
    return 0;
}
