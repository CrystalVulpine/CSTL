#ifndef _VECTOR_H
#define _VECTOR_H


/**
 *  The vector data type including all its properties.
 */
typedef struct {
	void *data;
	unsigned int typeSize;
	unsigned int size;
	unsigned int capacity;
} vector;

// Define this pointer type once so it doesn't have to be re-written all the time.
typedef vector *const __restrict _VECTORTHIS;


/**
 * Preallocates memory for the given \p capacity of elements.
 */
extern void vector_reserve(_VECTORTHIS this, const unsigned int capacity);

/**
 * Adds the given \p element to the end of the vector.
 */
extern void vector_push_back(_VECTORTHIS this, const void *const __restrict element);

/**
 * Removes the last element of the vector.
 */
extern void vector_pop_back(_VECTORTHIS this);

/**
 * Initializes the vector.
 *
 * @param typeSize The memory size of each object in the vector, in bytes.
 */
extern void vector_init(_VECTORTHIS this, const unsigned int typeSize);

/**
 * Clears all elements of the vector. Does not deallocate memory.
 */
extern void vector_clear(_VECTORTHIS this);

/**
 * Deallocates memory to the current size of the vector.
 */
extern void vector_shrink_to_fit(_VECTORTHIS this);

/**
 *  Inserts \p element at the given \p pos.
 */
extern void vector_insert(_VECTORTHIS this, const unsigned int pos, const void *const __restrict element);

/**
 * Removes the element at the given \p pos.
 */
extern void vector_erase(_VECTORTHIS this, const unsigned int pos);

/**
 * Resizes the vector to the given \p newSize. If it's larger than before, insert \p def into new elements.
 */
extern void vector_resize(_VECTORTHIS this, const unsigned int newSize, const void *const __restrict def);

/**
 * Returns a pointer to the element at \p pos. If \p ret is specified, it stores a copy of the element in that location (and returns that pointer). This is always recommended, as if the vector ever needs reallocated pointers to elements in it will become invalidated.
 */
extern void *vector_get(_VECTORTHIS this, const unsigned int pos, void *const __restrict ret);


#endif
