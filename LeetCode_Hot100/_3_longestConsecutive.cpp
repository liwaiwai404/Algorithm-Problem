#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        //将元素存入集合去重，且方便查找
        unordered_set<int> num_set;
        for (auto &num : nums)
            num_set.insert(num);
        //保存目前最长连续序列长度
        int longestStreak = 0;
        //循环遍历每个元素
        //每个元素只会被访问一次，因为数组中的元素要么是连续序列的首元素，要么是中间元素或尾元素
        //遍历每个元素并检查其是否为连续序列首元素，当其是首元素时再查找表中是否有以有后续元素
        //因为每个中间元素只能成为某一个首元素构成连续序列的中间元素，当这个首元素被遍历时，其中的while循环会访问到这些中间元素
        //访问其他首元素时则不会再访问这些中间元素，每个中间元素只会在其自己的首元素的连续序列查找时访问
        for (const auto &num : num_set)
        {
            //如果该元素-1不存在，即当前元素只能是连续序列的首元素
            if (!num_set.count(num - 1))
            {
                //记录以该元素为首元素的连续序列当前状态
                int currentNum = num; //当前连续到哪个元素
                int currentStreak = 1; //当前的连续序列长度
                
                //从该 首元素+1 开始在set中寻找是否存在
                while (num_set.count(currentNum + 1))
                {
                    //存在则更新序列状态
                    currentNum += 1; //当前最新的连续元素
                    currentStreak += 1; //当前的序列长度
                }

                //比较 以这次遍历到的元素为首元素找到的最长序列长度 和 历史最长长度 来更新历史最长长度
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;

    }
};