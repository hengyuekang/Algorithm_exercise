/*
 * @lc app=leetcode.cn id=2013 lang=cpp
 *
 * [2013] 检测正方形
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <array>
#include <fstream>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <initializer_list>
#include <map>
using namespace std;
class DetectSquares {
private:
    map<pair<int,int>,int> posTime;
public:
    DetectSquares() {

    }
    
    void add(vector<int> point) {
        pair<int,int> tmp(point[0],point[1]);
        if(posTime.find(tmp)!=posTime.end()){
            posTime[tmp]++;
        }
        else{
            posTime[tmp]=1;
        }

    }
    
    int count(vector<int> point) {
        int res=0;
        pair<int,int> tmp(point[0],point[1]);
        for(auto p:posTime){
            int xDif=abs(tmp.first-p.first.first);
            int yDif=abs(tmp.second-p.first.second);
            // represent all 4 points,and then you can find remaining 2points only then
            if((xDif==yDif)&&(xDif!=0)){
                int time1=p.second;
                // cant control all 4 directions by this way
                pair<int,int> next1(p.first.first,tmp.second);
                pair<int,int> next2(tmp.first,p.first.second);
                if((posTime.find(next1)!=posTime.end())&&(posTime.find(next2)!=posTime.end())){
                    int time2=posTime[next1];
                    int time3=posTime[next2];
                    res+=(time1*time2*time3);
                }
            }
        }
        return res;
    }
};
int main(){
    DetectSquares detectSquares;
    detectSquares.add(vector<int>{3,10});
    detectSquares.add(vector<int>{11,2});
    detectSquares.add(vector<int>{3,2});
    int res=detectSquares.count(vector<int>{11,10}); // return 1. You can choose:
                               //   - The first, second, and third points
    detectSquares.count(vector<int>{14,8});  // return 0. The query point cannot form a square with any points in the data structure.
    detectSquares.add(vector<int>{11,2});    // Adding duplicate points is allowed.
    int ans=detectSquares.count(vector<int>{11,10});
    return 0;

}
/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
// @lc code=end

