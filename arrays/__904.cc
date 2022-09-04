#include "../defs.h"
using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int result = 0;
        size_t left = 0;
        size_t right = 0;
        size_t size = fruits.size();
        int keys[2] = {-1, -1};
        int values[2] = {0, 0};
        for (; right < size; right++)
        {
            if (keys[0] == -1 || keys[1] == -1)
            {
                //类型还小于两个时，如果不存在就加入一下表示存在了。
                if (keys[0] == fruits[right])
                {
                    values[0]++;
                }
                else if (keys[0] == -1)
                {
                    keys[0] = fruits[right];
                    values[0] = 1;
                }else{
                    keys[1] = fruits[right];
                    values[1] = 1;
                }
            }
            else
            {
                //类型等于两个时
                if(keys[0]==fruits[right]||keys[1]==fruits[right]){
                    if(keys[0]==fruits[right]){
                        values[0]++;
                    }else{
                        values[1]++;
                    }
                }else{
                    //来了新的类型
                    if(keys[0]==fruits[right-1]){
                        result = result>(right-left)?result:(right-left);
                        while(values[1]!=0){
                            if(keys[0]==fruits[left]){
                                values[0]--;
                            }else{
                                values[1]--;
                            }
                            left++;
                        }
                        keys[1]=fruits[right];
                        values[1]=1;
                    }else{
                        result = result>(right-left)?result:(right-left);
                        while(values[0]!=0){
                            if(keys[0]==fruits[left]){
                                values[0]--;
                            }else{
                                values[1]--;
                            }
                            left++;
                        }
                        keys[0]=fruits[right];
                        values[0]=1;
                    }
                    
                }
            }
        }
        return result>(right-left)?result:(right-left);
    }
};

// 执行结果：
// 通过
// 显示详情:

// 执行用时：
// 68 ms
// , 在所有 C++ 提交中击败了
// 99.75%
// 的用户
// 内存消耗：
// 64.5 MB
// , 在所有 C++ 提交中击败了
// 83.35%
// 的用户
// 通过测试用例：
// 91 / 91