#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
int a[100000];
int val[100000],weight[100000];
int main(){
    int t;
    cin>>t;
    while(t--){
    int t1,t2;
    cin>>t1>>t2;
    int w=t2-t1;
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>val[i]>>weight[i];
    }
    if(w<0){
        cout<<"This is impossible."<<endl;
        continue;
    }
    for(int i=1;i<=w;++i)
        a[i]=inf;
    a[0]=0;

    for(int i=1;i<=n;++i){
        for(int j=weight[i];j<=w;++j){
            a[j]=min(a[j],val[i]+a[j-weight[i]]);
        }
    }
    
    if(a[w]==inf){
        cout<<"This is impossible."<<endl;
    }
    else{
        
        cout<<"The minimum amount of money in the piggy-bank is "<<a[w]<<"."<<endl;
    }
}


}
