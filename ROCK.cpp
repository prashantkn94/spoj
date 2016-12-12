#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
int a[200][200][2];
int res[200][200];
int main(){
	freopen("c:\\in.txt","r",stdin);
	int t;
	cin>>t;
	while(t--){
	memset(a,0,sizeof a);
	memset(res,0,sizeof res);
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(int i=0;i<n;++i){
		for(int j=i;j<n;++j){
			if(i==j&&s[i]=='1'){
				a[i][j][1]=1;
				a[i][j][0]=0;
			}
			else if(i==j&&s[i]=='0'){
				a[i][j][1]=0;
				a[i][j][0]=1;
			}
			else{
				if(s[j]=='1'){
					a[i][j][1]=a[i][j-1][1]+1;
					a[i][j][0]=a[i][j-1][0];
				}
				else if(s[j]=='0'){
					a[i][j][0]=a[i][j-1][0]+1;
					a[i][j][1]=a[i][j-1][1];
				}
			}
		}
	}
	for(int i=0;i<n;++i){
		res[i][i]=a[i][i][1]==1;
	}
	for(int l=1;l<=n;++l)
		for(int i=0;i+l<=n;++i){
			int j=i+l-1;
			if(a[i][j][1]>a[i][j][0])
				res[i][j]=l;
			else {
				int tt=0;
				for(int k=i;k<j;++k)
					tt=max(tt,res[i][k]+res[k+1][j]);
				res[i][j]=tt;
				
			}
		}
	
	cout<<res[0][n-1]<<"\n";
			
	
	}
				
}
