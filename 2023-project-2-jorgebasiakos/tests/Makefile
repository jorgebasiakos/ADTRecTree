# Κάνοντας compile το <foo>_test.c με μια υλοποίηση <foo>.c του
# συγκεκριμένου τύπου, παράγουμε ένα tets για την υλοποίηση αυτή.

# Υλοποιήσεις μέσω Heap: ADTPriorityQueue
# Το Heap χρησιμοποιεί Vector, οπότε χρειαζόμαστε και μια υλοποίηση του ADTVector.
#
UsingHeap_ADTPriorityQueue_test_OBJS  = ADTPriorityQueue_test.o $(MODULES)/UsingHeap/ADTPriorityQueue.o $(MODULES)/UsingDynamicArray/ADTVector.o

ADTRecTree_test_OBJS  = ADTRecTree_test.o $(MODULES)/UsingLinkedTree/ADTRecTree.o
ADTRecTree_test_OBJS  = ADTRecTree_testt.o $(MODULES)/UsingADTMap/ADTRecTree.o
# Ο βασικός κορμός του Makefile
include ../common.mk
