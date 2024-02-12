///////////////////////////////////////////////////////////////////
//
// Υλοποίηση του ADT RecTree μέσω links
//
///////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include "ADTRecTree.h"

//  Ένα δέντρο είναι pointer σε αυτό το struct
struct rec_tree {
	void* value;
	RecTree left;
	RecTree right;
	RecTree previous;
	int size;
};


// Δημιουργεί και επιστρέφει ένα νέο δέντρο, με τιμή (στη ρίζα) value και υποδέντρα left και right.

RecTree rectree_create(Pointer value, RecTree left, RecTree right) {
	RecTree rec_tree = malloc(sizeof(*rec_tree));
	rec_tree->value = rec_tree;		 //συμβαση να παιρνει αυτο σαν τιμη (=> !=ΝULL) 
	rec_tree->left = left;
	rec_tree->right = right;
	rec_tree->size = 1;				 //μετα την σημιουργια εχουμε μεγεθος 1
	rec_tree->previous = value;      //στη συγκεκριμενη υλοποιηση το θελω για να βρισκω τον πατερα (εαν υπαρχει)
	return rec_tree;
}

// Insert on the left

void insertLeft(RecTree tree) {
  tree->size++;
  tree->left = rectree_create(tree, REC_TREE_EMPTY, REC_TREE_EMPTY);
}

// Insert on the right

void insertRight(RecTree tree) {
  tree->size++;	
  tree->right = rectree_create(tree, REC_TREE_EMPTY, REC_TREE_EMPTY);
}


// Επιστρέφει τον αριθμό στοιχείων που περιέχει το δέντρο.

int rectree_size(RecTree tree) {
	return tree->size;
}

// Ελευθερώνει όλη τη μνήμη που δεσμεύει το δέντρο tree.

void rectree_destroy(RecTree tree) {
	tree->size--;								//καθε δεντρο εχει το
	if(tree->previous != NULL){					//δικο του size αλλα
		tree->previous->size--;					//μια αφαιρεση αφορα 
	}											//και το υπολοιπο συνολο
	free(tree);
}

// Επιστρέφουν την τιμή (στη ρίζα), το αριστερό και το δεξί υποδέντρο του δέντρου tree.

Pointer rectree_value(RecTree tree) {
	return tree->value;
}

RecTree rectree_left(RecTree tree) {
	return tree->left;
}

RecTree rectree_right(RecTree tree) {
	return tree->right;
}

Pointer rectree_previous(RecTree tree) {
	return tree->previous;
}


