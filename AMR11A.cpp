#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int s[500][500],dp[500][500];
int r,c;
bool check(int x){
	dp[0][0]=x;
	for(int i=0;i<r;++i){
		for(int j=0;j<c;++j){
			if(i==0){
				if(j==0)continue;
				if(dp[i][j-1]>0)
				dp[i][j]=s[i][j]+dp[i][j-1];
				else dp[i][j]=-1;
			}
			else if(j==0){
				if(dp[i-1][j]>0)
				dp[i][j]=s[i][j]+dp[i-1][j];
				else dp[i][j]=-1;
			}
			else if(dp[i-1][j]>0||dp[i][j-1]>0)
			dp[i][j]=s[i][j]+max(dp[i-1][j],dp[i][j-1]);
		    else dp[i][j]=-1;
		}
	}
	return dp[r-1][c-1]>0;
	
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int lo=1,hi=0;
		scanf("%d %d",&r,&c);
		for(int i=0;i<r;++i){
			for(int j=0;j<c;++j){
			scanf("%d",&s[i][j]);
			if(s[i][j]<0)
			hi+=abs(s[i][j]);
			}
		}
		while(lo<hi){
			int x=(lo+hi)/2;
			if(check(x))
			hi=x;
			else lo=x+1;
		}
		printf("%d\n",lo);
		
	}
}
