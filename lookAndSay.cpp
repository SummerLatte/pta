/*1 8
1123123111

1 11 12 1121 122111 112213 12221131 1123123111*/
#include<iostream>
#include<vector>
using namespace std;
void las(vector<int> v, vector<int> &t){
    int p=0,present,cnt;
    present=v[0];
    while (p<v.size())
    {
        if(present==v[p]){
            cnt++;
        }
        else
        {
            t.push_back(present);
            t.push_back(cnt);
            present=v[p];
            cnt=1;
        }
        p++;
    }
    t.push_back(present);
    t.push_back(cnt);
}

int main() {
    string s;
    int n, j;
    cin >> s >> n;
    for (int cnt = 1; cnt < n; cnt++) {
        string t;
        for (int i = 0; i < s.length(); i = j) {
            for (j = i; j < s.length() && s[j] == s[i]; j++);
            t += s[i] + to_string(j - i);
        }
        s = t;
    }
    cout << s;
    return 0;
}

int main1(){
    int d,n;
    cin>>d>>n;
    vector<int> v;
    v.push_back(d);
    vector<int> t;
    t.push_back(d);
    for(int i=1;i<n;i++){
        v = t;
        t.clear();
        las(v, t);
    }
    for(int i:t){
        cout<<i;
    }
}