#include <stdlib.h>
#include "StrList.h"
#include <stdio.h>
#include <string.h>


int main(){
    int flag=0;
    StrList* Str = StrList_alloc();
    do{
        scanf(" %d", &flag);
        if(flag==1){
            int words;
            scanf(" %d", &words);
            
            int i;
            for (i=0; i<words; i++){
                char* temp =(char*)malloc(30);
                scanf(" %s", temp);
                char* data;
                data = (char*)realloc(temp, sizeof(char)*strlen(temp));
                StrList_insertLast(Str, data);
            }
        }
        else if (flag==2)
        {
            int index;
            char* temp =(char*)malloc(30);
            scanf(" %d", &index);
            scanf(" %s", temp);
            StrList_insertAt(Str,temp, index);
        }
        else if (flag==3)
        {
            StrList_print(Str);
        }
        else if (flag==4)
        {
            int x = StrList_size(Str);
            printf("%d\n", x);
        }
        else if (flag==5)
        {
            int index;
            scanf(" %d", &index);
            StrList_printAt(Str, index);
        }
        else if (flag==6)
        {
            int num=StrList_printLen(Str);
            printf("%d\n", num);
        }
        else if (flag==7)
        {
            char* temp =(char*)malloc(30);
            scanf(" %s", temp);
            int count = StrList_count(Str, temp);
            printf("%d\n", count);
        }
        else if (flag==8)
        {
            char* temp =(char*)malloc(30);
            scanf(" %s", temp);
            StrList_remove(Str, temp);
        }
        else if (flag==9)
        {
            int index;
            scanf(" %d", &index);
            StrList_removeAt(Str, index);
        }
        else if (flag==10)
        {
            StrList_reverse(Str);
        }
        else if (flag==11)
        {
            StrList_free(Str);
            Str = StrList_alloc();
        }
        else if (flag==12)
        {
            StrList_sort(Str);

        }  
        else if (flag==13)
        {
            int curr;
            curr = StrList_isSorted(Str);
            if(curr== 1){
                printf("true\n"); 
            }
            else if (curr==0)
            {
                printf("false\n");
            }
        } 
    }while(flag>=1 && flag<=13);
    return 0;
}