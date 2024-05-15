#include <stdio.h>
#include <string.h>

typedef struct {
    char task[100];
    int taskno;
} Task;

Task Tasks[1000];

int main() {
    int choice;
    int temp = 0;
    int n = 0;
    Task newTask;
    int taskid;
    int index = -1;

    FILE *file = fopen("tasks.txt", "r");
    if (file) {
        while (fscanf(file, "%d\n%[^\n]\n", &Tasks[n].taskno, Tasks[n].task) == 2) {
            n++;
        }
        fclose(file);
    }

    do {
        printf("\n1). Enter Tasks for today\n");
        printf("2). Show today's Tasks\n");
        printf("3). Update Tasks\n");
        printf("4). Completed Tasks\n");
        printf("5). Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of new tasks for today: ");
                int newTasksCount;
                scanf("%d", &newTasksCount);
                getchar(); 

                // Open the file in append mode
                file = fopen("tasks.txt", "a");
                if (file) {
                    for (int i = 0; i < newTasksCount; i++) {
                        printf("Enter task number: ");
                        scanf("%d", &newTask.taskno);
                        getchar(); 
                        printf("Enter task description: ");
                        fgets(newTask.task, 100, stdin);
                        Tasks[n + i] = newTask; 

                        
                        fprintf(file, "%d) %s\n", newTask.taskno, newTask.task);
                    }
                    fclose(file);
                }
                n += newTasksCount; 
                printf("Tasks added successfully\n");
                break;

            case 2:
                printf("DISPLAYING YOUR TASKS \n \n");
                for(int i = 0; i < n; i++){
                    printf("%d) %s",Tasks[i].taskno, Tasks[i].task);
                }
                break; // Added break statement here
            
            case 3: 
                file = fopen("tasks.txt", "w"); 
                if (file) {
                    printf("Enter the task no that you want to update: ");
                    scanf("%d", &taskid);
                    getchar(); 
                    
                    for(int i = 0; i < n; i++){
                        if(Tasks[i].taskno == taskid){
                            index = i;
                            break;
                        }
                    }
                    
                    if(index != -1){
                        printf("Enter your new Task: ");
                        fgets(Tasks[index].task, 100, stdin);
                        printf("Task updated successfully\n");
                        
                        for(int i = 0; i < n; i++) {
                            fprintf(file, "%d) %s\n", Tasks[i].taskno, Tasks[i].task);
                        }
                        fclose(file);
                    }
                    else {
                        printf("Entered Task no is not found\n");
                    } 
                }
                else {
                    printf("Error opening the file\n");
                } 
                break;

            case 4:
                file = fopen("tasks.txt", "w"); 
                if (file) {
                    fprintf(file, "DISPLAYING YOUR TASKS FOR TODAY \n \n"); 
                    fclose(file); 
                    file = fopen("tasks.txt", "a"); 
                    if (file) {
                        printf("Enter the Task no that you completed: ");
                        scanf("%d", &taskid);
                        for (int i = 0; i < n; i++) {
                            if (Tasks[i].taskno == taskid) {
                                index = i;
                                break;
                            }
                        }
                        if (index != -1) {
                            for (int i = index; i < n - 1; i++) {
                                Tasks[i] = Tasks[i + 1];
                            }
                            n--; 

                            // Shift task numbers
                            for (int i = index; i < n; i++) {
                                Tasks[i].taskno = i + 1;
                            }
                            for (int i = 0; i < n; i++) {
                                fprintf(file, "%d) %s\n", Tasks[i].taskno, Tasks[i].task);
                            }
                            fclose(file);

                            printf("Congratulations! You've completed your task\n");
                        } else {
                            printf("Entered task no is not found\n");
                        }
                    } else {
                        printf("Error opening the file\n");
                    }
                } else {
                    printf("Error opening the file\n");
                }
                break; 
            case 5:
                temp = 5;
                printf("\nExiting");
                break;
            default:
                printf("Invalid choice\n");         
        }
    } while (temp != 5);

    return 0;
}
