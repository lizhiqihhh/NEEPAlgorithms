#include <stdio.h>

int main() {
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF) {
        //用buf1,buf2分别保存从两个整数中拆解出来的数位数字，其数量由size1,size2表示
        int buf1[20], buf2[20], size1 = 0, size2 = 0;
        //数位拆解，当a大于零时不断重复拆解过程
        while (a != 0) {
            buf1[size1++] = a % 10; //取得当前个位上的数字将其保存
            a /= 10; //将所有数位上的数字移动到高一位上
        }
        //拆解第二个数字
        while (b != 0) {
            buf2[size2++] = b % 10;
            b /= 10;
        }
        int ans = 0;
        for (int i = 0; i < size1; i++)
            for (int j = 0; j < size2; j++)
                ans += buf1[i] * buf2[j]; //两两相乘后相加
        printf("%d\n", ans);
    }
    return 0;
}
