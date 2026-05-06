#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    cin.ignore();
    for(int i=0; i<n; i++){
        string str;
        getline(cin, str);

        istringstream iss(str);
        vector<int> weights;
        int sum = 0;
        int w;
        // 把輸入變成 iss 讀進來
        while(iss >> w){
            weights.push_back(w);
            sum += w;
        }
        if(sum%2 != 0){
            cout<<"NO"<<endl;
            continue;
        }
        int target = sum /2;
        vector<bool> dp(target+1, 0);
        dp[0] = 1;
        // 做 dp
        for(int weight: weights){
            for(int j = target; j>=weight; j--){
                if(dp[j-weight]){
                    dp[j] = true;
                }
            }
        }
        if(dp[target] == true){
            cout << "Yes" << endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}