//
// Created by ������ on 25-2-26.
//
#include <iostream>
#include <list>
#include <string>
using namespace std;

class BrowserHistory {
    list<string> history;
    list<string>::iterator it;

public:
    BrowserHistory(string homepage) : history{homepage}, it(history.begin()) {
    }

    void visit(string url) {
        ++it;
        history.erase(it, history.end());
        history.emplace_back(url);
        it = history.end();
        std::advance(it, -1);
    }

    string back(int steps) {
        int count = std::distance(history.begin(), it);
        steps = min(count, steps);
        std::advance(it, -steps);
        return *it;
    }

    string forward(int steps) {
        int count = std::distance(it, history.end());
        steps = min(count - 1, steps);
        std::advance(it, steps);
        return *it;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

int main() {
    BrowserHistory browserHistory("leetcode.com");
    browserHistory.visit("google.com"); // ��ԭ������� "leetcode.com" ������ "google.com"
    browserHistory.visit("facebook.com"); // ��ԭ������� "google.com" ������ "facebook.com"
    browserHistory.visit("youtube.com"); // ��ԭ������� "facebook.com" ������ "youtube.com"
    cout << browserHistory.back(1) << endl; // ��ԭ������� "youtube.com" �����˵� "facebook.com" ������ "facebook.com"
    cout << browserHistory.back(1) << endl; // ��ԭ������� "facebook.com" �����˵� "google.com" ������ "google.com"
    cout << browserHistory.forward(1) << endl; // ��ԭ������� "google.com" ��ǰ���� "facebook.com" ������ "facebook.com"
    browserHistory.visit("linkedin.com"); // ��ԭ������� "facebook.com" �� ���� "linkedin.com"
    cout << browserHistory.forward(2) << endl; // ��ԭ������� "linkedin.com" �����޷�ǰ���κβ�����
    cout << browserHistory.back(2) << endl;
    // ��ԭ������� "linkedin.com" ���������������ȵ� "facebook.com" ��Ȼ�� "google.com" �������� "google.com"
    cout << browserHistory.back(7) << endl; // ��ԭ������� "google.com"�� ��ֻ�ܺ���һ���� "leetcode.com" �������� "leetcode.com"

    return 0;
}
