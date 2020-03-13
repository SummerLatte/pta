#include<vector>
#include<queue>
#include<iostream>
#include<string.h>

using namespace std;

vector<int> in, post;
int tree[35][2], root;
queue<int> q;
vector<int> levelv[35];

void build(int &node, int inl, int inr, int postl, int postr){
    if(inl>inr) return;
    int i=0;
    while(in[i]!=post[postr]){
        i++;
    }
    node=postr;
    build(tree[node][0], inl, i-1, postl, postl+i-inl-1);
    build(tree[node][1], i+1, inr, postl+i-inl, postr-1);
}

void travel(int deep, int index){
    levelv[deep].push_back(post[index]);
    if(tree[index][0]!=0)
    {
        travel(deep+1, tree[index][0]);
    }
    if(tree[index][1]!=0)
    {
        travel(deep+1, tree[index][1]);
    }
}

int main(){
    int nl;
    cin>>nl;
    in.resize(nl+1);
    post.resize(nl+1);
    for(int i=1;i<=nl;i++){
        int num;
        cin>>num;
        in[i]=num;
    }

    for(int i=1;i<=nl;i++){
        int num;
        cin>>num;
        post[i]=num;
    }
    memset(tree, 0, sizeof(tree));
    build(root, 1, nl, 1, nl);
    travel(0, nl);

    cout<<levelv[0][0];
    for(int i=1; i<34; i++){
        if(i%2==1){
            for(int j=0;j<levelv[i].size();j++){
                cout<<" "<<levelv[i][j];
            }
        }
        else
        {
            for(int j=levelv[i].size()-1;j>=0;j--){
                cout<<" "<<levelv[i][j];
            }
        }
        
    }

    return 0;
}