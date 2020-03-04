#include<vector>
#include<unordered_map>
#include<iostream>

using namespace std;

struct node
{
    int val;
    string next, add;
};

int main(){
    string fadd;
    int l,k;
    cin>>fadd>>l>>k;
    unordered_map<int, node> umap;

    for(int i=0;i<l;i++){
        string add,nadd;
        int value;
        cin>>add>>value>>nadd;

        umap[stoi(add)]=node{value,nadd,add};
    }

    vector<node> nv[3];

    node *np = &umap[stoi(fadd)];
    while (stoi(np->next)!=-1)
    {
        if(np->val<0){
            nv[0].push_back(*np);
        }
        else if(np->val<=k)
        {
            nv[1].push_back(*np);
        }
        else
        {
            nv[2].push_back(*np);
        }
        np=&umap[stoi(np->next)];
    }
    if(np->val<0){
        nv[0].push_back(*np);
    }
    else if(np->val<=k)
    {
        nv[1].push_back(*np);
    }
    else
    {
        nv[2].push_back(*np);
    }

    int flag = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < nv[i].size(); j++) {
            if (flag == 0) {
                printf("%s %d ", nv[i][j].add.c_str(), nv[i][j].val);
                flag = 1;
            } else {
                printf("%s\n%s %d ", nv[i][j].add.c_str(), nv[i][j].add.c_str(), nv[i][j].val);
            }
        }
    }
    printf("-1");

}


int main1(){
    string fadd;
    int l,k;
    cin>>fadd>>l>>k;
    unordered_map<int, node> umap;

    for(int i=0;i<l;i++){
        string add,nadd;
        int value;
        cin>>add>>value>>nadd;

        umap[stoi(add)]=node{value,nadd,add};
    }

    vector<node> nv;
    vector<node> kv;
    vector<node> gkv;

    node *np = &umap[stoi(fadd)];
    while (stoi(np->next)!=-1)
    {
        if(np->val<0){
            nv.push_back(*np);
        }
        else if(np->val<=k)
        {
            kv.push_back(*np);
        }
        else
        {
            gkv.push_back(*np);
        }
        np=&umap[stoi(np->next)];
    }
    if(np->val<0){
        nv.push_back(*np);
    }
    else if(np->val<k)
    {
        kv.push_back(*np);
    }
    else
    {
        gkv.push_back(*np);
    }
    nv.insert(nv.end(),kv.begin(),kv.end());
    nv.insert(nv.end(),gkv.begin(),gkv.end());

    for(int i=0;i<nv.size()-1;i++){
        printf("%s %d %s\n",nv[i].add.c_str(), nv[i].val,nv[i+1].add.c_str());
    }
    printf("%s %d -1",nv[nv.size()-1].add.c_str(), nv[nv.size()-1].val);
}
