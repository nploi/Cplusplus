//http://lightoj.com/volume_showproblem.php?problem=1224

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

#define MAX 4
using namespace std;

//map<char, int> mm;

int MAP[85] ;

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
        if(s.size() == 0){
            return 0;
        }
        int ch, Max = -1;
        node *temp = root;
        for (int i = 0; i < s.size(); ++i) {
            ch = MAP[s[i]];
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
        int ch, Max = -1;
        node *temp = root;
        for (int i = 0; i < s.size(); ++i) {
            ch = MAP[s[i]];
            if (temp->child[ch] == NULL) {
                temp->child[ch] = newNode(0);
            }
            temp->count++;
            if ((i) * temp->count > Max) {
                Max = (i) * temp->count;
            }
            temp = temp->child[ch];
        }
        temp->count++;
        if ((s.size()) * temp->count > Max) {
            Max = (s.size()) * temp->count;
        }
        temp->countLeaf++;
        return Max;
    }

    int find_pri(node *&root, string s) {
        int ch;
        node *temp = root;
        for (int i = 0; i < s.size(); ++i) {
            ch = MAP[s[i]];
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

        int ch = MAP[s[level]];
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

    long n, Max = 0, test;
    long num = 1;

    MAP[65] = 0;
    MAP[67] = 1;
    MAP[71] = 2;
    MAP[84] = 3;
    cin >> test;
    while (test--){
        trie t;
        string a[4];
        cin >> n;
        Max = 0;
        for (int i = 0; i < n; ++i) {
            string str;
            cin >> str;
            int temp = t.add(str);
            if(temp > Max){
                Max = temp;
            }
        }
        cout <<"Case " << num ++ <<": "<< Max << endl;
        t.deleteWords();
    }

    return 0;
}
