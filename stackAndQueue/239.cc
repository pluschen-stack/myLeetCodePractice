#include "../defs.h"

class Solution
{
private:
    class MyQueue
    {
        deque<int> que;

    public:
        void push(int num)
        {
            while (!que.empty() && num > que.back())
            {
                que.pop_back();
            }
            que.push_back(num);
        }
        void pop(int num)
        {
            if (!que.empty() && this->front() == num)
            {
                que.pop_front();
            }
        }
        int front()
        {
            return que.front();
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> result;
        MyQueue que;
        for (int i = 0; i < k; i++)
        {
            que.push(nums[i]);
        }
        result.push_back(que.front());
        for (int i = k; i < nums.size(); i++)
        {
            que.push(nums[i]);
            que.pop(nums[i-k]);
            result.push_back(que.front());
        }
        return result;
    }
};