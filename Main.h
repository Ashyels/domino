#ifndef main_H
#define main_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>


// typedef area 

typedef struct Elmtlist	*address;

typedef struct Elmtlist
{
	int info1;
	int info2;
	address next;

}	Elmtlist;


typedef struct
{
	address first;
	
}	List;



// void area 

void create_list(List *L);

address alokasi(int value1, int value2);

boolean is_empty(List L);

void insert_first(List *L, address P);

void insert_last(List *L, address P);

void insert_vlast(List *L, int value1, int value2);

void card_display(List L, int player);

void card_print1(int value1, int value2, int x, int y);

void card_print3(int value1, int value2, int x, int y);

void card_print2(int value1, int value2, int x, int y);

void card_print4(int value1, int value2, int x, int y);

void card_shuffle(List *L1, List *L2, List *L3, List *L4);

void turn_display(int turn, int turn_before);

void turn_box_display();

int cursor();

void card_erase_print1(int count);
void card_erase_print2(int count);
void card_erase_print3(int count);
void card_erase_print4(int count);

void value_card_arena(int value1, int value2);
void card_arena_display();

void card_erase(List *L, int player, int value1, int value2);

void card_check(List *L, int player, int choice, int *value1_arena, int *value2_arena);

bool balak_3(List *L, int player);

void enemy_card_check(List *L, int player, int *value_arena1, int *value_arena2);

int check_winner(List L);

void congratulation(int player, const char* player_name[], char my_name[]);

void player_name_display(const char* player_name[], char my_name[]);

void insert_name(char my_name[]);

void play_again(bool *play);

//void card_play(list *L);


// void area 

void colors(int color);


void gotoxy(int x, int y);

void wait( float second);


#endif
