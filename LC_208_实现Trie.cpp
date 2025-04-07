//
// Created by cml on 25-4-6.
//
#include <iostream>
#include <string>
using namespace std;

struct Node {
    Node *next[26];
    // 这个变量特别关键，用来表示当前位置是否为一个单词的结尾，因为插入过程中可能出现插入的某个词是另一个词的前缀，
    // 如果不用变量区分的话，后边的完全匹配可能会被当做前缀匹配
    bool isend = false;
};

class Trie {
    Node *root;

    int find(string word) {
        Node *p = root;
        for (char c: word) {
            c -= 'a';
            if (p->next[c] == nullptr)
                return 0;
            p = p->next[c];
        }
        return p->isend ? 2 : 1;
    }

public:
    Trie() {
        root = new Node();
        root->isend = true;
    }

    void insert(string word) {
        Node *p = root;
        for (char c: word) {
            c -= 'a';
            if (p->next[c] == nullptr)
                p->next[c] = new Node();
            p = p->next[c];
        }
        p->isend = true;
    }

    bool search(string word) { return find(word) == 2; }

    bool startsWith(string prefix) { return find(prefix) != 0; }
};

int main() {
    Trie *trie = new Trie();
    trie->insert("apple");
    cout << trie->search("apple") << endl; // 返回 True
    cout << trie->search("app") << endl; // 返回 False
    cout << trie->startsWith("app") << endl; // 返回 True
    trie->insert("app");
    cout << trie->search("app") << endl; // 返回 True
    return 0;
}
