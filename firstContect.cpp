#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<string>

using namespace std;

typedef struct Node{
    int a,b;
}node;

bool cmp(node a, node b){
    return a.a!=b.a?a.a<b.a:a.b<b.b;
}

int main(){
    int cnt,pairs;
    unordered_map<int, bool> pv;
    vector<int> rv[10000];
    cin>>cnt>>pairs;
    for(int i=0;i<pairs;i++){
        string a,b;
        cin>>a>>b;
        if(a.size()==b.size()){
            rv[abs(stoi(a))].push_back(abs(stoi(b))) ;
            rv[abs(stoi(b))].push_back(abs(stoi(a))) ;
        }
        pv[abs(stoi(a))*10000+abs(stoi(b))]=pv[abs(stoi(b))*10000+abs(stoi(a))]=true;
    }
    int cases;
    cin>>cases;
    for (int i = 0; i < cases; i++)
    {
        int a,b;
        cin>>a>>b;
        a=abs(a);
        b=abs(b);
        vector<node> ans;
        for(int j=0; j < rv[a].size(); j++){
            for(int m=0; m < rv[b].size(); m++){
                if(rv[a][j] == b || rv[b][m] == a ) continue;
                if(pv[rv[a][j]*10000+rv[b][m]]){
                    ans.push_back(node{abs(rv[a][j]), abs(rv[b][m])});
                }
            }
        }

        sort(ans.begin(), ans.end(), cmp);

        cout<<ans.size()<<endl;
        for(int j=0; j<ans.size(); j++){
            printf("%04d %04d\n", ans[j].a, ans[j].b);
        }
    }
    return 0;
}