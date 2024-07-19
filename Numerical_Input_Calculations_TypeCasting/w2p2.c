#include <stdio.h>
int main(void) {

  double sfee, dbalance, uinput;

  double
      roundsfee; // can delete it and just use sfee but doing it for my own use

  int centsbalance, toonies, loonies, quarters, dimes, nickles, pennies;

  // initial print f statements
  printf("Change Maker Machine\n");
  printf("====================\n");
  printf("Enter dollars and cents amount to convert to coins: $");

  // User input
  scanf("%lf", &uinput);

  // Service fee calculation

  sfee = uinput * 0.05;

  // printf("sfee=%lf\n", sfee); //for own use

  // Round sevice fee to whole number

  roundsfee = sfee + 0.005;

  // printf("roundsfee=%lf\n", roundsfee); //for own use

  printf("Service fee (5.0 percent): %.2lf\n", roundsfee);

  // Calculation for balance to dispense

  dbalance = uinput - roundsfee;

  // printf("dbalance=%lf\n", dbalance); //for own use

  printf("Balance to dispense: $%.2lf\n", dbalance);
  printf("\n");

  // round balance
  dbalance += 0.005;

  // printf("dbalance=%lf\n", dbalance); //for own use

  // Convert balance to cents and int

  centsbalance = dbalance * 100;

  // Toonies calculation

  toonies = 942 / 200;
  centsbalance = 942 % 200;

  printf("$2.00 Toonies  X %d (remaining: $%.2lf)\n", toonies,
         (double)centsbalance / 100);

  // Loonies calculation

  loonies = centsbalance / 100;
  centsbalance = centsbalance % 100;

  printf("$1.00 Loonies  X %d (remaining: $%.2lf)\n", loonies,
         (double)centsbalance / 100);

  // Quarters calculation

  quarters = centsbalance / 25;
  centsbalance = centsbalance % 25;

  printf("$0.25 Quarters X %d (remaining: $%.2lf)\n", quarters,
         (double)centsbalance / 100);

  // Dimes calaculation

  dimes = centsbalance / 10;
  centsbalance = centsbalance % 10;

  printf("$0.10 Dimes    X %d (remaining: $%.2lf)\n", dimes,
         (double)centsbalance / 100);

  // Nickles calculation

  nickles = centsbalance / 5;
  centsbalance = centsbalance % 5;

  printf("$0.05 Nickels  X %d (remaining: $%.2lf)\n", nickles,
         (double)centsbalance / 100);

  // Pennies calculation

  pennies = centsbalance / 1;
  centsbalance = centsbalance % 1;

  printf("$0.01 Pennies  X %d (remaining: $%.2lf)\n", pennies,
         (double)centsbalance / 100);

  printf("\n");

  printf("All coins dispensed!\n");

  return 0;
}
