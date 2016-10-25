#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
	
	int t;
	scanf("%d",&t);
	while(t--){
		long long int n;
		int f=0;
		scanf("%lld",&n);
		long long int hi=sqrt(n);
		long long int lo=0;
		while(hi>=lo){
			long long int temp=hi*hi+lo*lo;
			if(temp==n){
				printf("Yes\n");
				f=1;
				break;
			
			}
			else if(temp<n) ++lo;
			else --hi;
		}
		if(f==0)printf("No\n");
		
	}

}
