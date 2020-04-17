#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

bool isPrime(int n){
    if(n==1){
        return true;
    }
    else
    {
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
        }
    }
    return true;
}

int main(){
    vector<int> sv(10000,0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int rankn;
        cin>>rankn;
        if(i==0){
            sv[rankn]=1;
        }
        else if(isPrime(i+1)){
            sv[rankn]=2;
        }
        else
        {
            sv[rankn]=3;
        }
    }
    int qn;
    cin>>qn;
    for(int i=0;i<qn;i++){
        int id;
        cin>>id;
        if(sv[id]==1){
            printf("%04d: Mystery Award\n",id);
            sv[id]=4;
        }
        else if (sv[id]==2)
        {
            printf("%04d: Minion\n" ,id);
            sv[id]=4;
        }
        else if (sv[id]==3)
        {
            printf("%04d: Chocolate\n" ,id);
            sv[id]=4;
        }
        else if (sv[id]==4)
        {
            printf("%04d: Checked\n" ,id);
            sv[id]=4;
        }
        else
        {
            printf("%04d: Are you kidding?\n" ,id);
        }
    }
}