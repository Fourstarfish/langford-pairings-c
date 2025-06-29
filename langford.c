#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function: integer_array_helper
// Parameters:
//   - argc: Number of command-line arguments
//   - argv: Array of command-line argument strings
// Returns:
//   - A dynamically allocated integer array containing parsed values from
// command-line arguments (excluding the program name)
// Note: The caller is responsible for freeing the allocated memory after use.

int* integer_array_helper(const int argc, char const *argv[]) {

  // Allocate memory for the integer array based on the number of command-line
  // arguments

  int *arr = (int*)malloc((argc - 1) * sizeof(int));

  // Iterate through command-line arguments starting from index 1 (excluding the
  // program name)

  for (int i = 1; i < argc; i++) {

    // Parse the current argument as an integer using strtol

    char *endptr;
    arr[i - 1] = strtol(argv[i], &endptr, 10);
  }

  // Return the dynamically allocated integer array

  return arr;
}

// Function: print_int_array
// Parameters:
//   - arr: Pointer to an integer array
//   - size: Size of the integer array
// Prints the elements of the given integer array to the standard output in a
// formatted way.

void print_int_array(const int *arr, const int size) {

  // Print the opening bracket of the array

  printf("[");

  // Iterate through the elements of the array

  for (int i = 0; i < size; i++) {

  // Print the current element

    printf("%d", arr[i]);

    // Add a comma and space if it's not the last element

    if (i < size - 1) {
      printf(", ");
    }
  }

  // Print the closing bracket of the array and a newline character

  printf("]\n");
}

// Function: is_langford_pairing
// Parameters:
//   - size: Size of the integer array
//   - int_array: Pointer to an integer array representing a candidate
//     Langford pairing
// Checks if the given integer array is a valid Langford pairing.
// Returns:
//   - true if the array is a Langford pairing
//   - false otherwise

bool is_langford_pairing(int size, const int int_array[]) {

  // Check if the array is even; odd arrays can not be Langford Pairings

  if (size % 2 != 0) {
    return false;
  }

  // Check if the array is congruent to 0 or 3 modulo 4; only those arrays can
  // be Langford Pairings

  int half_size = size / 2;

  if ((3 * half_size * half_size - half_size) % 4 != 0) {
    return false;
  }

  // Iterate through the elements of the array

  for (int i = 0; i < size; i++) {

    // Retrieve the value at the current index

    int value = int_array[i];

    // Check if the 2 * value is greater than the size of the array

    if (2 * value > size) {
      return false;
    }

    // Calculate the index of the next occurrence of the value

    int next_index = i + value + 1;

    // Check if the next occurrence is out of bounds

    if (next_index >= size) {

      // Calculate the index of the previous occurrence of the value

      int prev_index = i - value - 1;

      // Check if the previous occurrence is within bounds and not equal to the
      // value

      if (prev_index >= 0 && int_array[prev_index] != value) {
        return false;
      }
    } else if (int_array[next_index] != value) {

      // Check if the next occurrence is not equal to the value

      int prev_index = i - value - 1;

      // Check if the previous occurrence is within bounds and not equal to the
      // value

      if (prev_index >= 0 && int_array[prev_index] != value) {
        return false;
      }
    }
  }
  // If the loop completes without returning false, the array is a Langford
  // pairing

  return true;
}

// Function: ceiling_of_division
// Parameters:
//   - numerator: Numerator of the division
//   - denominator: Denominator of the division
// Calculates the ceiling of the division result (numerator / denominator).
// The ceiling of a division is the smallest integer greater than or equal to
// the division result.
// Returns: The result of the ceiling division.
// Note: The function assumes both numerator and denominator are non-negative.
// Note: The function assumes the denominator is not 0.

int ceiling_of_division(const int numerator, const int denominator) {

    // Calculate the result of the division

    int result = numerator / denominator;

    // Check if there is a remainder (numerator is not divisible by denominator)

    if (numerator % denominator != 0) {

        // Increment the result to obtain the ceiling value

        result++;
    }

    // Return the result of the ceiling division

    return result;
}

