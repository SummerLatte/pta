#include<iostream>
#include<stdio.h>
#include<string>
#include<unordered_map>
#include<set>

using namespace std;

unordered_map<char, int> smap;
set<char> cset;

void stateChange(char v, int state){
    // 0 init 1 stuck 2 not
    if(state == 2){
        smap[v]=2;
    }
    else
    {
        if(smap.find(v)==smap.end()){
            smap[v]=1;
        }
        else
        {
            if(smap[v]==2){
                return;
            }
            else
            {
                smap[v]=1;
            }
        }
    }
}

int main(){
    int stn;
    cin>>stn;
    string txt;
    cin>>txt;
    int l=txt.length();
    for(int i=0;i<txt.length()-stn+1;i++){
        int tmps = 1;
        for(int j=1;j<stn;j++){
            if(txt.at(i)!=txt.at(i+j)){
                tmps=2;
                break;
            }
        }
        if(tmps==2){
            stateChange(txt.at(i), 2);
        }
        else
        {
            stateChange(txt.at(i), 1);
            i+=stn-1;
        }
    }

    for(int i=0;i<txt.length();i++){
        if(smap.find(txt.at(i))!=smap.end() && smap[txt.at(i)]==1 && cset.find(txt.at(i))==cset.end()){
            cout<<txt.at(i);
            cset.insert(txt.at(i));
        }
    }
    cout<<endl;
    for(int i=0;i<txt.length();i++){
        if(smap.find(txt.at(i))!=smap.end() && smap[txt.at(i)]==1){
            cout<<txt.at(i);
            i+=stn-1;
        }
        else
        {
            cout<<txt.at(i);
        }
        
    }
    cout<<endl;
}