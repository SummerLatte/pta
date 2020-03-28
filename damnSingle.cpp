#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<set>

using namespace std;
int pa[100005];

int main(){
    int cs;
    cin>>cs;
    set<int> singleS;
    for (int i = 0; i < 100000; i++) {
        pa[i] = -1;
    }
    for(int i=0;i<cs;i++){
        int a,b;
        cin>>a>>b;
        pa[a]=b;
        pa[b]=a;
    }
    int num;
    cin>>num;
    for(int i=0;i<num;i++){
        int id;
        cin>>id;
        if(pa[id]==-1){
            singleS.insert(id);
            continue;
        }
        auto it=singleS.find(pa[id]);
        if(it!=singleS.end()){
            singleS.erase(pa[id]);
            continue;
        }
        singleS.insert(id);
    }
    cout<<singleS.size()<<endl;
    for(auto its=singleS.begin();its!=singleS.end();its++){
        if(its==singleS.begin()){
            printf("%05d", *its);
        }
        else
        {
            printf(" %05d", *its);
        }
    }
    return 0;
}