
#include <stdio.h>

#define MAX 100

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    struct Student students[MAX];
    int count = 0;
    int choice;
    int i;

    do {
        printf("\n===== Student Record System =====\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (count >= MAX) {
                printf("Student record limit reached!\n");
                continue;
            }

            printf("Enter roll number: ");
            scanf("%d", &students[count].roll);

            printf("Enter name (without spaces): ");
            scanf("%49s", students[count].name);

            printf("Enter marks (0 to 100): ");
            scanf("%f", &students[count].marks);

            if (students[count].marks < 0 ||
                students[count].marks > 100) {
                printf("Invalid marks! Record not added.\n");
                continue;
            }

            count++;
            printf("Student added successfully!\n");
        }
        else if (choice == 2) {
            if (count == 0) {
                printf("No student records found.\n");
            }

            for (i = 0; i < count; i++) {
                printf("\nRoll Number: %d\n",
                       students[i].roll);
                printf("Name: %s\n", students[i].name);
                printf("Marks: %.2f\n", students[i].marks);

                if (students[i].marks >= 33) {
                    printf("Result: Pass\n");
                } else {
                    printf("Result: Fail\n");
                }
            }
        }
        else if (choice == 3) {
            printf("Thank you for using the program!\n");
        }
        else {
            printf("Invalid choice! Try again.\n");
        }

    } while (choice != 3);

    return 0;
}
