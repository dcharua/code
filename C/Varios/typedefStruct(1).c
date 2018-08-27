/*
Gilberto Echeverría

Typedef / Struct
*/

#define _CRT_SECURE_NO_DEPRECATE

#define LIMIT 5

#include <stdio.h>

typedef int entero;

typedef struct monster
{
	int HP;
	int MP;
	float attack;
	float attack_percent;
} monster;


void print_monster(monster mons)
{
	printf("Monster stats:\n");
	printf("\tHP: %d\n", mons.HP);
	printf("\tMP: %d\n", mons.MP);
	printf("\tAtt: %.2f\n", mons.attack);
	printf("\tAtt %%: %.2f\n\n", mons.attack_percent);
}


monster create_monster()
{
	// Static variable so that it does not die when the function finishes
	static monster patito;

	// Fill in the monster data somehow

	return patito;
}


int main()
{
	// Create variables of type "monster"
	monster pikachu;
	// Initialize the data in the struct
	monster lucario = { 300, 10, 5.2, 0.75 };
	monster charizard = { .HP = 300, .MP = 15, .attack = 2.1, .attack_percent = 0.8 };
	// Create an array of type "monster"
	monster horde[LIMIT];

	// Fill the data for Pikachu
	pikachu.HP = 200;
	pikachu.MP = 10;
	pikachu.attack = 2.4;
	pikachu.attack_percent = 0.65;

	printf("Pikachu:\n");
	print_monster(pikachu);
	printf("Lucario:\n");
	print_monster(lucario);
	printf("Charizard:\n");
	print_monster(charizard);

	// Using the array of monsters
	printf("The horde:\n");
	for (int i = 0; i < LIMIT; i++)
	{
		horde[i].HP = 10 + i * 20;
		horde[i].MP = 12;
		horde[i].attack = 4.0;
		horde[i].attack_percent = 0.5 + i * 0.05;
		print_monster(horde[i]);
	}

	return 0;
}