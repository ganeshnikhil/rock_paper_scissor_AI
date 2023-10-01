#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// basic rock paper scissor game
int count_rock, count_paper, count_scissor;
int computer_score, player_score;

void update_counts(int user_input) {
   if (user_input == 1) {
      count_rock++;
   } else if (user_input == 2) {
      count_paper++;
   } else {
      count_scissor++;
   }

}
int predict() {
   int pred;

   if (count_rock > count_paper  && count_rock > count_scissor ) {
      pred = 2; // Predict Paper to counter Rock
   } else if (count_paper > count_rock  && count_paper > count_scissor ) {
      pred = 3; // Predict Scissors to counter Paper
   } else if (count_scissor > count_rock  && count_scissor > count_paper) {
      pred = 1; // Predict Rock to counter Scissors
   } else {
         pred = rand() % 3 + 1; // If no last move, use random prediction
      }

   return pred;
}

void update_score(int user_input) {
   int predi = predict();
   if (user_input == 1) {
      if (predi == 1) {
         printf("Draw Rock cancels Rock..\n");
      } else if (predi == 2) {
         computer_score++;
         printf("Computer won Rock loss against paper...\n");
      } else if (predi == 3) {
         player_score++;
         printf("You won Rock win against scissors....\n");
      }
   } else if (user_input == 2) {
      if (predi == 1) {
         player_score++;
         printf("You won Paper win against Rock..\n");
      } else if (predi == 2) {
         printf("Draw Paper cancels against Paper....\n");
      } else if (predi == 3) {
         computer_score++;
         printf("Computer won Paper loss against Scissor...\n");
      }
   } else {
      if (predi == 1) {
         computer_score++;
         printf("Computer won Scissor loss against Rock..\n");
      } else if (predi == 2) {
         player_score++;
         printf("You won Scissor win against Paper...\n");
      } else if (predi == 3) {
         printf("Draw Scissor cancels against Scissors....\n");
      }
   }

   printf("Computer score: %d  and Your score: %d\n", computer_score, player_score);
}

int main() {
   int n;
   int win_score = 20;
   srand(time(0));
   printf("1 for rock..\n");
   printf("2 for paper..\n");
   printf("3 for scissor..\n");

   for (int i = 0; i < win_score; i++) {

      do {
         printf("Enter user input:");
         scanf("%d", &n);
      } while (n < 1 || n > 3);
      update_counts(n);
      update_score(n);
   }

   if (player_score > computer_score) {
      printf("You won by %d\n", player_score - computer_score);
   } else if (computer_score > player_score) {
      printf("Computer won by %d\n", computer_score - player_score);
   } else {
      printf("Match Draw, your score %d and computer score %d\n", player_score, computer_score);
   }

   return 0;
}
