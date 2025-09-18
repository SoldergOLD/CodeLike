#include <iostream>
#include <vector>
#include <unordered_map>

#include <stdlib.h>


using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;

int main(int args, char* argv[])
{
    if(args < 2)
    {
        cout<<"������Ŀ��ֵ������"<<endl;
    }

    vector<int> nums = {2,4,6,8,10};
    int target = atoi(argv[1]);

    unordered_map<int, int> temp;

    // �����ϣ���� key:Ԫ��ֵ, value:�±�
    int i = 0;
    for(auto it = nums.begin(); it!=nums.end();++it)
    {
        temp.emplace(*it, i++);
    }

    int j = 0;
    for(auto it = nums.begin(); it!=nums.end();++it)
    {
        if(temp.find(target - *it) != temp.end())
        {
            auto itMap = temp.find(target - *it);
            printf("Target:%d, Index:%d, Index2:%d\n", target, j, itMap->second);
            return 0;
        }
        ++j;
    }
    printf("Target:%d, no find\n", target);

    return 0;
}
