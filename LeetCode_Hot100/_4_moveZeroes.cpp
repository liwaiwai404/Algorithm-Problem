#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int length = nums.size();
        //指针初始指向首元素
        int leftP = 0, rightP = 0;
        //通过右指针遍历容器
        while (rightP < length) //下标范围 0 ~ length-1
        {
            //遇到0元素，左指针停下，右指针继续移动
            if (!nums.at(rightP))
            {
                ++rightP; //移动右指针
                continue; //继续处理下一个元素
            }
            //遇到非零元素
            //交换左右指针指向的元素，如果之前遇到过0元素，左指针会停在那，这次为继上次左指针停下后首次遇到非0元素
            //因此右指针指向的当前元素与左指针停下的0元素之间均为0元素或者二者相邻
            swap(nums.at(leftP), nums.at(rightP));
            //交换后左指针不再指向0则前进
            ++leftP;
            //右指针继续前进检查下一个元素
            ++rightP;
        }
        
    }
};