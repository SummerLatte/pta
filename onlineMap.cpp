#include<iostream>
#include<vector>
#include<string.h>
#include<set>
#include<algorithm>

using namespace std;
const int inf = 999999999;
int da[505][505];
int ta[505][505];
int src,des;

vector<int> tmptPath, truetPath;
vector<int> tmpdPath, truedPath;
bool visit[505];
int preDis[505], preTime[505];
int disa[505], timea[505];
int speeda[505], nodea[505];

void dfsd(int u){
    truedPath.push_back(u);
    if(u==src){
        return;
    }
        dfsd(preDis[u]);
}

void dfst(int u){
        truetPath.push_back(u);
    if(u==src){
        return;
    }
        dfst(preTime[u]);
}

int main(){
    int n,m;
    // fill(timea, timea+505, inf);
    // fill(disa, disa+505, inf);
    memset(timea,0x3f,sizeof(timea));
    memset(disa,0x3f,sizeof(disa));
    memset(speeda, 0x3f, sizeof(speeda));
    memset(nodea, 0, sizeof(nodea));
    memset(da,0x3f,sizeof(da));
    memset(ta,0x3f,sizeof(ta));
    // fill(da[0], da[0]+505*505, inf);
    // fill(ta[0], ta[0]+505*505, inf);
    
    scanf("%d %d", &n, &m);
    for(int i=0;i<m;i++){
        int a,b,c,d,e;
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
        if(c==1){
            da[a][b]=d;
            ta[a][b]=e;
        }
        else
        {
            da[a][b]=da[b][a]=d;
            ta[a][b]=ta[b][a]=e;
        }
    }
    
    cin>>src>>des;
    tmpdPath.push_back(src);
    for(int i = 0; i < n; i++)
        preDis[i] = i;
    disa[src]=0;
    for(int i=0;i<n;i++){
        int tmin=999999999;
        int u=-1;
        for(int j=0;j<n;j++){
            if(visit[j] == false && disa[j]<tmin){
                tmin = disa[j];
                u=j;
            }
        }
        if(u==-1){
            break;
        }
        visit[u]=true;
        for(int j=0;j<n;j++){
            if(visit[j] == false && da[u][j]<999999999){
                if(disa[j]>disa[u]+da[u][j]){
                    disa[j]=disa[u]+da[u][j];
                    preDis[j]=u;
                    timea[j]=timea[u]+ta[u][j];
                }
                else if(disa[j] == disa[u]+da[u][j] && timea[u]+ta[u][j] < timea[j] )
                {
                    preDis[j]=u;
                    timea[j]=timea[u]+ta[u][j];
                }
            }
        }
    }
    dfsd(des);
    
    fill(visit, visit + 505, false);
    speeda[src]=0;
    for(int i = 0; i < n; i++)
        preTime[i] = i;
    for(int i=0;i<n;i++){
        int tmin=999999999;
        int u=-1;
        for(int j=0;j<n;j++){
            if(visit[j] == false && speeda[j]<tmin){
                tmin = speeda[j];
                u=j;
            }
        }
        if(u==-1){
            break;
        }
        visit[u]=true;
        for(int j=0;j<n;j++){
            if(visit[j] == false && ta[u][j]<999999999){
                if(speeda[j]>speeda[u]+ta[u][j]){
                    speeda[j]=speeda[u]+ta[u][j];
                    preTime[j]=u;
                    nodea[j]=nodea[u]+1;
                }
                else if(speeda[j] == speeda[u]+ta[u][j] && nodea[u]+1 < nodea[j] )
                {
                    preTime[j]=u;
                    nodea[j]=nodea[u]+1;
                }
            }
        }
    }


    dfst(des);

    if(truetPath == truedPath){
        printf("Distance = %d; Time = %d: ",disa[des], speeda[des]);
        for(int i=truedPath.size()-1;i >= 0;i--){
            if(i==truedPath.size()-1){
                cout<<truedPath[i];
            }
            else
            {
                cout<<" -> "<<truedPath[i];
            }
        }
        return 0;
    }

    printf("Distance = %d: ",disa[des]);
    for(int i=truedPath.size()-1;i >= 0;i--){
        if(i==truedPath.size()-1){
            cout<<truedPath[i];
        }
        else
        {
            cout<<" -> "<<truedPath[i];
        }
    }
    cout<<endl;
    printf("Time = %d: ", speeda[des]);
    for(int i=truetPath.size()-1;i >= 0;i--){
        if(i==truetPath.size()-1){
            cout<<truetPath[i];
        }
        else
        {
            cout<<" -> "<<truetPath[i];
        }
    }

}