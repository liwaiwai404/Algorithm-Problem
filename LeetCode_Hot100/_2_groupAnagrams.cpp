#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> result;
        // <排序后的字符串, 数组中有这些字符的字符串>
        unordered_map<string, vector<string>> strHash;

        //遍历每个字符串
        for (const auto &str : strs)
        {
            //获取当前字符串的副本
            string key = str;
            //将副本字符串排序
            sort(key.begin(), key.end());
            //将当前字符串拷贝一份加入 以排序后字符串为键 的表中的vecotr
            //具有相同字符的字符串通过其排序后的副本进入同一个vector
            strHash[key].push_back(str);
        }
        //将哈希表中的各个相同字符串vector存入结果
        for (const auto &pair : strHash)
        {
            result.push_back(pair.second);
        }
        return result;
        
    }
};


class Solution2 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> strHash;
        for (auto &str : strs)
        {
            //对字符串中二十六个小写字母的出现次数计数
            vector<int> count(26, 0);
            for (char c : str)
                ++count[c - 'a'];
            //将每个字符和其出现次数拼接成字符串作为表的key
            // "amn" -> "a1m1n1"
            string key;
            //遍历每个字符出现的次数
            for (int i = 0; i < 26; ++i)
                key += string(1,'a' + i) + std::to_string(count[i]);
            strHash[key].push_back(str);
        }
        vector<vector<string>> result;
        //将哈希表中的各个相同字符串vector存入结果
        for (const auto &pair : strHash)
        {
            result.push_back(pair.second);
        }
        return result;

    }
};