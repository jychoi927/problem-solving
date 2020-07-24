#include <iostream>
#include <vector>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

const int MAX = 26;
vector<pair<char,char>> v[MAX];

//전위순회 : 부모 출력 -> left child 이동 -> right child 이동
void preorder(char node){
    cout << node;
    if(v[node - 'A'].front().first != '.') //left child가 null이 아니면
        preorder(v[node - 'A'].front().first);
    if(v[node - 'A'].front().second != '.') //right_child가 null이 아니면
        preorder(v[node - 'A'].front().second);
}
//중위순회 : left child 이동 -> 부모 출력 -> right child 이동
void inorder(char node){
    if(v[node - 'A'].front().first != '.')
        inorder(v[node - 'A'].front().first);
    cout << node;
    if(v[node - 'A'].front().second != '.')
        inorder(v[node - 'A'].front().second);
}
//후위순회 : left child 이동 -> right child 이동 -> 부모 출력
void postorder(char node){
    if(v[node - 'A'].front().first != '.')
        postorder(v[node - 'A'].front().first);
    if(v[node - 'A'].front().second != '.')
        postorder(v[node - 'A'].front().second);
    cout << node;
}

int main(){
    fastio;

    int n;
    char parent, left_child, right_child;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> parent >> left_child >> right_child;
        v[parent-'A'].push_back(make_pair(left_child, right_child));
    }
	
    preorder('A');
    cout << endl;
    inorder('A');
    cout << endl;
    postorder('A');
    cout << endl;
	
    return 0;
}
