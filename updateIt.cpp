#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
int bit[2000000];
void update(int n,int val,int index){
  while(index<=n){
    bit[index]+=val;
    index=index+(index & (-index));
  }
}
long int sum(int index){
  long int ans=0;
  while(index!=0){
    ans+=bit[index];
    index=index-(index & (-index));
    
  }
  return ans;
}
int main(){
  int t,n,c;
  scanf("%d",&t);
  while(t--){
  scanf("%d %d",&n,&c);
  memset(bit,0,sizeof(bit));
  while(c--){
  
  		long int p,q,v;
  		scanf("%ld %ld %ld",&p,&q,&v);
  		update(n,v,p+1);
  		update(n,-v,q+2);
 
}
int q;
scanf("%d",&q);
while(q--){
	int x;
	scanf("%d",&x);
	printf("%ld\n",sum(x+1));
}
}
}
  
