#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MIN_YEAR 2010
#define MAX_YEAR 2021
#define LOG_DAYS 3

int main() {
  const int JAN = 1;
  const int DEC = 12;
  int user_year, user_month;
  int day;
  double user_morning, user_even;
  int test1;
  int test2;
  double sum_morning, sum_even, total_sum;
  double avg_morn, avg_even, total_avg;

  printf("General Well-being Log\n");
  printf("======================\n");

  // logic outline

  /*
   do{

    print prompt to enter year and month
   read year and month
   if year is not valid print year error
   if month is not valid print month error

   }while (year not valid or month not valid);

  */

  // intitial printf stataments for entering year and month

  do {

    printf("Set the year and month for the well-being log (YYYY MM): ");
    scanf("%d %d", &user_year, &user_month);

    // if loop to check the condition of year

    if (user_year < MIN_YEAR || user_year > MAX_YEAR) {

      printf("   ERROR: The year must be between 2010 and 2021 inclusive\n");
    }

    if (user_month < JAN || user_month > DEC) {
      printf("   ERROR: Jan.(1) - Dec.(12)\n");

      // selection to convert user input of month from numbers to characters
    }

  } while (user_year < MIN_YEAR || user_year > MAX_YEAR || user_month < JAN ||
           user_month > DEC);

  if (user_year >= MIN_YEAR && user_year <= MAX_YEAR && user_month >= JAN &&
      user_month <= DEC)
    ;

  { // start of if statement to begin part 2

    printf("\n");
    printf("*** Log date set! ***\n");

    for (day = 0; day < LOG_DAYS; day++)
      // begin part 2

      do // begining do while of switch to print out date and days
      {

        printf("\n");
        switch (user_month)

        { // switch beginning

        case 1:
          printf("%d-JAN-0%d\n", user_year, day + 1);
          break;

        case 2:
          printf("%d-FEB-0%d\n", user_year, day + 1);
          break;

        case 3:
          printf(" %d-MAR-0%d\n", user_year, day + 1);
          break;

        case 4:
          printf("%d-APR-0%d\n", user_year, day + 1);
          break;

        case 5:
          printf("%d-MAY-0%d\n", user_year, day + 1);
          break;

        case 6:
          printf("%d-JUN-0%d\n", user_year, day + 1);
          break;

        case 7:
          printf("%d-JUL-0%d\n", user_year, day + 1);
          break;

        case 8:
          printf("%d-AUG-0%d\n", user_year, day + 1);
          break;

        case 9:
          printf("%d-SEP-0%d\n", user_year, day + 1);
          break;

        case 10:
          printf("%d-OCT-0%d\n", user_year, day + 1);
          break;

        case 11:
          printf("%d-NOV-0%d\n", user_year, day + 1);
          break;

        case 12:
          printf("%d-DEC-0%d\n", user_year, day + 1);
          break;

        } // switch end

        // morning rating loop

        do { // beginning of morning do while loop

          printf("   Morning rating (0.0-5.0): ");
          scanf("%lf", &user_morning);

          // validate morning rating

          if (user_morning < 0.0 ||
              user_morning > 5.0) // beginning if loop morning rating
          {

            printf(
                "      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");

            test1 = 0;

          } // end of if loop morning rating

          else if (user_morning >= 0.0 &&
                   user_morning <= 5.0) // beginning of else if loop morning
                                        // rating to make it valid

          {
            test1 = 1;
            sum_morning += user_morning;

          } // end of else if loop morning rating to make it valid

        } while (test1 != 1); // end of morning do while loop

        // Evening rating Loop

        do

        { // beginning of evening do while loop

          printf("   Evening rating (0.0-5.0): ");
          scanf("%lf", &user_even);

          // validate evening rating

          if (user_even < 0.0 ||
              user_even > 5.0) { // beginning if loop morning rating

            printf(
                "      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");

            test2 = 0;

          } // end of if loop morning rating

          else if (user_even >= 0.0 && user_even <= 5.0)

          { // begining of else if loop evening rating to make it valid

            test2 = 1;
            sum_even += user_even;

          } // end of else if loop evening rating to make it valid

        } while (test2 != 1); // end of evening do while loop

      } while (user_morning < 0.0 || user_morning > 5.0 || user_even < 0.0 ||
               user_even > 5.0); // end do while of switch to print out dates
                                 // and days add even to condition after

    printf("\n");
    printf("Summary\n");
    printf("=======\n");

    printf("Morning total rating: %.3f\n", sum_morning);
    printf("Evening total rating: %.3f\n", sum_even);
    printf("----------------------------\n");

    // calculations

    total_sum = sum_morning + sum_even;

    printf("Overall total rating: %.3f\n", total_sum);
    printf("\n");

    // Avg morning rating calculation

    avg_morn = sum_morning / 3;

    printf("Average morning rating:  %.1f\n", avg_morn);

    // Avg evening rating calculation

    avg_even = sum_even / 3;

    printf("Average evening rating:  %.1f\n", avg_even);
    printf("----------------------------\n");

    // Avg combined morning and evening ratings

    total_avg = (avg_even + avg_morn) / 2;

    printf("Average overall rating:  %.1f\n", total_avg);

  } // end of if statement to begin part 2

  return 0;
}
