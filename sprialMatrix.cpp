#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

bool cmp(int a, int b){
    return a>b;
}

int main(){
    int row=1,col=1;
    int n;
    cin>>n;
    if(n==1){
        row=1;col=1;
    }
    else
    {
        for(int i=1;i<n;i++){
            if(n%i==0){
                if(i>n/i){
                    break;
                }
                row = n/i;
                col = i;
            }
        }
    }

    vector<int> datav;
    for(int i=0;i<n;i++){
        int d;
        cin>>d;
        datav.push_back(d);
    }

    sort(datav.begin(), datav.end(), cmp);
    
    vector<vector<int>> mv;
    mv.resize(row);
    for(int i=0;i<mv.size();i++){
        mv[i].resize(col,-1);
    }

    //0r 1d 2l 3u
    int i=0,j=0;
    int cnt=0;
    int stat=0;
    while(cnt<n){
        mv[i][j]=datav[cnt];
        cnt++;
        if(stat==0){
            if(j!=col-1 && mv[i][j+1]==-1)
            {
                j=j+1;
                continue;
            }
            else
            {
                stat=1;
            }
        }
        if(stat==1){
            if(i!=row-1 && mv[i+1][j]==-1)
            {
                i++;
                continue;
            }
            else
            {
                stat=2;
            }
        }
        if(stat==2){
            if(j!=0 && mv[i][j-1]==-1)
            {
                j--;
                continue;
            }
            else
            {
                stat=3;
            }
        }
        if(stat==3){
            if(i!=0 && mv[i-1][j]==-1)
            {
                i--;
                continue;
            }
            else
            {
                stat=0;
                j=j+1;
            }
        }
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(j==0){
                cout<<mv[i][j];
            }
            else
            {
                cout<<" "<<mv[i][j];
            }
        }
        cout<<endl;
    }
}