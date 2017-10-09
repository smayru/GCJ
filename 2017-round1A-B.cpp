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
    int n=3;
    int p=3;
    int N[]={70,80,90};
    int P[][max_num]={{1260,1500,700},{800,1440,1600},{1700,1620,900}};//N times P
    int Index[n][p]; //takes one if it is used.
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            Index[i][j]=0;
        }
    }
    int min_pack[n][p];
    int max_pack[n][p];
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            min_pack[i][j]=floor(P[i][j]/(N[i]*1.1));
            max_pack[i][j]=floor(P[i][j]/(N[i]*0.9));
        }
    }
    int set_count=0;
    
    for(int tmp=0;tmp<1000;tmp++){
        int valid[n][p];
        for(int i=0;i<n;i++){
            for(int j=0;j<p;j++){
                valid[i][j]=0;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<p;j++){
                if(Index[i][j]==0 and min_pack[i][j]<=tmp and max_pack[i][j]>=tmp){
                    cout<<"selected"<<tmp<<"\n";
                    valid[i][j]=1;
                }
            }
        }

        int comp_set[n];
        for(int i=0;i<n;i++){
            int position_value=max_num;
            int position=-1;
            for(int j=0;j<n;j++){
                if(valid[i][j]==1 and min_pack[i][j]<position_value){
                    position_value=min_pack[i][j];
                    position=j;
                }
            }
            comp_set[i]=position;
            
        }
        int ans=1;
        for(int i=0;i<n;i++){
            if(comp_set[i]<0){
                ans=ans*0;
            }
        }
        if(ans>0){
            for(int i=0;i<n;i++){
                cout<<"position"<<comp_set[i]<<"\n";
            }
        }
        if(ans>0){
            for(int i=0;i<n;i++){
                Index[i][comp_set[i]]=1;
            }
            set_count+=1;
        }
    }
    


    cout<<set_count<<"\n";
    return 0;
}
