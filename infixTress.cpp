#include<iostream>
#include<vector>

using namespace std;

struct node{
    string name;
    int l,r;
    int p=-1;
};

vector<node> tv;

void inTravel(int root, int depth){
    if(depth>1 && tv[root].l != -1 && tv[root].r != -2){
        cout<<"(";
    }
    if(tv[root].l != -2 ){
        inTravel(tv[root].l, depth+1);
    }
    
    cout<<tv[root].name;

    if(tv[root].r != -2){
        inTravel(tv[root].r, depth+1);
    }
    if(depth>1 && tv[root].l != -1 && tv[root].r != -2){
        cout<<")";
    }
}

int main(){
    int l;
    cin>>l;
    for (int i = 0 ; i<l; i++)
    {
        string name;
        int l,r;
        cin>>name>>l>>r;
        tv.push_back(node{name,l-1,r-1,-1});
    }
    for (int i = 0 ; i<l; i++)
    {
        if(tv[i].l!=-1){
            
            tv[tv[i].l].p=i;
        }
        if(tv[i].r!=-1){
            tv[tv[i].r].p=i;
        }
    }
    int root;
    for (int i = 0 ; i<l; i++)
    {
        if(tv[i].p==-1){
            root=i;
        }
    }
    inTravel(root, 1);
    return 0;
}