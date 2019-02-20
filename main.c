#include <stdio.h>
#include<math.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 7

typedef struct

{
    float subjectAScore;
    float subjectBScore;
    int totalNumber;
    char studentName[30];

} student;

float GetMeanScore(float data[], int n)
{
    float sum = 0;
    int i;
    for (i = 1; i < n; i++)
    {
        sum += data[i];
    }
    return sum / n;
}

void ascendingOrder(student studentInfo[], int n)
{
    int j, i;

    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            if (studentInfo[j].subjectAScore > studentInfo[j + 1].subjectAScore)
            {
                student temp = studentInfo[j];
                studentInfo[j] = studentInfo[j + 1];
                studentInfo[j + 1] = temp;
            }
        }
    }
}


void displayInfo(student studentInfo[], int totalStudents)
{
    int i;
    for (i = 0; i < totalStudents; i++)
    {
        printf("%s %d %.2f %.2f ", studentInfo[i].studentName, studentInfo[i].totalNumber,
               studentInfo[i].subjectAScore, studentInfo[i].subjectBScore);
    }
}


float getStandardDeviationScore(float data[], int n)
{
    float m = GetMeanScore(data, n), squaredSum;
    int i;
    for (i = 1; i < n; i++)
    {

        squaredSum += (data[i] - m)*(data[i] - m);
    }
    return sqrt(squaredSum / n);
}


void writeData(FILE *file_pointer,student studentInfo [],int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        fprintf(file_pointer, "%s %d %f %f ", studentInfo[i].studentName, studentInfo[i].totalNumber, studentInfo[i].subjectAScore, studentInfo[i].subjectBScore);
    }
}

int main()
{

// run main section 1
// takes grade scores and outputs them to a saved file

    printf("\n");
    printf("\n");
    printf("Grades are now posted");
    printf("\n");
    printf("\n");
    printf("Final Grades Results below:");
    printf("\n");
    printf("\n");


    FILE *filepointer = NULL;
    student studentInfo[SIZE];
    int i = 0;
    int totalStudents = 0;
    char line[100];

// section 1.1. Open grades.txt for input

    if (NULL == (filepointer = fopen("grades.txt", "r")))
    {
        perror("Error while opening the file. ");
        exit(EXIT_FAILURE);
    }
    while (fgets(line, 100, filepointer) != NULL)
    {
        sscanf(line, "%s %d %f %f ", studentInfo[totalStudents].studentName, &studentInfo[totalStudents].totalNumber,
               &studentInfo[totalStudents].subjectAScore, &studentInfo[totalStudents].subjectBScore);
        totalStudents++;
    }
    fclose(filepointer);
    displayInfo(studentInfo, totalStudents);

// section 1.2. Saves to output.txt, writing complete output to single file

    if (NULL == (filepointer = fopen("output.txt", "w")))
    {
        perror("Error while opening the file. ");
        exit(EXIT_FAILURE);
    }

    writeData(filepointer,studentInfo,SIZE);
    fprintf(filepointer, " Student With diploma ");
    for (i = 0; i < totalStudents; i++)
    {
        if (studentInfo[i].subjectAScore >= 50 && studentInfo[i].subjectBScore >= 50)
            fprintf(filepointer, "%s %d %f %f ", studentInfo[i].studentName, studentInfo[i].totalNumber, studentInfo[i].subjectAScore, studentInfo[i].subjectBScore);
    }

    ascendingOrder(studentInfo, totalStudents);
    printf("\n");
    printf("\n");
    printf("Subject A sorted from lowest to highest");
    printf("\n");
    printf("\n");
    fprintf(filepointer,"Subject A sorted from lowest to highest");
    displayInfo(studentInfo, totalStudents);
    writeData(filepointer,studentInfo,SIZE);
    printf("\n");

    float subjectAScore[SIZE];
    float subjectBScore[SIZE];
    for (i = 0; i < SIZE; i++)
    {
        subjectAScore[i] = studentInfo[i].subjectAScore;
        subjectBScore[i] = studentInfo[i].subjectBScore;
    }
    float meanA = GetMeanScore(subjectAScore, SIZE);
    float meanB = GetMeanScore(subjectBScore, SIZE);
    float stdA = getStandardDeviationScore(subjectAScore, totalStudents);
    float stdB = getStandardDeviationScore(subjectBScore, totalStudents);

    printf("\n");
    printf("Mean Of Subject A:%.2f ", meanA);
    printf("\n");
    printf("Mean Of Subject B:%.2f ", meanB);
    printf("\n");
    printf("\n");
    fprintf(filepointer, "Mean Of Subject A:%.2f ", meanA);
    printf("\n");
    fprintf(filepointer, "Mean Of Subject B:%.2f ", meanB);
    printf("Standard Deviation Of Subject A:%.2f ", stdA);
    printf("\n");
    printf("Standard Deviation Of Subject B:%.2f ", stdB);
    printf("\n");
    fprintf(filepointer, " Standard Deviation Of Subject A:%.2f ", stdA);
    printf("\n");
    fprintf(filepointer, "Standard Deviation Of Subject B:%.2f ", stdB);
    fclose(filepointer);
    printf("Processing complete:\n");
    printf("Grades have been output to a saved filed for records\n");
    printf("\n");
    return 0;
}