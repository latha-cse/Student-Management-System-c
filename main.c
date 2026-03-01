#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

struct Student students[100];
int count = 0;

// Function Declarations
void addStudent();
void displayStudents();
void searchStudent();
void deleteStudent();
void saveToFile();
void loadFromFile();

int main() {
    int choice;

    loadFromFile();   // Load data when program starts

    while(1) {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}

// Add Student
void addStudent() {
    printf("Enter Roll Number: ");
    scanf("%d", &students[count].roll);

    printf("Enter Name: ");
    scanf("%s", students[count].name);

    printf("Enter Marks: ");
    scanf("%f", &students[count].marks);

    count++;

    saveToFile();  // Save after adding
    printf("Student Added Successfully!\n");
}

// Display Students
void displayStudents() {
    if(count == 0) {
        printf("No students found.\n");
        return;
    }

    for(int i = 0; i < count; i++) {
        printf("\nRoll: %d", students[i].roll);
        printf("\nName: %s", students[i].name);
        printf("\nMarks: %.2f\n", students[i].marks);
    }
}

// Search Student
void searchStudent() {
    int roll, found = 0;

    printf("Enter Roll Number to Search: ");
    scanf("%d", &roll);

    for(int i = 0; i < count; i++) {
        if(students[i].roll == roll) {
            printf("\nStudent Found!\n");
            printf("Roll: %d\n", students[i].roll);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }

    if(found == 0) {
        printf("Student not found.\n");
    }
}

// Delete Student
void deleteStudent() {
    int roll, found = 0;

    printf("Enter Roll Number to Delete: ");
    scanf("%d", &roll);

    for(int i = 0; i < count; i++) {
        if(students[i].roll == roll) {
            for(int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            saveToFile();  // Save after deleting
            printf("Student Deleted Successfully!\n");
            found = 1;
            break;
        }
    }

    if(found == 0) {
        printf("Student not found.\n");
    }
}

// Save Data to File
void saveToFile() {
    FILE *fp = fopen("students.txt", "w");

    for(int i = 0; i < count; i++) {
        fprintf(fp, "%d %s %f\n",
                students[i].roll,
                students[i].name,
                students[i].marks);
    }

    fclose(fp);
}

// Load Data from File
void loadFromFile() {
    FILE *fp = fopen("students.txt", "r");

    if(fp == NULL)
        return;

    while(fscanf(fp, "%d %s %f",
                 &students[count].roll,
                 students[count].name,
                 &students[count].marks) != EOF) {
        count++;
    }

    fclose(fp);
}
