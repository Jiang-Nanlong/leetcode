//
// Created by 曹孟龙 on 25-2-27.
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
    TextEditor textEditor; // 当前 text 为 "|" 。（'|' 字符表示光标）
    textEditor.addText("leetcode"); // 当前文本为 "leetcode|" 。
    cout<<textEditor.deleteText(4)<<endl; // 返回 4
    // 当前文本为 "leet|" 。
    // 删除了 4 个字符。
    textEditor.addText("practice"); // 当前文本为 "leetpractice|" 。
    cout<<textEditor.cursorRight(3)<<endl; // 返回 "etpractice"
    // 当前文本为 "leetpractice|".
    // 光标无法移动到文本以外，所以无法移动。
    // "etpractice" 是光标左边的 10 个字符。
    cout<<textEditor.cursorLeft(8)<<endl; // 返回 "leet"
    // 当前文本为 "leet|practice" 。
    // "leet" 是光标左边的 min(10, 4) = 4 个字符。
    cout<<textEditor.deleteText(10)<<endl; // 返回 4
    // 当前文本为 "|practice" 。
    // 只有 4 个字符被删除了。
    cout<<textEditor.cursorLeft(2)<<endl; // 返回 ""
    // 当前文本为 "|practice" 。
    // 光标无法移动到文本以外，所以无法移动。
    // "" 是光标左边的 min(10, 0) = 0 个字符。
    cout<<textEditor.cursorRight(6)<<endl; // 返回 "practi"
    // 当前文本为 "practi|ce" 。
    // "practi" 是光标左边的 min(10, 6) = 6 个字符。

    return 0;
    }