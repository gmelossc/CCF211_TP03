Tcel* textoEncaSelectionSort(Tcel *head, long long int * comparar, long long int * movimentar){
    Tcel *a, *b, *c, *d, *r;
    a = b = head; 
  
    // While b is not the last Tcel 
    while (b->prox) { 
  
        c = d = b->prox; 
  
        // While d is pointing to a valid Tcel 
        while (d) { 
  
            if (b->word.inicio->letra > d->word.inicio->letra) { 
                (*comparar)++;
                // If d appears immediately after b 
                if (b->prox == d) { 
                    (*comparar)++;
                    // Case 1: b is the head of the linked list 
                    if (b == head) { 
                        (*comparar)++;
                        // Move d before b 
                        b->prox = d->prox; 
                        (*movimentar)++;
                        d->prox = b; 
                        (*movimentar)++;
  
                        // Swap b and d pointers 
                        r = b; 
                        (*movimentar)++;
                        b = d; 
                        (*movimentar)++;
                        d = r; 
                        (*movimentar)++;
  
                        c = d; 
                        (*movimentar)++;
  
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
                        (*movimentar)++;
                        d->prox = b; 
                        (*movimentar)++;
                        a->prox = d; 
                        (*movimentar)++;
  
                        // Swap b and d pointers 
                        r = b; 
                        (*movimentar)++;
                        b = d; 
                        (*movimentar)++;
                        d = r; 
                        (*movimentar)++;
  
                        c = d; 
                        (*movimentar)++;
  
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
                        (*movimentar)++;
                        b->prox = d->prox;
                        (*movimentar)++; 
                        d->prox = r; 
                        (*movimentar)++;
                        c->prox = b; 
                        (*movimentar)++;
  
                        // Swap b and d pointers 
                        r = b; 
                        (*movimentar)++;
                        b = d; 
                        (*movimentar)++;
                        d = r; 
                        (*movimentar)++;
  
                        c = d; 
                        (*movimentar)++;
  
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
                        (*movimentar)++;
                        b->prox = d->prox;
                        (*movimentar)++; 
                        d->prox = r; 
                        (*movimentar)++;
                        c->prox = b; 
                        (*movimentar)++;
                        a->prox = d; 
                        (*movimentar)++;
  
                        // Swap b and d pointers 
                        r = b; 
                        (*movimentar)++;
                        b = d; 
                        (*movimentar)++;
                        d = r; 
                        (*movimentar)++;
  
                        c = d; 
                        (*movimentar)++;
  
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
                (*movimentar)++;
                d = d->prox; 
                (*movimentar)++;
            } 
        } 
  
        a = b; 
        (*movimentar)++;
        b = b->prox; 
        (*movimentar)++;
    }
    return head; 
}