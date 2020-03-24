#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main(){
    int m,n,s;
    cin>>m>>n>>s;
    vector<string> fv;
    fv.resize(m+1);
    for(int i=1;i<=m;i++){
        string name;
        cin>>name;
        fv[i]=name;
    }
    if(s>m){
        cout<<"Keep going...";
        return 0;
    }

    set<string> ns;
    for(int i=s;i<=m;i+=n){
        auto it = ns.find(fv[i]);
        if(it==ns.end()){
            ns.insert(fv[i]);
            cout<<fv[i]<<endl;
        }
        else
        {
            i++;
            while (i<=m)
            {
                it = ns.find(fv[i]);
                if(it==ns.end()){
                    ns.insert(fv[i]);
                    cout<<fv[i]<<endl;
                    break;
                }
                i++;
            }
        }
        
        
    }

    return 0;
}