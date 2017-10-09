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

bool check(string K[],int r,int C){
    bool ans=true;
    string tmp="?";
    for(int i=0;i<C;i++){
        if(K[r][i]==tmp[0]){
            ans=ans*true;
        }
        else{
            ans=ans*false;
        }
    }
    return ans;
}
string fill(string K[], string k,int r,int C){
    string tmp="?";
    string moji;
    int tmp_start=0;
    for(int i=0;i<C;i++){
        if(K[r][i]!=tmp[0]){
            moji[0]=K[r][i];
            int first=tmp_start;
            int end=i;
            for(int j=first;j<=end;j++){
                k[j]=moji[0];
            }
            first=end+1;
        }
    }
    for(int i=0;i<C;i++){
        if(k[i]==tmp[0]){
            if(i>0){
                for(int j=i;j<C;j++){
                    k[j]=k[i-1];
                }
            }
            break;
        }
    }
    return k;
}
int main() {
    int   R=4;
    int   C=3;
    string K[max_num];
    K[0]="G??";
    K[1]="?C?";
    K[2]="??J";
    K[3]="???";
    string k(C,'?');
    for(int r=0;r<R;r++){
        bool ans=check(K,r,C);
        if(ans==false){
            K[r]=fill(K,k,r,C);
        }
        
    }
    int count=0;
    for(int r=0;r<R;r++){
        bool ans=check(K,r,C);
        if(ans==true){
            count+=1;
        }
    }
    
    while(count!=0){
        
        
        for(int r=0;r<R;r++){
            bool ans=check(K,r,C);
            if(ans==true){
                if(r<C-1 and r>0){
                    bool tmp1=check(K,r+1,C);
                    bool tmp2=check(K,r-1,C);
                    if(tmp1==false){
                        K[r]=K[r+1];
                    }
                    else if (tmp2==false){
                        K[r]=K[r-1];
                    }
                }
                else if (r>0){
                    bool tmp2=check(K,r-1,C);
                    if(tmp2==false){
                        K[r]=K[r-1];
                    }
                }
                else if (r<C-1){
                    bool tmp1=check(K,r+1,C);
                    if(tmp1==false){
                        K[r]=K[r+1];
                    }

                }

            }
        }
        count=0;
        for(int r=0;r<R;r++){
            bool ans=check(K,r,C);
            if(ans==true){
                count+=1;
            }
        }
    }
    cout<<"Answer"<<"\n";
    cout<<K[0]<<"\n";
    cout<<K[1]<<"\n";
    cout<<K[2]<<"\n";
    cout<<K[3]<<"\n";
    return 0;
}
