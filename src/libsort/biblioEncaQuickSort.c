int biblioFindListLength(Tccel *list) //returns length of list
{
    int counter = 0;
    for (; list != NULL; list = list->prox)
    {
        ++counter;
    }
    return counter;
}

Tccel *biblioFindRandomPivotNode(Tccel *head_node) //finds pivot node in list
{
    int list_length = biblioFindListLength(head_node);
    int pivot_position = rand() % list_length; 

    for (int count = 0; count < pivot_position; count++)
    {
        head_node = head_node->prox;
    }
    return head_node;
}

Tccel * biblioFindLastNode(Tccel * current_node)
{
    for (; current_node->prox != NULL; current_node = current_node->prox);
    return current_node;
}

Tccel * biblioJoin(Tccel* left_list, Tccel * pivot, Tccel * right_list)
{
    pivot->prox = right_list;

    if (left_list == NULL)  return pivot;

    Tccel * left_tail = biblioFindLastNode(left_list);
    left_tail->prox = pivot;

    return left_list;
}

Tccel * biblioEncaQuickSort(Tccel * list, long long int * comparar)
{
    if (list == NULL || list->prox == NULL){
        (*comparar)++;
        return list;
    }

    Tccel *pivot = biblioFindRandomPivotNode(list);

    Tccel *left_sub_list = NULL, *right_sub_list = NULL;

    for (Tccel * current_node = list; current_node != NULL;)
    {
        Tccel * prox_node = current_node->prox;

        if (current_node != pivot)
        {
            (*comparar)++;
            if (current_node->texto.tamanhotexto <= pivot->texto.tamanhotexto)
            {
                (*comparar)++;
                current_node->prox = left_sub_list;
                left_sub_list = current_node;
            }
            else
            {
                (*comparar)++;
                current_node->prox = right_sub_list;
                right_sub_list = current_node;
            }
        }
        current_node = prox_node;
    }

    return biblioJoin(biblioEncaQuickSort(left_sub_list, comparar), pivot, biblioEncaQuickSort(right_sub_list, comparar));
}