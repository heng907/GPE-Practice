#include <bits/stdc++.h>
using namespace std;

int sol(int n){
    int empty;
    int total;
    empty = n;
    total = n;
    while(empty >= 3){
        int new_bottle = empty / 3;
        int rest_bottle = empty % 3;
        total = total + new_bottle;
        empty = new_bottle + rest_bottle;
    }

    if(empty == 2){
        total++;
    }
    return total;
}

int main(){
    int n;
    while(cin>>n){
        int ans;
        ans = sol(n);
        cout << ans<< endl;
    }
}