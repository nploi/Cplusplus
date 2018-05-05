/*
@author
    nploi1998@gmail.com
@date
    04/04/2018.
*/

//TODO(loinp)
#ifndef GTEST_TRIE_H
#define GTEST_TRIE_H

#include <iostream>
#include <string>
#include <sstream>

#define MAX 26

using namespace std;

struct node {
    struct node *child[MAX];
    int countLeaf;

    node() {
        for (int i = 0; i < MAX; ++i) {
            child[i] = NULL;
        }
    }
};

struct node *newNode(int count){
    node *Node = new node;
    Node->countLeaf = 0;
    for (int i = 0; i < MAX; ++i) {
        Node->child[i] = NULL;
    }
    return Node;
}

class Trie {

public:
    Trie() {
        root = newNode(0);
    }

    void add(string str) {
        add_pri(root, str);
    }

    int find(string str) {
        return find_pri(root, str);
    }


    void deleteWord(string str) {
        deleteWord_pri(root, str, 0, str.size());
    }

    void deleteAll() {
        deletenodes(this->root);
    }

    ~Trie() {
        if (this->root != NULL) {
            deleteAll();
        }
    }

private:
    void deletenodes(node *&pNode) {
        for (int i = 0; i < MAX; i++) {
            if (pNode->child[i]) {
                deletenodes(pNode->child[i]);
                if (pNode->child != NULL) {
                    delete pNode->child[i];
                }
            }
        }
    }

    void add_pri(node *&root, string s) {
        int ch;
        node *temp = root;
        for (int i = 0; i < s.size(); ++i) {
            ch = s[i] - 'a';
            if(ch < MAX + 1) {
                if (temp->child[ch] == NULL) {
                    temp->child[ch] = newNode(0);
                }
            }else{
                break;
            };
            temp = temp->child[ch];
        }
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

#endif //GTEST_TRIE_H
