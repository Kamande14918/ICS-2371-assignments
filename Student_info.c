//KENNEDY KAMAU KAMANDE
//ENE212-0169/2021
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COURSES 10
#define MAX_NAME_LENGTH 50
#define MAX_LINE_LENGTH 256
#define MIN_COURSES 3

typedef struct {
    char first_name[MAX_NAME_LENGTH];
    char last_name[MAX_NAME_LENGTH];
    int roll_number;
    int num_courses;
    char courses[MAX_COURSES][MAX_NAME_LENGTH];
} Student;

void input_student(Student *student) {
    printf("Enter student's first name: ");
    fgets(student->first_name, MAX_NAME_LENGTH, stdin);
    student->first_name[strcspn(student->first_name, "\n")] = '\0';

    printf("Enter student's last name: ");
    fgets(student->last_name, MAX_NAME_LENGTH, stdin);
    student->last_name[strcspn(student->last_name, "\n")] = '\0';

    printf("Enter student's roll number: ");
    scanf("%d", &student->roll_number);
    getchar(); // Consume newline character

    printf("Enter student's courses (at least %d courses, up to %d courses, enter a blank line to finish):\n", MIN_COURSES, MAX_COURSES);
    student->num_courses = 0;
    char line[MAX_LINE_LENGTH];
    while (student->num_courses < MAX_COURSES && fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
        line[strcspn(line, "\n")] = '\0';
        if (strlen(line) == 0) {
            break;
        }
        strcpy(student->courses[student->num_courses], line);
        student->num_courses++;

        // Ensure the student is registered to at least 3 courses
        if (student->num_courses == MIN_COURSES) {
            break;
        }
    }

    if (student->num_courses < MIN_COURSES) {
        printf("Error: Student must be registered to at least %d courses.\n", MIN_COURSES);
        exit(1);
    }
}

void display_student(Student *student) {
    printf("\nStudent information:\n");
    printf("Name: %s %s\n", student->first_name, student->last_name);
    printf("Roll number: %d\n", student->roll_number);
    printf("Courses:\n");
    for (int i = 0; i < student->num_courses; i++) {
        printf("%d: %s\n", i + 1, student->courses[i]);
    }
}

void edit_student(Student *student) {
    int choice;
    while (1) {
        printf("\n1. Edit name\n2. Edit roll number\n3. Editcourses\n4. Finish editing\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter new first name: ");
                fgets(student->first_name, MAX_NAME_LENGTH, stdin);
                student->first_name[strcspn(student->first_name, "\n")] = '\0';

                printf("Enter new last name: ");
                fgets(student->last_name, MAX_NAME_LENGTH, stdin);
                student->last_name[strcspn(student->last_name, "\n")] = '\0';
                break;
            case 2:
                printf("Enter new roll number: ");
                scanf("%d", &student->roll_number);
                getchar(); // Consume newline character
                break;
            case 3:
                printf("Enter new courses (at least %d courses, up to %d courses, enter a blank line to finish):\n", MIN_COURSES, MAX_COURSES);
                student->num_courses = 0;
                char line[MAX_LINE_LENGTH];
                while (student->num_courses < MAX_COURSES && fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
                    line[strcspn(line, "\n")] ='\0';
                    if (strlen(line) == 0) {
                        break;
                    }
                    strcpy(student->courses[student->num_courses], line);
                    student->num_courses++;

                    // Ensure the student is registered to at least 3 courses
                    if (student->num_courses == MIN_COURSES) {
                        break;
                    }
                }

                if (student->num_courses < MIN_COURSES) {
                    printf("Error: Student must be registered to at least %d courses.\n", MIN_COURSES);
                    exit(1);
                }
                break;
            case 4:
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void save_student(Student *student) {
    FILE *file;
    char filename[MAX_NAME_LENGTH + 5];
    strcpy(filename, student->first_name);
    strcat(filename, ".txt");

    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Unable to open file %s for writing.\n", filename);
        exit(1);
    }

    fprintf(file, "First name: %s\n", student->first_name);
    fprintf(file, "Last name: %s\n", student->last_name);
    fprintf(file, "Roll number: %d\n", student->roll_number);
    fprintf(file, "Courses:\n");
    for (int i = 0; i < student->num_courses; i++) {
        fprintf(file, "%d: %s\n", i + 1, student->courses[i]);
    }

    fclose(file);
}

void load_student(Student *student) {
    FILE *file;
    char filename[MAX_NAME_LENGTH + 5];
    printf("Enter the filename: ");
    scanf("%s", filename);
    getchar(); // Consume newline character

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s for reading.\n", filename);
        exit(1);
    }

    fgets(student->first_name, MAX_NAME_LENGTH, file);
    student->first_name[strcspn(student->first_name, "\n")] = '\0';

    fgets(student->last_name, MAX_NAME_LENGTH, file);
    student->last_name[strcspn(student->last_name, "\n")] = '\0';

    fscanf(file, "Roll number: %d\n", &student->roll_number);

    char line[MAX_LINE_LENGTH];
    student->num_courses = 0;
    while (student->num_courses < MAX_COURSES && fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        if (strlen(line) == 0) {
            break;
        }
        sscanf(line, "%d: %s", &student->num_courses, student->courses[student->num_courses]);
        student->num_courses++;
    }

    fclose(file);
}

int main() {
    Student student;
    int choice;

    while (1) {
        printf("\n1. Input student\n2. Display student\n3. Edit student\n4. Save student\n5. Load student\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                input_student(&student);
                break;
            case 2:
                display_student(&student);
                break;
            case 3:
                edit_student(&student);
                break;
            case 4:
                save_student(&student);
                break;
            case 5:
                load_student(&student);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
