#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int mod = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    multiset<pair<ll,ll>> v;
    ll x;
    for(int i=0 ; i<n ; i++){
        cin>>x;
        if(x!=0)v.insert({-x,i+1});
    }
    vector<pair<ll,ll>> res;
    while(v.size()>1){
        auto it=*v.begin();
        v.erase(it);
        auto it2=*v.begin();
        v.erase(it2);
        res.push_back({it.second,it2.second});
        it.first+=1;
        it2.first+=1;
        if(it.first<0)v.insert(it);
        if(it2.first<0)v.insert(it2);
    }
    ll ans=res.size();
    cout<<ans<<'\n';
    for(auto& i:res){
        cout<<i.first<<" "<<i.second<<'\n';
    }    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    int k=1;
    while(t--){
        // cout<<"Case #"<<k++<<": ";
        solve();
    }
    return 0;
}    