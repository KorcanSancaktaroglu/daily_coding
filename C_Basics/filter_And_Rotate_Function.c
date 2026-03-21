void filterAndRotate(stack** top, int threshold) {
    if (!(*top) || !top) {
        printf("Stack is underflow\n"); return ;
    }
    stack* curr = *top, *parent = NULL;
    
    while (curr) {
        if (curr->value < threshold) {


            if (*top == curr) {
                *top = curr->prev;
                free(curr);
                curr = *top;


            }
            else {
                parent->prev = curr->prev;
                free(curr);
                curr = parent->prev;

            }

        }
        else
        {
            parent = curr;
            curr = curr->prev;
        }   

        
      
        
        
        
    }

}

