#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main(){
int m,n;
cin>>m>>n;
int t=n;
vector<vector<int>> v(m+1);
for(int i=1;i<m+1;++i)
    v[i].push_back(i);
while(t--){
    int i,j;
    cin>>i>>j;
    v[i].push_back(j);
    v[j].push_back(i);
}
if(m-1!=n){
    cout<<"\nNO\n";
    return 0;
}
bool visited[m+1];
for(int i=1;i<m+1;++i)
    visited[i]=false;
stack<int> mys;
mys.push(v[1][0]);
while(mys.empty()==false){
    int s=mys.top();
    mys.pop();
    if(visited[s]==false){
        visited[s]=true;
        for(int i=0;i<v[s].size();++i){
            if(visited[v[s][i]]==false){
                mys.push(v[s][i]);
            }
        }
    }
}
for(int i=1;i<m+1;++i){
    if(visited[i]==false){
        cout<<"\nNO\n";
        return 0;
    }
}
cout<<"\nYES\n";
return 0;
}
