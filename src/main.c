#include <stdio.h>
#include <stdlib.h>

#include "single_linked_list.h"
#include "double_linked_list.h"

void app_main() {
    struct singleLinkedList list;

    // Initialize the list
    initSingleLinkedList(&list);
    addElementSingleLinkedList(&list, 5);
    addElementSingleLinkedList(&list, 3);
    addElementSingleLinkedList(&list, 7);
    printSingleLinkedList(&list);
    removeFirstElementSingleLinkedList(&list);
    printSingleLinkedList(&list);
    removeLastElementSingleLinkedList(&list);
    printSingleLinkedList(&list);
    /* EXPECTED OUTPUT:
    * 3 , 5 , 7 -> 5, 7 -> 5
    */

    struct doubleLinkedList dlist;
    initDoubleLinkedList(&dlist);
    addElementDoubleLinkedList(&dlist, 5);
    addElementDoubleLinkedList(&dlist, 3);
    addElementDoubleLinkedList(&dlist, 7);
    printDoubleLinkedList(&dlist);
    removeFirstElementDoubleLinkedList(&dlist);
    printDoubleLinkedList(&dlist);
    removeLastElementDoubleLinkedList(&dlist);
    printDoubleLinkedList(&dlist);
    /* EXPECTED OUTPUT:
    * 3 , 5 , 7 -> 5, 7 -> 5
    */
    removeFirstElementDoubleLinkedList(&dlist);
    printDoubleLinkedList(&dlist);
    /* EXPECTED OUTPUT:
    * 
    */
   addElementDoubleLinkedList(&dlist, 5);
   printDoubleLinkedList(&dlist);
    /* EXPECTED OUTPUT:
     * 5 
    */

    removeFirstElementSingleLinkedList(&list);
    printSingleLinkedList(&list);
    /* EXPECTED OUTPUT:
    *
    */
   addElementSingleLinkedList(&list, 5);
    printSingleLinkedList(&list);
     /* EXPECTED OUTPUT:
      * 5 
     */

}