class Solution {
public:
    
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k <= 1) return 0;

    int n = nums.size();
    int i = 0;
    int count = 0;
    long long prod = 1;

    for (int j = 0; j < n; j++) {
        while (i < j && prod > (k - 1) / nums[j]) {
            prod /= nums[i];
            i++;
        }

        // If even the new element is too large,
        // the window must start after j.
        if (nums[j] >= k) {
            i = j + 1;
            prod = 1;
            continue;
        }

        prod *= nums[j];

        while (i <= j && prod >= k) {
            prod /= nums[i];
            i++;
        }

        count += j - i + 1;
    }

    return count;
}

};