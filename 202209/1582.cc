#include "../defs.h"

class Solution
{
public:
    int numSpecial(vector<vector<int>> &mat)
    {
        int sum = 0;
        for (int i = 0; i < mat.size(); i++)
        {
            int pos = -1;
            for (int j = 0; j < mat[0].size(); j++)
            {

                if (mat[i][j] == 1)
                {
                    if(pos==-1){
                        pos = j;
                    }else{
                        pos=-1;
                        break;
                    }
                }
            }
            if(pos==-1){
                continue;
            }
            bool flag = true;
            for(int k = 0; k < mat.size();k++){
                if(k!=i&&mat[k][pos]==1){
                    flag = false;
                    break;
                }
            }
            if(flag){
                sum++;
            }
        }
        return sum;
    }
};

int main(){
    Solution s;
    vector<vector<int>> a= vector<vector<int>>{{0,0,0,0,0},{1,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,1}};
    s.numSpecial(a);
}