// Function: create_odd_array
// Parameters:
//   - start: The starting value of the odd numbers
//   - end: The ending value of the odd numbers
//   - size: A pointer to an integer to store the size of the created array
// Creates an array containing odd numbers in the specified range [start, end].
// The length of the array is calculated based on the number of odd values in
// the range.
// Returns: A dynamically allocated array containing odd numbers.
// The size parameter is updated with the length of the created array.

int* create_odd_array(const int start, const int end, int* size) {

  // Calculate the length of the array containing odd numbers
  // Adjust the length based on whether the start is an odd or even number

    int length = (end - start + 1 + (start % 2)) / 2;

    // Update the size parameter with the calculated length

    *size = length;

    // Allocate memory for the array

    int* array = (int*)malloc(length * sizeof(int));

    // Populate the array with odd numbers in the specified range

    for (int i = start, j = 0; i <= end; i += 2, j++) {
        array[j] = i;
    }

    // Return the dynamically allocated array

    return array;
}

// Function: create_even_array
// Parameters:
//   - start: The starting value of the even numbers
//   - end: The ending value of the even numbers
//   - size: A pointer to an integer to store the size of the created array
// Creates an array containing even numbers in the specified range [start, end].
// The length of the array is calculated based on the number of even values in
// the range.
// Returns: A dynamically allocated array containing even numbers.
// The size parameter is updated with the length of the created array.

int* create_even_array(const int start, const int end, int* size) {

    // Calculate the length of the array containing even numbers
    // Adjust the length based on whether the start is an odd or even number

    int length = (end - start + 2 - (start % 2)) / 2;

    // Update the size parameter with the calculated length

    *size = length;

    // Allocate memory for the array

    int* array = (int*)malloc(length * sizeof(int));

    // Populate the array with even numbers in the specified range

    for (int i = start, j = 0; i <= end; i += 2, j++) {
        array[j] = i;
    }

    // Return the dynamically allocated array

    return array;
}

// Function: reverse_array
// Parameters:
//   - array: Pointer to an array of integers to be reversed
//   - size: The size of the array
// Creates a new array containing the elements of the input array in reversed
// order.
// Parameters:
//   - array: Pointer to the original array
//   - size: The size of the original array
// Returns: A dynamically allocated array containing elements in reversed order.

int* reverse_array(const int* array, int size) {

    // Allocate memory for the reversed array

    int* reversed_array = malloc(size * sizeof(int));

    // Copy elements from the original array to the reversed array in reversed
    // order

    for (int i = 0, j = size - 1; i < size; i++, j--) {
        reversed_array[i] = array[j];
    }

    // Return the dynamically allocated reversed array
    return reversed_array;
}

// Function: concatenate_arrays_zero_mod_four
// Parameters:
//   - reversed_s: Pointer to an array containing reversed elements for s
//   - reversed_p: Pointer to an array containing reversed elements for p
//   - b: An integer value
//   - p: Pointer to an array containing elements for p
//   - c: An integer value
//   - s: Pointer to an array containing elements for s
//   - d: An integer value
//   - reversed_r: Pointer to an array containing reversed elements for r
//   - reversed_q: Pointer to an array containing reversed elements for q
//   - a: An integer value
//   - q: Pointer to an array containing elements for q
//   - r: Pointer to an array containing elements for r
//   - length: Pointer to an integer that will store the length of the resulting
//     array
//   - size_p: Size of array p
//   - size_q: Size of array q
//   - size_r: Size of array r
//   - size_s: Size of array s
// Calculates the total length of the resulting array, allocates memory, and
// copies
// elements from input arrays to the resulting array in a specific order.
// Returns: Pointer to a dynamically allocated array containing the concatenated
// elements.

