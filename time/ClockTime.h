#ifndef TC_TIME_H
#define TC_TIME_H

///TODO: Make an output mask for time in different formats (for instance: "dd:hh:mm:ss")

namespace tc
{
    class ClockTime
    {
    private:
        long long seconds;
        long minutes,
             hours,
             days;

        void recalculate();

    public:
        ClockTime(long long seconds = 0,
                  long minutes = 0,
                  long hours = 0,
                  long days = 0);

        long long to_seconds() const; // Convert all time to seconds
        long to_minutes() const; // Convert all time to minutes
        long to_hours() const; // Convert all time to hours

        inline long long get_seconds() const
        { return seconds; }

        inline long get_minutes() const
        { return minutes; }

        inline long get_hours() const
        { return hours; }

        inline long get_days() const
        { return days; }

        void add_seconds(long long seconds);
        void add_minutes(long minutes);
        void add_hours(long hours);
        void add_days(long days);
        void reset(long long seconds = 0,
                   long minutes = 0,
                   long hours = 0,
                   long days = 0);

        const ClockTime &operator+(const ClockTime &time) const;
        const ClockTime &operator-(const ClockTime &time) const;
        const ClockTime &operator*(float k) const;
        inline friend const ClockTime &operator*(float k, const ClockTime &time)
        { return time * k; }

        const ClockTime &operator*=(float k);
        const ClockTime &operator/=(float k);
        const ClockTime &operator+=(const ClockTime &time);
        const ClockTime &operator-=(const ClockTime &time);
    };
}

#endif // TC_TIME_H
