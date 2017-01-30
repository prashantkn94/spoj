#include <bits/stdc++.h>
using namespace std;
int c[26];
int main(){
    string a;
    while(cin>>a){
        memset(c,0,sizeof c);
        string b;
        cin>>b;
        vector<char> ans;
        for(char t:a){
            c[t-97]++;
        }

        for(char t:b){
            if(c[t-97]>0){
                char temp=t-97;
                ans.push_back(t);
                --c[t-97];
            }
        }
        sort(ans.begin(),ans.end());
        for(char t:ans)
            cout<<t;
        cout<<"\n";
    }
}
