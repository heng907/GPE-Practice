#include<bits/stdc++.h>
using namespace std;
int n; 
int arr[10];
int dp[10];
vector<vector<int>> results;

void dfs(int i, vector<int>& current){
    current.push_back(arr[i]);
    if(dp[i] == 1){
        vector<int> seq(current.rbegin(), current.rend());
        results.push_back(seq);
    }
    else{
        for(int j=i-1; j>=0; j--){
            if(arr[j]<arr[i] && dp[j] == dp[i]-1){
                dfs(j, current);
            }
        }
    }
    current.pop_back();
}


int main(){
    int t;
    while(cin>>t){
        while(t--){
            cin>>n;
            for(int i=0; i<n; i++){
                cin>>arr[i];
            }
            // 直接做 LIS
            for(int i=0; i<n; i++){
                dp[i] = 1;
                for(int j=0; j<i; j++){
                    if(arr[j]<arr[i]){
                        dp[i] = max(dp[i], dp[j]+1);
                    }
                }
            }
            int maxlen = 0;
            for(int i=0; i<n; i++){
                maxlen = max(maxlen, dp[i]);
            }
            // dfs 回去找 seq
            results.clear();
            vector<int> curr;
            for(int i=0; i<n; i++){
                if(dp[i] == maxlen){
                    dfs(i, curr);
                }
            }
            // 先對result的內部做sort，再reverse
            sort(results.begin(), results.end());
            reverse(results.begin(), results.end());
            // 輸出
            cout<<results.size()<<endl;
            for(auto& seq: results){
                for(int i=0; i<seq.size(); i++){
                    if(i){
                        cout<<" ";
                    }
                    cout<<seq[i];
                }
                cout<<endl;
            }
        }
    }
}