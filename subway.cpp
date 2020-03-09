#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<unordered_map>
#include<stdio.h>
#include<queue>

using namespace std;


vector<int> vs[10000];
int minDis=9999999;
int minTransCnt=99999;
int start, stop;

unordered_map<int, int> line;
int visit[10000];

vector<int> path, tmpPath;

int getTransCnt(){
    int transCnt=0, preLine=0;
    for(int i=1;i<tmpPath.size();i++){
        if(line[tmpPath[i-1]*10000+tmpPath[i]]!=preLine){
            if(preLine != 0){
                transCnt++;
            }
            preLine=line[tmpPath[i-1]*10000+tmpPath[i]];   
        }
    }

    return transCnt;
}

void dfs(int node, int dis){
    if(dis>minDis){
        return;
    }
    if(node==stop && (dis<minDis || (dis==minDis && getTransCnt()<minTransCnt))){
        minDis = dis;
        minTransCnt = getTransCnt();
        path = tmpPath;
    }
    if(node==stop){
        return;
    }

    for(int i=0;i<vs[node].size();i++){
        if(visit[vs[node][i]]==0){
            visit[vs[node][i]]=1;
            tmpPath.push_back(vs[node][i]);
            dfs(vs[node][i], dis+1);
            tmpPath.pop_back();
            visit[vs[node][i]]=0;
        }
    }
}


int main(){
    int ls;
    cin>>ls;
    for(int i=0;i<ls;i++){
        int ss;
        cin>>ss;
        int id=-1,lid=-1;
        for(int j=0;j<ss;j++){
            cin>>id;
            if(lid ==-1){
                lid=id;
                continue;
            }
            vs[id].push_back(lid);
            vs[lid].push_back(id);
            line[id*10000+lid] = line[lid*10000+id] = i + 1;
            lid=id;
        }
    }

    int cs;
    cin>>cs;
    for(int i=0;i<cs;i++){
        cin>>start>>stop;
        minDis=9999999;
        minTransCnt=99999;
        tmpPath.clear();
        tmpPath.push_back(start);
        dfs(start, 0);
        cout<<minDis<<endl;
        
        int now=0, preLine=0;
        for(int i=1;i<path.size();i++){
            if(line[path[i-1]*10000+path[i]]!=preLine){
                if(preLine != 0){
                    printf("Take Line#%d from %04d to %04d.\n", preLine, path[now], path[i-1]);
                }
                now = i-1;
                preLine=line[path[i-1]*10000+path[i]];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preLine, path[now], stop);
    }
}
