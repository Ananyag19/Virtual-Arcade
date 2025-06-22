#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <string.h>
char guessWord();
int isAlreadyGuessed(char);
int setBlanks(char);
int checkIfWon();
void printBoard();
void pickword();
void reset();
int playAgain();
int isInWord(char, char*);


char* secret = NULL;
char* blanks = NULL;
char* guessingBank = NULL;

int position;
int length;
char* board[] =
{"  O", "  O\n  |", "  O\n /|", "  O\n /|\\", "  O\n /|\\\n /", "  O\n /|\\\n / \\",};


int numberGuessingGame(int lower, int upper)

{
    srand(time(0));
    int randomNumber = (rand() % (upper - lower + 1)) + lower;

    int guess, attempts = 0;

    printf("Welcome to the Number Guessing Game!\n");
    printf("I have selected a number between %d and %d. Try to guess it!\n", lower, upper);

    do
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess == randomNumber)
        {
            printf("Congratulations! You guessed the correct number in %d attempts.\n", attempts);
            return 1;
        } else if (guess < randomNumber)
        {
            printf("Too low! Try again.\n");
        } else
        {
            printf("Too high! Try again.\n");
        }

    }
    while (1);
}
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to check if the array is sorted
int isArraySorted(int arr[], int size)
{
    for (int i = 1; i < size; i++)
        {
        if (arr[i - 1] > arr[i])
        {
            return 0; // Array is not sorted
        }
    }
    return 1; // Array is sorted
}
typedef struct
{
    char question[200];
    char optionA[50];
    char optionB[50];
    char optionC[50];
    char optionD[50];
    char correctAnswer;
}
MultipleChoiceQuestion;

int askMultipleChoiceQuestions(MultipleChoiceQuestion questions[], int numQuestions)
{
    int score = 0;

    for (int i = 0; i < numQuestions; ++i)
        {
        printf("%d. %s\n", i + 1, questions[i].question);
        printf("   A. %s\n", questions[i].optionA);
        printf("   B. %s\n", questions[i].optionB);
        printf("   C. %s\n", questions[i].optionC);
        printf("   D. %s\n", questions[i].optionD);

        char userAnswer;
        printf("Your answer (A/B/C/D): ");
        scanf(" %c", &userAnswer);

        if (userAnswer == questions[i].correctAnswer)
            {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %c.\n", questions[i].correctAnswer);
        }
    }

    return score;
}

