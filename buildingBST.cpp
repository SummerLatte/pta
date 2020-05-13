#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

struct node{
    int l,r;
    int val;
};

node dataa[105];
vector<int> datav;
queue<int> q;

int getAmt(int index){
    int cnt=0;
    if(dataa[index].l!=-1){
        cnt+=getAmt(dataa[index].l);
    }
    if(dataa[index].r!=-1){
        cnt+=getAmt(dataa[index].r);
    }
    return cnt+1;
}

void preOrder(int l, int index){
    int Lamt=0;
    if(dataa[index].l!=-1){
        Lamt=getAmt(dataa[index].l);
    }
    dataa[index].val=datav[l+Lamt];
    if(dataa[index].l!=-1){
        preOrder(l,dataa[index].l);
    }
    if(dataa[index].r!=-1){
        preOrder(l+Lamt+1,dataa[index].r);
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        dataa[i].l=a;
        dataa[i].r=b;
    }
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        datav.push_back(c);
    }
    sort(datav.begin(),datav.end());

    preOrder(0,0);

    q.push(0);
    int cnt=0;
    while (!q.empty())
    {
        int tmp=q.front();
        q.pop();
        if(dataa[tmp].l!=-1){
            q.push(dataa[tmp].l);
        }
        if(dataa[tmp].r!=-1){
            q.push(dataa[tmp].r);
        }
        if(cnt==0){
            cout<<dataa[tmp].val;
        }
        else
        {
            cout<<" "<<dataa[tmp].val;
        }
        cnt++;
    }
    
}