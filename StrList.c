//#pragma once

#include <stdlib.h>
#include "StrList.h"
#include <stdio.h>
#include <string.h>


/********************************************************************************
 *
 * A StrList library.
 *
 * This library provides a StrList of STRINGS data structure.
 *
 * This library will fail in unpredictable ways when the system memory runs
 * out.
 ********************************************************************************/

/* StrList represents a StrList data structure.*/
typedef struct _node {
    char * _word;
    struct _node * _next;
    int _sizenode;

}Node;

struct _StrList{
    Node* _head;
    size_t _size;
};


/* Allocates a new empty StrList.
 * It's the user responsibility to free it with StrList_free.*/
StrList* StrList_alloc(){
    StrList* p = (StrList*)malloc(sizeof(StrList));
    p->_head= NULL;
    p->_size= 0;
    return p;
}

/* create a new node and insert to the list and update the data*/
void creat_node(char* data, StrList* Strlist){
    Node* p = Strlist->_head;
    while(p->_next!=NULL){
        p=p->_next;
    }
    Node* pnew = (Node*)malloc(sizeof(Node));
    p->_next=pnew;
    pnew->_next= NULL;
    pnew->_word= data;
    pnew->_sizenode=strlen(data);
}

void Node_free(Node* node) {
	free(node);
}

/* Frees the memory and resources allocated to StrList.
 * If StrList==NULL does nothing (sam1e as free).*/
void StrList_free(StrList* Strlist){
    if (Strlist==NULL) return;
    Node* p1= Strlist->_head;
    while(p1){
        Node* p2;
        p2=p1;
        p1= p1->_next;
        Node_free(p2);
    }
    free(Strlist);
}

/* Returns the number of elements in the StrList.*/
size_t StrList_size(const StrList* StrList){
    return StrList->_size;
}

/* Inserts an element in the end of the StrList.*/
void StrList_insertLast(StrList* StrList,const char* data){
    Node* pnew = (Node*)malloc(sizeof(Node));
    pnew->_next = NULL;
    pnew->_word = (char*)data;
    pnew->_sizenode= strlen(data);
    StrList->_size++;
    if(StrList->_head==NULL){
        StrList->_head=pnew;
        return;
    }
    Node* pcurr = StrList->_head;
    while(pcurr->_next){
        pcurr = pcurr->_next;
    }
    pcurr->_next = pnew;
}

/* Inserts an element at given index */
void StrList_insertAt(StrList* StrList,const char* data,int index){
    // define the new elment and his data
    Node* pnew = (Node*)malloc(sizeof(Node));
    pnew->_word = (char *)data;
    pnew->_sizenode= strlen(data);
    int i;
    if(index==0){
        pnew->_next=StrList->_head;
        StrList->_head= pnew;
        StrList->_size++;
        return;
    }
    // the first Node and the seconde
    Node* pcurr1 = StrList->_head;
    Node* pcurr2 = StrList->_head->_next;
    // run untill the  pcurr2 index is the requeir index  
    for (i=1; i< index; i++){
        pcurr1 = pcurr1->_next;
        pcurr2 = pcurr2->_next;
    }
    //insert the pnew between pcurr1 to pcurr2
    pcurr1->_next = pnew;
    pnew->_next = pcurr2;
    StrList->_size++;
}

/* Returns the StrList first data.*/
char* StrList_firstData(const StrList* StrList){
    return StrList->_head->_word;
}

/* Prints the StrList to the standard output.*/
void StrList_print(const StrList* StrList){
    Node* p =StrList->_head;
    if(p){
        printf("%s", p->_word);
        p=p->_next;
        while(p){
            printf(" %s", p->_word);
            p=p->_next;
        }
    }
    printf("\n"); 
}

/* Prints the word at the given index to the standard output. */
void StrList_printAt(const StrList* Strlist, int index){
    // the index is in the list rang for sure???????????///
    int i;
    const Node* pcurr1 = Strlist->_head;
    for(i=0; i<index; i++){
        pcurr1 = pcurr1->_next;
    } 
    if(i==index){
        printf("%s\n", pcurr1->_word); 
    }
}

