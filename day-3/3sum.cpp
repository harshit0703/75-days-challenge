class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        int n = nums.size();
        if (n < 3)
            return {};

        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            int target = -nums[i]; // to make the sum of triplet 0
            int st = i + 1;
            int en = n - 1;

            while (st < en)
            {
                int sum = nums[st] + nums[en];
                if (target > sum)
                    st++;
                else if (target < sum)
                    en--;
                else
                {
                    int a = nums[i];
                    int b = nums[st];
                    int c = nums[en];
                    vector<int> temp(3, 0);
                    temp = {a, b, c};
                    ans.push_back(temp);

                    // removing duplicates
                    while (st < en && nums[st] == b)
                        st++;
                    while (st < en && nums[en] == c)
                        en--;
                }
            }
            // removing duplicates
            while (i + 1 < n && nums[i] == nums[i + 1])
                i++;
        }

        return ans;
    }
};