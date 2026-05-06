#include<bits/stdc++.h>
using namespace std;

int main(){
    int val[] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};
    int num = 11;
    int MAX = 6000;

    long long dp[6001]={0};
    // 湊出 0 元 有 1 種方法
    dp[0]=1;

    for(int i=0; i<num; i++){
        for(int j=val[i]; j<=MAX; j++){
            dp[j] += dp[j-val[i]];
        }
    }

    double n;
    while(cin>>n && n != 0.0){
        int ans = (int)round(n/0.05);
        cout<<fixed<<setprecision(2)<<setw(6)<<n<<setw(17)<<dp[ans]<<endl;
    }
    return 0;
}