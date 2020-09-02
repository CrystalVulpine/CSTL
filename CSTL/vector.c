#include <stdlib.h>
#include <string.h>
#include "include/CSTL/vector.h"

void vector_reserve(_VECTORTHIS this, const unsigned int capacity) {
	if (this->data == NULL) {
		this->data = malloc(capacity * this->typeSize);
	} else if (this->capacity < capacity) {
		this->data = realloc(this->data, capacity * this->typeSize);
	}
	this->capacity = capacity;
}

void vector_push_back(_VECTORTHIS this, const void *const __restrict element) {
	const unsigned int size = this->size;
	const unsigned int typeSize = this->typeSize;

	// If the vector is not already allocated enough, we must do so.
	vector_reserve(this, size + 1);

	memcpy(&this->data[size * typeSize], element, typeSize);
	this->size += 1;
}

void vector_pop_back(_VECTORTHIS this) {
	this->size -= 1;
}

void vector_init(_VECTORTHIS this, const unsigned int typeSize) {
	this->data = NULL;
	this->typeSize = typeSize;
	this->size = 0;
	this->capacity = 0;
}

void vector_clear(_VECTORTHIS this) {
	this->size = 0;
}

void vector_shrink_to_fit(_VECTORTHIS this) {
	const unsigned int capacity = this->size * this->typeSize;
	if (this->capacity != capacity) {
		this->data = realloc(this->data, capacity);
		this->capacity = capacity;
	}
}

void vector_insert(_VECTORTHIS this, const unsigned int pos, const void *const __restrict element) {
	const unsigned int typeSize = this->typeSize;
	vector_reserve(this, this->size + 1);
	for (unsigned int i = this->size; i > pos; --i) {
		memcpy(&this->data[i * typeSize], &this->data[(i - 1) * typeSize], typeSize);
	}
	memcpy(&this->data[pos * typeSize], element, typeSize);
	this->size += 1;
}

void vector_erase(_VECTORTHIS this, const unsigned int pos) {
	const unsigned int typeSize = this->typeSize;
	for (unsigned int i = pos; i < this->size - 1; ++i) {
		memcpy(&this->data[i * typeSize], &this->data[(i + 1) * typeSize], typeSize);
	}
	this->size -= 1;
}

void vector_resize(_VECTORTHIS this, const unsigned int newSize, const void *const __restrict def) {
	const unsigned int typeSize = this->typeSize;
	vector_reserve(this, newSize);
	if (def != NULL) {
		for (unsigned int i = this->size; i < newSize; ++i) {
			memcpy(&this->data[i * typeSize], def, typeSize);
		}
	}
	this->size = newSize;
}

void *vector_get(_VECTORTHIS this, const unsigned int pos, void *const __restrict ret) {
	if (ret == NULL) {
		return &this->data[pos * this->typeSize];
	} else {
		return memcpy(ret, &this->data[pos * this->typeSize], this->typeSize);
	}
}
