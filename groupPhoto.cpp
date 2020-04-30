#include<iostream>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

using namespace std;

struct people
{
    int height;
    string name;
};

vector<people> pv;
bool cmp(people a, people b){
    if(a.height!=b.height){
        return a.height>b.height;
    }
    else
    {
        return a.name<b.name;
    }
    
}

int main(){
    int n, row;
    cin>>n>>row;
    for(int i=0;i<n;i++){
        string name;
        int h;
        cin>>name>>h;
        pv.push_back(people{h,name});
    }

    sort(pv.begin(), pv.end(), cmp);

    int lastRow, otherRow=n/row;
    int index=0;
    int x=0;
    if(row!=1){
        lastRow = n - (n/row)*(row-1);
        deque<string> out;
        for(;index<lastRow;index++){
            if(index%2==0){
                out.push_back(pv[index].name);
            }
            else
            {
                out.push_front(pv[index].name);
            }
        }
        for(int i=0;i<out.size();i++){
            if(i==0){
                cout<<out[i];
            }
            else
            {
                cout<<" "<<out[i];
            }
        }
        cout<<endl;
        x++;
    }

    for(int i=x;i<row;i++){
        int ss=index;
        deque<string> out;
        out.push_back(pv[index].name);
        index++;
        int j=1;
        for(;index<ss+otherRow;index++){
            if(j%2==0){
                out.push_back(pv[index].name);
            }
            else
            {
                out.push_front(pv[index].name);
            }
            j++;
        }
        cout<<out[0];
        for(int j=1;j<out.size();j++){
            cout<<" "<<out[j];
        }
        cout<<endl; 
    }

    return 0;
}