
#include <iostream>
#include <utility>      // std::swap
#include <math.h>
using namespace std;
typedef long long ll;
#include <string>
#include <stdio.h>
#include <iostream>
string turn(string S, int n){//turn and reverse first n strings
    string plus="+";
    string minus="-";
    for(int i=0;i<n;i++){
        if(S[i]==plus[0]){
            S[i]=minus[0];
        }
        else{
            S[i]=plus[0];
        }
    }
    string tmp=S;
    for(int i=0;i<n;i++){
        S[i]=tmp[n-i-1];
    }
    return S;
}
int judge(string S,int num,string plus, string minus){
    int end_index1=1;
    for(int i=0;i<int(S.length());i++){
        if(S[i]!=plus[0]){
            end_index1=0;
        }
    }
    int end_index2=1;
    for(int i=0;i<int(S.length());i++){
        if(S[i]!=minus[0]){
            end_index2=0;
        }
    }
    if(end_index1==1){
        return num+0;
    }
    else if(end_index2==1){
        return num+1;
    }
    else{
        return -1;
    }
}
int positon(string S){
    string target;
    target=S[0];
    int num=-1;
    bool index=false;
    for(int i=int(S.length())-1;i>=0;i--){
        if(S[i]!=target[0] and index==false){
            index=true;
            num=i;
        }
        if(S[i]==target[0] and index==true){
            num=i+1;
            break;
        }
    }
    return num;
}
int main() {
    string S="--+-";
    string plus="+";
    string minus="-";
    
 
    int count=0;
    int num;
    while(judge(S,count,plus,minus)==-1){
        num=positon(S);
        S=turn(S,num);
        count+=1;
    }
    if(judge(S,count,plus,minus)!=-1){
        cout<< judge(S,count,plus,minus)<<"\n";
    }
    
    
    
    cout << S <<"\n";
    
    return 0;
}