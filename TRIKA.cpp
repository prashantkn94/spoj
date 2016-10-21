#include <iostream>
using namespace std;

int main() {

	int n,m,x,y;
	cin>>n>>m>>x>>y;
	int dp[21][21];
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j)
	cin>>dp[i][j];
	
	for(int i=x;i<=n;++i)
	for(int j=y;j<=m;++j){
		if(i==x&&j==y)continue;
		else if(x==i)dp[i][j]=dp[i][j-1]-dp[i][j];
		else if(y==j)dp[i][j]=dp[i-1][j]-dp[i][j];
		else dp[i][j]=max(dp[i-1][j],dp[i][j-1])-dp[i][j];
	}
	if(dp[n][m]>=0)cout<<"Y "<<dp[n][m]<<"\n";
	else cout<<"N\n";
}
