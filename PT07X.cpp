#include <bits/stdc++.h>
using namespace std;
const int N=(int)1e5+5;
int a1[N],a2[N];
vector<int> g[N];
void dfs(int v,int p){
  int s1=0,s2=0;
  for(int i:g[v]){
    if(i==p)continue;
    dfs(i,v);
    s2+=a1[i];
    s1+=min(a1[i],a2[i]);

  }
  a2[v]=s2;
  a1[v]=1+s1;
}
int main(){
  int n;
  cin>>n;
  for(int i=0;i<n-1;++i){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1,0);
  cout<<min(a1[1],a2[1])<<endl;
}
