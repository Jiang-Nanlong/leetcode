#include <vector>
#include <unordered_map>
#include <list> // Using list or vector to store indices
#include <iostream>

std::vector<int> find_product_pair(
    long long q,
    const std::vector<int> &nums,
    const std::unordered_map<long long, std::list<int> > &num_to_indices) {
    for (int i = 0; i < nums.size(); ++i) {
        long long num1 = nums[i];

        if (num1 <= 1 && q % num1 != 0) {
            continue;
        }

        long long target = q / num1;

        auto it = num_to_indices.find(target);
        if (it != num_to_indices.end()) {
            const std::list<int> &indices_of_target = it->second;
            for (int j: indices_of_target) {
                if (i != j)
                    return {i, j};
            }
        }
    }

    return {-1, -1};
}

int main() {
    std::vector<int> nums{1, 2, 3, 2, 4};
    std::unordered_map<long long, std::list<int> > num_to_indices;
    for (int i = 0; i < nums.size(); ++i) {
        num_to_indices[static_cast<long long>(nums[i])].push_back(i);
    }

    int target = 4;

    std::vector<int> result = find_product_pair(target, nums, num_to_indices);
    std::cout << result[0] << " " << result[1] << "\n"; // Use "\n" for faster output


    return 0;
}
