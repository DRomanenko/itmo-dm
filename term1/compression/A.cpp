#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll sum = 0;

class Node {
public:
    ll val;
    Node *left = nullptr, *right = nullptr;

    Node () {}

    Node (Node *l, Node *r) {
        left = l;
        right = r;
        val = l -> val + r -> val;
    }
};

void count(Node *root, ll k = 0) {
    if (root != nullptr) {
        count(root -> left, k + 1);
        if (root -> left == nullptr && root -> right == nullptr) {
            sum += (k) * root -> val;
        }
        count(root -> right, k + 1);
    }
}

bool cmp (Node* l, Node *r) {
    return l -> val < r -> val;
}

int main() {
    iostream::sync_with_stdio(0), cin.tie(0);
    ifstream cin("huffman.in");
    ofstream cout("huffman.out");

    ll n;
    cin >> n;
    list<Node*> huffmanTree;
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        Node *curr = new Node;
        curr -> val = a;
        huffmanTree.push_back(curr);
    }
    while (huffmanTree.size() != 1) {
        huffmanTree.sort(cmp);

        Node *sonL = huffmanTree.front();
        huffmanTree.pop_front();
        Node *sonR = huffmanTree.front();
        huffmanTree.pop_front();

        Node *parent = new Node(sonL, sonR);
        huffmanTree.push_back(parent);
    }
    Node *root = huffmanTree.front();
    count(root);
    cout << sum << endl;
    return 0;
}
