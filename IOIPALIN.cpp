#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
int a[5003][5003];
char s[5003];
int main(){
	int n;
	scanf("%d",&n);
	scanf("%s",s);
	for(int i=0;i<n;++i)a[i][i]=0;
	for(int i=n-1;i>=0;--i){
		for(int j=i+1;j<n;++j){
			if(s[i]==s[j])
				a[i][j]=a[i+1][j-1];
			else a[i][j]=1+min(a[i+1][j],a[i][j-1]);
		}
	}
	printf("%d",a[0][n-1]);
}
