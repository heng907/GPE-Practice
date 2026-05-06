#include<bits/stdc++.h>
using namespace std;
// 用計算機慢慢算，記得從0開始
const int m[20]={0, 1, 5, 2, 8, 3, 9, 2, 8, 7, 7, 8, 4, 7, 3, 8, 4, 1, 5, 4};
int main(){
    string n;
    while(cin>>n){
        if(n == "0") break;
        int len = n.size();
        
        char a, b;
        int val;
        int A, B;
        // 取最後兩位數
        if(len==1){
            b = n[len-1];
            B = b-'0';
            val = B;
        }
        else{
            a = n[len-2];
            b = n[len-1];
            A = a-'0';
            B = b-'0';
            val = A*10 + B;
        }      
        int idx = val % 20;
        // val 每20個會*4
        int ans = m[idx] + val/20*4;
        // 最後再取last digit
        ans %= 10;
        cout << ans << endl;
    }
    return 0;
}