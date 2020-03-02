#include<iostream>
#include<vector>

using namespace std;

struct node {
    int val;
    struct node *l, *r;
};

node* build(int v, node* root){
    if(root==NULL){
        root = new node();
        root->val=v;
        root->l=root->r=NULL;
    }
    else if(abs(v) > abs(root->val)) root->r = build(v, root->r);
    else root->l = build(v, root->l);
    return root;
}

bool judgeC(node* root){
    if(root==NULL) return false;
    if(root->val< 0){
        if(root->r!=NULL){
            return root->r->val>0?false:true;
        }
        if(root->l!=NULL){
            return root->l->val>0?false:true;
        }
    }
    return judgeC(root->l) || judgeC(root->r);
}

int getNum(node* root){
    if(root==NULL) return 0;
    int r = getNum(root->r);
    int l = getNum(root->l);
    return root->val>0?max(l, r) + 1:max(l, r);
}

bool judgeB(node* root){
    if(root==NULL) return false;
    int l = getNum(root->l);
    int r = getNum(root->r);
    return (l!=r) || judgeB(root->l) || judgeB(root->r);
}

int main(){
    int cs,nl;
    cin>>cs;
    for(int i=0; i<cs; i++){
        cin>>nl;
        node* root=NULL;
        int val;
        for(int j=0;j<nl;j++){
            cin>>val;
            root = build(val, root);
        }
        if(root->val<0||judgeC(root)||judgeB(root)){
            cout<<"No"<<endl;
        }
        else
        {
            cout<<"Yes"<<endl;
        }
    }
}