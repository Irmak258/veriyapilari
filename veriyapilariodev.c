#include <stdio.h>
#include <time.h>

typedef struct {
    int year, month, day, hour, minute, second;
} DateTime;

typedef union {
    time_t epochTime;
    DateTime dateTime;
} TimeUnion;

time_t convertToEpoch(DateTime dt) {
    struct tm t = {0};
    t.tm_year = dt.year - 1900;
    t.tm_mon = dt.month - 1;
    t.tm_mday = dt.day;
    t.tm_hour = dt.hour;
    t.tm_min = dt.minute;
    t.tm_sec = dt.second;
    return mktime(&t);
}

int main() {
    TimeUnion start, end;
    
    printf("Ise giris zamanini giriniz (YYYY MM DD HH MM SS): ");
    scanf("%d %d %d %d %d %d", &start.dateTime.year, &start.dateTime.month, &start.dateTime.day,
          &start.dateTime.hour, &start.dateTime.minute, &start.dateTime.second);
    start.epochTime = convertToEpoch(start.dateTime);
    
    printf("Isten cikis zamanini giriniz (YYYY MM DD HH MM SS): ");
    scanf("%d %d %d %d %d %d", &end.dateTime.year, &end.dateTime.month, &end.dateTime.day,
          &end.dateTime.hour, &end.dateTime.minute, &end.dateTime.second);
    end.epochTime = convertToEpoch(end.dateTime);
    
    printf("Ise giris epoch zamani: %ld\n", start.epochTime);
    printf("Isten cikis epoch zamani: %ld\n", end.epochTime);
    
    double work_duration = difftime(end.epochTime, start.epochTime);
    printf("Toplam calisma suresi: %.0f saniye (%.2f saat)\n", work_duration, work_duration / 3600.0);
    
    return 0;
}

