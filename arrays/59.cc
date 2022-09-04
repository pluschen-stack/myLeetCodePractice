#include "../defs.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        size_t startx ,starty;
        size_t loop = n/2;
        size_t count = 1;
        size_t offset = 0;
        while(loop--){
            size_t end = n - offset;
            size_t start = offset;
            startx = start;
            starty = start;
            for(;starty<end-1;starty++){
                result[startx][starty]=count++;
            }
            for(;startx<end-1;startx++){
                result[startx][starty]=count++;
            }
            for(;starty>start;starty--){
                result[startx][starty]=count++;
            }
            for(;startx>start;startx--){
                result[startx][starty]=count++;
            }
            offset++;
        }
        if(n%2!=0){
            result[n/2][n/2] = count;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    solution.generateMatrix(3);
}
