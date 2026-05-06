#include<bits/stdc++.h>
using namespace std;

struct Node{
    // 子資料夾的名字; 子資料夾節點的指標
    map<string, Node*> children;
};

// construct the tree
void insert(Node* root, const string& path){
    Node* cur = root;
    string name;
    stringstream ss(path);
    // seperate the path with "\"
    while(getline(ss, name, '\\')){
        // 在children裡面找有沒有 name
        if(!cur->children.count(name)){
            cur->children[name] = new Node();
        }
        // 移到下一層
        cur = cur->children[name];
    }
}

// dfs print the tree
void dfs(Node* node, int depth){
    for(auto& [name, child]:node->children){
        // 用來產生縮排空格的，深度幾層就印幾個空格
        cout << string(depth, ' ') << name << endl;
        dfs(child, depth+1);
    }
}

int main(){
    int n;
    while(cin>>n){
        cin.ignore();
        Node* root = new Node();
        for(int i=0; i<n; i++){
            string path;
            getline(cin, path);
            insert(root, path);
        }
        dfs(root, 0);
        cout<<endl;
    }
}