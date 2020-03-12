#include<iostream>
#include<vector>

using namespace std;

int main(){
    int c;
    cin>>c;
    for(int i=0;i<c;i++){
        int n;
        cin>>n;
        vector<int> padv;
        vector<int> hash(n+1, 0);
        for(int j=0;j<n;j++){
            int col;
            cin>>col;
            padv.push_back(col);
            hash[col]++;
        }

        bool flg=false;
        for(int j=0;j<n;j++){
            int tmp=padv[j];
            if(hash[tmp]==2){
                flg=true;
                break;
            }
            for(int k=j+1;k<n;k++){
                if(tmp+k-j < n + 1 && padv[k]==tmp+k-j){
                    flg=true;
                    break;
                }
                if(tmp-k+j > 0 && padv[k]==tmp-k+j){
                    flg=true;
                    break;
                }
                if(flg){
                    break;
                }
                if(tmp+k-j > n && tmp-k+j < 1){
                    continue;
                }
            }
        }

        if(flg){
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }
    }
}