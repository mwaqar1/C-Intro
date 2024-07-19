#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_PATH 70
#define MIN_PATH 10

// delcare structure
struct PlayerInfo {
  int nlives;
  char symbol;
  int count_treasure;
  int history_path[MAX_PATH];
  int livesCount;
};

struct GameInfo {
  int max_moves;
  int path_length;
  int bombs[MAX_PATH];
  int treasure[MAX_PATH];

  int gameSymbol[MAX_PATH];
  int treasureCount;
  int movesCount;
  int nextMove;
};

int main() {

  struct PlayerInfo player = {0};
  struct GameInfo game = {0};
  int percent;
  int i;
  int j;
  int const modus = 5;
  int line3 = 0;
  int pathLeft = 0;
  int movePosition = 0;

  printf("================================\n");
  printf("         Treasure Hunt!         \n");
  printf("================================\n");
  printf("\n");
  printf("PLAYER Configuration\n");
  printf("--------------------\n");

  printf("Enter a single character to represent the player: ");
  scanf(" %c", &player.symbol);

  do {
    printf("Set the number of lives: ");
    scanf("%d", &player.nlives);

    if (player.nlives < 1 || player.nlives > 10) {
      printf("     Must be between 1 and 10!\n");
    } else {
      printf("Player configuration set-up is complete\n");
    }
  } while (player.nlives < 1 || player.nlives > 10);

  printf("\n");
  printf("GAME Configuration\n");
  printf("------------------\n");

  do {
    printf("Set the path length (a multiple of 5 between 10-70): ");
    scanf("%d", &game.path_length);

    if (game.path_length < MIN_PATH || game.path_length > MAX_PATH ||
        ((game.path_length % modus)) > 0) {
      printf("     Must be a multiple of 5 and between 10-70!!!\n");
    }

  } while (game.path_length < MIN_PATH || game.path_length > MAX_PATH ||
           (game.path_length % modus) > 0);

  percent = game.path_length * .75;

  do {
    printf("Set the limit for number of moves allowed: ");
    scanf("%d", &game.max_moves);

    if (game.max_moves < player.nlives || game.max_moves > percent) {
      printf("    Value must be between %d and %d\n", player.nlives,
             (int)percent);
    }
  } while (game.max_moves < player.nlives || game.max_moves > percent);

  printf("\n");
  printf("BOMB Placement\n");
  printf("--------------\n");

  printf("Enter the bomb positions in sets of 5 where a value\n");
  printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
  printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.path_length);

  for (i = 0; i < game.path_length; i += modus) {
    printf("   Positions [%2d-%2d]: ", i + 1, i + modus);

    for (j = 0; j < modus; j++) {
      scanf(" %d", &game.bombs[i + j]);
    }
  }

  printf("BOMB placement set\n");
  printf("\n");
  printf("TREASURE Placement\n");
  printf("------------------\n");
  printf("Enter the treasure placements in sets of 5 where a value\n");
  printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
  printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.path_length);

  for (i = 0; i < game.path_length; i += modus) {
    printf("   Positions [%2d-%2d]: ", i + 1, i + modus);
    for (j = 0; j < modus; j++) {
      scanf(" %d", &game.treasure[i + j]);
    }
  }

  // printf summary
  printf("TREASURE placement set\n");
  printf("\n");
  printf("GAME configuration set-up is complete...\n");
  printf("\n");
  printf("------------------------------------\n");
  printf("TREASURE HUNT Configuration Settings\n");
  printf("------------------------------------\n");

  printf("Player:\n");
  printf("   Symbol     : %c\n", player.symbol);
  printf("   Lives      : %d\n", player.nlives);
  printf("   Treasure   : [ready for gameplay]\n");
  printf("   History    : [ready for gameplay]\n");
  printf("\n");
  printf("Game:\n");
  printf("   Path Length: %d", game.path_length);
  printf("\n");

  printf("   Bombs      : ");

  for (i = 0; i < game.path_length; i++) {
    printf("%d", game.bombs[i]);
  }

  printf("\n");
  printf("   Treasure   : ");

  for (i = 0; i < game.path_length; i++) {
    printf("%d", game.treasure[i]);
  }

  printf("\n");
  printf("\n");
  printf("====================================\n");
  printf("~ Get ready to play TREASURE HUNT! ~\n");
  printf("====================================\n");

  // part 2

  printf("\n"); // print out intitial game board
  printf("  -");

  for (i = 0; i < (game.path_length - 1); i++) {
    printf("-");
  }

  printf("\n");

  for (i = 1; i <= game.path_length; i++) {
    if (i == 1) {
      printf("  |");
    } else if (i != 1 && i < 10 && i < (game.path_length)) {
      printf("|");
    } else if (i != 1 && i == 10) {
      line3 = i / 10;
      printf("%d", line3);
    } else if (i != 1 && i < game.path_length && i != game.path_length) {
      printf("|");
    } else if (i != 0 && i == game.path_length) {
      line3 = i / 10;
      printf("%d", line3);
    }
  }

  printf("\n");

  for (i = 1; i <= MIN_PATH; i++) {
    if (i == 1) {
      printf("  %i", i);
    } else if (i != 1 && i < MIN_PATH && i < (MIN_PATH)) {
      printf("%d", i);
    } else if (i != 1 && i == MIN_PATH) {
      line3 = i % 10;
      printf("%d", line3);
    }
  }

  pathLeft = (game.path_length - MIN_PATH);

  for (i = 1; i <= pathLeft; i++) {
    if (i < pathLeft) {
      printf("%d", i);
    } else if (i == pathLeft) {
      line3 = i % 10;
      printf("%d", line3);
    }
  }

  // set up variables before game starts

  player.livesCount = player.nlives;
  game.movesCount = game.max_moves;

  // set all elements player.histoy_path[] to 0;

  for (i = 0; i < game.path_length; i++) {
    player.history_path[i] = 0;
  }

  printf("\n");
  printf("+---------------------------------------------------+\n");
  printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n",
         player.livesCount, game.treasureCount, game.movesCount);
  printf("+---------------------------------------------------+\n");

  // game starts

  while (player.livesCount > 0 && game.movesCount > 0) {
    do {
      printf("Next Move [1-%d]: ", game.path_length);
      scanf("%d", &game.nextMove);

      if (game.nextMove < 1 || game.nextMove > game.path_length) {
        printf("  Out of Range!!!\n");
      }
    } while (game.nextMove < 1 || game.nextMove > game.path_length);

    movePosition = game.nextMove - 1; // decrease user value for game.nextMove
                                      // by 1 and store it in new variables

    printf("\n");

    // check to see if game.nextMove has been entered before

    if (player.history_path[movePosition] == 0) {

      game.movesCount--;

      if (game.bombs[movePosition] == 1 && game.treasure[movePosition] == 1) {
        player.livesCount--;
        game.treasureCount++;
        printf("===============> [&] !!! BOOOOOM !!! [&]\n");
        printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
        game.gameSymbol[movePosition] = 4;
      } else {
        if (game.bombs[movePosition] == 1) {
          player.livesCount--;
          printf("===============> [!] !!! BOOOOOM !!! [!]\n");
          game.gameSymbol[movePosition] = 3;
        } else if (game.treasure[movePosition] == 1) {
          game.treasureCount++;
          printf("===============> [$] $$$ Found Treasure! $$$ [$]\n");
          game.gameSymbol[movePosition] = 2;
        }
      }
      if (game.bombs[movePosition] == 0 && game.treasure[movePosition] == 0) {
        printf("===============> [.] ...Nothing found here... [.]\n");
        game.gameSymbol[movePosition] = 1;
      }

      player.history_path[movePosition] = 1;

    } else // if(p1.historyArray[movePosition] == 1)   //change to else if you
           // want
    {
      printf("===============> Dope! You've been here before!\n");
      game.movesCount = game.movesCount + 0; // delete if not needed
    }

    if (player.livesCount <= 0 || game.movesCount <= 0) {
      printf("\n");
      printf("No more LIVES remaining!");
      printf("\n");
    }

    printf("\n"); // print out intitial game board
    printf("  ");

    for (i = 0; i < game.path_length; i++) {
      if (i == movePosition) {
        printf("%c", player.symbol);
      } else {
        printf(" ");
      }
    }

    printf("\n");
    printf("  ");

    for (i = 0; i < game.path_length; i++) {
      if (i == movePosition) // select for current movePosition symbol
      {
        if (game.gameSymbol[i] == 1) {
          printf(".");
        } else if (game.gameSymbol[i] == 2) {
          printf("$");
        } else if (game.gameSymbol[i] == 3) {
          printf("!");
        } else if (game.gameSymbol[i] == 4) {
          printf("&");
        }

      } else // select for all other values that are not currently the
             // movePosition
      {
        if (player.history_path[i] == 0) {
          // delete ? game.gameSymbol[i] = 0;	//unvisisted locations
          printf("-");
        } else {
          if (game.gameSymbol[i] == 1) {
            printf(".");
          } else if (game.gameSymbol[i] == 2) {
            printf("$");
          } else if (game.gameSymbol[i] == 3) {
            printf("!");
          } else if (game.gameSymbol[i] == 4) {
            printf("&");
          }

        } // end of else for player.history[i]==1
      }
    } // end of for loop

    printf("\n");

    for (i = 1; i <= game.path_length; i++) {
      if (i == 1) {
        printf("  |");
      } else if (i != 1 && i < 10 && i < (game.path_length)) {
        printf("|");
      } else if (i != 1 && i == 10) {
        line3 = i / 10;
        printf("%d", line3);
      } else if (i != 1 && i < game.path_length && i != game.path_length) {
        printf("|");
      } else if (i != 0 && i == game.path_length) {
        line3 = i / 10;
        printf("%d", line3);
      }
    }

    printf("\n");

    for (i = 1; i <= MIN_PATH; i++) {
      if (i == 1) {
        printf("  %i", i);
      } else if (i != 1 && i < MIN_PATH && i < (MIN_PATH)) {
        printf("%d", i);
      } else if (i != 1 && i == MIN_PATH) {
        line3 = i % 10;
        printf("%d", line3);
      }
    }

    pathLeft = (game.path_length - MIN_PATH);

    for (i = 1; i <= pathLeft; i++) {
      if (i < pathLeft) {
        printf("%d", i);
      } else if (i == pathLeft) {
        line3 = i % 10;
        printf("%d", line3);
      }
    }
    printf("\n");
    printf("+---------------------------------------------------+\n");
    printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n",
           player.livesCount, game.treasureCount, game.movesCount);
    printf("+---------------------------------------------------+\n");
  } // end of while loop

  printf("\n");
  printf("##################\n");
  printf("#   Game over!   #\n");
  printf("##################\n");
  printf("\n");
  printf("You should play again and try to beat your score!\n");

  return 0;
}
