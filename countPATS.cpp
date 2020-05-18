#include<iostream>
#include<string.h>

char dataa[100005];
int tcnt[100005];
long long atcnt[100005];

using namespace std;

int main(){
    memset(dataa, 0, sizeof(dataa));
    memset(tcnt, 0, sizeof(tcnt));
    memset(atcnt, 0, sizeof(atcnt));
    scanf("%s", dataa);

    int len=0;
    for(int i=0;i<100005&&dataa[i]!=0;i++){
        len++;
    }
    int tcount=0;
    for(int i=len-1;i>=0;i--){
        if(dataa[i]=='T'){
            tcount++;
        }
        tcnt[i]=tcount;
    }
    long long atcount=0;
    for(int i=len-1;i>=0;i--){
        if(dataa[i]=='A'){
            atcount+=tcnt[i+1];
        }
        atcnt[i]=atcount;
    }

    long long pats=0;
    for(int i=0;i<100005&&dataa[i]!=0;i++){
        if(dataa[i]=='P'){
            pats+=atcnt[i+1];
        }
        if(pats>1000000007){
            pats=pats%1000000007;
        }
    }
    cout<<pats;
}