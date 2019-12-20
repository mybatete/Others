#include<stdio.h>
#include<math.h>

int square(long int x){
	return x*x;
}

int cube(long int x){
	return x*x*x;
}

void* return_counter(int x){
	int count = x;
	int counter(){
		count--;
		return count;
	}
	return counter;
}

void run_with_5(void (*param)(int)){
	param(5);
}
/*
 * The following bit:  You can't say list_of_functions[i]
 * list_of_functions is type void*, so the compiler won't know
 * how to find element i.  It will have to be a void*.  There are
 * two options:  Cast it as a void*, or make a new variable that is
 * the correct type.
 */

/*
void* list_of_functions;
((void**)list_of_functions)[i]; // Cast as void** option
void** lof_as_list = list_of_functions; // Make a new variable of the right type option
lof_as_list[i]; 
*/
int main(){
	printf("0x%x\n", printf);

	int (*foo)(long int) = square;
	void *pointer_to_square = square;
//	pointer_to_square(10); // This won't work, because pointer_to_square is type void*
	int (*another_pointer)(long int) = pointer_to_square;
	//printf(another_pointer(10));
	((int (*)(long int))pointer_to_square)(100); // You can cast and call in one line

	printf("foo(5) = %d\n", foo(5));
	foo = cube;
	printf("foo(5) = %d\n", foo(5));
	// Strange use
	//foo = printf;
	//printf("foo(5) = %d\n", foo("hi\n"));

	int (*our_counter)() = return_counter(5);
	int A[5];
	for(int i = 0; i < 5; i++)
		A[i] = our_counter();

	for(int i = 0; i < 5; i++)
		printf("A[%d] = %d\n", i, A[i]);

	int (*our_other_counter)() = return_counter(10);
	//printf("The sin of 10 is %f\n", sin(10)); // This line breaks it!
	for(int i = 0; i < 10; i++)
		printf("Counter returned %d\n", our_other_counter());

	void print_our_argument(int x){
		printf("Our argument was %d\n", x);
	}
	run_with_5(print_our_argument);


	return 0;
}
