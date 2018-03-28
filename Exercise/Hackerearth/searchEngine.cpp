//https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/search-engine/

#include <iostream>
#include <string>

#define MAX 26

using namespace std;

struct node {
    struct node *child[MAX];
    int countLeaf, priority;
    node(){
        for (int i = 0; i < MAX; ++i) {
            child[i] = NULL;
        }
    }
};

struct node *newNode(int weight){
    node *Node = new node;
    Node->countLeaf = 0;
    Node->priority = weight;
    for (int i = 0; i < MAX; ++i) {
        Node->child[i] = NULL;
    }
    return Node;
}

class trie {

public:
    trie(){
        root = newNode(-1);
    }
    void add(string str, int weight) {
        add_pri(root, str, weight);
    }

    int find(string str) {
        return find_pri(root, str);
    }

    int findPriorityMax(string str){
        return findPriorityMax(root, str);
    }
    void deleteWord(string str) {
        deleteWord_pri(root, str, 0, str.size());
    }

private:
    int findPriorityMax(node * root, string s){
        int ch;
        node *temp = root;
        for (int i = 0; i < s.size(); ++i) {
            ch = s[i] - 'a';
            if (temp->child[ch] == NULL) {
                return false;
            }
            temp = temp->child[ch];
        }

        return (temp->priority);
    }
    void add_pri(node *&root, string s, int weight) {
        int ch;
        node *temp = root;
        for (int i = 0; i < s.size(); ++i) {
            ch = s[i] - 'a';
            if (temp->child[ch] == NULL) {
                temp->child[ch] = newNode(weight);
            }
            temp->priority = max(temp->priority, weight);
            temp = temp->child[ch];
        }
        temp->priority = max(temp->priority, weight);
        temp->countLeaf++;
    }

    int find_pri(node *&root, string s) {
        int ch;
        node *temp = root;
        for (int i = 0; i < s.size(); ++i) {
            ch = s[i] - 'a';
            if (temp->child[ch] == NULL) {
                return false;
            }
            temp = temp->child[ch];
        }

        return (temp->countLeaf > 0);
    }

    bool deleteWord_pri(node *&root, string s, int level, int len) {
        if (!root)
            return false;

        int ch = s[level] - 'a';
        if (level == len) {
            if (root->countLeaf > 0) {
                root->countLeaf--;
                return true;
            }
            return false;
        }
        int flag = deleteWord_pri(root->child[ch], s, level + 1, len);

        if (flag && !isWord(root->child[ch]) && isEmpty(root->child[ch])) {
            delete root->child[ch];
            root->child[ch] = NULL;
        }
        return flag;
    }

    bool isEmpty(node *root) {
        for (int i = 0; i < MAX; ++i) {
            if (root->child[i] != NULL) {
                return false;
            }
        }
        return true;
    }

    bool isWord(node *pNode) {
        return (pNode->countLeaf != 0);
    }

private:
    node *root;
};

int main(){
    trie t;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        string str;
        int weight;
        cin >> str >> weight;
        t.add(str, weight);
    }

    for (int j = 0; j < m; ++j) {
        string str;
        cin >> str;
        int result = t.findPriorityMax(str);
        cout << ((result != 0) ? result : -1) << endl;
    }
    return 0;
}
