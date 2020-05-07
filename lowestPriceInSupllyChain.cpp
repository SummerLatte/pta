#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> fv[100005];
vector<int> levv;
int n,cnt,mindepth=0x7fffffff;

void dfs(int lev, int index){
    for(int i=0; i<fv[index].size();i++){
        int child=fv[index][i];
        if(fv[child].size()==0){
            if(lev==mindepth) cnt++;
            else if(lev<mindepth) cnt=1,mindepth=lev;
        }
        else
        {
            dfs(lev+1, fv[index][i]);
        }
    }
}

// void dfs(int lev, int index){
//     if(fv[index].size()==0){
//         if(lev==mindepth) cnt++;
//         else if(lev<mindepth) cnt=1,mindepth=lev;
//     }
//     for(int i=0; i<fv[index].size();i++){
//             dfs(lev+1, fv[index][i]);
//     }
// }

int main(){
    int n;
    double pd, rate;
    scanf("%d %lf %lf", &n, &pd, &rate);
    for(int i=0;i<n;i++){
        int k;
        scanf("%d", &k);
        for(int j=0;j<k;j++){
            int s;
            scanf("%d", &s);
            fv[i].push_back(s);
        }
    }
    dfs(1, 0);

    for(int i=0;i<mindepth;i++){
        pd =(double(1.0+(rate/100.00)) * pd);
    }
    printf("%.4lf %d\n", pd, cnt);
}