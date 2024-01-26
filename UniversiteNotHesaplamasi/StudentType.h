#ifndef STUDENTTYPE_H
#define STUDENTTYPE_H

#include "PersonType.h"
#include "Course.h"

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
static const int SIZE = 10;

class StudentType
{

private:
    string fullName;
    int sID;
    string numberofCourses[SIZE];
    int coursesEnrolled;
    PersonType person;
    Course sortCourses[SIZE];
    char isTuitionPaid;

public:

    // öğrenci bilgileri ayarlanması:
    void setStudentInfo(PersonType p, int id, char tuition, int enrolled)
    {
        string name = p.getName();
        string surname = p.getLastName();
        fullName = name + " " + surname;
        isTuitionPaid = tuition;
        sID = id;
        coursesEnrolled = enrolled;
    }

    // tek tek değerler alındı private oldukları için
    int getStudentID()
    {
        return sID;
    }

    string getFullName()
    {
        return fullName;
    }

    int getCoursesEnrolled()
    {
        return coursesEnrolled;
    }

    // dersler bu fonksiyonla eklendi
    void addCourse(Course course, int index)
    {
        if (coursesEnrolled < SIZE)
        {
            sortCourses[index] = course;
            index++;
        }
    }

    // not raporu dersleri artan sırada yazdıracağından, dersleri ders numarasına göre sıralanması
    void sortCourseNumbers()
    {
        for (int i = 0; i < coursesEnrolled - 1; i++)
        {
            int minIndex = i;
            for (int j = i + 1; j < coursesEnrolled; j++)
            {
                if (sortCourses[j].getcoursenumber() < sortCourses[minIndex].getcoursenumber())
                {
                    minIndex = j;
                }
            }
            Course temp = sortCourses[i];
            sortCourses[i] = sortCourses[minIndex];
            sortCourses[minIndex] = temp;
        }
    }
    // öğrenci bilgileri bu fonksiyonla yazdırılıyor
    void printStudentInfo(int tuitionPerCredit, ofstream &outFile)
    {
        // önce ders numarasına göre sıralanması için fonksiyonumuzu çağırdık
        sortCourseNumbers();
        // daha sonra başka bir dizi oluşturduk çünkü öğrencilerin aldığı dersler kadar size'a sahip dizi olması gerekiyordu 
        Course temp[coursesEnrolled];

        // eleman sayısı kadar sortCourses dizisinden eleman aldık ki dersleri alabilsin
        for (int i = 0; i < coursesEnrolled; i++)
        {
            temp[i] = sortCourses[i];
        }

        outFile << left << "Student Name: " << setw(20) << getFullName() << endl;
        outFile << "Student ID: " << setw(20) << getStudentID() << endl;

        outFile << "Number of courses enrolled: " << setw(20) << getCoursesEnrolled() << endl;
        outFile << left << setw(17) << "Course Name" << setw(17) << "Course No" << setw(10) << "Credits" << setw(10) << "Grade" << endl;
        for (Course course : temp)
        {
            course.printCourseInfo(outFile);
            if(isTuitionPaid == 'Y'){
                outFile << course.getcourseGrade() << endl;
            }
            else{
                outFile << '-' << endl;;
            }
        }
        // eğer harç ödenmişse notların bastırılabilmesi için bu işlemleri yapar
        if (isTuitionPaid == 'Y')
        {
            outFile << "Total number of credits: " << calculateCreditHour(temp, coursesEnrolled) << endl;
            outFile << "Mid-Semester GPA: " << calculateGPA(temp, coursesEnrolled) << endl;
        }
        // harç ödenmediyse ödenmesi için bilgi ve fatura bastırılır
        else
        {

            outFile << "WAITING FOR THE PAYMENT" << endl;
            outFile << "BILL: " << calculateBill(tuitionPerCredit, temp, coursesEnrolled);
        }
    }

    // toplam kredi saati hesaplanıyor
    int calculateCreditHour(Course course[], int enrolled)
    {
        int toplam = 0;
        for (int i = 0; i < enrolled; i++)
        {
            toplam += course[i].getCredits();
        }
        return toplam;
    }

    // derslerin numaraları diziye aktarılıyor
    void getCourseNumber()
    {
        for (int i = 0; i < sizeof(sortCourses); i++)
        {
            numberofCourses[i] = sortCourses[i].getcoursenumber();
        }
    }

    // gpa hesaplanması
    double calculateGPA(Course course[], int enrolled)
    {

        double gpa = 0.0;
        double total = 0.0;

        for (int i = 0; i < enrolled; i++)
        {

            total += (course[i].getGrade(course[i].getcourseGrade()) * course[i].getCredits());
        }
        gpa = total / calculateCreditHour(course, enrolled);
        return gpa;
    }

    // fatura bu fonksiyonla hesaplanıyor
    int calculateBill(int percredit, Course course[], int enrolled)
    {
        int total = 0;
        total = percredit * calculateCreditHour(course, enrolled);
        return total;
    }
};
#endif