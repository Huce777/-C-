#include <stdio.h>
#include <time.h>

clock_t start, stop; /* clock_t �� clock() �������صı������� */
double duration; /* ��¼���⺯������ʱ�䣬����Ϊ��λ */

int MyFunction(int a, int b) {
    return a + b;
}

int main() {
    /* ���ڲ��Է�Χ�ڵ�׼������д�� clock() ����֮ǰ */
    start = clock(); /* ��ʼ��ʱ */
    /* �ѱ��⺯���������ʹ��ʱ����������뱻��� */
    int result = MyFunction(450, 100); /* �������ﴫ���������� */
    stop = clock(); /* ֹͣ��ʱ */
    /* ��������ʱ�� */
    duration = ((double)(stop - start)) / CLOCKS_PER_SEC; /* ע�� CLOCKS_PER_SEC �Ǳ�׼���� */
    /* ��ĳЩ IDE ��Ҳ���ܽ� CLK_TCK �� */

    /* ��� duration ��ֵ */
    printf("%f\n", duration); /* ʹ�� %f ��ӡ double ���� */

    /* �������ڲ��Է�Χ�Ĵ���д�ں��棬������� duration ��ֵ */
    return 0;
}
