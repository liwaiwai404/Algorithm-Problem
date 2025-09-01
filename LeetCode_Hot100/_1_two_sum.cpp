#include <vector>
#include <unordered_map>
#include <iterator>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        //哈希表存放数组里每个元素的值和其对应的数组下标 <元素值, 数组中位置下标>
        unordered_map<int, int> hashTable;
        //遍历数组中每个元素
        for (int i = 0; i != nums.size(); ++i)
        {
            //在哈希表中查找能与当前元素相加得到target的元素的下标
            //find返回迭代器，没找到返回尾后迭代器
            auto it = hashTable.find(target - nums[i]);
            //没返回尾后迭代器说明找到了符合条件的元素
            if (it != hashTable.end())
                //通过指向符合条件元素的迭代器得到其数组下标
                //返回当前元素的和匹配元素的下标
                return {it->second, i};
            //没找到匹配的元素则将当前元素的值和其下标位置存入哈希表，以供后续元素方便查找之前存入哈希表内的元素并得到其下标
            hashTable[nums[i]] = i;
        }
        return {};
    }
};

//暴力枚举法
//将每个元素与其他元素配对并于target比较
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i != nums.size(); ++i)
        {
            for (int j = i + 1; j != nums.size(); ++j)
            {
                if (nums[i] + nums[j] == target)
                    return {i, j};
            }
        }
        return {};
    }
};