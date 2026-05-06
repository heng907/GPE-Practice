#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v(1000001);

bool sol(int mid){
    int container = 1;
    int sum = 0; // 用來累積每瓶牛奶的容量
    for(int i=0; i<n; i++){
        if(sum + v[i] > mid){
            container++; // 目前這個 vessel 放不進當前的 container
            sum = v[i]; // 新 container 裡已經有 v[i] 這個 vessel 的量
            if(container > m){
                return false;
            }
        }
        else{
            sum += v[i];
        }
    }
    return true;
}

int main(){

    while(cin>>n>>m){
        
        int left=0;  // vessel 中最大的那個
        int right=0; // 所有 vessel 的總和
        int mid;
        
        for(int i=0; i<n; i++){
            cin>>v[i];
            right += v[i];
            left = max(left, v[i]);
        }

        while(left < right){
            mid = (left + right) / 2;
            if(sol(mid)){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        cout<<left<<endl;
    }
    return 0;
}