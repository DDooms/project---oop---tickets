#include "Date.h"

size_t Date::daysInMonth(size_t month, size_t year)
{
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 31;

    else if (month == 2)
    {
        return 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    return 0;
}

bool Date::compareDates(Date& date1, Date& date2)
{
    if (date1.year == date2.year)
    {
        if (date1.month == date2.month)
        {
            if (date1.day == date2.day)
                return false;
            return true;
        }
        return false;
    }
    return false;
}

bool Date::isDateCorrect(size_t day, size_t month, size_t year)
{
    if (day < 1 || day > 31 || month < 1 || month > 12 || year > 2021 || year < 2021)
        return false;
    return day <= daysInMonth(month, year);
}

Date::Date() : day(0), month(0), year(0) {}
Date::Date(size_t days, size_t months, size_t years) : Date(){
    if (isDateCorrect(days, months, years))
    {
        day = days;
        month = months;
        year = years;
    }
    else std::cout << "Nice, you can't enter a correct date...\n";
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

void Date::setDays(size_t days)
{
    day = days;
}

void Date::setMonths(size_t months)
{
    month = months;
}

void Date::setYears(size_t years)
{
    year = years;
}

void Date::print() const
{
    std::cout << day << "." << month << "." << year << "\n";
}

std::ostream& operator<<(std::ostream& out, const Date& current)
{
    out << current.day << "." << current.month << "." << current.year << "\n";
    return out;
}
