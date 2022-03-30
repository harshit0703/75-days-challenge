class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        pair<int, int> ans;
        ans.first = INT_MAX;
        ans.second = 0;

        for (int i = 0; i < n; i++)
        {

            int st = i + 1;
            int en = n - 1;

            while (st < en)
            {
                int sum = nums[i] + nums[st] + nums[en];
                int diff = abs(target - sum);
                if (diff < ans.first)
                {
                    ans.first = diff;
                    ans.second = sum;
                }

                if (target > sum)
                    st++;
                else if (target < sum)
                    en--;
                else
                    return target;
            }
        }

        return ans.second;
    }
};