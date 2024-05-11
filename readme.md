# Uno

## How to compile our bot

Compile:
```
cd modulo
make all
```
To run bot_T (our executable):

```
cd ..
./uno bot_A bot_B modulo/bot_T
```

## Introduction

This is a version of the Uno card game, with some differences:

The first is that this is a turn-based game. In other words, a player only acts when it is their turn. Therefore, there will be no option to shout "UNO" when a player only has one card. This rule was left out.

The second is that it is played with cards from the traditional deck. In other words, instead of colors, we will have suits (hearts, spades, diamonds, and clubs) and, instead of special cards (such as "Draw two" or "Pass the turn"), we will have deck cards such as Jack, Queens, King, Ace, and Joker. These cards replace the Special One cards, following the correspondence:
* "BUY 4": C = JOKER
* "BUY 2": V = JACK
* "RETURN" : D = LADY
* "SKIP TURN": R = KING
* "CHANGE THE COLOR": A = ACE (changes the suit)

The game will be played with a single deck. Thus, we will have four cards of one value. For example, 7♥, 7♦, 7♣, 7♠, except the joker, of which there are only two: a red one and a black one. However, to follow the card pattern, the jokers will also have a suit, but they will only be of the suits: ♥ (red) and ♣ (black).

The game is managed by a "simulator" that will control the game, giving the round's turn to the bot. The bot must read the data from the standard input (scanf) in the format specified by the simulator, otherwise, it will get lost and be eliminated from the match. The bot must also send its actions to the simulator via standard output (printf) in the format expected by the simulator, again under penalty of being eliminated from the match.

The cards in the deck are always in the "ValueSuit" format.
In this format, Value is one of the traditional card values, that is, A, 2, 3, 4, 5, 6, 7, 8, 9, 10, V, D, R, and C, and Suit is one of the following suits: ♥, ♦, ♣, ♠.

Suits are characters in extended ascii format, which have a representation greater than one byte (char). This means that they must be treated as if they were strings.

The logic presented in this template aims to illustrate the input and output of data from a bot. It's up to you to improve the logic of your bot's actions.

Good game!!!

## About the project

This project was done in collaboration with [Wisla Argolo](https://github.com/wislaargolo) and [Rubens Matheus](https://github.com/RubensMatheus), it was our final assignment for the course "Programming Techniques Introduction" in IMD, and our teacher gave us the following files: bot_A, bot_t, and the uno(simulator), our goal was to build a bot capable of beating bot_A and bot_B, we name our bot bot_T.

## What you will find

Our teacher gave us 6 files

- `readme.md`: this file.
- `bot_A.c`: initial template with explanations for creating a bot.
- `bot_B.c`: contains the same content as `bot_A.c`, allowing you to have a backup of the explanations.
- `bot_A`: executable with basic behavior for testing purposes.
- `bot_B`: same executable `bot_A`, but another name so you can put one to play with the other.
- `uno`: Uno game manager program.

Besides what was given by our teacher, you'll find a folder called "modulo" with our files

- `auxi.c`: responsible for making actions, like returning and buying cards.
- `carta.c`: responsible for creating cards and monitoring actions.
- `debug.c`: a debug file
- `estrategia.c`: responsible for making strategic decisions, like what card to play.
- `main.c`: main file, contains all actions, once they are called, the other files are used.
- `mao.c`: responsible for storing our deck of cards during the game.
- `bot_T`: Our bot

The files `uno`, `bot_A`, `bot_B` and `bot_T` are executable in the Linux format (they do not work on other OS). You must therefore work on Linux or WSL (over Windows).

To get an idea of how the game works, call the `uno` program by clicking on the button "Run"

https://replit.com/@GABRIELSILVA247/UnoProject?v=1

The console will display the sequence of actions performed by the bots.
