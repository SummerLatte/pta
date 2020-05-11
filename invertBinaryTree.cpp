#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

vector<vector<int>> datav;
vector<int> hashv;
vector<int> inret;
int root;

void inorder(int root){
    if(datav[root][0]!=-1){
        inorder(datav[root][0]);
    }
    inret.push_back(root);
    if(datav[root][1]!=-1){
        inorder(datav[root][1]);
    }
}

int main(){
    int n,s;
    cin>>n;
    datav.resize(n);
    hashv.resize(n, -1);
    for(int i=0;i<n;i++){
        string a,b;
        cin>>b>>a;
        if(a=="-"){
            datav[i].push_back(-1);
        }
        else
        {
            datav[i].push_back(stoi(a));
            hashv[stoi(a)]=i;
            s=stoi(a);
        }
        if(b=="-"){
            datav[i].push_back(-1);
        }
        else
        {
            datav[i].push_back(stoi(b));
            hashv[stoi(b)]=i;
            s=stoi(b);
        }
    }


    while (hashv[s]!=-1)
    {
        s=hashv[s];
    }
    root = s;

    queue<int> q;
    q.push(root);
    vector<int> retv;
    while (!q.empty())
    {
        int tmp=q.front();
        retv.push_back(tmp);
        q.pop();
        if(datav[tmp][0]!=-1){
            q.push(datav[tmp][0]);
        }
        if(datav[tmp][1]!=-1){
            q.push(datav[tmp][1]);
        }
    }
    cout<<retv[0];
    for(int i=1;i<retv.size();i++){
        cout<<" "<<retv[i];
    }
    cout<<endl;

    inorder(root);
    cout<<inret[0];
    for(int i=1;i<inret.size();i++){
        cout<<" "<<inret[i];
    }

}