int quizzgameplay()
{
    // Define multiple-choice questions for each category
    MultipleChoiceQuestion filmsQuestions[] =
    {
        {"Complete the quote from Mohabbatein: 'Parampara. Pratishtha. __________.'", "Anushasan", "Prem", "Ishq", "Safalta", 'A'},
        {"Who played the role of 'Munna Bhai' in the film 'Munna Bhai M.B.B.S.'?", "Aamir Khan", "Salman Khan", "Sanjay Dutt", "Shah Rukh Khan", 'C'},
        {"Which actress made her Bollywood debut with the film 'Dhadak'?", "Alia Bhatt", "Sara Ali Khan", "Kangana Ranaut", "Jhanvi Kapoor", 'D'},
        {"Who directed the film 'Zindagi Na Milegi Dobara'?", "Karan Johar", "Anurag Kashyap", "Imtiaz Ali", "Zoya Akhtar", 'D'}
    };

    MultipleChoiceQuestion politicsQuestions[] =
    {
        {"Who is the recently formed CM of MP?", "Shivraj Singh Chouhan", "Kamal Nath", "Digvijaya Singh", "Mohan Yadav", 'D'},
        {"The minimum age of the voter in India is?", "16", "18", "21", "25", 'B'},
        {"The members of the Rajya Sabha are elected for a term of five years? (T/F)", "True", "False", "", "", 'F'},
        {"'Eknath Shinde' is CM of which state?", "Maharashtra", "Gujarat", "Rajasthan", "Karnataka", 'A'}
    };

    MultipleChoiceQuestion gkQuestions[] =
    {
        {"Name the National tree of India?", "Peepal tree", "Banyan tree", "Neem tree", "Mango tree", 'B'},
        {"What is the largest ocean on Earth?", "Atlantic Ocean", "Indian Ocean", "Arctic Ocean", "The Pacific Ocean", 'D'},
        {"What is the smallest planet in our solar system?", "Venus", "Earth", "Mercury", "Mars", 'C'},
        {"Who invented the light bulb?", "Nikola Tesla", "Thomas Edison", "Alexander Graham Bell", "Albert Einstein", 'B'}
    };

    MultipleChoiceQuestion youtubeQuestions[] =
    {
        {"Biggest YouTuber in India?", "CarryMinati", "Technical Guruji", "BB Ki Vines", "Ashish Chanchlani", 'A'},
        {"The YouTuber who recently was the runner up in Bigg Boss?", "CarryMinati", "Bhuvan Bam", "Ashish Chanchlani", "Abhishek Malhan", 'D'},
        {"When was YouTube invented?", "2000", "2002", "2005", "2008", 'C'},
        {"Who is the biggest YouTuber in the world?", "PewDiePie", "T-Series", "MrBeast", "Dude Perfect", 'C'}
    };

    int totalScore = 0;
    char category[50];

    printf("Welcome to the Quiz Game!\n");
    printf("Choose a category: 'films', 'politics', 'gk', 'youtube'\n");
    scanf("%s", category);

    if (strcmp(category, "films") == 0)
        {
        totalScore += askMultipleChoiceQuestions(filmsQuestions, sizeof(filmsQuestions) / sizeof(filmsQuestions[0]));
    } else if (strcmp(category, "politics") == 0)
    {
        totalScore += askMultipleChoiceQuestions(politicsQuestions, sizeof(politicsQuestions) / sizeof(politicsQuestions[0]));
    } else if (strcmp(category, "gk") == 0)
    {
        totalScore += askMultipleChoiceQuestions(gkQuestions, sizeof(gkQuestions) / sizeof(gkQuestions[0]));
    } else if (strcmp(category, "youtube") == 0)
    {
        totalScore += askMultipleChoiceQuestions(youtubeQuestions, sizeof(youtubeQuestions) / sizeof(youtubeQuestions[0]));
    } else
    {
        printf("Invalid category. Please choose 'films', 'politics', 'gk', or 'youtube'.\n");
    }

    printf("Your total score is: %d out of 4\n", totalScore);

    return 0;
}
// Function to print the array
void printArrayy(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to check if the array is sorted
int isArraySortedd(int arr[], int size)
{
    for (int i = 1; i < size; i++)
        {
        if (arr[i - 1] > arr[i])
        {
            return 0; // Array is not sorted
        }
    }
    return 1; // Array is sorted
}

int numberseqgame()
{
    srand(time(NULL));

    const int size = 5; // You can change the size of the array

    // Generate an array of random numbers
    int numbers[size];
    for (int i = 0; i < size; i++)
        {
        numbers[i] = rand() % 100; // Generate random numbers between 0 and 99
    }

    printf("Welcome to the Number Arranging Game!\n");
    printf("Try to arrange the numbers in ascending order.\n");

    // Display the initial array
    printArrayy(numbers, size);

    int moveCount = 0;

    while (!isArraySortedd(numbers, size))
        {
        int pos1, pos2;

        // Get positions to swap from the player
        printf("Enter two positions to swap (space-separated): ");
        scanf("%d %d", &pos1, &pos2);

        // Perform the swap
        int temp = numbers[pos1];
        numbers[pos1] = numbers[pos2];
        numbers[pos2] = temp;

        // Display the updated array
        printArrayy(numbers, size);

        moveCount++;
    }

    printf("Congratulations! You arranged the numbers in %d moves.\n", moveCount);

    return 0;
}

int generateComputerMove()
{
    return rand() % 3 + 1; // 1 for Rock, 2 for Paper, 3 for Scissors
}

// Function to determine the winner of a round
int determineWinner(int playerMove, int computerMove)
{
    if (playerMove == computerMove)
    {
        return 0; // It's a tie
    } else if ((playerMove == 1 && computerMove == 3) || (playerMove == 2 && computerMove == 1) || (playerMove == 3 && computerMove == 2))
    {
        return 1; // Player wins
    } else
    {
        return -1; // Computer wins
    }
}



int Rockpaperscissors()
{
    srand(time(NULL));

    printf("Welcome to the Rock, Paper, Scissors Game!\n");

    int playerScore = 0;

    for (int round = 1; round <= 5; ++round)
    {
        printf("\nRound %d\n", round);


        int playerMove;
        printf("Enter your move (1 for Rock, 2 for Paper, 3 for Scissors): ");
        scanf("%d", &playerMove);

        // Validate user input
        if (playerMove < 1 || playerMove > 3)
        {
            printf("Invalid move. Please enter 1, 2, or 3.\n");
            --round; // Repeat the current round
            continue;
        }

        int computerMove = generateComputerMove();

        printf("Computer's move: %d\n", computerMove);

        int result = determineWinner(playerMove, computerMove);

        if (result == 0)
        {
            printf("It's a tie!\n");
        } else if (result == 1)
        {
            printf("You win this round!\n");
            ++playerScore;
        } else
        {
            printf("Computer wins this round!\n");
        }
    }

    printf("\nGame over. Your final score is: %d\n", playerScore);
return 0;
}


char Board[3][3];
void initializeBoard()
{
    int i;
    int j;
    for (i = 0; i < 3; i++)
        {
        for (j = 0; j < 3; j++)
            {
            Board[i][j] = '-';
        }
    }
}

void displayBoard()
{
    int i;
    int j;
    printf("\nTic Tac Toe\n");
    for (i = 0; i < 3; i++)
        {
        for (j = 0; j < 3; j++)

        {
            printf("%c ", Board[i][j]);
        }
        printf("\n");
    }
}

int Winner(char symbol)

{
    int i;
    int j;
    for (i = 0; i < 3; i++)

        {
        if (Board[i][0] == symbol && Board[i][1] == symbol && Board[i][2] == symbol)

        {
            return 1;
        }
        if (Board[0][i] == symbol && Board[1][i] == symbol && Board[2][i] == symbol)

        {
            return 1;
        }
    }

    if (Board[0][0] == symbol && Board[1][1] == symbol && Board[2][2] == symbol)
    {
        return 1;
    }
    if (Board[0][2] == symbol && Board[1][1] == symbol && Board[2][0] == symbol)
    {
        return 1;
    }
    return 0;
}

int makeMove(int row, int col, char symbol)

{
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && Board[row][col] == '-')

        {
        Board[row][col] = symbol;
        return 1;
    }
    return 0;
}

