#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[1001][1001];
int arr[1001];
int f(int N,int K){
	if(N<1||K<1)return 0;
	else if(dp[N][K]>=0)return dp[N][K];
	else if(arr[N] > K){
		dp[N][K]=f(N-1,K);
		
	}
	else {
		dp[N][K]=max((arr[N]+f(N-2,K-arr[N])),f(N-1,K));
	}
	return dp[N][K];
}
int main() {
	int t;
	cin>>t;
	int c=1;
	while(t--){
		memset(dp,-1,sizeof(dp));
		int N,K;
		cin>>N>>K;
		for(int i=1;i<=N;++i)
		cin>>arr[i];
		cout<<"Scenario #"<<c++<<": "<<f(N,K)<<"\n";
	}
}
