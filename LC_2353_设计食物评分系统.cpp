//
// Created by 曹孟龙 on 25-2-28.
//
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class FoodRatings {
    unordered_map<string, pair<string, int> > food_2_score;

    struct Compare {
        bool operator()(const pair<int, string> &a,
                        const pair<int, string> &b) const {
            if (a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        }
    };

    unordered_map<string, priority_queue<pair<int, string>,
        vector<pair<int, string> >, Compare> >
    cuisine_2_score_2_food;

public:
    FoodRatings(vector<string> &foods, vector<string> &cuisines,
                vector<int> &ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            food_2_score[foods[i]] = make_pair(cuisines[i], ratings[i]);
            cuisine_2_score_2_food[cuisines[i]].push(
                make_pair(ratings[i], foods[i]));
        }
    }

    void changeRating(string food, int newRating) {
        food_2_score[food].second = newRating;
        string curisine = food_2_score[food].first;
        cuisine_2_score_2_food[curisine].push(make_pair(newRating, food));
    }

    string highestRated(string cuisine) {
        auto pa = cuisine_2_score_2_food[cuisine].top();
        while (food_2_score[pa.second].second != pa.first) {
            cuisine_2_score_2_food[cuisine].pop();
            pa = cuisine_2_score_2_food[cuisine].top();
        }
        return pa.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

int main() {
    vector<string> foods{"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
    vector<string> cuisines{"korean", "japanese", "japanese", "greek", "japanese", "korean"};
    vector<int> ratings{9, 12, 8, 15, 14, 7};
    FoodRatings foodRatings(foods, cuisines, ratings);
    cout << foodRatings.highestRated("korean") << endl; // 返回 "kimchi"
    // "kimchi" 是分数最高的韩式料理，评分为 9 。
    cout << foodRatings.highestRated("japanese") << endl; // 返回 "ramen"
    // "ramen" 是分数最高的日式料理，评分为 14 。
    foodRatings.changeRating("sushi", 16); // "sushi" 现在评分变更为 16 。
    cout << foodRatings.highestRated("japanese") << endl; // 返回 "sushi"
    // "sushi" 是分数最高的日式料理，评分为 16 。
    foodRatings.changeRating("ramen", 16); // "ramen" 现在评分变更为 16 。
    cout << foodRatings.highestRated("japanese") << endl; // 返回 "ramen"
    // "sushi" 和 "ramen" 的评分都是 16 。
    // 但是，"ramen" 的字典序比 "sushi" 更小。
    return 0;
}
