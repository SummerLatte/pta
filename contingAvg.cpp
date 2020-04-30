#include<iostream>
#include<string>

using namespace std;

bool isLeg(string s){
    int dotCnt=0;
    int index;
    for(int i=0;i<s.length();i++){
        if(s[i]=='.'){
            dotCnt++;
            index=i;
        }
    }
    if(dotCnt==0){
        return true;
    }
    if(dotCnt >1){
        return false;
    }
    if((s.length()-index )> 3){
        return false;
    }
    return true;
}

int main(){
    int n, lcnt=0;
    float sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        string txt;
        cin>>txt;
        float num;
        try{
            num = stof(txt);
        }
        catch(exception){
            cout<<"ERROR: "<<txt<<" is not a legal number"<<endl;
            continue;
        }

        if(!isLeg(txt)){
            cout<<"ERROR: "<<txt<<" is not a legal number"<<endl;
            continue;
        }

        if(num>1000||num<-1000){
            cout<<"ERROR: "<<txt<<" is not a legal number"<<endl;
            continue;
        }
        sum+=num;
        lcnt++;
    }

    if(lcnt == 1)
        printf("The average of 1 number is %.2f", sum);
    else
    if(lcnt!=0){printf("The average of %d numbers is %.2f\n", lcnt, (float)(sum/(float)lcnt));}
    else{
        printf("The average of 0 numbers is Undefined\n");
    }

}
