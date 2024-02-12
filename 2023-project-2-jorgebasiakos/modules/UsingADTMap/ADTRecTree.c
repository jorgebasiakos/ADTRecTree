#include <stdio.h>
#include <stdlib.h>
#include "ADTRecTree.h"
#include <assert.h>
#include "ADTSet.h"
#include "ADTMap.h"
#include "ADTMap.c"
#include "ADTSet.c"
#include "ADTVector.h"
#include "ADTVector.c"

int compare_keys(void* a, void* b){
	return *(int*)a*1.5 - *(int*)b;
}

static int tree = 0;
Map map_v;  //global
Map map_l;	//global
Map map_r;	//global

RecTree rec_tree_create(int a, int b){
	int rectree;
	int value;

	map_v = map_create(compare_keys, NULL, NULL);
	map_l = map_create(compare_keys, NULL, NULL);
	map_r = map_create(compare_keys, NULL, NULL);

	//TEST_ASSERT(map_v == NULL);
	//tha ekmetalleytoyme oti ena kleidi yparxei sigoyra ston map_v kai taytoxrona eite ston map_l, eite ston map_r
	//tha ekmetalleytoume epishs thn sxesh oti an o pateras brisketai sthn thesh x tote to aristero paidi
	//brisketai sth thesh x*2 kai to deji sth thesi x*2+1
	Vector vec = vector_create(0,free);	
	Vector vec_v = vector_create(0,NULL);			
	Vector vec_l = vector_create(0,NULL);
	Vector vec_r = vector_create(0,NULL);

	for(int i = a; i < b; i++){
		tree++;
		int size = map_size(map_v);
		int sizel = map_size(map_l);
		int sizer = map_size(map_r);
		int j = 100;      											//xvris vlavh genikothtas
		
		if(tree == 1){
			map_insert(map_v, &rectree + i, &value + i);
			//map_insert(map_l, &rectree + i, REC_TREE_EMPTY);		//arxika to aristero NULL (de xreiazetai aparaithta sth sygkekrimenh ylopoihsh) 
			//map_insert(map_r, &rectree + i, REC_TREE_EMPTY);		//arxika to deji NULL (de xreiazetai aparaithta omoiws)
			vector_insert_last(vec_v, &rectree + i);
		}else if(tree == 2){										//left
			map_insert(map_v, &rectree + i, &value + i);
			map_insert(map_l, &rectree + i, &rectree - (tree - 1));			//paidi me patera
			vector_insert_last(vec_v, &rectree + i);
			vector_insert_last(vec_l, &rectree + i);
		}else if(tree == 3){										//right
			map_insert(map_v, &rectree + i, &value + i);
			map_insert(map_r, &rectree + i, &rectree - (tree - 1));			//paidi me patera
			vector_insert_last(vec_v, &rectree + i);
			vector_insert_last(vec_r, &rectree + i);
		}else{
			if(i%(i/2) == 0){										// => aristero paidi
				map_insert(map_v, &rectree + i, &value + i);
				map_insert(map_l, &rectree + i, &rectree - (tree - 1));
				while(size == map_size(map_v) || sizel == map_size(map_l)){
					map_insert(map_v, &rectree + i + j, &value + i);
					map_insert(map_l, &rectree + i + j, &value + i);
					j++;
				}
				vector_insert_last(vec_v, &rectree + i);
				vector_insert_last(vec_l, &rectree + i);
			}else{                                                    //if(i%(i/2)) == 1  => deji paidi
				map_insert(map_v, &rectree + i, &value + i);
				map_insert(map_r, &rectree + i, &rectree - (tree - 1));
				while(size == map_size(map_v) || sizer == map_size(map_r)){
					map_insert(map_v, &rectree + i + j, &value + i);
					map_insert(map_r, &rectree + i + j, &value + i);
					j++;
				}
				vector_insert_last(vec_v, &rectree + i);
				vector_insert_last(vec_r, &rectree + i);
			}
		}
	}
	vector_insert_last(vec, vec_v);
	vector_insert_last(vec, vec_l);
	vector_insert_last(vec, vec_r);

	return (RecTree)vec;
}



