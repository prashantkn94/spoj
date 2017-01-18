#include <bits/stdc++.h>
using namespace std;
const int inf=(int)1e9;
int main(){
    int t;
    cin>>t;
    while(t--){
    string s;
    cin>>s;
    int n=s.length();
    long long int a[n][n],b[n][n];
    memset(a,-1,sizeof a);
    
    for(int i=0;i<n;++i){
        if(!(s[i]>='0'&&s[i]<='9'))continue;
        a[i][i]=s[i]-'0';
        b[i][i]=s[i]-'0';
    }
   
    for(int len=3;len<=n;len+=2){
        for(int i=0;i<=n-len;i+=2){
            //if(!(s[i]>='0'&&s[i]<='9'))continue;
            int j=i+len-1;
            b[i][j]=inf;
            for(int k=i;k<j;k+=2){
                if(s[k+1]=='+'){
                if(a[i][j]<a[i][k]+a[k+2][j])
                    a[i][j]=a[i][k]+a[k+2][j];
                if(b[i][j]>b[i][k]+b[k+2][j])
                    b[i][j]=b[i][k]+b[k+2][j];

            }
                else {
                    if(a[i][j]<a[i][k]*a[k+2][j])
                        a[i][j]=a[i][k]*a[k+2][j];
                    if(b[i][j]>b[i][k]*b[k+2][j])
                        b[i][j]=b[i][k]*b[k+2][j];
                }

            }

        }
    }
    cout<<a[0][n-1]<<" "<<b[0][n-1]<<"\n";
}
}
