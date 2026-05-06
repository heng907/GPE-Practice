#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while(cin>>n>>m){
        vector<int> val(m);
        for(int i=0; i<m; i++){
            cin>>val[i];
        }
        // dp[i] = true, if Stan wins when there are i stones
        vector<bool> dp(n+1, false);
        for(int i=1; i<=n; i++){
            for(int j=0; j<m; j++){
                // check 這步移動是否 valid 且 剩下石頭數量對下一個拿的人是否必敗
                if(i - val[j] >=0 && !dp[i-val[j]]){
                    dp[i] = 1;
                    break;
                }
            }
        }
        if(dp[n]) cout<<"Stan wins"<<endl;
        else cout<<"Ollie wins"<<endl;
    }
    return 0;
}

