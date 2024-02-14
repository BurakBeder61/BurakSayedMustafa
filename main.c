#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

struct Task{
    char name[50];
    int completed;
    struct Task* next;
};

struct TaskList{
    char name[50];
    struct Task* head;
    struct TaskList* next;
};

struct Reminder {
    char message[100];
    time_t trigger_time;
    struct Reminder* next;
};

void addTask(struct TaskList* list, const char* taskName){ //Fügt Task hinzu.

   if(list == NULL){ 
    printf("List does not exist.\n");
    return;
   }

   struct Task* newTask = (struct Task*)malloc(sizeof(struct Task));
   
   if(newTask == NULL) {
      printf("Memory allocation failed.\n");
      return;
   }              //TODO Burak <--

    strncpy(newTask->name, taskName, sizeof(newTask->name) - 1); //prevent buffer overflow 
    newTask->name[sizeof(newTask->name) - 1] = '\0'; // Ensure null-termination
    newTask->completed = 0;
    newTask->next = list->head; // sets ne task on beginning of list
    list->head = newTask; //pointer to head to make newTask the new head of the list
    printf("Task added to %s successfully!\n", list->name);
};

void deleteTask(struct TaskList* list, const char* taskName) {
    if (list == NULL) {
        printf("List does not exist.\n");
        return;
    }
    
    struct Task* current = list->head;
    struct Task* prev = NULL;

    while (current != NULL && strcmp(current->name, taskName) != 0) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        if (prev == NULL) {
            list->head = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
        printf("Task deleted from %s successfully!\n", list->name);
    } else {
        printf("Task not found in %s. No task deleted.\n", list->name);
    }
}

void markTaskCompleted(struct TaskList* list, const char* taskName) {
    if (list == NULL) {
        printf("List does not exist.\n");
        return;
    }

    struct Task* current = list->head;

    while (current != NULL && strcmp(current->name, taskName) != 0) {
        current = current->next;
    }

    if (current != NULL) {
        current->completed = 1;
        printf("Task in %s marked as completed!\n", list->name);
    } else {
        printf("Task not found in %s. No task marked as completed.\n", list->name);
    }
}

void displayTasks(struct TaskList* list) {
    if (list == NULL) {
        printf("List does not exist.\n");
        return;
    }

    printf("Tasks in %s:\n", list->name);

    struct Task* current = list->head;

    while (current != NULL) {
        printf("%s - %s\n", current->name, current->completed ? "Completed" : "Incomplete");
        current = current->next;
    }

    if (list->head == NULL) {
        printf("No tasks in %s.\n", list->name);
    }
}