/* Return the amount of chars in the list.*/
int StrList_printLen(const StrList* Strlist){
    int count=0,i;
    Node* pcurr = Strlist->_head;
    for(i=0; i<Strlist->_size; i++){
        count= count + pcurr->_sizenode;
        pcurr= pcurr->_next;
    }
    return count;
}

/* Given a string, return the number of times it exists in the list.*/
int StrList_count(StrList* StrList, const char* data){
    int count=0;
    Node* pcurr = StrList->_head;
    while (pcurr){
        if(strcmp(pcurr->_word, data)==0){
            count++;
        }
        pcurr= pcurr->_next;
    }
    return count;
}

/* Given a string and a list, remove all the appearences of this string in the list.*/
void StrList_remove(StrList* StrList, const char* data){
    Node* pcurr = StrList->_head;
    int i=0, count=0;
    while (pcurr){
        if(strcmp(pcurr->_word, data) == 0){
            StrList_removeAt(StrList, i);
            count++;
            pcurr= StrList->_head;
            i=0;
        }
        else{
            pcurr= pcurr->_next;
            i++;
        }
    }
}

/* Given an index and a list, remove the string at that index.*/
void StrList_removeAt(StrList* StrList, int index){
    Node* pcurr1 = StrList->_head;
    Node* pcurr2 = StrList->_head->_next;
    int i;
    if(index> StrList->_size) {
        return;
    }
    // if the given index is 0 so the for loop wont be abel to remove it
    if(index==0){
        StrList->_head=StrList->_head->_next;
        StrList->_size--;
        return;
    }
    // run untill the  pcurr2 index is the requeir index  
    for (i=1; i< index; i++){
        pcurr1 = pcurr1->_next;
        pcurr2 = pcurr2->_next;
    }
    pcurr1->_next=pcurr2->_next;
    StrList->_size--;
    free(pcurr2);
}

/* Checks if two StrLists have the same elements
 * returns 0 if not and any other number if yes */
int StrList_isEqual(const StrList* StrList1, const StrList* StrList2){
    Node* pcurr1 = StrList1->_head;
    Node* pcurr2 = StrList2->_head;
    int flag=0;
    if (StrList1->_size==StrList2->_size){
        flag =1;
        while(pcurr1 && flag==1){
            if(strcmp(pcurr1->_word, pcurr2->_word)!=0){
                flag = 0;
            }
            // add one if the words are the same 
            pcurr1=pcurr1->_next;
            pcurr2=pcurr2->_next;
        }
    }
    // all the words need to be the same so the cound is the size
    // if(count== StrList1->_size){
    //     return count;
    // }
    return flag;
}

/* alloc function to node*/
Node* Node_alloc(char* data, Node* next) {
	Node* p= (Node*)malloc(sizeof(Node));
	p->_word= data;
	p->_next= next;
	return p;
}

/* Clones the given StrList. 
 * It's the user responsibility to free it with StrList_free.*/
StrList* StrList_clone(const StrList* Strlist){
    StrList* ret= StrList_alloc();
	const Node* old= Strlist->_head;
	Node* * copy= &(ret->_head);
	ret->_size= Strlist->_size;
	while(old) {
		*copy= Node_alloc(old->_word,NULL);
		old= old->_next;
		copy= &((*copy)->_next);
	}
	return ret;
}

/* Reverces the given StrList. */
// revers the orders of the strings not the strings it self ***********************
void StrList_reverse( StrList* Strlist){
    Node* pcurr1 = Strlist->_head->_next;
    Node* pcurr2 = Strlist->_head;
    while(pcurr1->_next!=NULL){
        StrList_insertAt(Strlist, pcurr1->_word, 0);
        pcurr2->_next=pcurr1->_next;
        pcurr1=pcurr1->_next;
    } 
    StrList_insertAt(Strlist, pcurr1->_word, 0); 
    pcurr2->_next=NULL;
    free(pcurr1);
}


