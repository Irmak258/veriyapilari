#include <stdio.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
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
    TimeUnion t1, t2;
  
    printf("Birinci tarihi giriniz (YYYY MM DD HH MM SS): ");
    scanf("%d %d %d %d %d %d", &t1.dateTime.year, &t1.dateTime.month, &t1.dateTime.day, &t1.dateTime.hour, &t1.dateTime.minute, &t1.dateTime.second);
    t1.epochTime = convertToEpoch(t1.dateTime);
 
    printf("Ikinci tarihi giriniz (YYYY MM DD HH MM SS): ");
    scanf("%d %d %d %d %d %d", &t2.dateTime.year, &t2.dateTime.month, &t2.dateTime.day, &t2.dateTime.hour, &t2.dateTime.minute, &t2.dateTime.second);
    t2.epochTime = convertToEpoch(t2.dateTime);
    
    printf("Birinci zamanýn epoch deðeri: %ld\n", t1.epochTime);
    printf("Ikinci zamanýn epoch deðeri: %ld\n", t2.epochTime);
    
    double difference = difftime(t2.epochTime, t1.epochTime);
    printf("Iki tarih arasindaki fark: %.0f saniye\n", difference);
    
    return 0;
}
