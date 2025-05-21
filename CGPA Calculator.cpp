#include <stdio.h>

int main() {
    int numCourses;
    float grade, credit, totalCredits = 0, totalGradePoints = 0;
    char courseName[100];

    printf("Enter the number of courses: ");
    scanf("%d", &numCourses);

    for (int i = 0; i < numCourses; i++) {
        printf("\nCourse %d:\n", i + 1);
        printf("Enter course name: ");
        scanf(" %[^\n]", courseName);  // Reads course name with spaces
        printf("Enter grade (on a 10-point scale): ");
        scanf("%f", &grade);
        printf("Enter credit hours: ");
        scanf("%f", &credit);

        totalGradePoints += grade * credit;
        totalCredits += credit;
    }

    if (totalCredits == 0) {
        printf("\nTotal credit hours cannot be zero.\n");
        return 1;
    }

    float cgpa = totalGradePoints / totalCredits;
    float percentage = cgpa * 9.5;

    printf("\nTotal Grade Points: %.2f", totalGradePoints);
    printf("\nTotal Credit Hours: %.2f", totalCredits);
    printf("\nCGPA: %.2f", cgpa);
    printf("\nEquivalent Percentage: %.2f%%\n", percentage);

    return 0;
}
