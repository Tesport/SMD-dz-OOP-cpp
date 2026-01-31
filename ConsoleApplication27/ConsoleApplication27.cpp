#include <iostream>
using namespace std;

// 1
class Integer {
private:
    int variable;

public:
    Integer(int val) : variable(val) {
        cout << "Variable was created succesful" << endl;
    };

    void var_setter(int value) {
        variable = value;
    }

    int var_getter() {
        return variable;
    }
};
// 2
class Circle {
private:
    int radius;
public:
    Circle(int val) : radius(val) {}
    Circle() : radius(5) {}

    double perimeter() {
        return radius * 3.14;
    }

    double area() {
        return 3.14 * (radius * radius);
    }

    void rad_setter(int value) {
        if (value > 0)
            radius = value;
        else
            cout << "Error, invalid input" << endl;
    }

    int rad_getter() {
        return radius;
    }
};

// 3
class AlarmClock {
private:
    int hours;
    int minutes;
    int alarm_hour;
    int alarm_minutes;

public:
    AlarmClock() {};

    void tick() {
        if (++minutes == 60) {
            minutes = 0;
            if (++hours == 24)
                hours = 0;
        }
        if (minutes == alarm_minutes) {
            if (hours == alarm_hour) {
                cout << "Alarm is ringing" << endl;
                return;
            }
        }
        cout << "tick" << endl;

    }

    bool time_checker(int h, int m) {
        if (0 <= h and h < 24 and 0 <= m and m < 60)
            return 1;
        return 0;
    }

    void time_setter(int h, int m) {
        if (time_checker(h, m))
            hours = h, minutes = m;
        else
            cout << "Input error, time settings were denied. Try again" << endl;
    }

    void alarm_setter(int h, int m) {
        if (time_checker(h, m))
            alarm_hour = h, alarm_minutes = m;
        else
            cout << "Input error, time settings were denied. Try again" << endl;
    }
};

int main()
{
    // 1
    Integer obj(17);
    cout << "1st = " << obj.var_getter() << endl;
    obj.var_setter(20);
    cout << "2nd = " << obj.var_getter() << endl;
    
    // 2
    Circle obj2;
    cout << "\n" << obj2.rad_getter() << endl;

    Circle obj3(3);
    cout << obj3.rad_getter() << endl;

    cout << obj3.area() << endl;
    cout << obj3.perimeter() << endl;
    obj3.rad_setter(0);
    cout << obj3.rad_getter() << endl;
    obj3.rad_setter(2);
    cout << obj3.rad_getter() << endl;

    // 3
    cout << "\nAlarmClock: " << endl;
    AlarmClock timer;
    timer.alarm_setter(10, 30);
    timer.time_setter(10, 27);
    for (int i = 0; i < 5; i++)
        timer.tick();
}
