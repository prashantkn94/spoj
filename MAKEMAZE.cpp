#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
char a[20][20];
int vis[20][20];
int x[4]={1,0,-1,0};
int y[4]={0,1,0,-1};
int main(){
	int t;
	cin>>t;
	while(t--){
	memset(vis,0,sizeof(vis));
	int n,m;
	cin>>n>>m;
	int c=0;
	int idx,idy,f=0;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j){
			cin>>a[i][j];
			if((i==0||i==n-1||j==0||j==m-1) && a[i][j]=='.'){
				++c;
				if(c>2){
					f=1;
				}
				idx=i;
				idy=j;
			}
		}
	if(c!=2){
		cout<<"invalid\n";
		continue;
	}
	stack<pair<int,int>> s;
	s.push(make_pair(idx,idy));
	while(s.empty()==false){
		int i=s.top().first;
		int j=s.top().second;
		s.pop();
		if(f==1){
		break;}
		if(vis[i][j]==0){
			vis[i][j]=1;
			for(int k=0;k<4;++k){
				if(i+x[k]>=0&&i+x[k]<n&&j+y[k]>=0&&j+y[k]<m){
					int xx=i+x[k];
					int yy=j+y[k];
					if(a[i+x[k]][j+y[k]]=='#'||vis[i+x[k]][j+y[k]]==1)continue;
					else if((xx==0||xx==n-1||yy==0||yy==m-1))
						f=1;
					else s.push(make_pair(xx,yy));
					
				}
			}
		}
	}
	if(f==0)cout<<"invalid\n";
	else cout<<"valid\n";
	
	
		
}
}
