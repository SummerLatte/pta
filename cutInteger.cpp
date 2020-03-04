#include<iostream>

using namespace std;

int main(){
    int c;
    cin>>c;
    for(int i=0;i<c;i++){
        string num;
        cin>>num;
        long f,b;
        f=stoi(num.substr(0, (num.length()/2)));
        b=stoi(num.substr(num.length()/2, num.length()));
        if(f==0||b==0){
            cout<<"No"<<endl;
        }
        else if(stol(num)%(f*b)==0){
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
        
    }
}