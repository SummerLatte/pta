#include<vector>
#include<iostream>

using namespace std;

int main(){
    int g[210][210];
    int v,e,m,n,c;

    cin>>v>>e;

    for (int i = 0; i < e; i++)
    {
        cin>>m>>n;
        g[m][n] = g[n][m] = 1;
    }
    
    cin>>c;
    for (int i = 0; i < c; i++)
    {
        cin>>m;
        vector<int> cv(m);
        bool isC=true, isM= true;
        int hash[210] = {0};
        for (int j = 0; j < m; j++)
        {
            cin>>cv[j];
            hash[cv[j]] = 1;
        }
        
        for (int j = 0; j < m; j++)
        {
            if(isC == false) break;
            for (int k = j+1; k < m; k++)
            {
                if(g[cv[j]][cv[k]]==0){
                    isC = false;
                    break;
                }
            }
        }

        if(isC==false){
            cout<<"Not a Clique"<<endl;
            continue;
        }
        
        int k;
        for (int j = 1; j < v; j++)
        {
            if(hash[j]==0){
                for (k = 0; k < m; k++)
                {
                    if(g[j][cv[k]] == 0) break;
                }
                if(k == m){isM = false;}
            }
        }

        if(isM==false){
            cout<<"Not Maximal"<<endl;
            continue;
        }
        cout<<"Yes"<<endl;
    }
    
}