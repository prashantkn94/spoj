#include <iostream>
#include <string>
using namespace std;
int c[6102][6102];
int main() {
    int t;
    cin>>t;
    while(t--){
    	string s;
    	cin>>s;
    	string r;
    	for(int i=s.length()-1;i>=0;--i){
    		r+=s[i];
    	}
    	for(int i=0;i<=s.length();++i)
    	c[i][0]=0;
    	for(int i=0;i<=s.length();++i)
    	c[0][i]=0;
    	for(int i=1;i<=s.length();++i){
    		for(int j=1;j<=s.length();++j){
    			if(s[i-1]==r[j-1])c[i][j]=c[i-1][j-1]+1;
    			else if(c[i-1][j]>c[i][j-1])c[i][j]=c[i-1][j];
    			else c[i][j]=c[i][j-1];
    		}
    	}
    	cout<<"\n"<<s.length()-c[s.length()][s.length()];
    	
    }
}
