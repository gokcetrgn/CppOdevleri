#ifndef COURSE_H
#define COURSE_H
#include <iostream>
using namespace std;
#include <iomanip>
#include <fstream>

class Course {

private:
    string courseName;
    string courseNumber;
    int creditHour;
    char courseGrade;

public:

    // kurs bilgileri setleniyor
    void setCourseInfo(string course, string coursenum, int credith, char grade)
    {
        courseName = course;
        courseNumber = coursenum;
        creditHour = credith;
        courseGrade = grade;
    }

    // tek tek değerler alınıyor
    string getCourseName()
    {
        return courseName;
    }

    string getcoursenumber()
    {
        return courseNumber;
    }

    int getCredits()
    {
        return creditHour;
    }

    char getcourseGrade()
    {
        return courseGrade;
    }
    // kurs bilgileri bu fonksiyonla yazdırılıyor
    void printCourseInfo(ofstream &outFile)
    {
        outFile << left << setw(20) << getCourseName() << setw(15) << getcoursenumber() << setw(10) << getCredits() << setw(10);
    }
    // kredi numaraları
    void displayCredits()
    {
        cout << "Credit number: " << getCredits() << endl;
    }

    int getGrade(char grade)
    {
        switch (grade)
        {
        case 'A':
            return 4;
        case 'B':
            return 3;
        case 'C':
            return 2;
        case 'D':
            return 1;
        default:
            return 0;
        }
    }
};

#endif