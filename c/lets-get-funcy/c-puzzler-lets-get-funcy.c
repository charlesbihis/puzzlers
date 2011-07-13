/**
 * File: c-puzzler-lets-get-funcy.c
 * Blog Post: http://blogs.adobe.com/charles/2010/11/c-puzzler-like-java-puzzlers-but-for-c.html
 * Author: Charles Bihis
 *
 * Question:
 *   What value does main return?
 *
 *   a) 2
 *   b) 3
 *   c) 4
 *   d) it varies
 *
 * Walkthrough:
 *   There is a global variable, x, and it is initialized to 1.  In main()
 *   there is a local variable, y, and it is initialized to the value 
 *   returned by funcOne() plus the value returned by funcTwo().  The
 *   function funcOne() simply returns the value stored in variable x, which
 *   is 1.  The function funcTwo() also references x, but increments it in
 *   the process.  Since the increment operator is a prefix, it performs
 *   the increment before returning the value, and so funcTwo() will return
 *   the incremented value of x, which is 2.  Therefore, y will equal
 *   1 + 2, which is 3 and main() will return the int value 3.
 *
 * Answer:
 *   The answer is d - it varies.  This is because in ANSI C, there is no
 *   guarantee as to the order in which the operands of an operator are
 *   evaluated.  So, depending on the compiler implementation, funcOne()
 *   can be evaluated before funcTwo(), and vice versa, giving us a result
 *   of 3 or 4 depending on our compiler.  It should be noted, though, that
 *   MOST C compilers will evaluate expressions of operands left to right,
 *   including the GNU compiler, but there is no guarantee that this is the
 *   case.  As a result, the safest way to achieve compiler-agnostic results
 *   would be to use intermediary variables.
 *
 * Moral:
 *   The order in which operands of an operator is unspecified in C.  So, to
 *   give safe and predictable results, external variables should be modified
 *   carefully, and specifically noted in the function's documentation.  If the
 *   documentation for a function is lacking, or you are working with a 3rd
 *   party API which, for all intents and purposes, is a black-box, use of
 *   intermediary variables to ensure order of operations is safest.
 */

#include <stdio.h>

int funcOne();
int funcTwo();

int x = 1;

int main()
{
	int y = funcOne() + funcTwo();

	return y;
}

int funcOne()
{
	return x;
}

int funcTwo()
{
	return ++x;
}
