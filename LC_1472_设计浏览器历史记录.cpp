//
// Created by 曹孟龙 on 25-2-26.
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
    browserHistory.visit("google.com"); // 你原本在浏览 "leetcode.com" 。访问 "google.com"
    browserHistory.visit("facebook.com"); // 你原本在浏览 "google.com" 。访问 "facebook.com"
    browserHistory.visit("youtube.com"); // 你原本在浏览 "facebook.com" 。访问 "youtube.com"
    cout << browserHistory.back(1) << endl; // 你原本在浏览 "youtube.com" ，后退到 "facebook.com" 并返回 "facebook.com"
    cout << browserHistory.back(1) << endl; // 你原本在浏览 "facebook.com" ，后退到 "google.com" 并返回 "google.com"
    cout << browserHistory.forward(1) << endl; // 你原本在浏览 "google.com" ，前进到 "facebook.com" 并返回 "facebook.com"
    browserHistory.visit("linkedin.com"); // 你原本在浏览 "facebook.com" 。 访问 "linkedin.com"
    cout << browserHistory.forward(2) << endl; // 你原本在浏览 "linkedin.com" ，你无法前进任何步数。
    cout << browserHistory.back(2) << endl;
    // 你原本在浏览 "linkedin.com" ，后退两步依次先到 "facebook.com" ，然后到 "google.com" ，并返回 "google.com"
    cout << browserHistory.back(7) << endl; // 你原本在浏览 "google.com"， 你只能后退一步到 "leetcode.com" ，并返回 "leetcode.com"

    return 0;
}
