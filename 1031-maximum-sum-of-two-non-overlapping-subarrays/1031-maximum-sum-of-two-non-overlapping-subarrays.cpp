class Solution {
public:
   int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {

    int n = nums.size();
    int sum = 0, i = 0, j = 0;

    vector<pair<int, pair<int,int>>> v1, v2;

    while (j < n) {
        sum += nums[j];

        if (j - i + 1 == firstLen) {
            v1.push_back({sum, {i, j}});
            sum -= nums[i];
            i++;
        }
        j++;
    }

    i = 0;
    j = 0;
    sum = 0;

    while (j < n) {
        sum += nums[j];

        if (j - i + 1 == secondLen) {
            v2.push_back({sum, {i, j}});
            sum -= nums[i];
            i++;
        }
        j++;
    }

    int ans = 0;

    for (auto &a : v1) {
        for (auto &b : v2) {

            auto [sum1, pos1] = a;
            auto [sum2, pos2] = b;

            // Non-overlapping condition
            if (pos1.second < pos2.first ||
                pos2.second < pos1.first) {

                ans = max(ans, sum1 + sum2);
            }
        }
    }

    return ans;
}
};