int Tictactoe()

{
    int row, col;
    int currentPlayer = 1, moves = 0;
    char symbol;

    initializeBoard();

    while (1)
    {
        displayBoard();

 if (currentPlayer%2 == 1)
    {
        currentPlayer=1;
             symbol = 'X';

        }
 else {
            currentPlayer = 2;
            symbol = 'O';
        }

        printf("Player %d, enter row (0-2) and column (0-2) to place %c: ", currentPlayer, symbol);
        scanf("%d %d", &row, &col);


        if (makeMove(row, col, symbol))

            {
            moves++;
            if (Winner(symbol))
            {
                displayBoard();
                printf("Player %d wins!\n", currentPlayer);
                return 0;
            }
            else if (moves == 3 * 3)
            {
                displayBoard();
                printf("It's a draw!\n");
                return 0;
            }
            currentPlayer++;
        }
        else
        {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}

int Fortuneteller()
{
    int d;
    int y;
    int m;
    int a;
    int p;
    char n[100];
    char s[100];
    char sex;
    printf("enter your date of birth");
    printf("\n");
    printf("YEAR: ");
    scanf("%d",&y);
    printf("MONTH: ");
    scanf("%d",&m);
    printf("DAY: ");
    scanf("%d",&a);
    printf("Enter your Name:");
    scanf("%s",&n);
    printf("Enter Sex:");
    scanf("%s",&s);

    printf("\n");

    p=2023-y;
    printf("Name:%s\n",n);
    printf("sex:%s\n",s);
    printf("age:%d\n",p);
    printf("-----------------------------------------------------------------------------------------------------\n");
     if((m==3&& a>=21)||(m==4&& a<=19))
     {
        printf("your horoscope sign is aries\n");
        printf("Let the stirrings of your heart guide your decisions.Prioritise what brings you joy. If you�ve been avoiding certain    conversations,recognise how sliding things under the carpet is not serving you in any way. PS: Now is a good time to   approach that which has been weighing you down from a space of love and openness.");
     }
     if((m==4&& a>=20)||(m==5&& a<=20))
     {
        printf("your horoscope sign is taurus\n");
        printf("You are a solid 10, Taurus. So, instead of being a Negative Nancy about the given situation, take matters in your hands.We are not implying you mean you should swim upstream or resist the flow in any way. There is grace in accepting life on its terms and trusting the flow. At the same time, it is important to remember that you were not sent here without     power. Contemplate on how you can turn this situation in your favour.");
     }
    if((m==5&& a>=21)||(m==6&& a<=20))
    {
        printf("your horoscope sign is gemini\n");
        printf("Everything seems topsy-turvy at the moment and you don�t know how to make your way out of this mess. Start by changing  your vantage point; by looking for the good in your current situation. Overheard at the cosmic conference: the worst     thing that is happening to you is the best thing that is happening for you. Know that the law of karma is at play, beautiful, and that things will take a turn for the better in ways you cannot imagine.");
     }
     if((m==6&& a>=21)||(m==7&& a<=22))
     {
        printf("your horoscope sign is cancer\n");
        printf(" You lower your standards and undermine your potential. Consider this soulscope as a reminder to take a long, hard look in the mirror and recognise all the ways in which you have been sabotaging your own happiness. Overheard at the cosmic  conference: you deserve the best, beautiful. You deserve to dance the dance of life with somebody who makes you feel seen and celebrated.");
     }
     if((m==7&& a>=23)||(m==8&& a<=22))
     {
        printf("your horoscope sign is leo\n");
        printf("Right now, you are moving through life with joy, with ease, with love. You know you are where you are supposed to be,   and that everything in your life is unfolding in accordance with the divine plan. What is yours cannot pass you by! This is a truth you understand on a soul level. What more,is you are embracing the spirit of play as you recognise each    moment is a celebration!");
     }
     if((m==8&& a>=23)||(m==9&& a<=22))
     {
        printf("your horoscope sign is virgo\n");
        printf("You are on the right track. But, it is not just about creative pursuits for you this month. Health and wellness are     taking centre-stage too. You are in the mood to turn up the volume, to mix it up and to have plenty of fun when you are  burning those calories. ");
     }
     if((m==9&& a>=23)||(m==10&& a<=22))
     {
        printf("your horoscope sign is libra\n");
        printf("Let single-mindedness become your superpower word as you continue to explore the many multiverses, within and without.  If you have recently started your meditation practice, know that feeling distracted in the process is perfectly normal.  Allow the thoughts to come and go as you focus on the clear skies behind the dark clouds. With patience and persistence, you will be able to break free from the old patterns and find stillness exactly where you are.");
     }
     if((m==10&& a>=23)||(m==11&& a<=21))
     {
        printf("your horoscope sign is scorpio\n");
        printf("When you are not turning heads or redefining beauty standards, you are awakening the creative wildfire within you,      bringing more joy and sparkle into the manifest world, and living your highest potential! As such, this chapter of your life is about actively rewriting the old story, dissolving delusions and moving through life with trust, faith and surrender. You understand that what is yours will always will never pass you by and that what did was never meant to be yours.");
     }
    if((m==11&& a>=22)||(m==12&& a<=21))
    {
        printf("your horoscope sign is saggitarius\n");
        printf("The new moon in your sign promises to be all kinds of magical, Sagittarius. For starters, it will bring with itself the opportunity to move, to transition to a better place. So, choose what propels you in the direction of growth, what      supports acceleration. Know that you are fully prepared for the changes that lie ahead and that you are fully prepared  to step into the most embodied version of yourself.");
     }
     if((m==12&& a>=22)||(m==1&& a<=19))
     {
        printf("your horoscope sign is capricon\n");
        printf("You will have to let go many times over. Accept that all things, good, bad, and ugly, come to an end. Accept that       transience is a way of life in the earthly realm. At the same time, accept your need to take a breather, if that is something you are yearning for at the moment. Spending time at an ashram or attending a mindfulness retreat could help you  centre yourself.");
     }
     if((m==1&& a>=20)||(m==2&& a<=18))
     {
        printf("your horoscope sign is aquarius\n");
        printf("It is time to focus your intentions on what you truly want, what you truly desire, what you truly want to create for    yourself as you commit to showing up for your vision and your mission, every single day. Remember, discernment is an    integral part of the manifestation process. Learn to say no to that which does not feel authentic; that which does not  align with the song of your soul. Think of it this way: by saying no to what is not a vibrational match, you are        creating space for what will take you higher!");
     }
     if((m==2&& a>=19)||(m==3&& a<=20))
     {
        printf("your horoscope sign is pisces\n");
        printf("Right now, you are vibrating high, claiming your destiny, and inspiring those around you to reach their fullest         potential. This is what it means to lead by example, Pisces. This is what it means to run a heart-centred enterprise. If you are in the process of calling in your special someone, your divine counterpart, focus not on what you do not want  or what did not work out. Hold the vibration of what you are calling in within every cell, within your DNA, as you move through life with faith, with surrender and with trust.");
     }
}



int rollDice()
{
    return (rand() % 6) + 1;
}

int Dicegame()
{
    srand(time(NULL));

    int balance = 100;
    int bet;
    char choice;

    printf("Welcome to the High-Low Dice Game!\n");
    printf("You start with $%d.\n", balance);

    while (balance > 0)
    {
        printf("Place your bet (minimum $1): $");
        scanf("%d", &bet);

        if (bet < 1 || bet > balance)
        {
            printf("Invalid bet amount!\n");
            continue;
        }

        int dice1 = rollDice();
        int dice2 = rollDice();
        int total = dice1 + dice2;

        printf("The dice show: %d and %d (Total: %d)\n", dice1, dice2, total);

        printf("High (H) or Low (L)? ");
        scanf(" %c", &choice);

        if ((choice == 'H' || choice == 'h') && total > 7)
        {
            printf("You win $%d!\n", bet);
            balance += bet;
        }
        else if ((choice == 'L' || choice == 'l') && total <= 7)
        {
            printf("You win $%d!\n", bet);
            balance += bet;
        }
        else
        {
            printf("You lose $%d!\n", bet);
            balance -= bet;
        }

        printf("Your balance: $%d\n", balance);

        if (balance == 0)
        {
            printf("Sorry, you're out of money!\n");
            break;
        }

        printf("Play again? (Y/N): ");
        scanf(" %c", &choice);

        if (choice == 'N' || choice == 'n')
        {
            printf("Thanks for playing!\n");
            break;
        }
    }

    return 0;
}
#define DECK_SIZE 52

typedef struct
{
    char *rank;
    char *suit;
}
Card;

void initializeDeck(Card deck[]);
void shuffleDeck(Card deck[]);
void printCard(Card card);
int compareCards(Card card1, Card card2);

int HLcard()
{
    Card deck[DECK_SIZE];
    char guess;
    int score = 0;

    srand(time(NULL));

    initializeDeck(deck);
    shuffleDeck(deck);

    for (int i = 0; i < DECK_SIZE - 1; i++)
    {
        Card currentCard = deck[i];
        Card nextCard = deck[i + 1];

        printf("Current card: ");
        printCard(currentCard);

        printf("Higher or lower? (h/l): ");
        scanf(" %c", &guess);

        if (compareCards(currentCard, nextCard) == 1 && guess == 'h')
        {
            printf("Correct!\n");
            score++;
        } else if (compareCards(currentCard, nextCard) == -1 && guess == 'l')
        {
            printf("Correct!\n");
            score++;
        } else
        {
            printf("Wrong! Game over. Your score: %d\n", score);
            break;
        }
    }

    return 0;
}

void initializeDeck(Card deck[])
{
    char *ranks[] =
    {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    char *suits[] =
    {"Hearts", "Diamonds", "Clubs", "Spades"};

    for (int i = 0; i < DECK_SIZE; i++)
    {
        deck[i].rank = ranks[i % 13];
        deck[i].suit = suits[i / 13];
    }
}

void shuffleDeck(Card deck[])
{
    for (int i = DECK_SIZE - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void printCard(Card card)
{
    printf("%s of %s\n", card.rank, card.suit);
}

// Compare two cards and return 1 if card1 is higher, -1 if card2 is higher, and 0 if they are equal.
int compareCards(Card card1, Card card2)
{
    if (atoi(card1.rank) > atoi(card2.rank))
    {
        return 1;
    } else if (atoi(card1.rank) < atoi(card2.rank))
    {
        return -1;
    } else
    {
        return 0;
    }
}


int main()


{
    int result;
    int lower=1;
    int upper=100;
    int x=1;
    int points=10;
    char name[50];

    printf("Welcome to the Arcade!\n");
    printf("Please enter your name : ");
    scanf("%s",name);
    printf("Current points : %d ",points);
    while(1)

    {
        printf("\nEnter 1 to Play Number Guessing Game");
        printf("\nEnter 2 to Play Hangman");
        printf("\nEnter 3 to Play Quizz ");
        printf("\nEnter 4 to Play Number Sequence Game");
        printf("\nEnter 5 to Play Fortune Teller");
        printf("\nEnter 6 to Play Tic Tac Toe");
        printf("\nEnter 7 to Play Rock Paper Scissors");
        printf("\nEnter 8 to High low dice game");
        printf("\nEnter 9 to play High low card game");
         printf("\nEnter 0 to exit");
        printf("\nWhich Game You want to play ");
        scanf("%d",&x);
        switch(x)

        {
            case 1:
            result = numberGuessingGame(lower, upper);

            if (result == 1)

            {
                  printf("Game Over. You Win!\n");
            }
            else

            {
                  printf("Something went wrong.\n");
            }
            points--;
            printf("Total points left : %d",points);

            break;



            case 2:
            puts("HANGMAN:\n");
	        do
            {
                reset();
                while(position < 6)
                {
                    printBoard();
                    char guess = guessWord();
                    if(isAlreadyGuessed(guess)) continue;
                    else if(setBlanks(guess))
                    {
                        if(checkIfWon()) break;
                    }
                    else
                    {
                        guessingBank[position++]=guess;
                    }
                }
                if(position >= 6) printf("You lost the word was %s\n", secret);
            }
            while(playAgain());
            free(secret);
            free(blanks);
            free(guessingBank);
             points--;
            printf("Total points left : %d",points);
            break;




            case 3:
            quizzgameplay();
            points--;
            printf("Total points left : %d",points);
            break;




            case 4:
            numberseqgame();
            points--;
            printf("Total points left : %d",points);
            break;

            case 5:
            Fortuneteller();
            points--;
            printf("Total points left : %d",points);
            break;

            case 6:
            Tictactoe();
            points--;
            printf("Total points left : %d",points);
            break;

            case 7:
            Rockpaperscissors();
            points--;
            printf("Total points left : %d",points);
            break;

            case 8:
            Dicegame();
            points--;
            printf("Total points left : %d",points);
            break;

            case 9:
            HLcard();
            points--;
            printf("Total points left : %d",points);
            break;

            case 0:
            printf("\nThank you for playing in the arcade.");


            return 0;

        }

    }


}

void reset()
{
	position = 0;
	pickword();
}

void printBoard()
{
	puts(board[position]);
	printf("\n%s:\n", blanks);
}

char guessWord()
{
	puts("Enter a letter\n");
	char c = getchar();
	if(getchar() != '\n')
    {
		puts("Please enter only 1 letter next time\n");
		while(getchar() != '\n');
	} else if(isalpha(c)) return tolower(c);
	return guessWord();
}

int isAlreadyGuessed(char guess)
{
	if(isInWord(guess, guessingBank))
    {
		puts("You already guessed that letter\n");
		return 1;
	}
    return 0;
}

int setBlanks(char guess)
{
	int boolean = 0;
	for(int i = 0; i < length; ++i)
    {
		if(secret[i] == guess)
        {
			blanks[i] = guess;
			boolean = 1;
		}
	}
	return boolean;
}

int playAgain()
{
	puts("Enter y to play again\n");
	char c = getchar();
	while(getchar() != '\n');
	return tolower(c) == 'y';
}

int checkIfWon()
{
	if(strcmp(secret, blanks) == 0)
    {
		printf("You got it man! it was %s\n", secret);
		return 1;
	}
    return 0;
}

int isInWord(char guess, char* word)
{
	for(int i = 0; i < position; ++i)
    {
		if(word[i] == guess) return 1;
	}
    return 0;
}

void pickword()
{
	FILE* file;
	int lines = 0;
	char c = 0;

	file = fopen("words.txt", "r");

	while((c=getc(file)) != EOF) if(c == '\n') ++lines;

	fseek(file, 0, SEEK_SET);

	srand(time(NULL));

	int randomLine = 1 + rand() % lines;
	int seekWhere = 0;
	int characters = 0;

	lines = 0;
	c = 0;
	while(lines < randomLine && (c=getc(file)) != EOF)
    {
		if(lines+1 == randomLine)
        {
			++characters;
		}
		else
        {
			++seekWhere;
		}

		if(c == '\n') ++lines;
	}
	--characters;
	length = characters;
	if(secret == NULL && blanks == NULL && guessingBank == NULL)
    {
		secret = (char*) malloc(characters+1);
		blanks = (char*) malloc(characters+1);
		guessingBank = (char*) malloc(7);
	}
	else
    {
		secret = realloc(secret, characters+1);
		blanks = realloc(blanks, characters+1);
	}
	secret[characters] = '\0';
	blanks[characters] = '\0';
	guessingBank[6] = '\0';
	fseek(file, seekWhere, SEEK_SET);
	fread(secret, 1, characters, file);
	for(int i = 0; i < characters; ++i)
    {
		blanks[i] = '-';
	}

	for(int i = 0; i < 6; ++i)
    {
		guessingBank[i] = ' ';
	}
	fclose(file);
}
