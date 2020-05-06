#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<set>
#include<vector>

int visit[1005];
int hobby[1005];
int people[1006];
int hcnt[1005];

using namespace std;

bool cmp(int x,int y)
{
    return x>y;
}

int myfind(int val){
    int x = val;
    while(val != hobby[val]){
        val = hobby[val];
    }
    int t;
    while(x!=val){
        t=hobby[x];
        hobby[x]=val;
        x=t;
    }
    return val;
}

void myunion(int a, int b){
    int fa = myfind(a);
    int fb = myfind(b);

    if(fa!=fb){
        hobby[fb]=fa;
    }
}

int main(){
    int n;
    cin>>n;

    memset(visit, 0, sizeof(visit));
    memset(hcnt, 0, sizeof(hcnt));

    for(int i=0;i<1005;i++){
        hobby[i]=i;
    }

    for(int i=0;i<n;i++){
        int hc;
        scanf("%d:", &hc);
        int ga;
        for(int j=0;j<hc;j++){
            int h;
            scanf("%d", &h);
            if(j==0){
                ga = myfind(h);
            }
            myunion(ga, h);
            visit[h]=1;
        }
        people[i]=myfind(ga);
    }

    set<int> hset;
    for(int i=0;i<1005;i++){
        if(visit[i]==1){
            hset.insert(myfind(i));
        }
    }
    cout<<hset.size()<<endl;

    for(int i=0;i<n;i++){
        hcnt[myfind(people[i])]+=1;
    }
    vector<int> retv;
    for(int i=0;i<1005;i++){
        if(visit[i]==1 && hcnt[i]!=0){
            retv.push_back(hcnt[i]);
        }
    }
    sort(retv.begin(),retv.end(), cmp);
    
    for(int i=0;i<hset.size();i++){
        if(i==0){
            cout<<retv[0];
            continue;
        }
        cout<<" "<<retv[i];
    }
    cout<<endl;
}