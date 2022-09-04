#include"../defs.h"

class Solution {
private:
    vector<string> ans;
    unordered_map<string,map<string,int>> targets;//第二个使用map是为了有序，这也说明了c++里面字符串是按字典序的
    bool backtracking(int totalNum,int ticketNum){
        if(ticketNum==totalNum){
            return true;
        }
        //这里的遍历学会了，给key值加const就可以去修改value了。c++这个语法特性学会了。
        for(pair<const string,int>& ticket:targets[ans[ticketNum]]){
            if(ticket.second!=0){
                //这张票还没有用过
                ticket.second--;
                ans.push_back(ticket.first);
                if(backtracking(totalNum,ticketNum+1)) return true;//找到了就快速返回
                //如果这张票走不完就需要回溯了。
                ans.pop_back();
                ticket.second++;
            }
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //好难啊,这题还有一个特点就是票是有重复的，也就是一个地点到另一个地点的票是可以有两张的
        //仔细想了一下，这道题本质就是有一个有向图，然后有向边是可以重复的，要做的事情就是从一个点开始把所有的有向边跑完
        //所以回溯可以做，因为回溯本质就是一个深度优先而已。
        for(const vector<string>& ticket:tickets){
            targets[ticket[0]][ticket[1]]++;//c++的重载真厉害。
        }
        ans.push_back("JFK");
        backtracking(tickets.size(),0);
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<string>> tickets;
    tickets.push_back(vector<string>{"EZE","AXA"});
    tickets.push_back(vector<string>{"TIA","ANU"});
    tickets.push_back(vector<string>{"ANU","JFK"});
    tickets.push_back(vector<string>{"JFK","ANU"});
    tickets.push_back(vector<string>{"ANU","EZE"});

    tickets.push_back(vector<string>{"TIA","ANU"});
    tickets.push_back(vector<string>{"AXA","TIA"});
    tickets.push_back(vector<string>{"TIA","JFK"});
    tickets.push_back(vector<string>{"ANU","TIA"});
    tickets.push_back(vector<string>{"JFK","TIA"});
    s.findItinerary(tickets);
}