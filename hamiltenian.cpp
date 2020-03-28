#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

int arr[202][202];

int main(){
    int n,m;
    cin>>n>>m;
    int visit[202];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        arr[a][b] = arr[b][a] = 1;
    }
    int cnt;
    cin>>cnt;
    for(int i=0;i<cnt;i++){
        int num;
        int start,end;
        int last;
        bool succ = true;
        cin>>num;
        memset(visit, 0, sizeof(visit));
        for(int j=0;j<num;j++){
            int val;
            cin>>val;
            if(j==0){
                start = val;
                last = val;
                continue;
            }
            if(arr[last][val]==0){
                succ=false;
            }
            if(j==num-1){
                end = val;
            }
            if(visit[val]==1){
                succ=false;
            }
            if(val<1||val>n){
                succ=false;
            }
            visit[val]=1;
            last = val;
        }
        if(start != end || num!=(n+1)){
            succ = false;
        }
        printf("%s\n", succ?"YES":"NO");
    }
}