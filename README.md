# rock_paper_scissor_AI
# Rock-Paper-Scissors Game with Computer Prediction

`basic_rps.c`
   ## is the basic implimentation of roc paper scissor prediction model .

`advance_rps.c`
   ## is taking more powerfull approach to predict  the player move in rock-paper-scissor 


This is an advanced implementation of the Rock-Paper-Scissors game in C, where the computer tries to predict the player's move and win the match. In addition to predicting the player's move, the program includes adaptive strategies and a threshold mechanism to make the computer's gameplay more dynamic.

## How the Game Works

1. The game is played in rounds, and the first player to reach a certain score threshold (defined as `win_score`) wins the match. The default threshold is set to 20, but you can change it as per your preference.

2. The computer maintains counts of the player's previous moves, specifically for Rock, Paper, and Scissors, using `count_rock`, `count_paper`, and `count_scissor`.

3. The computer keeps track of the player's and its own scores using `player_score` and `computer_score`.

4. The game employs a "Tit-for-Tat" strategy by capturing the previous move of the player. The `last_player_move` and `current_player_move` variables store this information.

5. There is an adaptive threshold mechanism that adjusts the computer's strategy based on the difference in scores between the player and computer, as well as the number of draws in the game. If the computer is losing or drawing the match, it adjusts the prediction threshold to improve its chances.

6. The `predict` function is responsible for predicting the computer's move based on various conditions:
   - If the computer is losing or drawing significantly, it adjusts the threshold to be more aggressive or conservative.
   - If one move (Rock, Paper, or Scissors) is being used significantly more by the player than others, the computer predicts the move that can counter the player's dominant move.
   - If none of the above conditions apply, it employs a "Tit-for-Tat" strategy based on the player's previous move or makes a random prediction.

7. The `update_score` function updates the game scores and provides feedback on the outcome of each round.

8. The game continues for a predefined number of rounds (`win_score`). After each round, the player is prompted to enter their move (1 for Rock, 2 for Paper, and 3 for Scissors).

9. At the end of the game, the program declares the winner based on the scores:
   - If the player's score is higher than the computer's score, the player wins.
   - If the computer's score is higher than the player's score, the computer wins.
   - If both scores are equal, the game is declared a draw.

## How the Computer Predicts

The computer's prediction strategy can be summarized as follows:

- It checks if it should be more aggressive or conservative based on the score difference and the number of draws in the game.
- It looks at the player's previous moves and adjusts its prediction to counter the player's dominant move when appropriate.
- It uses a "Tit-for-Tat" strategy by considering the player's last move.
- When none of the above conditions apply, it makes a random prediction.

## Usage

1. Compile the program using a C compiler, such as GCC: `gcc -o rps_game rps_game.c`.

2. Run the compiled program: `./rps_game`.

3. Follow the on-screen instructions to play the game. Enter 1 for Rock, 2 for Paper, and 3 for Scissors.

4. The game will continue until one player reaches the specified `win_score`.

5. At the end of the game, the winner or a draw will be announced.

Feel free to experiment with different threshold values and strategies to see how the computer's gameplay changes in response to the player's moves and the game's progress. Enjoy the Rock-Paper-Scissors challenge!
