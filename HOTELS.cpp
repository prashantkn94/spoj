#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;++i)cin>>a[i];
	int sum=0,last=0,res=0;
	for(int j=0;j<n;++j){
		
		sum+=a[j];
		while(sum>m){
			sum=sum-a[last];
			++last;
		}
		res=max(sum,res);;
	}
	cout<<res<<endl;
}
