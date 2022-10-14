#include <iostream>

using namespace std;

int adj[1001][1001];
int in[1001];
int out[1001];

int main(){

    int n,m;
    cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            adj[i][j] = 0;
        }

        in[i] = 0;
        out[i]=0;
    }

    for(int i=0;i<m;i++){
        int x,y,w;
        cin >> x >> y >> w;
        x--;
        y--;

        in[x]++;
        out[y]++;

        adj[x][y] = w;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << adj[i][j] << " ";
        }

        cout << endl;
    }

    for(int i=0;i<n;i++){
        cout << out[i] << " " << in[i];
        cout << endl;
    }


    return 0;
}