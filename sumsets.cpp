#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(cin>>n && n!=0){
        vector<ll> SET(n);
        for(int i=0; i<n; i++){
            cin>>SET[i];
        }
        sort(SET.begin(), SET.end());
        // count all (a + b)
        unordered_map<ll, pair<int, int>> pair_sum;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                pair_sum[SET[i]+SET[j]] = {i, j};
            }
        }
        
        bool find = false;
        // 從最大的 d 往小枚舉 c，查詢 target = d - c
        for(int d = n-1; d>=0 && !find; d--){
            for(int c = 0; c<n && !find; c++){
                if(c==d) continue; // 直接跳過，因為 c 和 d 不能是同一個元素
                // d - c
                ll target  = SET[d] - SET[c];
                // the target index
                auto it = pair_sum.find(target);
                // 如果 it = false 就不執行
                if(it != pair_sum.end()){
                    int i = it->second.first;
                    int j = it->second.second;
                    // 題目要求 a、b、c、d 是四個不同的元素
                    if(i != c && j != c && i != d && j != d){
                        cout << SET[d]<<endl;
                        find = true;
                        break;
                    }
                }
            }
        }

        if(!find){
            cout << "no solution"<<endl;
        }

    }
    
}