#ifndef BOOL_H_
#define BOOL_H_

/**
 *  A bool is really just a byte that reads 0 or 1.
 */
typedef unsigned char bool;

/**
 *  Note: This is actually number, so using `== false` will not work on something < 0.
 */
#define false 0

/**
 * Note: This is actually number, so using `== true` will not work on something > 1.
 */
#define true 1

/**
 *  Returns "true" if true, or "false" otherwise. If \p ret is specified, the value is stored in it.
 */
extern char *bool_toString(const bool b, char *const __restrict ret);

/**
 * Attempts to read a string and convert it to a bool. Returns true if it reads "true" (case insensitive), otherwise false.
 */
extern char *bool_fromString(const char *const __restrict string);


#endif