int* concatenate_arrays_zero_mod_four(const int* reversed_s,
  const int* reversed_p, int b, const int* p, int c, const int* s, int d,
  const int* reversed_r, const int* reversed_q, int a, const int* q,
  const int* r, int* length, int size_p, int size_q, int size_r, int size_s) {

    // Calculate the total length of the resulting array

    *length = 8 + (2 * (size_p + size_q + size_r + size_s));

    // Allocate memory for the resulting array

    int* result = (int*)malloc((*length) * sizeof(int));

    // Copy elements to the resulting array in the specified order

    int index = 0;

    // Add elements from reversed_s

    for (int i = 0; i < size_s; i++) {
        result[index++] = reversed_s[i];
    }

    // Add elements from reversed_p

    for (int i = 0; i < size_p; i++) {
        result[index++] = reversed_p[i];
    }

    // Add b, p, c, s, d

    result[index++] = b;
    for (int i = 0; i < size_p; i++) {
        result[index++] = p[i];
    }
    result[index++] = c;
    for (int i = 0; i < size_s; i++) {
        result[index++] = s[i];
    }
    result[index++] = d;

    // Add elements from reversed_r

    for (int i = 0; i < size_r; i++) {
        result[index++] = reversed_r[i];
    }

    // Add elements from reversed_q

    for (int i = 0; i < size_q; i++) {
        result[index++] = reversed_q[i];
    }

    // Add b, a, q, c, r, a, d

    result[index++] = b;
    result[index++] = a;
    for (int i = 0; i < size_q; i++) {
        result[index++] = q[i];
    }
    result[index++] = c;
    for (int i = 0; i < size_r; i++) {
        result[index++] = r[i];
    }
    result[index++] = a;
    result[index++] = d;

    return result;
}

// Function: concatenate_arrays_three_mod_four
// Parameters:
//   - reversed_s: Pointer to an array containing reversed elements for s
//   - reversed_p: Pointer to an array containing reversed elements for p
//   - b: An integer value
//   - p: Pointer to an array containing elements for p
//   - c: An integer value
//   - s: Pointer to an array containing elements for s
//   - a: An integer value
//   - reversed_r: Pointer to an array containing reversed elements for r
//   - reversed_q: Pointer to an array containing reversed elements for q
//   - q: Pointer to an array containing elements for q
//   - r: Pointer to an array containing elements for r
//   - length: Pointer to an integer that will store the length of the resulting
//     array
//   - size_p: Size of array p
//   - size_q: Size of array q
//   - size_r: Size of array r
//   - size_s: Size of array s
// Calculates the total length of the resulting array, allocates memory, and
// copies
// elements from input arrays to the resulting array in a specific order.
// Returns: Pointer to a dynamically allocated array containing the concatenated
// elements.

int* concatenate_arrays_three_mod_four(const int* reversed_s,
  const int* reversed_p, int b, const int* p, int c, const int* s, int a,
  const int* reversed_r, const int* reversed_q, const int* q, const int* r,
  int* length, int size_p, int size_q, int size_r, int size_s) {

    // Calculate the total length of the resulting array

    *length = 6 + (2 * (size_p + size_q + size_r + size_s));

    // Allocate memory for the resulting array

    int* result = (int*)malloc((*length) * sizeof(int));

    // Copy elements to the resulting array in the specified order

    int index = 0;

    // Add elements from reversed_s

    for (int i = 0; i < size_s; i++) {
        result[index++] = reversed_s[i];
    }

    // Add elements from reversed_p

    for (int i = 0; i < size_p; i++) {
        result[index++] = reversed_p[i];
    }

    // Add b, p, c, s, a

    result[index++] = b;
    for (int i = 0; i < size_p; i++) {
        result[index++] = p[i];
    }
    result[index++] = c;
    for (int i = 0; i < size_s; i++) {
        result[index++] = s[i];
    }
    result[index++] = a;

    // Add elements from reversed_r

    for (int i = 0; i < size_r; i++) {
        result[index++] = reversed_r[i];
    }

    // Add elements from reversed_q

    for (int i = 0; i < size_q; i++) {
        result[index++] = reversed_q[i];
    }

    // Add b, a, q, c, r

    result[index++] = b;
    result[index++] = a;
    for (int i = 0; i < size_q; i++) {
        result[index++] = q[i];
    }
    result[index++] = c;
    for (int i = 0; i < size_r; i++) {
        result[index++] = r[i];
    }

    return result;
}

// Function: main
// Parameters:
//   - argc: Number of command-line arguments
//   - argv: Array of command-line arguments
// Entry point for the program.
// Checks command-line arguments, displays usage information, and creates
// Langford Pairing or checks if a given array is a valid Langford Pairing.
// Returns: 0 if the program executes successfully.

