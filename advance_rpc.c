#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// advance rock paper scissor game
int count_rock, count_paper, count_scissor;
int computer_score, player_score;
int last_player_move = 0;
int current_player_move = 0;
int threshold = 2;
int flag=0;

void swap() {
   int temp;
   temp = last_player_move;
   last_player_move = current_player_move;
   current_player_move = temp;
}

void update_counts(int user_input) {
   if (user_input == 1) {
      count_rock++;
   } else if (user_input == 2) {
      count_paper++;
   } else {
      count_scissor++;
   }
   // Implement tit-for-tat strategies by capturing the previous move of the player.
   swap();
   current_player_move = user_input;
   //printf("current move:%d and last move:%d\n", current_player_move, last_player_move);
}

int predict(int current) {
   int pred;
   // Adaptive threshold strategies
   // After each round, update the threshold based on the difference between computer_score and player_score
   int score_difference = player_score - computer_score;
   int total_draw = current - (player_score + computer_score);
   // it it losses 5 more than player and same for draw the match
   if (score_difference >= 5 || total_draw >= 5) {
      //decrement threshold to adjust the computer game play when he is lossing or drawing match
      if (flag==0){
         threshold--;
         if (threshold==-2){
            flag=1;
           }
      }
      // increment threshold to ajust the computer game play when he is lossing or drawing mathc
      else if(flag==1){
         threshold++;
         if (threshold==2){
            flag=0;
         }
      }
    }
      last_player_move=0;
      //printf("threshold:%d\n", threshold);
   }

   // You can experiment with different threshold values
   if (count_rock > count_paper + threshold && count_rock > count_scissor + threshold) {
      pred = 2; // Predict Paper to counter Rock
   } else if (count_paper > count_rock + threshold && count_paper > count_scissor + threshold) {
      pred = 3; // Predict Scissors to counter Paper
   } else if (count_scissor > count_rock + threshold && count_scissor > count_paper + threshold) {
      pred = 1; // Predict Rock to counter Scissors
   } else {
      //printf("last move:%d\n", last_player_move);
      // Implement "Tit-for-Tat" strategy
      if (last_player_move == 1) {
         pred = 2; // Predict Paper
      } else if (last_player_move == 2) {
         pred = 3; // Predict Scissors
      } else if (last_player_move == 3) {
         pred = 1; // Predict Rock
      } else {
         pred = rand() % 3 + 1; // If no last move, use random prediction
      }
   }

   return pred;
}

void update_score(int user_input, int current) {
   int predi = predict(current);

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
      update_score(n, i);
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
