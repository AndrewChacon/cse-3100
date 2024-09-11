#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    char id[10];
    int age;
    int grades[5];
} Student;

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int *array;
} Data;

void printStudent(Student student); // function declaration
void printPoints(Point points[]);

int main()
{
    Student andrew;

    andrew.age = 24;

    strcpy(andrew.name, "Andrew");
    strcpy(andrew.id, "931823");
    andrew.age = 40;
    andrew.grades[0] = 1;
    andrew.grades[1] = 2;
    andrew.grades[2] = 3;
    andrew.grades[3] = 4;
    andrew.grades[4] = 5;

    // printStudent(andrew);

    Point p1 = {5, 10};
    Point p2 = {.y = 8, .x = 2};

    // printf("p1.x: %d\n", p1.x);
    // printf("p1.y: %d\n", p1.y);

    // printf("p2.x: %d\n", p2.x);
    // printf("p2.y: %d\n", p2.y);

    p1 = p2; // copies the memory 

    // printf("p1.x: %d\n", p1.x);
    // printf("p1.y: %d\n", p1.y);

    Point points[10];
    for (int i = 0; i < 10; i++) {
        points[i].x = i;
        points[i].y = 10 - i;
    }

    // printPoints(points);

    // complications can arise from using a pointer var in a struct
    Data x;
    Data y;

    x.array = malloc(sizeof(int) * 5); // store 5 ints
    y.array = malloc(sizeof(int) * 5);

    x.array[0] = 1;
    x.array[1] = 2;
    x.array[2] = 3;
    x.array[3] = 4;
    x.array[4] = 5;

    y.array[0] = 9;
    y.array[1] = 9;
    y.array[2] = 9;
    y.array[3] = 9;
    y.array[4] = 9;

    x = y;
    /*
    this struct doesnt hold the data of an array
    it holds the data for a pointer TO an array
    array isnt copied, the pointer to the array is copied
    the array of x did not update
    x.array is now pointing to y.array 
    */

    // for (int i = 0; i < 5; i++) {
    //     printf("x.array[%d] = %d\n", i, x.array[i]);
    // }

    x.array[0] = 10;
    // pointing to y array, modified y arrays data
    for (int i = 0; i < 5; i++) {
        printf("x.array[%d] = %d\n", i, x.array[i]);
    }

    return 0;
}

void printPoints(Point points[]) {
    for (int i = 0; i < 10; i++) {
        printf("p%d = (%d,%d)\n", i, points[i].x, points[i].y);
    }
}

void printStudent(Student student) {
    printf("Name: %s\n", student.name);
    printf("Age: %d\n", student.age);
    printf("ID: %s\n", student.id);
    printf("Grades: ");

    for (int i = 0; i < 5; i++) {
        printf("%d ", student.grades[i]);
    }
    printf("\n");
}