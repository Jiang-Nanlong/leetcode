//
// Created by ������ on 25-2-27.
//
#include <iostream>
#include <string>
using namespace std;

class TextEditor {
    string left, right;

public:
    TextEditor() = default;

    void addText(string text) { left += text; }

    int deleteText(int k) {
        k = min(k, (int)left.size());
        left.resize(left.size() - k);
        return k;
    }

    string cursorLeft(int k) {
        while (k && !left.empty()) {
            right += left.back();
            left.pop_back();
            --k;
        }
        k = min(10, (int)left.size());
        return left.substr(left.size() - k, k);
    }

    string cursorRight(int k) {
        while (k && !right.empty()) {
            left += right.back();
            right.pop_back();
            --k;
        }
        k = min(10, (int)left.size());
        return left.substr(left.size() - k, k);
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */

int main(){
    TextEditor textEditor; // ��ǰ text Ϊ "|" ����'|' �ַ���ʾ��꣩
    textEditor.addText("leetcode"); // ��ǰ�ı�Ϊ "leetcode|" ��
    cout<<textEditor.deleteText(4)<<endl; // ���� 4
    // ��ǰ�ı�Ϊ "leet|" ��
    // ɾ���� 4 ���ַ���
    textEditor.addText("practice"); // ��ǰ�ı�Ϊ "leetpractice|" ��
    cout<<textEditor.cursorRight(3)<<endl; // ���� "etpractice"
    // ��ǰ�ı�Ϊ "leetpractice|".
    // ����޷��ƶ����ı����⣬�����޷��ƶ���
    // "etpractice" �ǹ����ߵ� 10 ���ַ���
    cout<<textEditor.cursorLeft(8)<<endl; // ���� "leet"
    // ��ǰ�ı�Ϊ "leet|practice" ��
    // "leet" �ǹ����ߵ� min(10, 4) = 4 ���ַ���
    cout<<textEditor.deleteText(10)<<endl; // ���� 4
    // ��ǰ�ı�Ϊ "|practice" ��
    // ֻ�� 4 ���ַ���ɾ���ˡ�
    cout<<textEditor.cursorLeft(2)<<endl; // ���� ""
    // ��ǰ�ı�Ϊ "|practice" ��
    // ����޷��ƶ����ı����⣬�����޷��ƶ���
    // "" �ǹ����ߵ� min(10, 0) = 0 ���ַ���
    cout<<textEditor.cursorRight(6)<<endl; // ���� "practi"
    // ��ǰ�ı�Ϊ "practi|ce" ��
    // "practi" �ǹ����ߵ� min(10, 6) = 6 ���ַ���

    return 0;
    }