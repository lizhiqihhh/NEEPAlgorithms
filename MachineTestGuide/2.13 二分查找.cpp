#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

//用于表示学生个体的结构体
struct Student {
    char no[100]; //学号
    char name[100]; //姓名
    int age; //年龄
    char sex[5]; //性别
    //重载小于运算符使其能使用sort函数排序
    bool operator < (const Student & A) const {
        return strcmp(no, A.no) < 0;
    }
} buf[1000];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%s%s%s%d", buf[i].no, buf[i].name, buf[i].sex, &buf[i].age); //输入
        }
        sort(buf, buf + n); //对数组排序使其按照学号升序排列
        int t;
        scanf("%d", &t); //有t组询问
        //while循环保证查询次数为t
        while (t-- != 0) {
            int ans = -1; //目标元素下标，初始化为-1
            char x[30];
            scanf("%s", x); //待查找学号
            int top = n - 1, base = 0; //初始时，开始下标0，结束下标n-1，查找子集为整个数组
            //当查找子集不为空集时重复二分查找
            while (top >= base) {
                int mid = (top + base) / 2; //计算中间点下标
                int tmp = strcmp(buf[mid].no, x); //比较中间点学号与目标学号
                if (tmp == 0) {
                    //若相等，则查找完跳出二分查找
                    ans = mid;
                    break;
                } else if (tmp > 0)
                    top = mid - 1; //若大于，则结束点下标变为中间点前一个点下标
                else
                    base = mid + 1; //若小于，则开始点下标变为中间点后一个点下标
            }
            if (ans == -1)
                printf("No Answer!\n"); //若查找失败
            else
                printf("%s %s %s %d\n", buf[ans].no, buf[ans].name, buf[ans].sex, buf[ans].age); //若查找成功
        }
    }
    return 0;
}
