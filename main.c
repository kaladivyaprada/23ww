#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    char name[50];
    char usn[15];
    char branch[50];
    float percentage;
};

void readStudents(struct Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("USN: ");
        scanf("%s", students[i].usn);
        printf("Branch: ");
        scanf("%s", students[i].branch);
        printf("Percentage: ");
        scanf("%f", &students[i].percentage);
    }
}


void printStudents(struct Student students[], int n) {
    printf("\nStudent Details:\n");
    printf("%-20s %-15s %-20s %-10s\n", "Name", "USN", "Branch", "Percentage");
    for (int i = 0; i < n; i++) {
        printf("%-20s %-15s %-20s %-10.2f\n", students[i].name, students[i].usn, students[i].branch, students[i].percentage);
    }
}

void bubbleSort(struct Student students[], int n) {
    struct Student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].percentage < students[j + 1].percentage) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    struct Student students[MAX_STUDENTS];
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    if (n > MAX_STUDENTS) {
        printf("Maximum number of students is %d\n", MAX_STUDENTS);
        return 1;
    }

    readStudents(students, n);

    bubbleSort(students, n);


    printStudents(students, n);

    return 0;
}
