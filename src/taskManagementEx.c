#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "taskManagementEx.h"
#include "hello.h" // For printLine

// 파일 이름을 상수로 정의
const char* FILENAME = "task.json";

// --- Helper Function ---
void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
// 작업(Task)의 정보를 담는 구조체
typedef struct Task {
    int id;
    char description[100];
    bool completed;
} Task;

// 연결 리스트의 노드 구조체
typedef struct Node {
    Task task;
    struct Node* next;
} Node;

// 새로운 작업을 추가하기 위한 전역 ID 카운터
static int current_id = 1;

// 새로운 노드를 생성하는 함수
// 함수를 해당 파일 내부에서만 사용하도록 static 키워드를 붙여주는 것
static Node* createNode(const char* description) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->task.id = current_id++;
    strncpy(newNode->task.description, description, sizeof(newNode->task.description) - 1);
    newNode->task.description[sizeof(newNode->task.description) - 1] = '\0'; // Null-terminate
    newNode->task.completed = false;
    newNode->next = NULL;
    return newNode;
}

// 리스트의 끝에 작업을 추가하는 함수
void addTask(Node** head, const char* description) {
    Node* newNode = createNode(description);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// ID로 작업을 찾아 완료 상태로 변경하는 함수
void markTaskCompleted(Node* head, int id) {
    Node* current = head;
    while (current != NULL) {
        if (current->task.id == id) {
            current->task.completed = true;
            printf("Task %d marked as completed.\n", id);
            return;
        }
        current = current->next;
    }
    printf("Task with ID %d not found.\n", id);
}

// ID로 작업을 찾아 리스트에서 삭제하는 함수
void deleteTask(Node** head, int id) {
    Node* temp = *head;
    Node* prev = NULL;

    // 삭제할 노드가 첫 번째 노드인 경우
    if (temp != NULL && temp->task.id == id) {
        *head = temp->next; // 헤드를 다음 노드로 변경
        free(temp);         // 이전 헤드 메모리 해제
        printf("Task %d deleted.\n", id);
        return;
    }

    // 리스트를 순회하며 삭제할 노드를 찾음
    while (temp != NULL && temp->task.id != id) {
        prev = temp;
        temp = temp->next;
    }

    // 노드를 찾지 못한 경우
    if (temp == NULL) {
        printf("Task with ID %d not found.\n", id);
        return;
    }

    // 노드를 찾은 경우 (첫 번째 노드가 아님)
    prev->next = temp->next; // 이전 노드가 삭제할 노드의 다음 노드를 가리키도록 함
    free(temp);              // 노드 메모리 해제
    printf("Task %d deleted.\n", id);
}

// 모든 작업을 출력하는 함수
void printTasks(Node* head) {
    Node* current = head;
    printf("\n--- Task List ---\n");
    while (current != NULL) {
        printf("ID: %d | Status: [%s] | Description: %s\n",
               current->task.id,
               current->task.completed ? "X" : " ",
               current->task.description);
        current = current->next;
    }
    printf("-----------------\n");
}

// 리스트의 모든 메모리를 해제하는 함수
void freeTasks(Node** head) {
    Node* current = *head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    *head = NULL;
}

// --- File I/O Functions ---

/**
 * @brief 현재 작업 리스트를 JSON 형식으로 파일에 저장합니다.
 * @param head 작업 리스트의 헤드 포인터.
 */
void saveTasksToFile(Node* head) {
    FILE* file = fopen(FILENAME, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }

    fprintf(file, "[\n");

    Node* current = head;
    while (current != NULL) {
        fprintf(file, "  {\n");
        fprintf(file, "    \"id\": %d,\n", current->task.id);
        // JSON 문자열 형식에 맞게 description에 포함된 " 를 \" 로 이스케이프 처리합니다. (여기서는 간단히 처리)
        fprintf(file, "    \"description\": \"%s\",\n", current->task.description);
        fprintf(file, "    \"completed\": %s\n", current->task.completed ? "true" : "false");
        fprintf(file, "  }");

        if (current->next != NULL) {
            fprintf(file, ",\n");
        } else {
            fprintf(file, "\n");
        }
        current = current->next;
    }

    fprintf(file, "]\n");
    fclose(file);
    printf("Tasks successfully saved to %s\n", FILENAME);
}

/**
 * @brief 파일에서 작업 리스트를 불러옵니다.
 * @param head 작업 리스트의 헤드 포인터에 대한 포인터.
 */
void loadTasksFromFile(Node** head) {
    FILE* file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No saved tasks file found. Starting with an empty list.\n");
        return;
    }

    // 기존 리스트 메모리 해제
    freeTasks(head);
    current_id = 1; // ID 카운터 초기화

    char line[256];

    // 매우 간단한 파서: 각 줄에서 description만 추출합니다.
    // 실제 JSON 파싱은 훨씬 복잡하지만, 이 예제의 목적에 맞게 단순화합니다.
    while (fgets(line, sizeof(line), file) != NULL) {
        char* desc_ptr = strstr(line, "\"description\": \"");
        if (desc_ptr) {
            char description[100];
            if (sscanf(desc_ptr, "\"description\": \"%99[^\"]\"", description) == 1) {
                addTask(head, description);
            }
        }
    }

    fclose(file);
    printf("Tasks loaded from %s\n", FILENAME);
}

void showTaskMenu(void) {
    printf("\n--- Task Manager Menu ---\n");
    printf("1. View All Tasks\n");
    printf("2. Add New Task\n");
    printf("3. Mark Task as Completed\n");
    printf("4. Delete Task\n");
    printf("5. Return to Main Menu\n");
    printf("-------------------------\n");
    printf("Enter your choice: ");
}

void taskManagementEx(void) {
    printLine("Interactive Task Management with Linked List");

    Node* taskList = NULL;
    int choice = 0;

    loadTasksFromFile(&taskList); // 프로그램 시작 시 파일에서 작업 불러오기

    while (choice != 5) { // 'Return to Main Menu'를 선택할 때까지 반복
        showTaskMenu();

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1: { // View All Tasks
                printTasks(taskList);
                break;
            }
            case 2: { // Add Task
                char description[100];
                printf("Enter new task description: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = 0; // Remove trailing newline
                addTask(&taskList, description);
                printf("Task added successfully.\n");
                saveTasksToFile(taskList); // 변경 사항 즉시 저장
                break;
            }
            case 3: { // Mark Complete
                int id;
                printf("Enter task ID to mark as complete: ");
                scanf("%d", &id);
                clearInputBuffer();
                markTaskCompleted(taskList, id);
                saveTasksToFile(taskList); // 변경 사항 즉시 저장
                break;
            }
            case 4: { // Delete Task
                int id;
                printf("Enter task ID to delete: ");
                scanf("%d", &id);
                clearInputBuffer();
                deleteTask(&taskList, id);
                saveTasksToFile(taskList); // 변경 사항 즉시 저장
                break;
            }
            case 5: // Return to Main Menu
                printf("\nReturning to main menu...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }

    // 메모리 해제
    freeTasks(&taskList);
    printf("\nTask list memory has been freed.\n");
}