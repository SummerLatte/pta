#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<string>

using namespace std;

int main(){
    int cnt,pairs;
    unordered_map<int, bool> pv;
    vector<int, int> rv[10000];
    cin>>cnt>>pairs;
    for(int i=0;i<pairs;i++){
        string a,b;
        cin>>a>>b;
        if(a.size()==b.size()){
            rv[abs(stoi(a))].push_back(abs(stoi(b))) ;
            rv[abs(stoi(b))].push_back(abs(stoi(a))) ;
        }
        pv[abs(stoi(a))*10000+abs(stoi(b))]=pv[abs(stoi(b))*10000+abs(stoi(a))]=true;
    }
    int cases;
    cin>>cases;
    for (int i = 0; i < cases; i++)
    {
        int a,b;
        cin>>a>>b;
        
    }
    
}