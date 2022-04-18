class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        int j = 0, i = 0;
        list<int> data;
        vector<int> ans;

        while (j < n)
        {

            while (!data.empty() && data.back() < nums[j])
                data.pop_back();
            // because all the smaller number appearing before the max will be never become a possible ans in the future
            // as till the window slides the curr max will remain the max

            data.push_back(nums[j]);

            if (j - i + 1 == k)
            {

                ans.push_back(data.front());
                if (nums[i] == data.front())
                    data.pop_front();
                i++;
            }

            j++;
        }

        return ans;
    }
};