#include<vector>
#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n;
    int sub=0;
    cin>>n;
    if(n%2!=0){
        sub=1;
    }
    vector<int> nv;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        nv.push_back(tmp);
    }
    sort(nv.begin(),nv.end());
    int sum1=0,sum2=0;
    for(int i=0;i<n/2;i++){
        sum1+=nv[i];
    }
    for(int i=n/2;i<n;i++){
        sum2+=nv[i];
    }
    printf("%d %d", sub, sum2-sum1);
}