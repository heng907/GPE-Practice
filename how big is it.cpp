#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        int m;
        cin>>m;
        vector<double> r(m);
        for(int i=0; i<m; i++){
            cin>>r[i];
        }

        sort(r.begin(), r.end());
        double best = 1e18;

        do{
            vector<double> cx(m); // 每個圓的圓心 x 座標
            cx[0] = r[0];
            for(int i=1; i<m; i++){
                cx[i] = r[i];
                // 檢查前面每一個圓
                // 放第 i 個圓時，它不能和前面任何一個圓重疊
                for(int j=0; j<i; j++){
                    // 對前面每個圓 j，計算「圓 i 和圓 j 不重疊的最小 x」，取最大值
                    cx[i] = max(cx[i], cx[j]+2.0*sqrt(r[j]*r[i]));
                }
            }
            double width = 0;
            for(int i=0; i<m; i++){
                width = max(width, cx[i]+r[i]);
            }
            best = min(best, width);
        }while(next_permutation(r.begin(), r.end()));

        cout << fixed << setprecision(3)<<best<<endl;
    }
    return 0;
}