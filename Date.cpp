#include "Date.h"


bool Date::isDateCorrect(size_t day, size_t month, size_t year)
{
    if (day < 1 || day > 31 || month < 1 || month > 12 || year <= 2020)
        return false;
    else
    {
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            if (day >= 1 && day <= 31)
                return true;
        }

        else if (month == 2)
        {
                if (isLeapYear(year))
                    if (day >= 1 && day <= 29) {
                        return true;
                    }
                else
                {
                    if (day >= 1 && day <= 28)
                        return true;
                }
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11) {
            if (day >= 1 && day <= 30)
                return true;
        }
    }
    return false;
}

bool Date::isLeapYear(size_t year)
{
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

Date::Date() : day(0), month(0), year(0) {}
Date::Date(size_t days, size_t months, size_t years) : Date(){
        day = days;
        month = months;
        year = years;
}
Date& Date::operator=(const Date& other)
{
    if (this != &other)
    {
        day = other.day;
        month = other.month;
        year = other.year;
    }
    return *this;
}
bool Date::operator==(const Date& other) const
{
    return day == other.day && month == other.month && year == other.year;
}

bool Date::operator<=(const Date& other) const
{
    return day <= other.day && month <= other.month && year <= other.year;
}

bool Date::operator>=(const Date& other) const
{
    return day >= other.day && month >= other.month && year >= other.year;
}

size_t Date::getDays() const
{
    return day;
}

size_t Date::getMonths() const
{
    return month;
}

size_t Date::getYears() const
{
    return year;
}

std::ostream& operator<<(std::ostream& out, const Date& current)
{
    out << current.day << "." << current.month << "." << current.year;
    return out;
}

std::istream& operator>>(std::istream& in, Date& current)
{
    char symbol;
    in >> current.day >> symbol >> current.month >> symbol >> current.year;
    return in;
}
