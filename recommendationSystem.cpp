#include<set>
#include<iostream>

using namespace std;

int ca[50001];

struct node
{
    int value,cnt;

    bool operator < (const node &a) const{
        return cnt!=a.cnt ? cnt > a.cnt : value < a.value;
    }
};


int main(){
    int n,k;
    cin>>n>>k;
    set<node> nset;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        if(i!=0){
            cout<<num<<":";
            int tempCnt=0;
            for(auto it=nset.begin();it!=nset.end()&&tempCnt<k;it++){
                cout<<" "<<it->value;
                tempCnt++;
            }
            cout<<endl;
        }
        auto it = nset.find(node{num, ca[num]});
        if(it!=nset.end()){
            nset.erase(it);
        }
        ca[num]++;
        nset.insert(node{num, ca[num]});
    }
}