int main(int argc, char const *argv[]) {

  // Check if the program is run with no arguments or if the first argument is
  // -h

  if (argc < 2 || (strcmp(argv[1], "-h") == 0)) {

    // Display usage information to standard error and terminate with exit code
    // 0

    fprintf(stderr, "usage: %s [-h] -c n | num...\n", argv[0]);
    exit(0);
  }

  // Check if the first argument is -c and handle Langford Pairing creation

  if (strcmp(argv[1], "-c") == 0) {

     // Check for errors associated with the -c option

     if (argc == 2) {
       fprintf(stderr, "%s: -c option requires an argument.\n", argv[0]);
       exit(1);
     }

     if (argc > 3) {
       fprintf(stderr, "%s: -c option received too many arguments.\n", argv[0]);
       exit(1);
     }

     // Check if the argument is not an integer

     char *endptr;
     strtol(argv[2], &endptr, 10);
     if (endptr && endptr[0] != '\0') {
       fprintf(stderr, "error: %s is not an integer.\n", argv[2]);
       exit(1);
     }

     // No errors found, create the Langford Pairing

     else {
       printf("Creating a langford pairing with n=%s\n", argv[2]);
       int n = atoi(argv[2]);
       if ((3 * n * n - n) % 4 != 0 || n <= 0) {
         printf("No results found.\n");
         exit(0);
       } else {

         // Calculate parameters for Langford Pairing

         int x = ceiling_of_division(n, 4);

         int a = (2 * x - 1);
         int b = (4 * x - 2);
         int c = (4 * x - 1);
         int d = (4 * x);

         // Create arrays for Langford Pairing

         int size_p, size_q, size_r, size_s;
         int* p = create_odd_array(1, a - 1, &size_p);
         int* q = create_even_array(2, a - 1, &size_q);
         int* r = create_odd_array(a + 2, b - 1, &size_r);
         int* s = create_even_array(a + 1, b - 1, &size_s);

         // Reverse arrays

         int* reversed_p = reverse_array(p, size_p);
         int* reversed_q = reverse_array(q, size_q);
         int* reversed_r = reverse_array(r, size_r);
         int* reversed_s = reverse_array(s, size_s);

         // Check if n is divisible by 4 and choose the appropriate
         // concatenation

         if (n % 4 == 0) {
           int length;
           int* result = concatenate_arrays_zero_mod_four(reversed_s,
             reversed_p, b, p, c, s, d, reversed_r, reversed_q, a, q, r,
             &length, size_p, size_q, size_r, size_s);
           print_int_array(result, length);

           // Free dynamically allocated memory
           free(p);
           free(q);
           free(r);
           free(s);
           free(reversed_p);
           free(reversed_q);
           free(reversed_r);
           free(reversed_s);
           free(result);

           exit(0);
         } else {
           int length;
           int* result = concatenate_arrays_three_mod_four(reversed_s,
             reversed_p, b, p, c, s, a, reversed_r, reversed_q, q, r, &length,
             size_p, size_q, size_r, size_s);
           print_int_array(result, length);

           // Free dynamically allocated memory
           free(p);
           free(q);
           free(r);
           free(s);
           free(reversed_p);
           free(reversed_q);
           free(reversed_r);
           free(reversed_s);
           free(result);
           exit(0);
         }
       }
     }
  }

  // Check for the only argument error in check mode

  if (strcmp(argv[1], "-c") != 0 && strcmp(argv[1], "-h") != 0) {
    for (int i = 1; i < argc; i++) {
      char *endptr;
      strtol(argv[i], &endptr, 10);
      if (endptr && endptr[0] != '\0') {
        fprintf(stderr, "error: %s is not an integer.\n", argv[i]);
        exit(1);
      }
    }

    // Convert command-line arguments to an integer array

    int *array_to_print = integer_array_helper(argc, argv);
    printf("Your sequence:");
    print_int_array(array_to_print, argc - 1);

    // Check if it is a Langford Pairing

    bool result = is_langford_pairing(argc - 1, array_to_print);

    // Print the result

    if (result) {
      printf("It is a langford pairing!\n");

      // Free dynamically allocated memory
      free(array_to_print);

      exit(0);
    } else {
      printf("It is NOT a langford pairing.\n");

      // Free dynamically allocated memory
      free(array_to_print);

      exit(0);
    }
  }
  return 0;
}
