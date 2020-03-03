#include<vector>
#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    int m,n,c;
    cin>>n>>m;
    
    vector<vector<int>> vv(n);

    for(int i=0;i<m;i++){
        int ea,eb;
        cin>>ea>>eb;
        vv[ea].push_back(i);
        vv[eb].push_back(i);
    }
    cin>>c;
    for(int i=0;i<c;i++){
        int vn,cnt=0;
        cin>>vn;
        vector<int> nvj(m,0);
        for(int j=0;j<vn;j++){
            int val;
            cin>>val;
            for(int k=0;k<vv[val].size();k++){
                nvj[vv[val][k]]=1;
            }
        }
        for(int j=0;j<m;j++){
            if(nvj[j]==1) cnt++;
        }
        if(cnt != m){
            cout<<"No"<<endl;
        }
        else cout<<"Yes"<<endl;
    }
}