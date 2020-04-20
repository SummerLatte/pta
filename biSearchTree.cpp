#include<iostream>
#include<stdio.h>

using namespace std;

typedef struct Node{
    struct Node *l;
    struct Node *r;
    int val;
}node, *nodep;

int l1,l2;
int n1=0,n2=0;

nodep insert(nodep root, int val){
    if(root==NULL){
        root = new Node();
        root->l=NULL;
        root->r=NULL;
        root->val=val;
    }
    else if(val <= root->val){
        root->l = insert(root->l, val);
    }
    else
    {
        root->r = insert(root->r, val);
    }
    return root;
}

int getHight(nodep root){
    if(root==NULL){
        return 0;
    }
    int l=getHight(root->l);
    int r= getHight(root->r);
    return max(l, r) + 1;
}

void walk(nodep root, int depth){
    if(root==NULL){
        return;
    }
    if(depth==l1){
        n1++;
    }else if(depth==l2){
        n2++;
    }

    walk(root->l, depth+1);
    walk(root->r, depth+1);
}

int main(){
    int n;
    nodep root=NULL;
    cin>>n;
    for(int i=0;i<n;i++){
        int v;
        cin>>v;
        root = insert(root, v);
    }
    int h = getHight(root);
    l1=h;
    l2=h-1;
    walk(root, 1);
    printf("%d + %d = %d", n1, n2, n1+n2);
}