#include<unordered_map>
#include<vector>
#include<iostream>
#include<string.h>

using namespace std;

vector<int> visit(0);


vector<vector<int>> vt;
int vcnt=0;

void bfs(int n){
    visit[n] = 1;
    vcnt++;

    for (int i = 0; i < vt[n].size(); i++)
        if (visit[vt[n][i]] == 0)
            bfs(vt[n][i]);
}

int main(){

    int v,e;
    cin>>v>>e;

    visit.resize(v);
    vt.resize(v + 1);

    unordered_map<int, int> vc;

    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        vc[a]+=1;
        vc[b]+=1;
        vt[a].push_back(b);
        vt[b].push_back(a);
    }

    int ec=0,oc=0;
    cout<<vc[1];
    if(vc[1]%2==0){
        ec++;
    }
    else
    {
        oc++;
    }
    
    for(int i=1;i<v;i++){
        cout<<" "<<vc[i+1];
        if(vc[i+1]%2==0){
            ec++;
        }
        else
        {
            oc++;
        }
    }
    cout<<endl;

    bfs(1);

    if(oc==0 && vcnt==v){
        cout<<"Eulerian";
    }
    else if (oc==2 && vcnt==v)
    {
        cout<<"Semi-Eulerian";
    }
    else
    {
        cout<<"Non-Eulerian";
    }
    return 0;
}