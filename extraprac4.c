#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 100
struct student {
    char name[50];
    int rollno;
    int marks[3]; // Marks for three subjects
    float percentage;
};
// Function prototypes
void input_students(struct student students[], int n);
void search1(struct student students[], int n, int x);
struct student search2(struct student students[], int n, int x);
struct student* search3(struct student students[], int n, int x);
void sort(struct student students[], int n);
void display(struct student s1);

int main() {
    struct student students[MAX_STUDENTS];
    int n, rollno_to_search;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Input student information
    input_students(students, n);

    // Search for a student using search1
    printf("\nEnter roll number to search using search1: ");
    scanf("%d", &rollno_to_search);
    search1(students, n, rollno_to_search);

    // Search for a student using search2
    printf("\nEnter roll number to search using search2: ");
    scanf("%d", &rollno_to_search);
    struct student found_student = search2(students, n, rollno_to_search);
    display(found_student);

    // Search for a student using search3
    printf("\nEnter roll number to search using search3: ");
    scanf("%d", &rollno_to_search);
    struct student* found_student_ptr = search3(students, n, rollno_to_search);
    if (found_student_ptr != NULL) {
        display(*found_student_ptr);
    } else {
        printf("Student with Roll No: %d not found.\n", rollno_to_search);
    }

    // Sort students by roll number
    sort(students, n);
    printf("\nStudents sorted by roll number:\n");
    for (int i = 0; i < n; i++) {
        display(students[i]);
    }
    return 0;
}

// Function to input student information
void input_students(struct student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll No: ");
        scanf("%d", &students[i].rollno);
        
        // Input marks for three subjects
        printf("Marks for subject 1: ");
        scanf("%d", &students[i].marks[0]);
        printf("Marks for subject 2: ");
        scanf("%d", &students[i].marks[1]);
        printf("Marks for subject 3: ");
        scanf("%d", &students[i].marks[2]);

        // Calculate percentage
        students[i].percentage = (students[i].marks[0] + students[i].marks[1] + students[i].marks[2]) / 3.0;
    }
}

// Function to search student by roll number and display information
void search1(struct student students[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (students[i].rollno == x) {
            printf("\nStudent found:\n");
            display(students[i]);
            return;
        }
    }
    printf("Student with Roll No: %d not found.\n", x);
}

// Function to search student by roll number and return the record
struct student search2(struct student students[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (students[i].rollno == x) {
            return students[i]; // Return the found student record
        }
    }
    struct student not_found; // Return an empty student if not found
    not_found.rollno = -1; // Indicate not found
    return not_found;
}

// Function to search student by roll number and return pointer to the record
struct student* search3(struct student students[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (students[i].rollno == x) {
            return &students[i]; // Return pointer to the found student record
        }
    }
    return NULL; // Return NULL if not found
}
void sort(struct student students[], int n) {
    struct student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].rollno > students[j + 1].rollno) {
                // Swap students[j] and students[j + 1]
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}
// Function to display information of a student
void display(struct student s1) {
    if (s1.rollno == -1) {
        printf("Student not found.\n");
        return;
    }
    printf("Name: %s\n", s1.name);
    printf("Roll No: %d\n", s1.rollno);
    printf("Marks: %d, %d, %d\n", s1.marks[0], s1.marks[1], s1.marks[2]);
    printf("Percentage: %.2f%%\n", s1.percentage);
}