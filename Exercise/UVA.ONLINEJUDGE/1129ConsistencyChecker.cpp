//http://lightoj.com/volume_showproblem.php?problem=1129
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

#define MAX 10
using namespace std;



struct node {
    struct node *child[MAX];
    int countLeaf, count;
    node(){
        for (int i = 0; i < MAX; ++i) {
            child[i] = NULL;
        }
    }
};

struct node *newNode(int count){
    node *Node = new node;
    Node->countLeaf = 0;
    Node->count = count;
    for (int i = 0; i < MAX; ++i) {
        Node->child[i] = NULL;
    }
    return Node;
}

class trie {

public:
    trie() {
        root = newNode(0);
    }

    long add(string str) {
        return add_pri(root, str);
    }

    int find(string str) {
        return find_pri(root, str);
    }

    int findMax(string str) {
        return findMax(root, str);
    }

    void deleteWord(string str) {
        deleteWord_pri(root, str, 0, str.size());
    }

    void deleteWords(){
        deletenode(this->root);
    }

private:
    void deletenode(node *pNode)
    {
        for (int i = 0; i<MAX; i++)
        {
            if (pNode->child[i])
            {
                deletenode(pNode->child[i]);
                delete pNode->child[i];
            }
        }
    }

    int findMax(node *root, string s) {
        if (s.size() == 0) {
            return 0;
        }
        int ch, Max = -1;
        node *temp = root;
        for (int i = 0; i < s.size(); ++i) {
            ch = s[i] - '1' + 1;
            if (temp->child[ch] == NULL) {
                return false;
            }
            if ((i) * temp->count > Max) {
                Max = (i) * temp->count;
            }
            temp = temp->child[ch];
        }
        if ((s.size()) * temp->count > Max) {
            Max = (s.size()) * temp->count;
        }
        return Max;
    }

    int add_pri(node *&root, string s) {
        int ch;
        node *temp = root;
        bool flag = false;
        for (int i = 0; i < s.size(); i++) {
            ch = s[i] - '1' + 1;
            if (temp->child[ch] == NULL) {
                temp->child[ch] = newNode(0);
                flag = true;
            }

            temp = temp->child[ch];
            if (temp->countLeaf == 1) {
                flag = false;
                break;
            }
        }
        temp->countLeaf = 1;
        return flag;
    }

    int find_pri(node *&root, string s) {
        int ch;
        node *temp = root;
        for (int i = 0; i < s.size(); ++i) {
            ch = s[i] - '1' + 1;
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

        int ch = s[level] - '1' + 1;
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

int main() {

    int test, n, num = 1;

    cin >> test;
    while (test--) {
        trie t;
        bool check = true;
        cin >> n;
        string first;
        for (int i = 0; i < n; ++i) {
            string str;
            cin >> str;
            if (!t.add(str)) {
                check = false;
            }
        }
        cout << "Case " << num++ << ": " << ((check == true) ? "YES" : "NO") << endl;
        t.deleteWords();
    }

    return 0;
}
