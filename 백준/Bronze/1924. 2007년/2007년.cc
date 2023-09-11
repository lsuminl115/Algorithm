#include <stdio.h>
#include <stdlib.h>

int main()
{
    int year = 2007 ,month,day , yearsum = 0 , day_cnt=0;
    scanf("%d %d",&month,&day);
    yearsum += (year - 1900)*365;
    yearsum += (year - 1900)/4;

    for(int i = 1; i<=month; i++)  // 1월부터 주어진 월까지
    {
        if( i!= month)  // i가 입력받은 월이 아닐때
        {
            if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)  // 만약 31일로 끝나는 달이면
            {
                day_cnt += 31;  // 31일을 더함
            }
            else if(i == 4 || i == 6 || i == 9 || i == 11)  // 만약 30일로 끝나는 달이면 (2월 제외)
            {
                day_cnt += 30;  // 30일을 더함
            }
            else if(i == 2)  // 만약 2월이면
            {
                day_cnt += 28;  // 28일을 더함
            }
        }
        else if(i == month)  // 만약 i가 입력받은 월이면
        {
            day_cnt += day;  // 받은 만큼의 일을 더함
        }
    }
    yearsum += day_cnt;
    if(yearsum % 7 == 0) printf("SUN");
    else if(yearsum % 7 == 1) printf("MON");  // 나머지가 1일때 월요일
    else if(yearsum % 7 == 2) printf("TUE");  // 나머지가 2일때 화요일
    else if(yearsum % 7 == 3) printf("WED");  // 나머지가 3일때 수요일
    else if(yearsum % 7 == 4) printf("THU");  // 나머지가 4일때 목요일
    else if(yearsum % 7 == 5) printf("FRI");  // 나머지가 5일때 금요일
    else if(yearsum % 7 == 6) printf("SAT");  // 나머지가 6일때 토요일
    return 0;
}
