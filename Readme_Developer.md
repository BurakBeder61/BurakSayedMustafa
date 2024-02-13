### Developer’s Markdown:

## Code Explanations: 

# Control through arrows: 

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
# Task Creation: 
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

# Task Deletion:
* The function first checks if the given list exists. If not, it prints an error message and returns.
* The function uses a while loop to traverse the linked list and find the task to be deleted based on its name.
* If the task is found, it is removed from the linked list, and its memory is freed.
* If the task is not found, an appropriate message is printed.

´´´

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


´´´

