Virtual Arcade -A C-Based Multi-Game Console

**Virtual Arcade** is a console-based arcade game hub developed in C, bringing together a variety of classic and logic-based games into a single terminal application. Designed as a semester project, 
this arcade serves as an engaging demo of core programming concepts like loops, conditionals, file handling, and data structures — all implemented from scratch.

**Games Included**


1.**Number Guessing Game** : Guess a randomly generated number within a range. 

2.**Hangman**              : Classic letter-guessing word game with a custom ASCII hangman board. 

3.**Quiz Game**            : Choose from categories like films, politics, GK, and YouTube. Includes scoring system.

4.**Number Sequence Game** : Arrange randomly shuffled numbers into ascending order using swaps.

5.**Fortune Teller**       : Enter your birthdate to receive zodiac-based horoscopes.

6.**Tic Tac Toe**          : Two-player grid-based game with winner logic.

7.**Rock Paper Scissors**  : Play against the computer for 5 rounds.

8.**High-Low Dice Game**   : Bet your virtual money based on the outcome of dice rolls.

9.**High-Low Card Game**   : Predict whether the next card in a shuffled deck will be higher or lower.

**Features**

- Modular game architecture using separate functions for each game.
- Text-based UI for easy interaction and reusability.
- Scoring and point system to track performance across games.
- Hangman uses file I/O to randomly select secret words from a dictionary.
- Good use of structs in games like quizzes and cards.

**File Structure**

plaintext
├── Arcade.c          # Main source code file containing all game logic
├── Arcade.exe        # Compiled executable (Windows)
├── Arcade.o          # Object file
├── words.txt         # Word list for Hangman (expected to be in working dir)

**Tech Stack**
Language: C
Libraries Used: stdio.h, stdlib.h, string.h, ctype.h, time.h, math.h
