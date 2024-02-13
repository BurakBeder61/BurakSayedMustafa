## Developer’s Markdown:

# Code Explanations: 

Control through arrows: 

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
Task Creation: 

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
