#include<vector>
#include<iostream>

using namespace std;

int main(){
    long n;
    cin>>n;
    vector<double> dv;
    for(int i=0;i<n;i++){
        double d;
        scanf("%lf", &d);
        dv.push_back(d);
    }

    vector<long> mutiv;
    for(long i=0;i<n/2+1;i++){
        mutiv.push_back((i+1)*(n-i));
    }

    int j=0;
    double sum;
    int i=0;
    for(;i<n/2;i++){
        sum = sum+dv[i]*(double)mutiv[j];
        j++;
    }
    if(n%2==0){
        j=(n/2)-1;
    }
    else
    {
        j=n/2;
    }
    
    for(;i<n;i++){
        sum = sum+dv[i]*(double)mutiv[j];
        j--;
    }

    printf("%.2lf", sum);
}
