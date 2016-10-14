#include <iostream>
#include <cstring>
using namespace std;
long long int BIT1[100001],BIT2[100001];
void update(long long int b[],int index,long long val,int n){
	for(;index<=n;index+=(index & -index))
	b[index]+=val;
}
long long int sum(long long int b[],int index){
	long long int ans=0;
	for(;index>0;index-=(index & -index))
	ans+=b[index];
	return ans;
}

long long int sum(int a){
	return a*sum(BIT1,a)-sum(BIT2,a);
}
long long int sum(int a,int b){
	return sum(b)-sum(a-1);
}
int main() {
	int t;
	cin>>t;
	while(t--){
		memset(BIT1,0,sizeof(BIT1));
		memset(BIT2,0,sizeof(BIT2));
		int n,c;
		cin>>n>>c;
		while(c--){
			int x,p,q;
			long long v;
			cin>>x;
			if(x==0){
				cin>>p>>q>>v;
				update(BIT1,p,v,n);
				update(BIT1,q+1,-v,n);
				update(BIT2,p,v*(p-1),n);
				update(BIT2,q+1,-v*q,n);
			}
			else{
				cin>>p>>q;
				cout<<sum(p,q)<<"\n";
				
			}
		}
	}
}
