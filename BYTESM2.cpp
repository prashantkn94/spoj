#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        int r,c;
        cin>>r>>c;
        int a[r][c];
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j)
                cin>>a[i][j];
        }
        for(int i=1;i<r;++i){
            for(int j=0;j<c;++j){
               if(j==0)a[i][j]=a[i][j]+max(a[i-1][j],a[i-1][j+1]);
                else if(j==c-1)a[i][j]=a[i][j]+max(a[i-1][j-1],a[i-1][j]);
                else a[i][j]=a[i][j]+max(max(a[i-1][j-1],a[i-1][j]),a[i-1][j+1]);
            }
        }
        int max=-1;
        for(int j=0;j<c;++j){
        	if(a[r-1][j]>max)max=a[r-1][j];
        }
        cout<<"\n"<<max;

    }

}
