#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define PLAYER_HP 20
#define MONSTER_HP 20



int main() {
	srand(time(NULL));


int player_hp = PLAYER_HP;
int monster_hp = MONSTER_HP;
int action, player_die, monster_die;


while(player_hp > 0 && monster_hp > 0)
{
    printf("Choose Your Action:\n");
    printf("1. Melee Attack\n");
    printf("2. Ranged Attack\n");
    printf("3. Magic Attack\n");
    printf("4. Run Away\n");
    printf("Enter your choice: ");
    scanf_s("%d", &action);


    player_die = rand() % 20 + 1; //20 sided die
    monster_die = rand() % 5 + 1; // 5 sided die



        switch(action) {
        case 1: // Melee Attack
            if (player_die % 2 != 0) { //checks if die is odd 
                printf("You have missed, hitting the monster");
            }
            else if (player_die == 20) {
                printf("You have done critial damage: 2 damage!");
                monster_hp -= 2;
            }
            else {
                printf("You have hit the target, 1 damage");
                monster_hp -= 1;
            }
            break;

        case 2: // ranged attacked
            if (player_die <= 8) {
                printf("Your range attacked has hit, results in 4 damage");
                monster_hp -= 4;
            }
            else {
                printf("You have missed unfortunate");
            }
            break;


        case 3: //Magic Attack
            if (player_die <= 8 && player_die % 2 != 0)
            {
                printf("You have chosen Magic Attack: Hit! Monster takes 6 damage.\n");
                monster_hp -= 6;
            }

            else {
                printf("Youve missed LOL");
            }

            break;

        case 4: // Run Away
            if (player_die > monster_hp) {
                printf("You have chosen to Run Away: Success!\n");
                return 0; // Game ends if player successfully runs away
            }
            else {
                printf("You have chosen to Run Away: Failed!\n");
            }
            break;

        default:
            printf("Invalid choice! Please choose again.\n");
            continue; // Skip monster's turn if invalid choice

            }

        if (monster_hp > 0) {
            printf("The monster attacks! You take %d damage.\n", monster_die);
            player_hp -= monster_die;

            // Display current HP
            printf("Player HP: %d, Monster HP: %d\n\n", player_hp, monster_hp);
        }

        // End of game
        if (player_hp <= 0) {
            printf("You have been defeated by the monster.\n");
        }
        else if (monster_hp <= 0) {
            printf("Congratulations! You have defeated the monster.\n");
        }

      
    }
return 0;

}

