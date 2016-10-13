#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool check(int c,int x,vector<long int>& v){
	int begin=v[0],nc=1;
	for(int i=1;i<v.size();++i){
		if(v[i]-begin>=x){
			++nc;
			begin=v[i];
		}
	}
	if(nc>=c)return true;
	return false;
}
int main() {
	int t;
	cin>>t;
	while(t--){
		int n,c;
		cin>>n>>c;
		vector<long int> v(n);
		for(int i=0;i<n;++i)
		cin>>v[i];
		sort(v.begin(),v.end());
		long int lo=0,hi=v[n-1]-v[0]+1;
		while(hi>lo){
			int x=lo+(hi-lo+1)/2 ;
			if(check(c,x,v)){
				lo=x;
			}
			else hi=x-1;
		}
			cout<<lo<<"\n";
	}
	
}
