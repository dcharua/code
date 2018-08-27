#include <stdio.h>
#include <string.h>

#define NAME_LENGTH 50
#define MATRICULA 10
#define COURSES 4
#define MONTH 13
#define MAX_STUDENTS 30

typedef float real;
typedef long unsigned int size_t;

typedef struct date
{
    int day;
    //char month[MONTH];
    int month;
    int year;
} date;

typedef struct student
{
    char name[NAME_LENGTH];
    char matricula[MATRICULA];
    int grades[COURSES];
    int age;
    date birthday;
} student;

// TODO: Change the program so that it uses the new typedef
// TODO: Initialize a structure, or an array of structures
// TODO: Allocate an array of students dynamically

void input_student(student * alumno);
void print_student(student alumno);

int main()
{
    long unsigned int length;
    size_t length_2;

    int number = 5;
    int array[MAX_STUDENTS] = {5, 7, 8};

    int * new_array = NULL;
    int size = 10; // Get this number from the user (scanf)
    new_array = malloc(sizeof(int) * size);
    new_array[6] = 6345;
    // Return the memory to the system
    free(new_array);

    student isaac = {"Isaac", "A32458754", {0}, 45, {2, 3, 1990}};
    student hector = {"Hector", "A32458754", {0}, 45, {4, 7, 1985}};
    student class[MAX_STUDENTS] = { {"Isaac", "A32458754", {0}, 45},
                                    {"Pedro", "A3948752", {34, 32, 65, 45}}
                                  };

    student * new_class = NULL;
    new_class = malloc(sizeof(student) * size); 
    /* USE THE NEW ARRAY OF STUDENTS */
    free(new_class);


    int i;
    for (i=0; i<MAX_STUDENTS; i++)
    {
        input_student(&class[i]);
    }

    input_student(&isaac);
    print_student(isaac);
}


void input_student(student * alumno)
{
    int tmp;
    int i;
    printf("Enter the student's name: ");
    fgets((*alumno).name, NAME_LENGTH, stdin);
    // Clear the newline from the end of the string
    alumno->name[strlen(alumno->name)-1] = '\0';

    printf("Enter the student ID: ");
    fgets(alumno->matricula, MATRICULA, stdin);
    // Clear the newline from the end of the string
    alumno->matricula[strlen(alumno->matricula)-1] = '\0';

    printf("Enter the student age: ");
    scanf("%d", &tmp);
    alumno->age = tmp;
    for (i=0; i<COURSES; i++)
    {
        printf("Enter the grade for course %d: ", i);
        scanf("%d", &tmp);
        alumno->grades[i] = tmp;
    }

    printf("Enter the birthday:\n");
    printf("\tDay: ");
    scanf("%d", &tmp);
    alumno->birthday.day = tmp;
    printf("\tMonth: ");
    scanf("%d", &tmp);
    alumno->birthday.month = tmp;
    printf("\tYear: ");
    scanf("%d", &tmp);
    alumno->birthday.year = tmp;
}

void print_student(student alumno)
{
    int i;
    printf("Name: %s\n", alumno.name);
    printf("Matricula: %s\n", alumno.matricula);
    printf("Age: %d\n", alumno.age);
    for (i=0; i<COURSES; i++)
    {
        printf("Grade %d: %d\n", i, alumno.grades[i]);
    }
    printf("Birthday: %d / %d / %d\n", alumno.birthday.day, alumno.birthday.month, alumno.birthday.year);
}
