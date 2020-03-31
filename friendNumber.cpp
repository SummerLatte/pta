#include<iostream>
#include<set>


using namespace std;

int getFN(int n){
    int sum=0;
    int tmp = n;
    while(tmp!=0){
        sum += tmp%10;
        tmp = tmp/10;
    }
    return sum+=tmp;
}

int main(){
    int n;
    cin>>n;
    set<int> fset;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        int fnum = getFN(num);
        auto it=fset.find(fnum);
        if(it==fset.end()){
            fset.insert(fnum);
        }
    }

    cout<<fset.size()<<endl;
    for(auto item=fset.begin();item!=fset.end();item++){
        if(item==fset.begin()){
            cout<<*item;
        }
        else
        {
            cout<<" "<<*item;
        }
    }

    return 0;
}