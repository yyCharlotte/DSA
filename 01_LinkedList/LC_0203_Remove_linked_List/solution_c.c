#include <stdio.h>
#include <stdlib.h>

// ==========================================
// 1. 定义链表节点结构体
// ==========================================
struct ListNode {
    int val;
    struct ListNode *next;
};

// ==========================================
// 2. 核心算法：移除链表元素 (LeetCode 203)
// ==========================================
struct ListNode* removeElements(struct ListNode* head, int val) {
    // ---------- 第一步：处理头节点 ----------
    // 如果头节点本身就是要删除的值，需要一直删
    while (head != NULL && head->val == val) {
        struct ListNode* temp = head;   // 先记住要删的头节点
        head = head->next;              // 头节点后移
        free(temp);                     // 释放内存
    }

    // ---------- 第二步：处理后面的节点 ----------
    struct ListNode* cur = head;
    
    // 注意循环条件：cur != NULL 保证自己安全，cur->next != NULL 保证看下一个人安全
    while (cur != NULL && cur->next != NULL) {
        if (cur->next->val == val) {
            struct ListNode* temp = cur->next;  // 1. 先存住要删的节点
            cur->next = cur->next->next;        // 2. 跳过它
            free(temp);                         // 3. 再释放它
        } else {
            cur = cur->next;                    // 不是要删的，继续往后走
        }
    }

    // ---------- 第三步：返回新的头节点 ----------
    return head;
}

// ==========================================
// 3. 辅助函数：创建新节点
// ==========================================
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (newNode == NULL) {
        printf("内存分配失败！\n");
        exit(1);
    }
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// ==========================================
// 4. 辅助函数：打印链表
// ==========================================
void printList(struct ListNode* head) {
    struct ListNode* cur = head;
    while (cur != NULL) {
        printf("%d -> ", cur->val);
        cur = cur->next;
    }
    printf("NULL\n");
}

// ==========================================
// 5. 辅助函数：释放链表内存
// ==========================================
void freeList(struct ListNode* head) {
    struct ListNode* cur = head;
    while (cur != NULL) {
        struct ListNode* temp = cur;
        cur = cur->next;
        free(temp);
    }
}

// ==========================================
// 6. 主函数：测试代码
// ==========================================
int main() {
    // 构建测试链表：1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6 -> NULL
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(6);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(5);
    head->next->next->next->next->next->next = createNode(6);

    int valToRemove = 6;

    printf("原始链表: ");
    printList(head);
    printf("要删除的值: %d\n", valToRemove);

    // 调用删除函数
    head = removeElements(head, valToRemove);

    printf("删除后链表: ");
    printList(head);

    // 释放内存
    freeList(head);
    head = NULL;

    return 0;
}
