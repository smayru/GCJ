
#include <iostream>
#include <utility>      // std::swap
#include <math.h>
using namespace std;
typedef long long ll;
#include <string>
#include <stdio.h>
#include <iostream>

void cal(int *array,int tmp_min,int tmp_max){
    int tmp_pos_ans=tmp_min+ceil((tmp_max-tmp_min)/2);
    int tmp_max_ans=ceil((tmp_max-tmp_min-1)/2);
    int tmp_min_ans=ceil((tmp_max-tmp_min-2)/2);
    array[0]=tmp_pos_ans;
    array[1]=tmp_min_ans;
    array[2]=tmp_max_ans;
}
int main() {
    
    int N=1000;
    int K=1000;
    
    
    
    int O[N+2];
    int array[3]={};
    for(int i=0;i<N+2;i++){
        O[i]=0;
    }
    O[0]=1;
    O[N+1]=1;
    int ans[3];
    if(N>K){
        for(int i=1;i<=K;i++){
            int L[i][2];
            L[0][0]=0;
            L[i-1][1]=N+1;
            int index=0;
            for(int j=0;j<i;j++){
                for(int l=index+1;l<=N;l++){
                    if(O[l]==1){
                        L[j][1]=l;
                        L[j+1][0]=l;
                        index=l;
                        break;
                    }
                }
            }
            int score[i][3];
            for(int j=0;j<i;j++){
                cal(array,L[j][0],L[j][1]);
                score[j][0]=array[0];
                score[j][1]=array[1];
                score[j][2]=array[2];
            }
    
            int max_1=0;
            int max_2=0;
            for(int j=0;j<i;j++){
                max_1=max(max_1,score[j][1]);
                max_2=max(max_1,score[j][2]);
            }
    
            int num_max_1=0;
            int num_max_2=0;
            for(int j=0;j<i;j++){
                if(score[j][1]==max_1){
                    num_max_1+=1;
                }
                if(score[j][2]==max_2){
                    num_max_2+=1;
                }
            }
        //int ans[3];
            if(num_max_1==1){
                for(int j=0;j<i;j++){
                    if(score[j][1]==max_1){
                        ans[0]=score[j][0];
                        ans[1]=score[j][1];
                        ans[2]=score[j][2];
                    }
                }
            }
            else if(num_max_2==1){
                for(int j=0;j<i;j++){
                    if(score[j][2]==max_2){
                        ans[0]=score[j][0];
                        ans[1]=score[j][1];
                        ans[2]=score[j][2];
                    }
                }
            }
            else{
                for(int j=0;j<i;j++){
                    if(score[j][1]==max_1){
                        ans[0]=score[j][0];
                        ans[1]=score[j][1];
                        ans[2]=score[j][2];
                        break;
                    }
                }
            }
            O[ans[0]]=1;


        }
        cout << ans[2] <<"\t"  <<ans[1] <<"\n" ;
    }
    else{
        cout << 0 <<"\t"  <<0 <<"\n" ;
    }
    
    return 0;
}