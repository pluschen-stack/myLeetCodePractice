#include "../defs.h"
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        size_t startx ,starty;
        size_t rowNums = matrix.size(), colNums=matrix[0].size();
        size_t size =  rowNums>colNums?colNums/2:rowNums/2;
        size_t loop = size;
        size_t offset = 0;
        
        while(loop--){
            size_t start = offset;
            startx = start;
            starty = start;
            for(;starty<colNums-offset-1;starty++){
                result.push_back(matrix[startx][starty]);
            }
            for(;startx<rowNums-offset-1;startx++){
                result.push_back(matrix[startx][starty]);
            }
            for(;starty>start;starty--){
                result.push_back(matrix[startx][starty]);
            }
            for(;startx>start;startx--){
                result.push_back(matrix[startx][starty]);
            }
            offset++;
        }
        size_t minNum = rowNums>colNums?colNums:rowNums;
        if(minNum%2!=0){
            //奇数的情况
            size_t start = offset;
            startx = start;
            starty = start;
            if(minNum==colNums){
                for(;startx<rowNums-offset;startx++){
                    result.push_back(matrix[startx][starty]);
                }
            }else{
                for(;starty<colNums-offset;starty++){
                    result.push_back(matrix[startx][starty]);
                }
            }
        }
        return result;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> a = {{1,2,3},{4,5,6},{7,8,9},{11,12,13},{14,15,16}};
    solution.spiralOrder(a);
}