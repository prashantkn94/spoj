#include <iostream>
using namespace std;
typedef long long int lli;
int main(){
    int n;
    cin>>n;
    while(n--){
    lli a,b;
    cin>>a>>b;
    int f=0;
    for(lli x=a;x<=b;++x){
        if(x==1)continue;
        for(lli i=2;i<=sqrt(x);++i){
            if(x%i==0){f=1;break;}
        }
        if(!f)cout<<"\n"<<x;
        f=0;
    }
    cout<<"\n";
}

}
