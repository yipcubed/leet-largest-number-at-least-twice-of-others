#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"

// https://leetcode.com/problems/largest-number-at-least-twice-of-others/

// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.empty()) return -1;
        int largei = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[largei])
                largei = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == nums[largei]) {
                if (i != largei)
                    return -1;
            } else {
                if (nums[i] * 2 > nums[largei])
                    return -1;
            }
        }
        return largei;
    }
};

void test1() {
    vector<int> v1{3, 6, 1, 0};

    cout << "1 ? " << Solution().dominantIndex(v1) << endl;

    vector<int> v2{1, 2, 3, 4};

    cout << "-1 ? " << Solution().dominantIndex(v2) << endl;
}

void test2() {

}

void test3() {

}