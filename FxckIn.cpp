#include<vector>
#include<iostream>
#include<stdio.h>

using namespace std;

bool unique = true;
vector<int> pre, post, in;

void inorder(int prel, int prer, int postl, int postr){
    if(prel == prer){
        in.push_back(pre[prel]);
        return;
    }
    if (pre[prel]==post[postr])
    {
        int i = prel+1;
        while(i<=prer && pre[i]!=post[postr-1]){
            i++;
        }
        if(i-prel>1){
            inorder(prel+1, i-1, postl, postl + (i - prel -1) -1);
        }
        else
        {
            unique=false;
        }
        in.push_back(pre[prel]);
        inorder(i, prer, postl + (i - prel -1), postr-1);
    }
}

int main(){
    int n;
    cin>>n;
    for(int i =0; i<n;i++){
        int tmp;
        cin>>tmp;
        pre.push_back(tmp);
    }
    for(int i =0; i<n;i++){
        int tmp;
        cin>>tmp;
        post.push_back(tmp);
    }
    inorder(0, n-1, 0, n-1);
    if(unique){
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
    cout<<endl;

    for(int i =0; i<n;i++){
        if(i==0){
            cout<<in[i];
        }
        else
        {
            cout<<" "<<in[i];
        }
    }
    
    return 0;
}