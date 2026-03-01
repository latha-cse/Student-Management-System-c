#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

struct Student students[100];
int count = 0;

void addStudent();
void displayStudents();
void searchStudent();
void deleteStudent();
int main() {
    int choice;

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

void addStudent() {
    printf("Enter Roll Number: ");
    scanf("%d", &students[count].roll);

    printf("Enter Name: ");
    scanf("%s", students[count].name);

    printf("Enter Marks: ");
    scanf("%f", &students[count].marks);

    count++;
    printf("Student Added Successfully!\n");
}

void displayStudents() {
    int i;
    if(count == 0) {
        printf("No students found.\n");
        return;
    }

    for(i = 0; i < count; i++) {
        printf("\nRoll: %d", students[i].roll);
        printf("\nName: %s", students[i].name);
        printf("\nMarks: %.2f\n", students[i].marks);
    }
}
void searchStudent() {
    int roll, i, found = 0;

    printf("Enter Roll Number to Search: ");
    scanf("%d", &roll);

    for(i = 0; i < count; i++) {
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
void deleteStudent() {
    int roll, i, j, found = 0;

    printf("Enter Roll Number to Delete: ");
    scanf("%d", &roll);

    for(i = 0; i < count; i++) {
        if(students[i].roll == roll) {
            for(j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            found = 1;
            printf("Student Deleted Successfully!\n");
            break;
        }
    }

    if(found == 0) {
        printf("Student not found.\n");
    }
}
