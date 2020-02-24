#include<algorithm>
#include<unordered_map>
#include<vector>
#include<string>
#include <iostream>
using namespace std;
typedef struct Node{
    int cnt,sc;
    string name;
}node;

bool cmp(node a, node b){
    if(a.sc!=b.sc) return a.sc>b.sc;
    else if(a.cnt!=b.cnt) return a.cnt<b.cnt;
    else return a.name<b.name;
}

int main(){
    int n;
    cin>>n;
    unordered_map<string, int> cntm;
    unordered_map<string, double> twsm;
    for(int i=0;i<n;i++){
        string id, sn;
        double sc;
        cin>>id>>sc>>sn;
        for(int j=0;j<sn.length();j++) sn[j]=tolower(sn[j]);
        if(id[0]=='B') sc=sc/1.5;
        if(id[0]=='T') sc=sc*1.5;
        cntm[sn] += 1;
        twsm[sn] += sc;
    }

    vector<node> v;
    for(auto &item:cntm){
        v.push_back(node{item.second, (int)(twsm[item.first]), item.first});
    }

    sort(v.begin(), v.end(), cmp);

    int rank = 0, pres = -1;
    printf("%d\n", (int)v.size());
    for (int i = 0; i < v.size(); i++) {
        if (pres != v[i].sc) rank = i + 1;
        pres = v[i].sc;
        printf("%d ", rank);
        cout << v[i].name;
        printf(" %d %d\n", v[i].sc, v[i].cnt);
    }
    return 0;
}