/* Sort the given list in lexicographical order */
void StrList_sort( StrList* StrList){

    int swapped;
    Node* pcurr1;
    Node* pcurr2 = NULL;

    // Check if the list is empty
    if (StrList->_head == NULL)
        return;

    do {
        // if ther was a swap changing to 1 and then can go to the loop agin otherwise th list is sorted
        swapped = 0;
        pcurr1 = StrList->_head;
        // Traverse the linked list
        while (pcurr1->_next != pcurr2) {
            // Compare adjacent nodes and swap if necessary
            if (strcmp(pcurr1->_word, pcurr1->_next->_word) > 0) {
                char *temp = pcurr1->_word;
                pcurr1->_word = pcurr1->_next->_word;
                pcurr1->_next->_word = temp;
                swapped = 1;
            }
            pcurr1 = pcurr1->_next;
        }
        pcurr2 = pcurr1;
    } while (swapped);
}

/* Checks if the given list is sorted in lexicographical order
 * returns 1 for sorted,   0 otherwise */
int StrList_isSorted(StrList* StrList){

    int swapped;
    Node* pcurr1;
    Node* pcurr2 = NULL;

    // Check if the list is empty
    if (StrList->_head == NULL){
        return 1;
    }
    swapped = 0;
    pcurr1 = StrList->_head;
    // Traverse the linked list
    while (pcurr1->_next != pcurr2) {
        // Compare adjacent nodes and swap if necessary
        if (strcmp(pcurr1->_word, pcurr1->_next->_word) > 0) {
            // char *temp = pcurr1->_word;
            // pcurr1->_word = pcurr1->_next->_word;
            // pcurr1->_next->_word = temp;
            swapped = 1;
        }
        pcurr1 = pcurr1->_next;
    }
    // if swapped is 0 so there wasn't changed and the list is sorted
    if(swapped==0){
        return 1;
    }
    else{
        return 0;
    } 
}


// int main(){
//     int flag=0;
//     StrList* Str= StrList_alloc();;
//     do{
//         scanf(" %d", &flag);
//         if(flag==1){
//             int words;
//             scanf(" %d", &words);
            
//             int i;
//             for (i=0; i<words; i++){
//                 char* temp =(char*)malloc(30);
//                 scanf(" %s", temp);
//                 //printf("%s this is the scan  size %ld  len %ld\n", temp ,sizeof(temp), strlen(temp));
//                 char* data;
//                 data = (char*)realloc(temp, sizeof(char)*strlen(temp));
//                 //printf("%s this is after realloc  size %ld len %ld\n", data, sizeof(data), strlen(data));
//                 StrList_insertLast(Str, data);
//             }
//         }
//         else if (flag==2)
//         {
//             int index;
//             char* temp =(char*)malloc(30);
//             scanf(" %d", &index);
//             scanf(" %s", temp);
//             StrList_insertAt(Str,temp, index);
//         }
//         else if (flag==3)
//         {
//             StrList_print(Str);
//         }
//         else if (flag==4)
//         {
//             int x = StrList_size(Str);
//             printf("%d\n", x);
//         }
//         else if (flag==5)
//         {
//             int index;
//             scanf(" %d", &index);
//             StrList_printAt(Str, index);
//         }
//         else if (flag==6)
//         {
//             int num=StrList_printLen(Str);
//             printf("%d\n", num);
//         }
//         else if (flag==7)
//         {
//             char* temp =(char*)malloc(30);
//             scanf(" %s", temp);
//             int count = StrList_count(Str, temp);
//             printf("%d\n", count);
//         }
//         else if (flag==8)
//         {
//             char* temp =(char*)malloc(30);
//             scanf(" %s", temp);
//             StrList_remove(Str, temp);
//         }
//         else if (flag==9)
//         {
//             int index;
//             scanf(" %d", &index);
//             StrList_removeAt(Str, index);
//         }
//         else if (flag==10)
//         {
//             StrList_reverse(Str);
//         }
//         else if (flag==11)
//         {
//             StrList_free(Str);
//             Str = StrList_alloc();
//         }
//         else if (flag==12)
//         {
//             StrList_sort(Str);

//         }  
//         else if (flag==13)
//         {
//             int curr;
//             curr = StrList_isSorted(Str);
//             if(curr== 1){
//                 printf("true\n"); 
//             }
//             else if (curr==0)
//             {
//                 printf("false\n");
//             }
//         } 
//     }while(flag>=1 && flag<=13);
//     return 0;
// }
