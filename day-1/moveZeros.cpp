class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {

        int st = 0;
        int en = nums.size() - 1;

        while (st < en)
        {

            if (nums[st] == 0)
            {

                for (int i = st; i < en; i++)
                {
                    nums[i] = nums[i + 1];
                }

                nums[en] = 0;
                en--;
            }

            else
            {
                st++;
            }
        }
    }
};