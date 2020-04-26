#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

struct DATA {
    int id, fid, mid, k, num, area;
    int kid[10];
}mydata[1005];

struct anode{
    int id;
    double num;
    double area;
    int people;
    int flg=0;
}ans[10000];

int father[10000];
int visit[10000];

int find(int id){
    while(father[id]!=id){
        id = father[id];
    }
    return id;
}

void myunion(int a, int b){
    int af = find(a);
    int bf = find(b);
    if(af<bf){
        father[bf] = af;
    }
    else
    {
        father[af] = bf;
    }
    
}

bool cmp1(anode a, anode b){
    if(a.area!=b.area){
        return a.area>b.area;
    }
    return a.id < b.id;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<10000;i++){
        father[i]=i;
        ans[i].flg=0;
    }
    memset(visit, 0, sizeof(visit));
    for(int i=0;i<n;i++){
        int a,f,m,k;
        cin>>a>>f>>m>>k;
        visit[a]=1;
        mydata[i].id=a;
        mydata[i].fid=f;
        mydata[i].mid=m;
        mydata[i].k=k;
        if(m!=-1){
            visit[m]=1;
            myunion(mydata[i].id, m);
        }
        if(f!=-1){
            visit[f]=1;
            myunion(mydata[i].id, f);
        }
        for(int j=0;j<k;j++){
            int kid;
            cin>>kid;
            visit[kid]=1;
            myunion(mydata[i].id, kid);
            mydata[i].kid[j]=kid;
        }

        int num, area;
        cin>>num>>area;
        mydata[i].area=area;
        mydata[i].num=num;
    }

    for(int i=0;i<n;i++){
        int faid = find(mydata[i].id);
        ans[faid].flg=1;
        ans[faid].area+=mydata[i].area;
        ans[faid].num+=mydata[i].num;
        ans[faid].id = faid;
    }

    int cnt=0, pcnt=0;
    for(int i=0;i<10000;i++){
        if(ans[i].flg==1){
            cnt++;
        }
        if(visit[i]==1){
            ans[find(i)].people++;
        }
    }

    for(int i=0;i<10000;i++){
        if(ans[i].flg == 1){
            ans[i].area = ans[i].area/((double)ans[i].people);
            ans[i].num = ans[i].num/((double)ans[i].people);
        }
    }

    sort(ans, ans+10000, cmp1);

    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++){
        printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].people, ans[i].num, ans[i].area);
    }
}