void addList(struct TaskList** head, const char* listName) {
    if (*head == NULL) {
        printf("Head is NULL.\n");
        return;
    }

    struct TaskList* newList = (struct TaskList*)malloc(sizeof(struct TaskList));
    if (newList == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    strncpy(newList->name, listName, sizeof(newList->name) - 1);
    newList->name[sizeof(newList->name) - 1] = '\0'; // Ensure null-termination
    newList->head = NULL;
    newList->next = *head;
    *head = newList;
    printf("List %s created successfully!\n", listName);
}

struct TaskList* switchList(struct TaskList* head, const char* listName) {
    struct TaskList* current = head;

    while (current != NULL && strcmp(current->name, listName) != 0) {
        current = current->next;
    }

    if (current != NULL) {
        printf("Switched to list: %s\n", listName);
        return current;
    } else {
        printf("List %s not found. Staying on the current list.\n", listName);
        return head;
    }
}

void addReminder(struct Reminder** head, const char* message, time_t trigger_time) {
    struct Reminder* newReminder = (struct Reminder*)malloc(sizeof(struct Reminder));
    if (newReminder == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    strncpy(newReminder->message, message, sizeof(newReminder->message) - 1);
    newReminder->message[sizeof(newReminder->message) - 1] = '\0'; // Ensure null-termination
    newReminder->trigger_time = trigger_time;
    newReminder->next = *head;
    *head = newReminder;
    printf("Reminder added successfully!\n");
}

void displayReminders(struct Reminder* head) {
    printf("Reminders:\n");
    struct Reminder* current = head;
    while (current != NULL) {
        printf("%s - Trigger Time: %s", current->message, ctime(&(current->trigger_time)));
        current = current->next;
    }
}

void checkReminders(struct Reminder** head) {
    time_t current_time = time(NULL);
    struct Reminder* current = *head;
    while (current != NULL) {
        if (current_time >= current->trigger_time) {
            printf("Reminder: %s\n", current->message);
            // Remove triggered reminder from the list
            struct Reminder* temp = current;
            *head = current->next;
            free(temp);
            current = *head;
        } else {
            current = current->next;
        }
    }
}

void SwitchArrow(int PfeilPos){
    char Pfeil[] = "<--";

    switch (PfeilPos) {
        case 1:
            printf("\n____________________________________________\n");
            printf("Add Task %s\n", Pfeil);
            printf("Delete Task\n");
            printf("Mark Task as Completed\n");
            printf("Display Tasks\n");
            printf("Add List\n");
            printf("Switch List\n");
            printf("Add Reminder\n");
            printf("Display Reminders\n");
            printf("\n___________________________________________\n");
            break;
        
        case 2:
            printf("\n____________________________________________\n");
            printf("Add Task \n");
            printf("Delete Task%s\n", Pfeil);
            printf("Mark Task as Completed\n");
            printf("Display Tasks\n");
            printf("Add List\n");
            printf("Switch List\n");
            printf("Add Reminder\n");
            printf("Display Reminders\n");
            printf("\n___________________________________________\n");
            break;
        
        case 3:
            printf("\n____________________________________________\n");
            printf("Add Task \n");
            printf("Delete Task\n");
            printf("Mark Task as Completed%s\n", Pfeil);
            printf("Display Tasks\n");
            printf("Add List\n");
            printf("Switch List\n");
            printf("Add Reminder\n");
            printf("Display Reminders\n");
            printf("\n___________________________________________\n");
            break;
        
        case 4:
            printf("\n____________________________________________\n");
            printf("Add Task \n");
            printf("Delete Task\n");
            printf("Mark Task as Completed\n");
            printf("Display Tasks%s\n", Pfeil);
            printf("Add List\n");
            printf("Switch List\n");
            printf("Add Reminder\n");
            printf("Display Reminders\n");
            printf("\n___________________________________________\n");
            break;
        
        case 5:
            printf("\n____________________________________________\n");
            printf("Add Task \n");
            printf("Delete Task\n");
            printf("Mark Task as Completed\n");
            printf("Display Tasks\n");
            printf("Add List%s\n", Pfeil);
            printf("Switch List\n");
            printf("Add Reminder\n");
            printf("Display Reminders\n");
            printf("\n___________________________________________\n");
            break;

        case 6:
            printf("\n____________________________________________\n");
            printf("Add Task \n");
            printf("Delete Task\n");
            printf("Mark Task as Completed\n");
            printf("Display Tasks\n");
            printf("Add List\n");
            printf("Switch List%s\n", Pfeil);
            printf("Add Reminder\n");
            printf("Display Reminders\n");
            printf("\n___________________________________________\n");
            break;
        case 7:
            printf("\n____________________________________________\n");
            printf("Add Task \n");
            printf("Delete Task\n");
            printf("Mark Task as Completed\n");
            printf("Display Tasks\n");
            printf("Add List\n");
            printf("Switch List\n");
            printf("Add Reminder%s\n", Pfeil);
            printf("Display Reminders\n");
            printf("\n___________________________________________\n");
            break;

        case 8:
            printf("\n____________________________________________\n");
            printf("Add Task \n");
            printf("Delete Task\n");
            printf("Mark Task as Completed\n");
            printf("Display Tasks\n");
            printf("Add List\n");
            printf("Switch List\n");
            printf("Add Reminder\n");
            printf("Display Reminders%s\n", Pfeil);
            printf("\n___________________________________________\n");
            break;
        default:
            break;
        }
}           

int main(){

    struct TaskList* taskLists = (struct TaskList*)malloc(sizeof(struct TaskList));
    if (taskLists == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    taskLists->head = NULL;
    taskLists->next = NULL;

    struct TaskList* currentList = taskLists;

    struct Reminder* reminders = NULL;


    char taskName[100];
    char listName[50];
    int PfeilPos = 1;
    char choice;
    char Pfeil[] = "<--";

        printf("\n\nYou can navigate with the arrow keys on your keyboard\n");

    do{
        //scanf(" %c", &choice);
        choice = getch();

         switch (choice) {
            case 72:
                if (PfeilPos > 1) //TODO PfeilPos zeigt wo sich der Pfeil befindet durch de gespeicherte Nummer
                    PfeilPos--; // Move up if possible
                    SwitchArrow(PfeilPos);
                break;
            case 80:
                if (PfeilPos < 8)
                    PfeilPos++; // Move down if possible
                    SwitchArrow(PfeilPos);
                break;
            case 'e':
                    switch (PfeilPos)
                    {
                    case 1:
                        printf("Enter the task name: ");
                        scanf("%99s", taskName); //%99s prevents buffer and only allows a char of 99 characters
                        addTask(currentList, taskName); //
                        break;

                    case 2:
                        printf("Enter the task name to delete: ");
                        scanf("%99s", taskName);
                        deleteTask(currentList, taskName);
                        break;

                    case 3:
                        printf("Enter the task name to mark as completed: ");
                        scanf("%99s", taskName);
                        markTaskCompleted(currentList, taskName);
                        break;

                    case 4:
                        displayTasks(currentList);
                        break;

                    case 5:
                        printf("Enter the list name: ");
                        scanf("%49s", listName);
                        addList(&taskLists, listName);
                        break;

                    case 6:
                        printf("Enter the list name to switch to: ");
                        scanf("%49s", listName);
                        currentList = switchList(taskLists, listName);
                        break;

                    case 7:
                        printf("Enter the reminder message: ");
                        scanf("%99s", taskName); // Using taskName variable temporarily
                        // Assuming user input for reminder time in seconds from current time
                        printf("Enter the time for the reminder in seconds from now: ");
                        int seconds;
                        scanf("%d", &seconds);
                        time_t trigger_time = time(NULL) + seconds;
                        addReminder(&reminders, taskName, trigger_time);
                        break;

                    case 8:
                        displayReminders(reminders);
                        break;

                    default:
                        break;
                    }
            //TODO write function that executes the chosen Number
            break;
        }

        checkReminders(&reminders);
    
    }while(choice != 'q');

return 0;
}
