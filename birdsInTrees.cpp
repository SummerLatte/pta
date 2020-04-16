#include<set>
#include<vector>
#include<iostream>

using namespace std;
vector<int> birdsv(100001, 0);
int getId(int k){
    int tmp=k;
    while(birdsv[tmp]!=tmp){
        tmp=birdsv[tmp];
    }
    return tmp;
}

void allSet(int k, int val){
    int tmp=k;
    int last=tmp;
    while(birdsv[tmp]!=tmp){
        last = tmp;
        tmp=birdsv[tmp];
        birdsv[last]=val;
        if(tmp==0){
            return;
        }
    }
    last = tmp;
    birdsv[last]=val;
}

int main(){
    int n;
    cin>>n;
    set<int> bs;
    set<int> treeset;
    for(int i=0;i<n;i++){
        int k;
        int min=9999999;
        cin>>k;
        vector<int> tmp;
        bool before=false;
        set<int> beforeTree;
        for(int j=0;j<k;j++){
            int tmpk;
            cin>>tmpk;
            tmp.push_back(tmpk);
            bs.insert(tmpk);

            if(birdsv[tmpk]!=0){
                before=true;
                beforeTree.insert(birdsv[tmpk]);
            }
        }
        if(before){
            for(auto it=beforeTree.begin();it!=beforeTree.end();it++){
                if(*it<min){
                    min = *it;
                }
            }
            for(auto it=beforeTree.begin();it!=beforeTree.end();it++){
                if(*it!=min){
                    treeset.erase(*it);
                }
            }
            for(int j=0;j<k;j++){
                allSet(tmp[j], min);
            }
        }
        else
        {
            for(int j=0;j<k;j++){
                if(tmp[j]<min){
                    min = tmp[j];
                }
            }
            treeset.insert(min);
            for(int j=0;j<k;j++){
                birdsv[tmp[j]] = min;
            }
        }
    }
    cout<<treeset.size()<<" "<<bs.size()<<endl;

    int qn;
    cin>>qn;
    for(int i=0;i<qn;i++){
        int a, b;
        cin>>a>>b;
        if(getId(a)==getId(b)){
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    return 0;
}