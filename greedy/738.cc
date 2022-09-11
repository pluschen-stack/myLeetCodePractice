#include "../defs.h"

class Solution
{
public:
    int monotoneIncreasingDigitsWithNum(int N)
    {
        //@银河也是河 写的，纯用int写的。努力学习位运算
        int i = 1;
        int res = N;
        while (i <= res / 10)
        {
            int n = res / i % 100; // 每次取两个位
            i *= 10;
            if (n / 10 > n % 10)       // 比较的高一位大于底一位
                res = res / i * i - 1; //例如1332 循环第一次变为1330-1=1329 第二次变为1300-1=1299
        }
        return res;
    }
    int monotoneIncreasingDigits(int n)
    {
        //感觉字符串确实在去十进制位上很方便。
        if (n <= 9)
            return n;
        string ns = to_string(n);
        int i = 1;
        for (; i < ns.size(); i++)
        {
            if (ns[i] >= ns[i - 1])
            {
                continue;
            }
            else
            {
                do
                {
                    i--;
                    ns[i]--;
                } while (i > 0 && ns[i] + 1 == ns[i - 1]);
                for (int j = i + 1; j < ns.size(); j++)
                {
                    ns[j] = '9';
                }
                break;
            }
        }
        return stoi(ns);
    }
};