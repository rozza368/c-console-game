#include <stdio.h>
#include <string.h>

// Random
#include <stdlib.h>
#include <time.h>

typedef struct
{
    char name[32];
    int health;
    int defence;
    int attack;
} ENTITY;

typedef struct
{
    char name[32];
    char description[100];
    int healthIncrease;
    int attackIncrease;
    int defenceIncrease;

} BOOST_ITEM;

int itemAmt = 4;
BOOST_ITEM boostItems[] = {
    // Name, desc, health, atk, defense
    {"Heart Ring", "A red ring that permanently increases health", 5, 0, 0},
    {"Battle Gauntlet", "Looks strong but is slightly damaged", 0, 2, 1},
    {"Hammer", "Simple but powerful", 0, 3, 0},
    {"Shield", "Provides some protection", 0, 0, 2}
};

int enemtAmt = 5;
ENTITY enemies[] = {
    // Name, health, defence, attack
    {"Bear", 8, 1, 4},
    {"Knight", 10, 3, 3},
    {"Possessed Tree", 20, 0, 2},
    {"Armoured Bear", 8, 3, 4},
    {"Long Snake", 5, 0, 4}
};

ENTITY player = {
    .health=10,
    .defence=1,
    .attack=3,
    .name="Player"
};

void setup(); // TODO: set player name from user input
void item();
void fight();

int main()
{
    srand(time);
    printf("Welcome, %s\n", player.name);
}