#ifndef COURSERA_AIRLINE_TICKET_H
#define COURSERA_AIRLINE_TICKET_H

#include <string>
using namespace std;

struct Date {
    int year, month, day;
};

struct Time {
    int hours, minutes;
};

struct AirlineTicket {
    string from;
    string to;
    string airline;
    Date departure_date;
    Time departure_time;
    Date arrival_date;
    Time arrival_time;
    int price;
};
#endif //COURSERA_AIRLINE_TICKET_H
