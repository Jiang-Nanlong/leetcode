#include <iostream>
#include <unordered_set>
using namespace std;

/*
* 判断一个数是否是一个快乐数，快乐数的定义是一个数等于他的每一位的平方和，如果这个数等于1，就是快乐数，如果不是就一直循环。
* 这个题的一个问题就是可能会一直循环下去。
* 这个题是出在了哈希表一节，开始的时候我实在想不通快乐数跟哈希表有什么关系。总想着把数的每一位映射到哈希表的每一个位置。
* 看了答案才知道，如果这个数在哈希表中出现过，那么就说明它陷入了循环，就不会是快乐数。如果没有出现在循环内，且不是1，就把它插入到哈希表。
*/

class Solution {
public:
	bool isHappy(int n) {
		unordered_set<int> uset;
		int sum = n;
		while (1) {
			sum = getsum(sum);
			if (sum == 1) return true;
			if (uset.find(sum) != uset.end())
				return false;
			else {
				uset.insert(sum);
			}
		}
	}

	//第二次做
	bool isHappy1(int n) {
		unordered_set<int> uset;
		long long sum = 0;
		while (n != 1) {
			while (n) {  //这个for循环用来求n的各位的平方和
				sum += pow(n % 10, 2);
				n /= 10;
			}
			if (uset.find(sum) != uset.end())
				return false;
			else {
				uset.insert(sum);
				n = sum;
				sum = 0;
			}
		}
		return true;
	}
private:
	int getsum(int n) {
		int sum = 0;
		while (n) {
			sum += (n % 10) * (n % 10);
			n /= 10;
		}
		return sum;
	}
};

int main() {
	Solution st;
	cout << boolalpha << st.isHappy(19) << endl;
	cout << st.isHappy(2) << noboolalpha << endl;
	cout << boolalpha << st.isHappy1(19) << endl;
	cout << st.isHappy1(2) << noboolalpha << endl;
	return 0;
}