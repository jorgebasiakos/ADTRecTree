#include "acutest.h"			// Απλή βιβλιοθήκη για unit testing
#include "ADTMap.h"
#include "ADTSet.h"
#include "ADTRecTree.h"
#include "ADTVector.h"

void test_create(void) {

    RecTree rec_tree = rectree_create(NULL, NULL, NULL);
    TEST_ASSERT(rec_tree != NULL);              //δημιουργηθηκε επιτυχως
	TEST_ASSERT(rectree_size(rec_tree) == 1);   //αν δεν ειναι null το μετραμε

    //create με αρχικά στοιχεία
    
    RecTree old_left = rectree_left(rec_tree);
    RecTree old_right = rectree_right(rec_tree);
    insertLeft(rec_tree);                           //εισαγω αριστερα

    RecTree new_left = rectree_left(rec_tree);
    TEST_ASSERT(old_left != new_left);              //μη ταυτιση μεταξυ τους
    TEST_ASSERT(rectree_value(new_left) == rectree_left(rec_tree));  //το παιδι του ενος δεντρου, ειναι η ριζα του αλλου

    insertRight(rec_tree);                          //εισαγω δεξια

    RecTree new_right = rectree_left(rec_tree);
    TEST_ASSERT(old_right != new_right);            //μη ταυτιση μεταξυ τους 
    TEST_ASSERT(rectree_value(new_left) == rectree_left(rec_tree));  //το παιδι του ενος δεντρου, ειναι η ριζα του αλλου

    TEST_ASSERT(rectree_size(rec_tree) == 3);       //μετα την αριστερη και την δεξια προσθηκη πρεπει να εχω size = 1 + 1 + 1 = 3
    

    rectree_destroy(rectree_right(rec_tree));       
    rectree_destroy(rectree_left(rec_tree));
    rectree_destroy(rec_tree);
    TEST_ASSERT(rectree_size(rec_tree) == 0);       //μετα τις 3 αφαιρεσεις πρεπει το μεγεθος να ειναι 0
    
}	











//Λίστα με όλα τα tests προς εκτέλεση
TEST_LIST = {
	{ "pqueue_create", test_create },


	{ NULL, NULL } // τερματίζουμε τη λίστα με NULL
};
