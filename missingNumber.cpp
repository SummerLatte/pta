#include<iostream>
#include<map>


using namespace std;

int main(){
    int l, num, k=1;
    map<int, int> nm;
    cin>>l;

    for(int i=0;i<l;i++){
        cin>>num;
        nm[num]++;
    }

    while(nm[k]!=0){
        k++;
    }
    cout<<k;
}