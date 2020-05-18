#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

struct myrecord
{
    string plate;
    int time;
    int state;
};

vector<myrecord> datav, truedatav;
unordered_map<string, int> vaildm,longm;
unordered_map<string, int> vaildsm;
unordered_map<string, int> timem;
int maxTime=-1;
vector<string> retv;

bool mycmp(myrecord a, myrecord b){
    return a.time < b.time;
}

bool cmp1(myrecord a, myrecord b){
    return a.plate < b.plate;
}

int main(){
    int n,k;
    cin>>n>>k;

    for(int i=0;i<n;i++){
        string name;
        cin>>name;
        int h,m,s,state;
        string st;
        scanf("%d:%d:%d", &h,&m,&s);
        cin>>st;
        if(st=="in"){
            state=1;
        }
        else
        {
            state=0;
        }
        
        datav.push_back(myrecord{name, h * 3600 + m * 60 + s, state});
    }
    sort(datav.begin(), datav.end(), mycmp);

    string tmpplate;
    for(int i=0;i<n;i++){
        tmpplate=datav[i].plate;
        if(datav[i].state==1){
            vaildm[tmpplate]=i;
            vaildsm[tmpplate]=1;
        }
        else
        {
            if(vaildm.find(datav[i].plate)!=vaildm.end()){
                if(vaildsm[tmpplate]==1){
                    truedatav.push_back(datav[vaildm[datav[i].plate]]);
                    truedatav.push_back(datav[i]);
                    vaildsm[tmpplate]=2;
                    vaildm[tmpplate]=truedatav.size()-1;
                }
            }
        }
    }
    sort(truedatav.begin(), truedatav.end(), mycmp);

    int vindex=0;
    int incnt=0;
    int intime=0;
    string nowplate;
    int last;
    int total;
    for(int i=0;i<k;i++){
        int qh,qm,qs;
        scanf("%d:%d:%d",&qh,&qm,&qs);
        int qt=qh*3600+qm*60+qs;
        while (truedatav[vindex].time<=qt && vindex<truedatav.size())
        {
            nowplate=truedatav[vindex].plate;
            if(truedatav[vindex].state==1){
                incnt++;
                longm[nowplate]=vindex;
            }
            else
            {
                incnt--;
                intime = truedatav[longm[nowplate]].time;
                last = truedatav[vindex].time -intime;
                if(timem.find(nowplate)!=timem.end()){
                    total=last+timem[nowplate];
                    timem[nowplate]=total;
                }
                else
                {
                    timem[nowplate]=last;
                    total=last;
                }
                
                if( total > maxTime){
                    maxTime = total;
                }
            }
            vindex++;
        }
        cout<<incnt<<endl;
    }

    while (vindex<truedatav.size())
    {
        nowplate=truedatav[vindex].plate;
        if(truedatav[vindex].state==1){
            incnt++;
            longm[nowplate]=vindex;
        }
        else
        {
            incnt--;
            intime = truedatav[longm[nowplate]].time;
            last = truedatav[vindex].time -intime;
            if(timem.find(nowplate)!=timem.end()){
                total=last+timem[nowplate];
                timem[nowplate]=total;
            }
            else
            {
                timem[nowplate]=last;
                total=last;
            }
            
            if( total > maxTime){
                maxTime = total;
            }
        }
        vindex++;
    }

    for(auto it=timem.begin();it!=timem.end();it++){
        if(it->second==maxTime){
            retv.push_back(it->first);
        }
    }
    sort(retv.begin(), retv.end());
    for(int i=0;i<retv.size(); i++){
        if(i==0){
            cout<<retv[i];
        }
        else
        {
            cout<<" "<<retv[i];
        }
    }
    printf(" %02d:%02d:%02d", maxTime/3600, (maxTime % 3600) / 60, maxTime%60);
}
