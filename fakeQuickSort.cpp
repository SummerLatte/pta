#include<iostream>
#include<vector>
#include<algorithm>

int maxa[100005];
int mina[100005];

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> nv;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        nv.push_back(tmp);
    }
    int max= nv[0];
    int min= nv[n-1];
    for(int i=1;i<n;i++){
        if(nv[i-1]>max){
            max=nv[i-1];
        }
        maxa[i]=max;
    }
    maxa[0]=-1;
    for(int i=n-2;i>=0;i--){
        if(nv[i+1]<min){
            min = nv[i+1];
        }
        mina[i]=min;
    }
    mina[n-1]=1000000000;
    int cnt=0;
    vector<int> ret;
    for(int i=0;i<n;i++){
        if(nv[i]>maxa[i] && nv[i]<mina[i]){
            cnt++;
            ret.push_back(nv[i]);
        }
    }
    sort(ret.begin(), ret.end());
    cout<<cnt<<endl;
    for(int i=0;i<ret.size();i++){
        if(i==0){
            cout<<ret[i];
        }
        else
        {
            cout<<" "<<ret[i];
        }
    }
    cout<<endl;
}