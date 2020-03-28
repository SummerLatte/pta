#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef struct Node
{
    int val;
    struct Node *r;
    struct Node *l;
}node, *nodep;

nodep rightRotate(nodep root){
    nodep tmp = root->l;
    root->l = tmp->r;
    tmp->r = root;
    return tmp;
}

nodep leftRotate(nodep root){
    nodep tmp = root->r;
    root->r = tmp->l;
    tmp->l = root;
    return tmp;
}

nodep leftRightRotate(nodep root){
    root->l = leftRotate(root->l);
    return rightRotate(root);
}

nodep rightLeftRotate(nodep root){
    root->r = rightRotate(root->r);
    return leftRotate(root);
}

int getDepth(nodep root){
    if(root==NULL){
        return 0;
    }
    
    return max(getDepth(root->l), getDepth(root->r))+1;
}

nodep insert(nodep root, int v){
    if(root==NULL){
        root = new node();
        root->val = v;
    }
    else
    {
        if(v < root->val){
            root->l = insert(root->l, v);
            int l = getDepth(root->l);
            int r= getDepth(root->r);
            if(l-r>=2){
                if(v >= root->l->val){
                    root = leftRightRotate(root);
                }
                else
                {
                    root = rightRotate(root);
                }
            }
        }
        else
        {
            root->r = insert(root->r, v);
            int l = getDepth(root->l);
            int r= getDepth(root->r);
            if(r-l>=2){
                if(v > root->r->val){
                    root = leftRotate(root);
                }
                else
                {
                    root = rightLeftRotate(root);
                }
            }
        }
    }
    
    return root;    
}

queue<nodep> q;
vector<int> resV;
bool isC=true, after=false;
void levelOrder(){
    while (!q.empty())
    {
        nodep tmp = q.front();
        q.pop();
        resV.push_back(tmp->val);
        if(tmp->l!=NULL){
            if(after)
                isC=false;
            q.push(tmp->l);
        }
        else
        {
            after=true;
        }
        
        if(tmp->r!=NULL){
            if(after)
                isC=false;
            q.push(tmp->r);
        }
        else
        {
            after=true;
        }
    }
}

int main(){
    int cnt;
    cin>>cnt;
    nodep root=NULL;
    for(int i=0;i<cnt;i++){
        int num;
        cin>>num;
        root = insert(root, num);
    }
    q.push(root);
    levelOrder();

    for(int i=0;i<resV.size();i++){
        if(i!=0){
            cout<<" "<<resV[i];
        }
        else
        {
            cout<<resV[i];
        }
    }
    printf("\n%s", isC ? "YES" : "NO");
    return 0;
}