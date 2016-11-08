#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits> 
#include <string>
#include <cstring>
#include <queue>
using namespace std;
long long int a[100010];
long long int b[100010];
long long int f(int i,int n){
    if(a[i]>0)return a[i];
    else if(i>=n) return 0;
    else {
        long long int x,y=-1,z=-1;
        x=b[i]+f(i+2,n);
        if(i+1<n)
        y=b[i]+b[i+1]+f(i+4,n);
        if(i+2<n)
        z=b[i]+b[i+1]+b[i+2]+f(i+6,n);
        a[i]=max(x,max(y,z));
    }
    return a[i];
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(a,0,sizeof(a));
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i)scanf("%lld",&b[i]);
        printf("%lld\n",f(0,n));

    }
}
