#include <stdlib.h>
#include "ft_list.h"

// The original linked list (begin_list) remains unchanged
// after calling ft_list_foreach.

void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    t_list *list_ptr;

    list_ptr = begin_list;
    while (list_ptr)
    {
        (*f)(list_ptr->data);
        list_ptr = list_ptr->next;
    }
}