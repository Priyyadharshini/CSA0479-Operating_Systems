#include <stdio.h>
#include <stdlib.h>
#define FILENAME "employee_data.dat"
int main()
{
    FILE *file;
    int choice,empId,empSalary;
    char empName[50];
    while(1)
	{
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. View Employee Details\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
		{
            case 1:
                file=fopen(FILENAME,"ab");
                if (file == NULL)
				{
                    printf("Error opening file.\n");
                    exit(1);
                }
                printf("Enter Employee ID: ");
                scanf("%d",&empId);
                printf("Enter Employee Name: ");
                scanf("%s",empName);
                printf("Enter Employee Salary: ");
                scanf("%d",&empSalary);
                fprintf(file,"%d %s %d\n",empId,empName,empSalary);
                fclose(file);
                break;
            case 2:
                file=fopen(FILENAME,"rb");
                if (file==NULL)
				{
                    printf("Error opening file.\n");
                    exit(1);
                }
                printf("\nEmployee Details:\n");
                printf("ID\tName\tSalary\n");
                while (fscanf(file,"%d %s %d",&empId,empName,&empSalary)!=EOF)
				{
                    printf("%d\t%s\t%d\n",empId,empName,empSalary);
                }
                fclose(file);
                break;
            case 3:
                printf("Exit the program.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}
