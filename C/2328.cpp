#include <stdio.h>
#include <time.h>

/* 读取一行 yy/mm/dd hh:mm:ss */
void read_time(int *y, int *m, int *d, int *hh, int *mm, int *ss)
{
    scanf("%d/%d/%d %d:%d:%d", y, m, d, hh, mm, ss);
}

/* 把 y-m-d hh:mm:ss 转成 time_t（UTC 算差，时区无关） */
time_t make_time(int y, int m, int d, int hh, int mm, int ss)
{
    struct tm tm = {0};
    tm.tm_year = y - 1900;
    tm.tm_mon  = m - 1;
    tm.tm_mday = d;
    tm.tm_hour = hh;
    tm.tm_min  = mm;
    tm.tm_sec  = ss;
    tm.tm_isdst = -1;
    return mktime(&tm);
}

int main(void)
{
    int y1, m1, d1, hh1, mm1, ss1;
    int y2, m2, d2, hh2, mm2, ss2;
    read_time(&y1, &m1, &d1, &hh1, &mm1, &ss1);
    read_time(&y2, &m2, &d2, &hh2, &mm2, &ss2);

    time_t t1 = make_time(y1, m1, d1, hh1, mm1, ss1);
    time_t t2 = make_time(y2, m2, d2, hh2, mm2, ss2);
    long long diff = (long long)t2 - (long long)t1;

    int neg = 0;
    if (diff < 0) {
        neg = 1;
        diff = -diff;
    }

    long long days = diff / 86400;
    long long rem  = diff % 86400;
    int hh = rem / 3600;
    int mm = (rem % 3600) / 60;
    int ss = rem % 60;

    /* 从 0000-00-00 开始累加 days 天 */
    struct tm zero = {0};
    zero.tm_year = -1900; /* 即 0000 年 */
    zero.tm_mon  = 0;
    zero.tm_mday = 1;     /* 0000-01-01 作为起点 */
    zero.tm_hour = 0;
    zero.tm_min  = 0;
    zero.tm_sec  = 0;
    zero.tm_isdst = -1;

    time_t base = mktime(&zero);
    base += days * 86400;
    struct tm *out = gmtime(&base);

    /* 输出：按题目宽度，年份 4 位，其余 2 位 */
    if (neg) putchar('-');
    printf("%04d/%02d/%02d %02d:%02d:%02d\n",
           out->tm_year + 1900,
           out->tm_mon + 1,
           out->tm_mday,
           hh, mm, ss);

    return 0;
}