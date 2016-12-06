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
int a[8][8];
int dis[8][8];
int x[8]={1,1,2,2,-1,-1,-2,-2};
int y[8]={2,-2,1,-1,2,-2,1,-1};
int main(){
int t;
cin>>t;
while(t--){
memset(a,0,sizeof(a));
memset(dis,0,sizeof(dis));
int xi,xe;
char r,rr;
int yi,ye;
cin>>r>>xi>>rr>>xe;
xi=xi-1;
xe=xe-1;
yi=r-97;
ye=rr-97;
int c=0;
queue<pair<int,int>> q;
q.push(make_pair(xi,yi));
if(xi==xe&&yi==ye){cout<<0<<"\n";continue;}
int f=0;
a[xi][yi]=1;
dis[xi][yi]=0;
while(q.empty()==false){
	if(f==1)break;
	int xx=q.front().first;
	int yy=q.front().second;
	q.pop();
	for(int i=0;i<8;++i){
		int xxx=x[i]+xx;
		int yyy=y[i]+yy;
		if(xxx>=0&&xxx<8&&yyy>=0&&yyy<8&&a[xxx][yyy]==0){
			a[xxx][yyy]=1;
			dis[xxx][yyy]=dis[xx][yy]+1;
			q.push(make_pair(xxx,yyy));
		if(xxx==xe&&yyy==ye){
			f=1;
			break;
		}
		}
	}
}
cout<<dis[xe][ye]<<"\n";
}
}
