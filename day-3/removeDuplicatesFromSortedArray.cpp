class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {

        int k = 1;
        int st = 1;

        while (st < nums.size() && nums[st - 1] != nums[st])
        {
            st++;
            k++;
        }

        if (st == nums.size())
            return k;

        int temp = st;
        int prev = nums[st - 1];

        while (temp < nums.size())
        {

            if (nums[st] != nums[temp] && nums[temp] != prev)
            {
                nums[st++] = nums[temp];
                prev = nums[temp];
                k++;
            }

            temp++;
        }

        return k;
    }
};