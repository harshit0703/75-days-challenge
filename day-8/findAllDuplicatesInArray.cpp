class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        // whenever we are given with an array with the range 1 - n and O(1) space is req always think of cyclic sort once
        // as this is the only sorting method that can sort in O(n) time

        int n = nums.size();
        int i = 0;

        while (i < n)
        {
            int crrIdx = nums[i] - 1;
            if (nums[i] != nums[crrIdx])
                swap(nums[i], nums[crrIdx]);
            else
                i++;
        }

        i = 0;
        vector<int> ans;

        while (i < n)
        {
            if (nums[i] != i + 1)
                ans.push_back(nums[i]);
            i++;
        }

        return ans;
    }
};