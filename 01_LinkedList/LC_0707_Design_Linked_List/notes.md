设计你自己的链表，然后头插尾插其实都可以用addAtIndex实现，然后注意使用虚拟头节点，每一步都要更新size，其次要先链接后一个节点，
index=size是尾插位置，没有越界；
删除节点要temp，然后free（temp）；
