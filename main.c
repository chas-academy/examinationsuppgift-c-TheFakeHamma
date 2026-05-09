#include <stdio.h>
#include <ctype.h>

#define STUDENTS 5
#define TESTS 13
#define NAME_LENGTH 11

void format_name(char name[])
{
    name[0] = toupper(name[0]);

    for (int i = 1; name[i] != '\0'; i++)
    {
        name[i] = tolower(name[i]);
    }
}

int main()
{
    char names[STUDENTS][NAME_LENGTH];
    int scores[STUDENTS][TESTS];
    double averages[STUDENTS];
    double total_sum = 0;
    double group_average = 0;
    int best_student = 0;

    for (int i = 0; i < STUDENTS; i++)
    {
        scanf("%10s", names[i]);

        format_name(names[i]);

        for (int j = 0; j < TESTS; j++)
        {
            scanf("%d", &scores[i][j]);
        }
    }

    for (int i = 0; i < STUDENTS; i++)
    {
        int student_sum = 0;

        for (int j = 0; j < TESTS; j++)
        {
            student_sum += scores[i][j];
        }

        averages[i] = student_sum / (double)TESTS;
        total_sum += student_sum;
    }

    group_average = total_sum / (double)(STUDENTS * TESTS);

    for (int i = 1; i < STUDENTS; i++)
    {
        if (averages[i] > averages[best_student])
        {
            best_student = i;
        }
    }

    printf("%s\n", names[best_student]);

    for (int i = 0; i < STUDENTS; i++)
    {
        if (averages[i] < group_average)
        {
            printf("%s\n", names[i]);
        }
    }

    return 0;
}