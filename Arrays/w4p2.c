#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MIN_INCOME 500.00
#define MAX_INCOME 400000.00
#define WISH_LIST 10
#define COST_MOD 100.00

int main()

{

  // declaring variables

  double user_income;
  int test_inc = 0;
  int user_wishlist;
  int test_wish = 0;
  int num_wishlist;

  double user_cost[] = {};
  int user_priority[] = {};
  int user_finance[] = {};
  int i;

  // starting printf

  printf("+--------------------------+\n");
  printf("+   Wish List Forecaster   |\n");
  printf("+--------------------------+\n");
  printf("\n");

  // Loop for income

  do { // start of do while loop for income

    printf("\n");
    printf("Enter your monthly NET income: $");
    scanf("%lf", &user_income);

    // validate user income

    if (user_income >= MIN_INCOME &&
        user_income <= MAX_INCOME) { // start of if for valid income

      test_inc = 1; // set flag to true if user_income is valid

    } else if (user_income < MIN_INCOME) // end of if for valid income
    {                                    // start of invalid min income value

      printf("ERROR: You must have a consistent monthly income of at least "
             "$500.00\n");

      test_inc = 0;

    } // end of invalid min income value

    else if (user_income > MAX_INCOME)

    { // start of invalid max income

      printf("ERROR: Liar! I'll believe you if you enter a value no more than "
             "$400000.00\n");
      test_inc = 0;

    } // end of invalid max income

  } while (test_inc != 1); // end of do while loop for income

  // Loop for wish list items

  do

  { // start of do while wish list loop

    printf("\n");
    printf("How many wish list items do you want to forecast?: ");
    scanf("%d", &user_wishlist);

    // if user_wishlist is invalid

    if (user_wishlist <= 0 ||
        user_wishlist > WISH_LIST) { // start of if invalid user_wishlist

      printf("ERROR: List is restricted to between 1 and 10 items.\n");
      test_wish = 0;

    } else if (user_wishlist > 0 &&
               user_wishlist <= WISH_LIST) // end of if invalid user_wishlist

    { // beginning of if for valid user_wishlist

      test_wish = 1;

    } // end of if invalid user_wishlist

  } while (test_wish != 1); // end of do while wish list loop

  // store user_wishlist value in new variable to avoid confusion

  num_wishlist = user_wishlist;

  // for loop to repeat number of items based on the value of num_wishlist

  for (i = 0; i < user_wishlist; i++)

  { // beginning of for loop to print out item number based on the value of
    // num_wishlist

    printf("\n");
    printf("Item-%d Details:\n", i + 1);

  } // end of for loop to print out item number  based on the value of
    // num_wishlist

  return 0;
}
