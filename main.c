#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//現在の日時
//int now_year,now_month,now_day,now_dayofweek,now_hour,now_min,now_sec;

struct datetime{
    int year;
    int month;
    int day;
    int dayofweek;
    int hour;
    int min;
    int sec;
};

struct datetime now;

void getnowdate(){ //現在の日時を取得
    time_t timer;
    timer = time(NULL);
    struct tm *local;

    local = localtime(&timer);

    now.year = local->tm_year + 1900;
    now.month = local->tm_mon + 1;
    now.day = local->tm_mday;
    now.dayofweek = local->tm_wday;
    now.hour = local->tm_hour;
    now.min = local->tm_min;
    now.sec = local->tm_sec;
}

void print_dayofweek(int dow){
    switch(dow){
        case 0:
            printf("(Sun.)");
            break;
        case 1:
            printf("(Mon.)");
            break;
        case 2:
            printf("(Tue.)");
            break;
        case 3:
            printf("(Wed.)");
            break;
        case 4:
            printf("(Thu.)");
            break;
        case 5:
            printf("()");
            break;
        case 6:
            break;
        default:
            break;
    }
}

int main(){
    getnowdate(); //現在の日時を取得
    printf("ターミナルで使うカレンダーソフト\n%d/%d/%d",now.year,now.month,now.day);
    print_dayofweek(now.dayofweek);
    return 0;
}