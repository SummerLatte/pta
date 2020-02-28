#include<string>
#include<cstring>
#include<iostream>
#include <algorithm>

using namespace std;

void ladd(string a, string b, string &ans){
    int la = a.length();
    int lb = b.length();
    int cf = 0;
    int sum = 0;
    ans.clear();
    string ra= a;
    string rb= b;
    reverse(ra.begin(), ra.end());
    reverse(rb.begin(), rb.end());
    for(int i=0;i<(la>lb?lb:la);i++){
        sum = (ra.at(i)-'0' + rb.at(i)-'0') + cf;
        cf=0;
        if(sum>9){
            sum -= 10;
            cf =1;
        }
        ans.append(to_string(sum));
    }
    string now = la>lb?a:b;
    if(la==lb){
        if(cf==0) {reverse(ans.begin(), ans.end()); return;}
        else{
            ans += "1";
            reverse(ans.begin(), ans.end());
            return;
        }
        
    }
    for(int i=now.length()-abs(la-lb);i<now.length();i++){
        sum=now.at(i)+cf;
        cf=0;
        if(sum>9){
            sum -= 10;
            cf =1;
        }
        ans.append(to_string(sum));
    }
    if(cf==0) {reverse(ans.begin(), ans.end());}
    else{
        ans += "1";
        reverse(ans.begin(), ans.end());;
    }
}

void shortLarge(string a, string &ans){
    int cf=0, sum=0;
    ans.clear();
    for(int i=0;i<a.length();i++){
        sum = a.at(i)-'0'+ a.at(a.length()-i-1)-'0' + cf;
         cf=0;
        if(sum>9){
            sum -= 10;
            cf =1;
        }
        ans.append(to_string(sum));
    }
    if(cf==0) {reverse(ans.begin(), ans.end());}
    else{
        ans += "1";
        reverse(ans.begin(), ans.end());;
    }
}

int main(){
    string in;
    cin>>in;
    string sum=in;
    string re;
    for(int i=0;i<10;i++){
        re = in;
        reverse(re.begin(), re.end());
        if(in==re) {
            cout<<in<<" is a palindromic number.";
            return 0;
        }
        shortLarge(re, sum);
        printf("%s + %s = %s\n", in.c_str(), re.c_str(), sum.c_str()) ;
        in = sum;
    }
    re = in;
    reverse(re.begin(), re.end());
    if(in==re) {
        cout<<in<<" is a palindromic number.";
        return 0;
    }
    cout<<"Not found in 10 iterations.";
}