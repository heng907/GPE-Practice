#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll s, d;
    while(cin>>s>>d){
        ll sum = 0;
        ll people = s;
        sum = s;
        while(sum<d){
            people++;
            sum = sum + people;
        }
        cout<<people<<endl;
    }
}