#include<iostream>
#include<vector>
#include<map>

using namespace std;
map<int, bool> mp;

int main(){
    int p, n;

    cin>>p>>n;
    vector<int> pre(n);
    
    for(int i=0;i<n;i++){
        cin>>pre[i];
        mp[pre[i]] = true;
    }

    for (int i = 0; i < p; i++)
    {
        int u,v,a;
        cin>>u>>v;
        for (int j = 0; j < n; j++)
        {
            a = pre[j];
            if((u<=a&&v>=a) || (u>=a&&v<=a) ){
                break;
            }
        }
        if(mp[u]==false&&mp[v]==false){
            printf("ERROR: %d and %d are not found.\n", u, v);
        }
        else if (mp[u]==false || mp[v]==false)
        {
            printf("ERROR: %d are not found.\n", mp[u]==false?u:v);
        }
        else if(a==u || v==a){
            printf("%d is an ancestor of %d.\n", a, a==u?v:u);
        }
        else{
            printf("LCA of %d and %d is %d.\n", u, v, a);
        }
    }
    return 0;
    
}