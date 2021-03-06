/*----------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class>
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			Pyramid of Numbers
 * Author:			<your name>
 * ----------------------------------------------------------
 * Description:
 * Calculates a pyramid of numbers, i.e., it multiplies a big
 * integer by the number 2, its result by 3, etc. and then
 * returns to the original value by subsequently dividing,
 * again starting by 2, 3, etc.
 * ----------------------------------------------------------
 */
 #include <stdio.h>
 #include <string.h>
 #include <stdbool.h>
 #include <math.h>

/// The maximum number of digits allowed in a big int.
#define MAX_DIGITS 80

/** BigInt represents an integer number which can have MAX_DIGITS digits
*** @see MAX_DIGITS
*/
struct BigInt {
	/** number of digits of the big int. */
	int digits_count;

	/** array of digits of big int. */
	unsigned int the_int[MAX_DIGITS];
};
		void	set_digits_count(const struct BigInt *big_int,  struct BigInt *big_result);
/** strtobig_int converts a string into a BigInt. If strtobig_int runs
*** against a character not between '0' and '9' the conversion stops
*** at this point.
*** @param *str The string to be converted.
*** @param len Number of characters in string to be converted.
*** @param *big_int The converted string now as BigInt.
* @return The number of characters converted.
*/
 int strtobig_int(const char *str, int len, struct BigInt* big_int);  //done

/** print_big_int() prints a BigInt.
*** @param *big_int The BigInt to be printed.
*/
void print_big_int(const struct BigInt *big_int);   //done

/** multiply() multiplies a BigInt by an int.
*** @param big_int The BigInt to be multiplied.
*** @param factor The int value which is multiplied by BigInt.
*** @param *big_result The result of the multiplication.
*/
void multiply(const struct BigInt *big_int, int factor, struct BigInt *big_result);

/** divide() multiplies a BigInt by an int.
*** @param big_int The BigInt to be divided.
*** @param divisor The int value by which we want to devide big_int.
*** @param *big_result The result of the division.
*/
void divide(const struct BigInt *big_int, int divisor, struct BigInt *big_result);

/** copy_big_int() copies a BigInt to another BigInt.
*** @param from The source where we want to copy from.
*** @param *to The target where we want to copy to.
*/
void copy_big_int(const struct BigInt *from, struct BigInt *to);

/**
*** main() reads the base number from which the pyramid has to be calculated
*** into an array of char. The max. length of this number is MAX_DIGITS.
*** The number is checked to contain only digits. If not the program exits.
*** Then the inputted number is converted into a big int by calling the
*** function strtobig_int().
*** After the conversion the tower is calculated by calling the functions
*** multiply(), print_big_int(), and copy_big_int() consecutively from 2 to
*** 9 and then again with divide() instead of multiply() from 2 to 9.
***
*/
int main(int argc, char *argv[])
{
	struct BigInt number;
	struct BigInt big_result;
	char user_input[MAX_DIGITS];
	int len;
	int factor = 2;
	int divisor = 9;


	// number.digits_count = 5;
	// number.the_int[0] = 1
	printf("Pyramid of Numbers\n");
	printf("\n");
	printf("Please enter a number: " );
	scanf("%s",user_input);
	len = strlen(user_input);
	strtobig_int(user_input, len, &number);
	//print_big_int(&number);

	//multiply(&number,factor, &big_result);

	for (int i = 2; i < 10; i++)
	{
		print_big_int(&number);
		multiply(&number, factor, &big_result);
		printf("\n");
		set_digits_count(&number, &big_result);
		number = big_result;
		factor++;
	}
	for (int i = 2; i < 10; i++)
	{
			print_big_int(&number);

			divide(&number, divisor, &big_result);

			printf("\n");
			number = big_result;
			divisor--;
	}

	return 0;
}

int strtobig_int(const char *str, int len, struct BigInt* big_int)
{
	big_int->digits_count = 0;
	int j = len - 1;
	for (int i = 0; i < len; i++)
	{
		if (str[i] >= '0' && str[i]<= '9')  // check: is str[j] a digit
		{
			big_int->the_int[j] = str[i] - '0'; // convert from char to int
			j--;
			big_int->digits_count++;
		}
	}
}
void print_big_int(const struct BigInt *big_int)
{
	for (int i = big_int->digits_count-1 ; i >=0 ; i--)
	{
		printf("%d",big_int->the_int[i]);
	}
}
void multiply(const struct BigInt *big_int, int factor, struct BigInt *big_result)
{
	//while (factor <= 9)
	//{
		//for (int i = big_int->digits_count-1 ; i >=0 ; i--)
		//{
			//	printf("%d",big_int->the_int[i]);
		//}
		printf("* %d = ",factor );
		//printf("digits count :%d\n",big_int->digits_count );
		for (int i = big_int->digits_count-1 ; i >=0 ; i--)
		{
			if (big_int-> the_int[i] * factor >= 10)
			{
				if (big_result->the_int[i] >= 1 && big_result->the_int[i] <= 9)
				{
					 	big_result->the_int[i] += (big_int-> the_int[i] * factor) % 10;
						big_result->the_int[i-1] = ((big_int-> the_int[i] * factor) - ((big_int-> the_int[i] * factor)%10)) / 10;
				}
				else
				{
					big_result->the_int[i] = (big_int-> the_int[i] * factor) % 10;
					big_result->the_int[i-1] = ((big_int-> the_int[i] * factor) - ((big_int-> the_int[i] * factor)%10)) / 10;
				}
			}
			else
			{
				if (big_result->the_int[i] >= 1 && big_result->the_int[i] <= 9)
				{
					 		big_result->the_int[i] += big_int-> the_int[i] * factor;
				}
				else
				{
						big_result->the_int[i] = big_int-> the_int[i] * factor;
				}
			}
		}
		for (int i = big_int->digits_count-1 ; i >=0 ; i--)
		{
				printf("%d",big_result->the_int[i]);
		}
		//printf("\n" );
		//factor++;
	//}
}
void divide(const struct BigInt *big_int, int divisor, struct BigInt *big_result)
{
		int ram =0;
		printf("/ %d = ",divisor );
		for (int i = 0; i < big_int->digits_count ; i++)
		{
			if (big_int-> the_int[i] + ram *10 / divisor < 1)
			{
				big_result->the_int[i] = 0;
				ram = big_result->the_int[i];
			}
			else
			{
				if (ram != 0)
				{
							big_result->the_int[i] = (big_int-> the_int[i] + ram*10) / divisor;
							ram = (big_int-> the_int[i] + ram*10) - divisor * big_result->the_int[i];
				}
				else
				{
							big_result->the_int[i] = big_int-> the_int[i] / divisor;
				}
			}
		}
		for (int i = 0;  i < big_int->digits_count ; i++)
		{
				printf("%d",big_result->the_int[i]);
		}
}

void set_digits_count(const struct BigInt *big_int, struct BigInt *big_result)
{
	big_result->digits_count = big_int->digits_count;
}
