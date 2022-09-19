/*
 *  lab1exe_B.cpp
 *  ENSF 614 Lab 1, exercise B
 *  Created by Mahmood Moussavi
 *  Completed by: Student Name
 */

#include <iostream>
#include <cmath>
using namespace std;

const double G = 9.8;   /* gravitation acceleration 9.8 m/s^2 */
const double PI = 3.141592654;

void create_table(double v);
double Projectile_travel_time(double a, double v);
double Projectile_travel_distance(double a, double v);
double degree_to_radian(double d);

void create_table(double v) {
    cout << "Angle \tt \t\td \n";
    cout << "(deg) \t(sec) \t\t(m) \n";

    double deg = 0.0; //angle in degrees start from 0


    while(deg <= 90.0){
        double deg_radian = degree_to_radian(deg);
        double time = Projectile_travel_time(deg_radian, v);
        double distance = Projectile_travel_distance(deg_radian, v);

        cout << deg << "\t" << time << "\t\t" << distance << endl;

        deg += 5.0;
    }
}

double degree_to_radian(double d) {
    return (d * (PI / 180)); 
}

double Projectile_travel_distance(double a, double v){
    return (((v * v) / G) * sin(2 * a));
}

double Projectile_travel_time(double a, double v) {
    return (((2 * v) * sin(a)) / G);
}

int main(void)
{
    double velocity;
    
    cout << "Please enter the velocity at which the projectile is launched (m/sec): ";
    cin >> velocity;
    
    if(!cin)  // means if cin failed to read
    {
        cout << "Invlid input. Bye...\n";
        exit(1);
    }
    
    while (velocity < 0 )
    {
        cout << "\nplease enter a positive number for velocity: ";
        cin >> velocity;
        if(!cin)
        {
            cout << "Invlid input. Bye...";
            exit(1);
        }
    }

    create_table(velocity);
    
    return 0;
}


