#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Course {
    string name;
    int credits;
    float grade;
};

float calculateCGPA(const vector<Course>& courses) {
    int totalCredits = 0;
    float totalGradePoints = 0.0;
    for (const auto& course : courses) {
        totalCredits += course.credits;
        totalGradePoints += course.credits * course.grade;
    }
    return totalGradePoints / totalCredits;
}

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<Course> courses(numCourses);

    for (int i = 0; i < numCourses; ++i) {
        cout << "\nEnter details for course " << i + 1 << ":\n";
        cout << "Course name: ";
        cin.ignore(); // To clear the newline character left in the buffer
        getline(cin, courses[i].name);
        cout << "Credits: ";
        cin >> courses[i].credits;
        cout << "Grade (as a number, e.g., 9.0 for A): ";
        cin >> courses[i].grade;
    }

    cout << "\n\nCourse Details:\n";
    cout << left << setw(20) << "Course Name" << setw(10) << "Credits" << setw(10) << "Grade" << endl;
    for (const auto& course : courses) {
        cout << left << setw(20) << course.name << setw(10) << course.credits << setw(10) << course.grade << endl;
    }

    float cgpa = calculateCGPA(courses);
    cout << "\nYour CGPA is: " << fixed << setprecision(2) << cgpa << endl;

    return 0;
}
