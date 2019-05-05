#include <math.h>
#include <stdio.h>

#include <iostream>
#include <iomanip>

using namespace std;

struct Date {
    int day, month, year;

public:
    Date() : day(1), month(1), year(0)
    {
    }

    Date(int days_since_BC)
    {
        year = 0;
        month = 1;
        day = days_since_BC;

        while (day > days_in_year(year)) {
            day -= days_in_year(year);
            year += 1;
        }

        while (day > days_in_month(month, year)) {
            day -= days_in_month(month, year);
            month += 1;
        }
    }

    Date(int d, int m, int y) : day(d), month(m), year(y)
    {
    }

    Date(const char *s)
    {
        sscanf(s, "%d.%d.%d", &day, &month, &year);
    }

    int days_in_year(int y)
    {
        if (y % 4 == 0) {
            return 366;
        }
        return 365;
    }

    int days_in_month(int m, int y)
    {   //                 Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec
        int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (y % 4 == 0) {
            days[2] += 1;
        }
        return days[m];
    }

    int days_since_BC()
    {
        int res = day;
        for (int m = 1 ; m < month ; m++) {
            res += days_in_month(m, year);
        }

        for (int y = 0 ; y < year ; y++) {
            res += days_in_year(y);
        }

        return res;
    }

    int day_of_week()
    {   //                               |-------> 19.06.2016 is Sunday.
        int d = (days_since_BC() - Date(19, 6, 2016).days_since_BC()) % 7;
        return (d + 7) % 7;
    }
};

ostream& operator<<(ostream& o, Date d)
{
    return o << setw(2) << setfill('0') << d.day   << '.'
             << setw(2) << setfill('0') << d.month << '.' << d.year;
}

int operator-(Date a, Date b)
{
    return a.days_since_BC() - b.days_since_BC();
}

Date operator+(Date a, int b)
{
    return Date(a.days_since_BC() + b);
}


struct FloatDate : public Date {
    FloatDate(float d) : Date(floor(d), int(100*(d - floor(d)) + 0.5), 2016)
    {}
};

// ------------------------------------------------------------------------- //

int main()
{
    Date d1("1.06.2016"),
         d2(5, 5, 2016),
         d3("16.05.2016");

    char* days[7] = {"Вс", "Пн", "Вт", "Ср", "Чт", "Пт", "Сб"};

    cout << d3 << " + " << 21 << " = " << d3 + 21 << endl;
    cout << d3 << " = " << d3.day_of_week() << " = " << days[d3.day_of_week()] << endl;

    FloatDate fd(08.03);
    cout << "fd = " << fd << endl;

    return 0;
}