#include<iostream>
#include<string.h>
using namespace std;


int dataa[100005];
int adda[100005];
int hasha[100000];

int main(){
    memset(hasha, 0, sizeof(hasha));

    int start,n;
    cin>>start>>n;
    int a,b,c;
    for(int i=0;i<n;i++){
        scanf("%d %d %d", &a, &b, &c);
        adda[a]=c;
        dataa[a]=b;
    }

    int now=start;
    int val;
    int cnt=0;
    while(now!=-1){
        val=dataa[now];
        if(hasha[abs(val)]==0){
            hasha[abs(val)]=1;
            if(cnt==0){
                printf("%05d %d ", now, val);
                cnt++;
            }
            else{
                printf("%05d\n%05d %d ", now, now, val);
            }
        }
        now = adda[now];
    }
    if(cnt!=0){
        printf("-1\n");
    }

    cnt=0;
    now=start;
    // memset(hasha, 0, sizeof(hasha));
    while(now!=-1){
        val=dataa[now];
        if(hasha[abs(val)]==1){
            hasha[abs(val)]=2;
        }
        else
        {
            if(cnt==0){
                printf("%05d %d ", now, val);
                cnt++;
            }
            else{
                printf("%05d\n%05d %d ", now, now, val);
            }
        }
        now = adda[now];
    }
    if(cnt!=0){
        printf("-1\n");
    }
}