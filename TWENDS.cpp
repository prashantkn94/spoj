#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
int a[1001][1001];
int v[1001];
int fun(int i,int j,int c){
	if(i>j)return 0;
	if(a[i][j]>=0)return a[i][j];
	else if(c==0){
		if(v[i]>=v[j]){
		a[i][j]=fun(i+1,j,1);
		}
		else {
			a[i][j]=fun(i,j-1,1);

		}
	}
	else{
		a[i][j]=max(v[i]+fun(i+1,j,0),v[j]+fun(i,j-1,0));
	}
	return a[i][j];
}
int main(){
	int n;
	int m=0;
	while(true){
	cin>>n;
	m++;
	if(n==0)break;
	int t=0;
	memset(a,-1,sizeof a);
	for(int i=0;i<n;++i){
		cin>>v[i];
		t+=v[i];
	}
	int p=fun(0,n-1,1)-(t-fun(0,n-1,1));
	cout<<"In game "<<m<<", the greedy strategy might lose by as many as "<<p<<" points.\n";
	}
	
}
