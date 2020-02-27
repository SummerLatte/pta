#include<vector>
#include<unordered_map>
#include<algorithm>
#include<iostream>
#include<cmath>

using namespace std;


typedef struct  Node
{
    string name;
    int gp,gm,gf,g;
} node;

bool cmp(node a, node b){
    return a.g!=b.g?a.g>b.g:a.name<b.name;
}

int main(){
    int p,m,n;
    cin>>p>>m>>n;
    unordered_map<string, node> imap;
    for(int i=0;i<p;i++){
        string name;
        int gp;
        cin>>name>>gp;
        if(gp<200) continue;
        imap[name] = node{name, gp, -1, -1,-1};
    }
    for(int i=0;i<m;i++){
        string name;
        int gm;
        cin>>name>>gm;
        if(imap.find(name)==imap.end()) continue;
        imap[name].gm=gm;
    }
    for(int i=0;i<n;i++){
        string name;
        int gf;
        cin>>name>>gf;
        if(imap.find(name)==imap.end()) continue;
        imap[name].gf = gf;
        if(imap[name].gm>imap[name].gf){
            imap[name].g=round((float)imap[name].gm*0.4+(float)imap[name].gf*0.6);
        }
        else imap[name].g = imap[name].gf;
    }
    vector<node> res;
    for(auto& v:imap){
        if(v.second.g<60) continue;
        res.push_back(v.second);
    }
    sort(res.begin(), res.end(), cmp);
    for(int i=0;i<res.size();i++){
        printf("%s %d %d %d %d\n", res[i].name.c_str(),res[i].gp,res[i].gm,res[i].gf,res[i].g);
    }
}
