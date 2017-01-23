#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int u64; 
u64 d[64][10];
u64 f(int pos,int num){
    if(pos==0)return 1;
    if(d[pos][num]>0)return d[pos][num];
    for(int i=num;i>=0;--i){
        d[pos][num]+=f(pos-1,i);
     }
    return d[pos][num];
}
int main(){
memset(d,0,sizeof d);
int t;
cin>>t;
while(t--){
int uu,n;
cin>>uu>>n;
--n;
u64 ans=0;
for(int i=9;i>=0;--i)
    ans+=f(n,i);
cout<<uu<<" "<<ans<<endl;
}

}
