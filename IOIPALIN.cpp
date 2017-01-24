#include <bits/stdc++.h>
using namespace std;
int a[5000][5000];
int n;
string s;
int f(int i,int j){
    if(i>=j)return 0;
    if(a[i][j]>=0)return a[i][j];
    else{
        if(s[i]==s[j]){
            a[i][j]=f(i+1,j-1);
            //cout<<"a[i][j] is "<<a[i][j]<<endl;
        }
        else{
        a[i][j]=1+min(f(i,j-1),f(i+1,j));
        //cout<<"a[i][j] is "<<a[i][j]<<endl;
    }
    }
    return a[i][j];
}
int main(){
memset(a,-1,sizeof a);
cin>>n;
cin>>s;
cout<<f(0,n-1)<<"\n";

}
