Tccel* biblioEncaSelectionSort(Tccel* head, long long int * comparar, int * movimentar){ 
    Tccel *a, *b, *c, *d, *r;
    a = b = head; 
  
    // While b is not the last Tcel 
    while (b->prox) { 
  
        c = d = b->prox; 

        // While d is pointing to a valid Tcel 
        while (d) { 
  
            if (b->texto.tamanhotexto > d->texto.tamanhotexto) { 
                (*comparar)++;
                // If d appears immediately after b 
                if (b->prox == d) { 
                    (*comparar)++;
                    // Case 1: b is the head of the linked list 
                    if (b == head) { 
                        (*comparar)++;
                        // Move d before b 
                        b->prox = d->prox; 
                        d->prox = b; 
  
                        // Swap b and d pointers 
                        r = b; 
                        b = d; 
                        d = r; 
  
                        c = d; 
  
                        // Update the head 
                        head = b; 
  
                        // Skip to the prox element 
                        // as it is already in order 
                        d = d->prox; 
                    } 
  
                    // Case 2: b is not the head of the linked list 
                    else { 
                        (*comparar)++;
                        // Move d before b 
                        b->prox = d->prox; 
                        d->prox = b; 
                        a->prox = d; 
  
                        // Swap b and d pointers 
                        r = b; 
                        b = d; 
                        d = r; 
  
                        c = d; 
  
                        // Skip to the prox element 
                        // as it is already in order 
                        d = d->prox; 
                    } 
                } 
  
                // If b and d have some non-zero 
                // number of Tcels in between them 
                else { 
                    (*comparar)++;
                    // Case 3: b is the head of the linked list 
                    if (b == head) { 
                        (*comparar)++;
                        // Swap b->prox and d->prox 
                        r = b->prox; 
                        b->prox = d->prox; 
                        d->prox = r; 
                        c->prox = b; 
  
                        // Swap b and d pointers 
                        r = b; 
                        b = d; 
                        d = r; 
  
                        c = d; 
  
                        // Skip to the prox element 
                        // as it is already in order 
                        d = d->prox; 
  
                        // Update the head 
                        head = b; 
                    } 
  
                    // Case 4: b is not the head of the linked list 
                    else { 
                        (*comparar)++; 
                        // Swap b->prox and d->prox 
                        r = b->prox; 
                        b->prox = d->prox; 
                        d->prox = r; 
                        c->prox = b; 
                        a->prox = d; 
  
                        // Swap b and d pointers 
                        r = b; 
                        b = d; 
                        d = r; 
  
                        c = d; 
  
                        // Skip to the prox element 
                        // as it is already in order 
                        d = d->prox; 
                    } 
                } 
            } 
            else { 
                (*comparar)++; 
                // Update c and skip to the prox element 
                // as it is already in order 
                c = d; 
                d = d->prox; 
            } 
        } 
  
        a = b; 
        b = b->prox; 
    }
    return head;
}