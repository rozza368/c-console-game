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
    // Name, desc, health, atk, defence
    {"Heart Ring", "A red ring that permanently increases health", 5, 0, 0},
    {"Battle Gauntlet", "Looks strong but is slightly damaged", 0, 2, 1},
    {"Hammer", "Simple but powerful", 0, 3, 0},
    {"Shield", "Provides some protection", 0, 0, 2}
};

int enemyAmt = 5;
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
int fight();

int main()
{
    srand(time);
    printf("Welcome, %s\n", player.name);
    int outcome;
    while (1)
    {
        // Main game loop
        printf("Press enter to roll.\n");
        printf("Your stats: HP %d  ATK %d  DEF %d ", player.health, player.attack, player.defence);
        getchar();
        outcome = rand() % 10;
        if (outcome < 2)
        {
            // 20% chance
            item();
        }
        else if (outcome > 1 && outcome < 7)
        {
            // 50% chance
            if (fight())
            {
                printf("You won!\n");
            }
            else
            {
                printf("You died. Game over.\n");
                break;
            }
        }
        else
        {
            // 30% chance
            printf("Nothing happened.\n");
        }
        printf("\n");
    }
}

void item()
{
    int index = rand() % itemAmt;
    BOOST_ITEM item = boostItems[index];
    printf("You found %s! %s.\n", item.name, item.description);
    printf("HP: +%d  ATK: +%d  DEF: +%d\n", item.healthIncrease, item.attackIncrease, item.defenceIncrease);
    player.health += item.healthIncrease;
    player.defence += item.defenceIncrease;
    player.attack += item.attackIncrease;
}

// return 1 if alive, 0 if dead
int fight()
{
    int index = rand() % enemyAmt;
    ENTITY enemy = enemies[index];
    printf("%s jumped out!\n", enemy.name);
    return 1;
}