#include<vector>
#include<iostream>
#include<string.h>

using namespace std;
int m,n,l,t;

bool datav[65][1300][200];
int dyev[65][1300][200];

#define MALLL 100000
int parent[MALLL];
int dyecount[MALLL];
int dyeindex=0;

int dir[6][3]={{0,0,1},{0,0,-1},{1,0,0},{-1,0,0},{0,1,0},{0,-1,0}};

int myfind(int a){
    int tmp=a;
    while(parent[a]!=a){
        a=parent[a];
    }
    int par=a;
    while(parent[tmp]!=par){
        a=parent[tmp];
        parent[tmp]=par;
        tmp=a;
    }
    return par;
}

void myunion(int a, int b){
    int pa = myfind(a);
    int pb= myfind(b);

    if(pa!=pb){
        parent[pb]=pa;
    }
}

void dye(int x, int y, int lay){

    if(!datav[lay][y][x]){
        return;
    }
    int ori=dyev[lay][y][x];

    int first=-1;
    int tx,ty,tz;
    for(int i=0;i<6;i++){
        tx=dir[i][0]+x;
        ty=dir[i][1]+y;
        tz=dir[i][2]+lay;

        if(tz<0||tz>=l||tx<0||tx>=n||ty<0||ty>=m){
            continue;
        }
        if(dyev[tz][ty][tx] != -1){
            if(first==-1){
                first=myfind(dyev[tz][ty][tx]);
                if(ori!=-1){
                    myunion(first, ori);
                    ori=first;
                }else
                {
                    ori=first;
                }
            }
            else
            {
                myunion(first, dyev[tz][ty][tx]);
            }
        }
    }

    if(ori==-1){
        ori=dyeindex;
        dyev[lay][y][x]=ori;
        dyeindex++;
    }

    for(int i=0;i<6;i++){
        tx=dir[i][0]+x;
        ty=dir[i][1]+y;
        tz=dir[i][2]+lay;

        if(tz<0||tz>=l||tx<0||tx>=n||ty<0||ty>=m){
            continue;
        }
        if(datav[tz][ty][tx]){
            // if(dyev[tz][ty][tx] == -1){
                dyev[tz][ty][tx]=ori;
            // }
        }
    }
}

int main(){

    cin>>m>>n>>l>>t;
    
    for(int i=0;i<MALLL;i++){
        parent[i]=i;
    }
    memset(dyecount,0,sizeof(dyecount));


    for(int i=0;i<m*l;i++){
        for(int j=0;j<n;j++){
            int d;
            scanf("%d", &d);
            if(d==0){
                datav[i/m][i%m][j]=false;
            }
            else
            {
                datav[i/m][i%m][j]=true;
            }
            dyev[i/m][i%m][j]=-1;
        }
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<l;k++){
                dye(i,j,k);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<l;k++){
                if(dyev[k][j][i]!=-1){
                    dyecount[myfind(dyev[k][j][i])]++;
                }
            }
        }
    }

    long long coreCnt=0;
    for(int i=0;i<MALLL;i++){
        if(dyecount[i]>=t){
            coreCnt=coreCnt+dyecount[i];
        }
    }
    cout<<coreCnt;
}