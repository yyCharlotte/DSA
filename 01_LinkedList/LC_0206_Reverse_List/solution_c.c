#include <stdio.h>
#include <stdlib.h>
﻿
// ==========================================
// 1. 定义链表节点结构体
// ==========================================
struct ListNode {
    int val;
    struct ListNode *next;
};
﻿
// ==========================================
// 2. 核心算法：反转链表 (LeetCode 206)
// ==========================================
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    struct ListNode* next_temp = NULL;
﻿
    while (cur != NULL) {
        // 第一步：保存下一个节点
        next_temp = cur->next;
﻿
        // 第二步：反转当前节点的指针
        cur->next = prev;
﻿
        // 第三步：将 prev 和 cur 都向后移动一步
        prev = cur;
        cur = next_temp;
    }
﻿
    // 循环结束时，cur 为 NULL，prev 指向原链表的最后一个节点（即反转后的头节点）
    return prev;
}
﻿
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
﻿
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
﻿
// ==========================================
// 5. 辅助函数：释放链表内存 (防止内存泄漏)
// ==========================================
void freeList(struct ListNode* head) {
    struct ListNode* cur = head;
    while (cur != NULL) {
        struct ListNode* temp = cur;
        cur = cur->next;
        free(temp);
    }
}
﻿
// ==========================================
// 6. 主函数：测试代码
// ==========================================
int main() {
    // 构建测试链表：1 -> 2 -> 3 -> 4 -> 5 -> NULL
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
﻿
    printf("原始链表: ");
    printList(head);
﻿
    // 调用反转函数
    head = reverseList(head);
﻿
    printf("反转后链表: ");
    printList(head);
﻿
    // 释放内存
    freeList(head);
    head = NULL;

    return 0;
}
