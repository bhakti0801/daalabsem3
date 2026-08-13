#include <stdio.h>

struct Student {
    int roll;
    char name[50];
    int marks[5];
    int total;
    float percentage;
    char grade;
};

int main() {
    int n, i, j;
    float classTotal = 0;
    int topper = 0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    // Input
    for (i = 0; i < n; i++) {
        printf("\nEnter details of student %d\n", i + 1);

        printf("Roll number: ");
        scanf("%d", &s[i].roll);

        printf("Name: ");
        scanf("%s", s[i].name);

        s[i].total = 0;

        for (j = 0; j < 5; j++) {
            printf("Marks in subject %d: ", j + 1);
            scanf("%d", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
        }

        s[i].percentage = s[i].total / 5.0;

        if (s[i].percentage >= 90)
            s[i].grade = 'A';
        else if (s[i].percentage >= 75)
            s[i].grade = 'B';
        else if (s[i].percentage >= 60)
            s[i].grade = 'C';
        else if (s[i].percentage >= 50)
            s[i].grade = 'D';
        else
            s[i].grade = 'F';

        classTotal += s[i].percentage;

        if (s[i].total > s[topper].total)
            topper = i;
    }

    // Display results
    printf("\n----- STUDENT RESULTS -----\n");

    for (i = 0; i < n; i++) {
        printf("\nRoll No: %d", s[i].roll);
        printf("\nName: %s", s[i].name);
        printf("\nTotal: %d", s[i].total);
        printf("\nPercentage: %.2f", s[i].percentage);
        printf("\nGrade: %c\n", s[i].grade);
    }

    // Class topper
    printf("\n----- CLASS TOPPER -----\n");
    printf("Name: %s", s[topper].name);
    printf("\nRoll No: %d", s[topper].roll);
    printf("\nPercentage: %.2f\n", s[topper].percentage);

    // Failed students
    printf("\n----- FAILED STUDENTS -----\n");

    for (i = 0; i < n; i++) {
        int failed = 0;

        for (j = 0; j < 5; j++) {
            if (s[i].marks[j] < 40) {
                failed = 1;
            }
        }

        if (failed)
            printf("%s (Roll No: %d)\n", s[i].name, s[i].roll);
    }

    // Class average
    printf("\nClass Average = %.2f\n", classTotal / n);

    return 0;
}