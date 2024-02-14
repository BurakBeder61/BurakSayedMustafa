# Developer’s Markdown:

## Code Explanations: 

# pressing the control keys (arrow keys): 
* The program enters a do-while loop to continuously prompt the user for input until the user presses 'q' to quit.
* Inside the loop, the program prints a message to the console instructing the user to navigate using arrow keys.
* The scanf function is used to capture a single character input from the user, and the result is stored in the variable choice.
* The switch (choice) statement is then used to handle the user's input. In the case of 'w' or 's', the program checks if the arrow position (PfeilPos) is within bounds (1 to 6) before adjusting it accordingly. After adjusting the position, the SwitchArrow function is called with the updated position to display the menu with the arrow indicating the current selection.
* The loop continues until the user presses 'q', at which point the program exits.
* The SwitchArrow function is responsible for displaying the menu with the arrow indicating the current selection based on the arrow position. It is defined earlier in the code and not shown here, but it's used to visually guide the user through the available options.
```
	do {
    printf("\n\nNavigate with arrow keys on your keyboard\n");
    scanf(" %c", &choice);

    switch (choice) {
        case 'w':
            if (PfeilPos > 1)
                PfeilPos--; // Move up if possible
            SwitchArrow(PfeilPos);
            break;
        case 's':
            if (PfeilPos < 6)
                PfeilPos++; // Move down if possible
            SwitchArrow(PfeilPos);
            break;
        case 'e':
            switch (PfeilPos) {
                // ... other cases for handling user input
            }
            break;
        default:
            printf("Please press one of the following keys: w, s\n");
    }

} while (choice != 'q');

```

###Structs
*In the following code we initialise and declerate our structs
*The following Structs are used to create new tasks and new lists and much more, by using linked lists(verkettete Listen)
```
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
```

### Task Creation: 
* The function first checks if the given list exists. If not, it prints an error message and returns.
* Memory is dynamically allocated for a new task (struct Task).
* The task's name is copied into the new task, ensuring null-termination.
* The completed field is initialized to 0 (indicating the task is incomplete).
* The new task is added to the beginning of the task list (list->head).
* A success message is printed.
```
	void addTask(struct TaskList* list, const char* taskName) {
    if (list == NULL) {
        printf("List does not exist.\n");
        return;
    }

    struct Task* newTask = (struct Task*)malloc(sizeof(struct Task));

    if (newTask == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    strncpy(newTask->name, taskName, sizeof(newTask->name) - 1);
    newTask->name[sizeof(newTask->name) - 1] = '\0'; // Ensure null-termination
    newTask->completed = 0;
    newTask->next = list->head;
    list->head = newTask;

    printf("Task added to %s successfully!\n", list->name);
	}

```

### Task Deletion:
* The function first checks if the given list exists. If not, it prints an error message and returns.
* The function uses a while loop to traverse the linked list and find the task to be deleted based on its name.
* If the task is found, it is removed from the linked list, and its memory is freed.
* If the task is not found, an appropriate message is printed.
```

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
```


### List Creation:
* The function takes a double pointer to the head of the task list (struct TaskList** head) and the name of the new list (const char* listName).
* It allocates memory for a new TaskList structure using malloc.
* The name of the new list is copied into the name field of the TaskList.
* The head of the new list is set to NULL since there are initially no tasks in the list.
* The newList is inserted at the beginning of the linked list, and the head is updated to point to the new list.
```
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

```

###List Selection
* The while branch loops as long as the current name is uneqaual to Null and is unequal to the name of another list
* If that is the case, it changes the current Pointer to the new listname (UserInput)
* If the user input is unequal to the existing lists, then a printf function displays that the list couldn't be found
```
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

```


###display tasks
*In this code snippet we can see a if branch which asks if the List is equal to Null
*if yes then it displays that the current list doesn't exist
*Next it prints a message which tells the user the current list name
*The tasks are checked to be completed or incompleted
*Then the List Head is checked, to see if there are any elements in the current list
*If the list Head s equal to Null, then it displays that there aren't any elements in the current list

```
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
```


###mark task as completed
*Again we check if the current list exists
*Then we compare the current name with taskName and loop through the current tasks
*If the Task exists it is marked as completed
*If not, it displays <code>Task not found in (current ListName). No task marked as completed.</code>
```
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
```

###Arrow next to task
*The SwitchArrow function displays the Pfeil String next to our Menu-Option
*Which each case we complete all our options
*If the user presses the up arrow key our PfeilPos(Pfeil-Position) prop decreases by one only until 1 which is checked with a if branch in the main function
*but if the arrow key down is pressed, the PfeilPos(Pfeil-Position) is increased by one until 6, because we only have 6 options
```
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
        printf("\n___________________________________________\n");
            break;

        default:
            break;
        }
}
```
