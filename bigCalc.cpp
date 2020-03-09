#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct bigInt
{
    int dig[1000];
    int len;

    bigInt(){
        memset(dig, 0, sizeof(dig));
        len = 0;
    }
    void print(){
        for(int i=0;i<len;i++){
            cout<<dig[len-1-i];
        }
    }
};

bigInt change(string val){
    bigInt bi;
    bi.len=val.length();
    for(int i=0;i<val.length();i++){
        bi.dig[val.length()-i-1] = val.at(i) - '0';
    }
    return bi;
}

bigInt add(bigInt a, bigInt b){
    bigInt res;
    int carry=0;
    int sum;
    for(int i=0;i<a.len||i<b.len;i++){
        sum = a.dig[i] + b.dig[i] + carry;
        res.dig[i] = sum % 10;
        carry = sum / 10;
        res.len++;
    }
    if(carry>0){
        res.dig[res.len]=1;
        res.len++;
    }
    return res;
}

int main(){
    bigInt bi= change("1234567890123");
    bigInt ai= change("9234567890123");
    bigInt sum = add(ai, bi);
    sum.print();
    cout<<"end";
}