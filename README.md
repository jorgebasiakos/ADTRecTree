Here, I have created two different implementations of the Abstract Data Type (ADT) Recursive Tree. 
In the first one, each tree contains other subtrees (no nodes). Every tree is immutable, meaning that if a tree is deleted, 
its subtrees are not automatically deleted. If we want to change something in a tree, we should create a new one or destroy the old one. 
In the second implementation, I took a different approach, using ADTMap and avoiding the use of malloc.
