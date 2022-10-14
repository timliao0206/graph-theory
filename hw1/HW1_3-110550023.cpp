#include <iostream>
#include <vector>
#include<algorithm>
#include <climits>
#include <stdio.h>

using namespace std;

void solve(){
    
    int n,m;
    cin >> n >> m;

    vector<long long> deg;
    deg.push_back(2LL*n);
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        deg.push_back(tmp);
    }

    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        deg[u]--;
        deg[v]--;
    }

    bool nflag = 0,eflag=0;

    for(int i=1;i<=n;i++){
        nflag |= deg[i] < 0;
        if(deg[i] % 2)
            eflag = !eflag;
    }

    if(nflag || eflag){
        cout << "No\n";
        return;
    }

    sort(deg.begin(),deg.end(),greater<long long>());

    vector<long long> prefix;
    prefix.push_back(0LL);
    vector<long long> subfix(n+2,0LL);

    long long cnt = 0LL;
    for(int i=1;i<=n;i++){
        cnt += deg[i];
        prefix.push_back(cnt);
    }

    for(int i=n;i>=1;i--){
        subfix[i] = subfix[i+1] + deg[i];
    }

    int less_idx = n;

    for(int k=1;k<=n;k++){

        
        while(less_idx >= 1 && deg[less_idx] < k){
            less_idx--;
        }
        

        long long sum = (long long)k*(long long)(k-1);
        
        if(less_idx >= k+1){
            sum += (long long)(less_idx - k)*(long long)k + subfix[less_idx+1];
        }else{
            sum += subfix[k+1];
        }

        if(sum < prefix[k]){
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
    return;





    return;
}

int main(){
    cin.tie();
    cin.sync_with_stdio(0);

    //test();

    int q;

    cin >> q;

    for(int i=0;i<q;i++){
        solve();
    }


    return 0;
}