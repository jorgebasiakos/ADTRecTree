#include "acutest.h"			// Απλή βιβλιοθήκη για unit testing
#include "ADTMap.h"
#include "ADTSet.h"
#include "ADTRecTree.h"
#include "ADTVector.h"

void test_create(void){
	RecTree rec = rec_tree_create(1,100);
	Vector vec = (Vector)rec;
	TEST_ASSERT(vec != NULL);
	TEST_ASSERT(vector_size(vec) == 3);					//periexei ta vec_v, vec_l, vec_r

	TEST_ASSERT(vector_size(vector_get_at(vec,0)) == 99);	//to vev_v periexei olous toys 100-1=99 "komvous"

	//epibebaiwsh oti to dentro einai complete (etsi sxediasthke)
	TEST_ASSERT(vector_size(vector_get_at(vec,0)) == (vector_size(vector_get_at(vec,1)) + vector_size(vector_get_at(vec,2)))+1);

	bool flag = false;

	for(VectorNode node = vector_first(vector_get_at(vec,1)); node != VECTOR_EOF; node = vector_next(vector_get_at(vec,1), node)){
		if(vector_get_at(vector_get_at(vec,0), 81) == vector_node_value(vector_get_at(vec,1), node)){
			flag = true;				//epibebaiwsh oti yparxei to stoixeio sto allo vector (vec_l)
		}
	}
	TEST_ASSERT(flag == true);

	flag = false;

	for(VectorNode node = vector_first(vector_get_at(vec,2)); node != VECTOR_EOF; node = vector_next(vector_get_at(vec,2), node)){
		if(vector_get_at(vector_get_at(vec,0), 82) == vector_node_value(vector_get_at(vec,2), node)){
			flag = true;				//epibebaiwsh oti yparxei to stoixeio sto allo vector (vec_r)
		}
	}

	TEST_ASSERT(flag == true);	

	map_destroy(map_v);
	map_destroy(map_r);
	map_destroy(map_l);
    vector_destroy(vector_get_at(vec,0));
    vector_destroy(vector_get_at(vec,1));
    vector_destroy(vector_get_at(vec,2));
	vector_destroy(vec);

}











//Λίστα με όλα τα tests προς εκτέλεση
TEST_LIST = {
	{ "pqueue_create", test_create },


	{ NULL, NULL } // τερματίζουμε τη λίστα με NULL
};
