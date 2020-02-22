#include<iostream>
#include<vector>

using namespace std;

bool isPrime(int a){
    if(a==1){
        return false;
    }

    for(int i=2;i*i<=a;i++){
        if(a%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int tsize, n, k;
    cin>>tsize>>n>>k;

    while (!isPrime(tsize))
    {
        tsize+=1;
    }
    
    vector<int> hasht(tsize);

    for(int j=0; j<n;j++){
        int key, pos;
        bool flg = true;
        cin>>key;
        for(int i=0;i<=tsize;i++){
            pos = (key + i * i) % tsize;
            if(hasht[pos] == 0){
                hasht[pos] = key;
                flg = false;
                break;
            }
        }
        if(flg){
            cout<<key<<" cannot be inserted."<<endl;
        }
    }

    int sum = 0;
    for(int i = 0;i<k;i++){
        int key, pos;
        cin>>key;
        for(int j=0;j<=tsize;j++){
            sum++;
            pos = (key + j * j) % tsize;
            if(hasht[pos] == key || hasht[pos] == 0){
                break;
            }
        }
    }

    printf("%.1f", sum*1.0/k);
}