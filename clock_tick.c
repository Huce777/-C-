#include <stdio.h>
#include <time.h>

clock_t start, stop; /* clock_t 是 clock() 函数返回的变量类型 */
double duration; /* 记录被测函数运行时间，以秒为单位 */

int MyFunction(int a, int b) {
    return a + b;
}

int main() {
    /* 不在测试范围内的准备工作写在 clock() 调用之前 */
    start = clock(); /* 开始计时 */
    /* 把被测函数加在这里，使用时这个函数必须被替代 */
    int result = MyFunction(450, 100); /* 假设这里传入两个参数 */
    stop = clock(); /* 停止计时 */
    /* 计算运行时间 */
    duration = ((double)(stop - start)) / CLOCKS_PER_SEC; /* 注意 CLOCKS_PER_SEC 是标准名称 */
    /* 在某些 IDE 下也可能叫 CLK_TCK 。 */

    /* 输出 duration 的值 */
    printf("%f\n", duration); /* 使用 %f 打印 double 类型 */

    /* 其他不在测试范围的处理写在后面，例如输出 duration 的值 */
    return 0;
}
