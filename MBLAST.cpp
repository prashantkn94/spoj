#include <bits/stdc++.h>
using namespace std;
const int N=(int)1e6;
int a[2001][2001];
int k;
int main(){
  std::ios_base::sync_with_stdio(false);  
  string s,p;
  cin>>s>>p;
  int k;
  cin>>k;
  for(int i=1;i<=s.length();++i)
    a[i][0]=i*k;
  for(int i=1;i<=p.length();++i)
    a[0][i]=i*k;

  for(int i=1;i<=s.length();++i){
    for(int j=1;j<=p.length();++j){
      a[i][j]=min(a[i-1][j-1]+abs(s[i-1]-p[j-1]),min(a[i-1][j]+k,a[i][j-1]+k));
    }
  }
  cout<<a[s.length()][p.length()]<<endl;

}
