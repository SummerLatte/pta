#include<iostream>
#include<string.h>

using namespace std;

int needa[256];

int main(){
    memset(needa, 0, sizeof(needa));

    string a,b;

    cin>>a>>b;
    int len;
    for(int i=0;i<b.length();i++){
        needa[b[i]]++;
    }

    int overCnt=0,lessCnt=b.length();
    char now;
    for(int i=0;i<a.length();i++){
        if(needa[a[i]]>0){
            needa[a[i]]--;
            lessCnt--;
        }
        else
        {
            overCnt++;
        }
        
    }

    if(lessCnt==0){
        printf("Yes %d", overCnt);
    }else
    {
        printf("No %d", lessCnt);
    }
    
}
