#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define class_size 7

int main(void)
{
    printf("\n");
    printf("Welcome to University!\n");
    printf("\n");
    printf("Main Menu");
    printf("\n");

    typedef struct Name classroom;
    {
        int number;
        char namespace [50];
        double subject_a;
        double subject_b;
    } students;
    void sort (students studentInfo[], int i)
    {
        int x, y;

        for (y = 1; y < i; y++) {
            for (x = 0; x < i - y; x++) {
                if (studentInfo[x].subject_a > studentInfo[x + 1].subject_a) {
                    student temp = studentInfo[x];
                    studentInfo[x] = studentInfo[x + 1];
                    studentInfo[x + 1] = temp;
                }
            }
        }
    }
}