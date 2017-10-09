#include <iostream>
#include <utility>      // std::swap
#include <math.h>
using namespace std;
typedef long long ll;
#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>

#define max_num 1000
#define N 10
int search_f(int start,int A[][N],int Forward[],int Visited[]){
    stack<int> st;
    Visited[start]=1;
    
    st.push(start);
    int valid=0;
    int const_value=0;
    int last=start; // one stap before
    while(st.size()>0){
        int node=st.top();
        Visited[node]=1;
        st.pop();
        int tmp=-1;
        if(A[node][last]==1){
            valid=1;
        }
        else{
            valid=0;
        }
        if(valid==0){
            for(int i=0;i<N;i++){
                if(Visited[i]==0 and i!=node and A[node][i]==1){
                    tmp=i;
                }
            }
        }
        else{
            for(int i=0;i<N;i++){
                if(Visited[i]==0 and i!=node and A[node][i]==1){
                    tmp=i;
                }
            }
            for(int i=0;i<N;i++){
                if(A[i][node]==1 and Visited[i]==0 and i!=node){
                    tmp=i;
                }
            }
        }
        if(tmp>=0){
            st.push(tmp);
        }
        last=node;
        const_value+=1;
    }

    return const_value;
}
int main() {
    
    int A[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            A[i][j]=0;
        }
    }
    int Forward[N]={7,8,10,10,9,2,9,6,3,3};
    for(int i=0;i<N;i++){
        Forward[i]-=1;
    }
    for(int i=0;i<N;i++){
        A[i][Forward[i]]=1;
    }
    int Visited[N];
    for(int i=0;i<N;i++){
        Visited[i]=0;
    }
    int ans=-1;
    for(int i=0;i<N;i++){
        int tmp=search_f(i,A,Forward,Visited);
        if(tmp>ans){
            ans=tmp;
        }
    }
    
    cout<<ans<<"\n" ;

    
    
    return 0;
}
