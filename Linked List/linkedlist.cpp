#include <iostream>
#include "linkedlist.h"

Node *createNode(int data){

    Node *createdNode = (Node *)malloc(sizeof(Node));
    createdNode->data = data;
    createdNode->next = NULL;

    return createdNode;
}

void printLinkedList(Node *head){

    Node *iterator = head;

    while(iterator){
        printf("%d ",iterator->data);
        iterator = iterator->next;
    }

    printf("\n");

}

void addNodeAtTheEnd(Node **head, int data){

    auto *createdNode = (Node *)malloc(sizeof(Node));

    createdNode->data = data;
    createdNode->next = nullptr;

    if(!(*head)){
        *head = createdNode;
    }
    else{
        Node *iterator = *head;
        while(iterator->next){
            iterator = iterator->next;
        }
        iterator->next = createdNode;
    }

}

void deleteLinkedList(Node **head){
    if(!(*head)){
        return;
    }
    Node *iterator;
    while(*head){
        iterator = (*head)->next;
        (*head)->next = nullptr;
        free(head);
        *head = iterator;
    }
}

void printLinkedListReverse(Node *head){

    if(!head){
        return;
    }
    printLinkedList(head->next);
    printf("%d ",head->data);
}

int sizeOfLinkedList(Node *head){
    if(!head){
        return 0;
    }
    int count = 0;
    Node *iterator = head;
    while(iterator){
        count++;
        iterator = iterator ->next;
    }
    return count;
}