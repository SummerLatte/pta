#include <iostream>
#include <vector>
using namespace std;
vector<int> pre, in;
bool flag = false;
void postOrder(int prel, int inl, int inr){
    if(flag || inl > inr) return;
    int i = inl;
    while(pre[prel] != in[i]) i++;
    postOrder(prel + 1, inl, i-1);
    postOrder(prel + 1 + i - inl, i+1, inr);
    if(!flag){
        printf("%d", in[i]);
        flag = true;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    pre.resize(n);
    in.resize(n);
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    postOrder(0, 0, n-1);
    return 0;
}