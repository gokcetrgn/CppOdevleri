#include <iostream>
using namespace std;
#include <fstream>
#include "StudentType.h"
#include "PersonType.h"
#include "Course.h"

int main()
{

    ifstream inFile;
    ofstream outFile;

    inFile.open("input.txt");

    // öğrenci sayısı ve kredi başına harç input dosyasından alındı
    int numStudents, tuitionPerCredit;
    inFile >> numStudents >> tuitionPerCredit;

    // dosyadan alınacak değişkenler belirlendi
    int studentID, coursesEnrolled,creditHour;
    char isTuitionPaid,courseGrade;
    PersonType person;
    string name, surname,courseName,courseNumber;

    // input dosyasından sırayla student ve course class'larına atama yapıldı
    for (int i = 0; i < numStudents; ++i)
    {
        StudentType student;
        inFile >> name >> surname >> studentID >> isTuitionPaid >> coursesEnrolled;

        person.setName(name);
        person.setLastName(surname);
        student.setStudentInfo(person, studentID, isTuitionPaid, coursesEnrolled);

        for (int j = 0; j < student.getCoursesEnrolled(); j++)
        {
            Course course;
            inFile >> courseName >> courseNumber >> creditHour >> courseGrade;
            course.setCourseInfo(courseName, courseNumber, creditHour, courseGrade);
            student.addCourse(course,j);
        }

        // öğrenci adlarına özel isimlerle dosyaları oluşturuldu ve bilgileri basıldı
        string dosyaAdi = person.getName() + ".txt";
        outFile.open(dosyaAdi);
        student.printStudentInfo(tuitionPerCredit,outFile);

        outFile.close();
    }
}