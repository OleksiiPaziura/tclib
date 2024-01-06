#include "ClockTime.h"
using namespace tc;

ClockTime::ClockTime(long long seconds, long minutes, long hours, long days)
{
    this->seconds = seconds;
    this->minutes = minutes;
    this->hours = hours;
    this->days = days;
    recalculate();
}

// Converts the whole time to seconds
long long ClockTime::to_seconds() const
{
    long long temp_seconds = seconds;
    long temp_minutes = minutes;
    long temp_hours = hours;
    long temp_days = days;

    temp_hours += temp_days * 24;
    temp_days = 0;

    temp_minutes += temp_hours * 60;
    temp_hours = 0;

    temp_seconds += temp_minutes * 60;
    temp_minutes = 0;

    return temp_seconds;
}

// Converts the whole time to minutes
long ClockTime::to_minutes() const
{

    long temp_minutes = minutes;
    long temp_hours = hours;
    long temp_days = days;

    temp_hours += temp_days * 24;
    temp_days = 0;

    temp_minutes += temp_hours * 60;
    temp_hours = 0;

    return temp_minutes;
}

// Converts the whole time to hours
long ClockTime::to_hours() const
{
    long temp_hours = hours;
    long temp_days = days;

    temp_hours += temp_days * 24;
    temp_days = 0;

    return temp_hours;
}

// Recalculates the whole time and puts according values
void ClockTime::recalculate()
{
    if (seconds >= 60)
    {
        minutes += seconds / 60;
        seconds %= 60;
    }

    if (minutes >= 60)
    {
        hours += minutes / 60;
        minutes %= 60;
    }

    if (hours >= 24)
    {
        days += hours / 24;
        hours %= 24;
    }
}


void ClockTime::add_seconds(long long seconds)
{
    this->seconds += seconds;
    recalculate();
}
void ClockTime::add_minutes(long minutes)
{
    this->minutes += minutes;
    recalculate();
}
void ClockTime::add_hours(long hours)
{
    this->hours += hours;
    recalculate();
}
void ClockTime::add_days(long days)
{
    this->days += days;
    recalculate();
}


// Resets time
void ClockTime::reset(long long seconds, long minutes, long hours, long days)
{
    this->seconds = seconds;
    this->minutes = minutes;
    this->hours = hours;
    this->days = days;
}

const ClockTime& ClockTime::operator*=(float k)
{
    seconds = to_seconds();
    seconds *= k;
    recalculate();
}
const ClockTime& ClockTime::operator/=(float k)
{
    seconds = to_seconds();
    seconds /= k;
    recalculate();
}

