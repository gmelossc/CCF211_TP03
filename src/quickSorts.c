#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int findListLength(Tcel *list) //returns length of list
{
    int counter = 0;
    for (; list != NULL; list = list->prox)
    {
        ++counter;
    }
    return counter;
}

Tcel *findRandomPivotNode(Tcel *head_node) //finds pivot node in list
{
    int list_length = findListLength(head_node);
    int pivot_position = rand() % list_length; 

    for (int count = 0; count < pivot_position; count++)
    {
        head_node = head_node->prox;
    }
    return head_node;
}

Tcel * findLastNode(Tcel * current_node)
{
    for (; current_node->prox != NULL; current_node = current_node->prox);
    return current_node;
}

Tcel * join(Tcel* left_list, Tcel * pivot, Tcel * right_list)
{
    pivot->prox = right_list;

    if (left_list == NULL)  return pivot;

    Tcel * left_tail = findLastNode(left_list);
    left_tail->prox = pivot;

    return left_list;
}

Tcel * encaQuickSort(Tcel * list)
{
    if (list == NULL || list->prox == NULL) return list;

    Tcel *pivot = findRandomPivotNode(list);

    Tcel *left_sub_list = NULL, *right_sub_list = NULL;

    for (Tcel * current_node = list; current_node != NULL;)
    {
        Tcel * prox_node = current_node->prox;

        if (current_node != pivot)
        {
            if (current_node->word.inicio->letra <= pivot->word.inicio->letra)
            {
                current_node->prox = left_sub_list;
                left_sub_list = current_node;
            }
            else
            {
                current_node->prox = right_sub_list;
                right_sub_list = current_node;
            }
        }
        current_node = prox_node;
    }

    return join(encaQuickSort(left_sub_list), pivot, encaQuickSort(right_sub_list));
}