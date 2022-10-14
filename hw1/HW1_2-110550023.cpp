#include <iostream>
#include <vector>
using namespace std;


vector<vector <int>> adj;
vector<int> infected;

int main(){

    int n,m,k,t;
    int cnt = 0;
    cin >> n >> m >> k >> t;


    adj.resize(n,vector<int>());
    infected.resize(n,0);

    for(int i=0;i<m;i++){
        int a,b;

        cin >> a >> b;

        adj[--a].push_back(--b);
    }

    vector<int> bfs;

    for(int i=0;i<k;i++){
        int a;
        cin >> a;
        bfs.push_back(--a);
        infected[a] = 1;
        cnt ++;
    }
    int prev_cnt = cnt;
    for(int i=1;i<t;i++){
        vector<int> new_round;

        for(int a:bfs){
            for(int b:adj[a]){
                if(!infected[b]){
                    infected[b] = 1;
                    cnt++;
                    new_round.push_back(b);
                }
            }
        }

        bfs = new_round;

        if(prev_cnt == cnt) break;
        prev_cnt = cnt;
    }

    cout << cnt << endl;



    return 0;
}