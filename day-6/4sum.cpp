class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {

        int n = nums.size();
        if (n < 4)
            return {};

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int newTarget = target - nums[i] - nums[j];

                int st = j + 1;
                int en = n - 1;

                while (st < en)
                {
                    int sum = nums[st] + nums[en];
                    if (newTarget > sum)
                        st++;
                    else if (newTarget < sum)
                        en--;
                    else
                    {
                        int a = nums[i];
                        int b = nums[j];
                        int c = nums[st];
                        int d = nums[en];
                        vector<int> temp(4, 0);
                        temp = {a, b, c, d};
                        ans.push_back(temp);

                        // deal with all the duplicates
                        while (st < en && nums[st] == c)
                            st++;
                        while (st < en && nums[en] == d)
                            en--;
                    }
                }

                while (j + 1 < n && nums[j + 1] == nums[j])
                    j++;
            }

            while (i + 1 < n && nums[i + 1] == nums[i])
                i++;
        }

        return ans;
    }
};