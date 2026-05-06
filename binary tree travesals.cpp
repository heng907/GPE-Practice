#include<bits/stdc++.h>
using namespace std;

void post(vector<char> &pre, vector<char> &in, int preStart, int inStart, int n){
    if(n<=0) return;
    char root = pre[preStart];
    
    // 在 inorder 找根的位置
    int index = 0;
    for(int i=inStart; i<inStart+n; i++){
        if(in[i] == root){
            index = i;
            break;
        }
    }

    int left_len = index - inStart;
    int right_len = n - (left_len+1);

    // left child
    post(pre, in, preStart+1, inStart, left_len);
    // right child
    post(pre, in, preStart+1+left_len, index+1, right_len);
    // root
    cout<<root<<" ";
}


int main(){
    int m;
    cin>>m;
    for(int i=0; i<m; i++){
        int n;
        cin >> n;
        vector<char> pre(n);
        vector<char> in(n);

        for(int i=0; i<n; i++){
            cin>>pre[i];
        }
        for(int i=0; i<n; i++){
            cin>>in[i];
        }
        post(pre, in, 0, 0, n);
        cout<<endl;

    }
    return 0;
}