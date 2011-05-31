/**
 * File: c-puzzler-give-me-a-float.c
 * Blog Post: http://blogs.adobe.com/charles/2011/02/c-puzzler-give-me-a-float.html
 * Author: Charles Bihis
 * 
 * Question:
 *   What value does main return?
 *
 *   a) 0
 *   b) 1
 *   c) it varies
 *   d) none of the above
 *
 * Walkthrough:
 *   There is a local variable x, and it is declared as an int.  It is
 *   being initialized to the sum of 0.5 and the value returned by
 *   the function giveMeAFloat(), which is declared in another source file.
 *   The function giveMeAFloat() returns the float value 0.5, and so the
 *   sum of these two values is the float value 1.0.  The variable x is 
 *   an int, and so truncates 1.0 to 1, and so main() returns the int 1.
 *
 * Answer:
 *   The answer is a - 0.  Notice that in the source file containing our 
 *   main function, there is no function prototype declaring the function
 *   giveMeAFloat().  Because of this, giveMeAFloat() is *assumed* to return
 *   an int.  With this in mind, it is clear to see that x will then be
 *   initialized to the sum of 0.5 and 0 (the int value of 0.5), which equals
 *   0.5.  The variable x then truncates 0.5 to an int value, giving 0.  Hence,
 *   main() returns the int 0.
 *
 * Moral:
 *   Given an arbitrary name that has not yet been previously defined, if the
 *   name is followed by a left parenthesis, it is declared to be a function
 *   and it is assumed to return an int.  To prevent this, explicitly declare
 *   the function, either as a function prototype at the top of the source
 *   file, like so...
 *
 *   #include <stdio.h>
 * 
 *   int giveMeAFloat();
 * 
 *   int main()
 *   {
 * 		int x = 0.5 + giveMeAFloat();
 * 
 * 		return x;
 *   }
 * 
 *   ...or within the calling routine, like so...
 *
 *   #include <stdio.h>
 * 
 *   int main()
 *   {
 * 		int x, giveMeAFloat();
 * 	
 * 		x = 0.5 + giveMeAFloat();
 * 
 * 		return x;
 *   }
 * 
 *   Now, there is no confusion, to yourself or the compiler, about
 *   the return type of the function giveMeAFloat().
 */
#include <stdio.h>

int main()
{
	int x = 0.5 + giveMeAFloat();

	//printf("%d\n", x);
	return x;
}


