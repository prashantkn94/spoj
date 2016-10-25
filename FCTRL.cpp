#include <iostream>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int c=0;
		while(n>0){
			n/=5;
			c+=n;
		}
		printf("%d\n",c);
	}
	
}
