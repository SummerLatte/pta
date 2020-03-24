#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int cnt;
    cin>>cnt;
    vector<int> nv;
    for(int i=0;i<cnt;i++){
        int num;
        cin>>num;
        nv.push_back(num);
    }
    sort(nv.begin(),nv.end());

    double sum=nv[0];
    for(int i=1;i<nv.size();i++){
        sum = sum / 2 + (double)nv[i] / 2;
    }
    cout<<int(sum);
}