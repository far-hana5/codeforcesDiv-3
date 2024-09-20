#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    string s; cin>>s;

    map<char,int>mp;
    for(auto itr:s){mp[itr]++;}

    vector<pair<int,char>>v;
    for(auto itr:mp){
        v.push_back({itr.second,itr.first});
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    string ans="";string temp="";

    for(auto it:v){ temp.push_back(it.second);}
    int sum=0;int i=v.size()-1;

    while(i>=0){
        int req=v[i].first-sum;
        for(int j=0;j<req;j++){
            ans+=temp;
        }
        sum+=req;
        temp.pop_back();
        i--;
    }
    cout<<ans<<endl;
}
int main(){
   int t;
   cin>>t;
   while(t--) {
    solve();
   }
}