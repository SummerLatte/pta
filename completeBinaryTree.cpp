#include<stdio.h>
#include<unordered_map>
#include<vector>
#include<string>
#include<iostream>
#include<queue>

using namespace std;
int dl[21];
int dr[21];
unordered_map<int, int> hashm;
int root;
queue<int> tq;

int main(){


    int n;
    scanf("%d", &n);
    int tmp;
    for(int i=0;i<n;i++){
        string a,b;
        int c,d;
        cin>>a>>b;
        if(a=="-"){
            c=-1;
        }else
        {
            c=stoi(a);
            tmp=c;
        }
        if(b=="-"){
            d=-1;
        }
        else
        {
            d=stoi(b);
            tmp=d;
        }
        
        dl[i]=c;
        dr[i]=d;
        hashm[c]=i;
        hashm[d]=i;
    }
    while(hashm.find(tmp)!=hashm.end()){
        tmp=hashm[tmp];
    }
    root=tmp;

    tq.push(root);
    bool isc=true;
    bool  lstat=false;
    while (!tq.empty())
    {
        tmp=tq.front();
        tq.pop();
        if(dl[tmp]!=-1){
            tq.push(dl[tmp]);
            if(lstat){
                isc=false;
            }
        }
        else
        {
            lstat=true;
        }
        if(dr[tmp]!=-1){
            tq.push(dr[tmp]);
            if(lstat){
                isc=false;
            }
        }
        else
        {
            lstat=true;
        }
    }

    if(isc){
        cout<<"YES "<<tmp;
    }else
    {
        cout<<"NO "<<root;
    }
    
    
}