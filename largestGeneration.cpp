#include<iostream>
#include<vector>
#include<string.h>
#include<queue>

using namespace std;

vector<vector<int>> datav;
int level[105];
queue<int> q;

void dfs(int lev, int index){
    level[lev]++;
    for(int i=0;i<datav[index].size();i++){
        dfs(lev+1, datav[index][i]);
    }
}


int main(){
    int n,m;
    cin>>n>>m;
    memset(level, 0, sizeof(level));
    datav.resize(n+1);
    for(int i=0;i<m;i++){
        int index,cnt;
        cin>>index>>cnt;
        for(int j=0;j<cnt;j++){
            int child;
            cin>>child;
            datav[index].push_back(child);
        }
    }

    dfs(1,1);

    int max=0,maxg=0;
    for(int i=0;i<105;i++){
        if(max<level[i]){
            max=level[i];
            maxg=i;
        }
    }

    cout<<max<<" "<<maxg;
}