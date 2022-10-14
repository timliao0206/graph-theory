#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>

using namespace std;

int simliar(string s1,string s2){
    int i=0;
    for(i=0;i<s1.length();i++){
        if(i>=s2.length()) break;
        if(s1[s1.length()-1-i] != s2[i]) break;
    }

    return i;
}

inline bool isSubstring(string s1,string s2){
    return s1.find(s2) != string::npos;
}

vector<vector<int>> graph;

int dp[1<<18][18];
int path[1<<18][18];

int main(){

    int n;
    cin >> n;

    vector<string> str;

    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        str.push_back(s);
    }

    cout << "in";
    for(int i=0;i<n;i++){
    
        for(int j=0;j<n;j++){
            if(i == j) continue;
            if(isSubstring(str[i],str[j])){
                n--;
                str.erase(str.begin() + j);
                j--;
            }
        }
    }

    graph.resize(n,vector<int>(n,0));

    for(int i=0;i<n;i++){
        graph[i][i] = 0;
        for(int j=i+1;j<n;j++){
            graph[i][j] = simliar(str[i],str[j]);
            graph[j][i] = simliar(str[j],str[i]);
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout << graph[i][j] << " ";
    //     }

    //     cout << endl;
    // }

    int last = -1;
    int min = INT_MAX;

    for(int i=1;i<(1<<n);i++){
        cout << i;
        for(int j=0;j<n;j++) dp[i][j] = INT_MAX;

        for(int j=0;j<n;j++){
            //is set
            if(i & (1<<j)){
                int prev = i ^ (1<<j);

                //if is only set
                if(prev){
                    dp[i][j] = str[j].length();
                }else{
                    for(int k=0;k<n;k++){

                        //dp[i][j] = min k dp[prev][k] + graph[k][j]
                        if(dp[prev][k] < INT_MAX && dp[prev][k] + graph[k][j] < dp[i][j]){
                            dp[i][j] = dp[prev][k] + graph[k][j];
                            path[i][j] = k;
                        }
                    }
                }
            }

            if(i == (1<<n) - 1 && dp[i][j] < min){
                min = dp[i][j];
                last = j;
            }
        }
    }


    //reconstruct

    string ans = "";
    int current = (1<<n) -1;

    stack<int> st;

    while(current){
        st.push(last);
        int tmp = current;
        current ^= (1 << last);
        last = path[tmp][last];
    }

    int prev_idx = -1;

    while(!st.empty()){
        if(ans == ""){
            int idx = st.top();
            st.pop();
            ans += str[idx];
            prev_idx = idx;
            continue;
        }

        int idx = st.top();
        st.pop();

        ans += string(str[idx],simliar(str[prev_idx],str[idx]));
        prev_idx = idx;
    }

    cout << ans << endl;

    return 0;
}