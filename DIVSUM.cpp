
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <numeric>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        vector<int> v;
        int n;
        scanf("%d",&n);
        if(n==1){
        	printf("%d\n",0);
        	continue;
        }
        for(int i=2;i<=sqrt(n);++i){
            if(n%i==0){
                v.push_back(i);
                if(i!=sqrt(n))
                v.push_back(n/i);
            }
        }
        printf("%d\n",accumulate(v.begin(),v.end(),0)+1);
    }
    
    
}
