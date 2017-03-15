


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#include "Main.h"
#include "Colors.h"

//	-----------------------------

int main()
{
	system("Mode 100,50");	system("Color F1");
	srand(time(NULL));
		
	const char* player_name[4];	
	char my_name[10];
	insert_name(my_name);

	awal:;

	List L1;	create_list(&L1); // Player 1 
	List L2;	create_list(&L2); // Player 2 
	List L3;	create_list(&L3); // Player 3 
	List L4;	create_list(&L4); // Player 4 

	card_shuffle(&L1, &L2, &L3, &L4);

	turn_box_display(); // menampilkan kotak giliran (kotoknya aja) 
	card_arena_display(); // menampilkan kartu yang di tengah 
	
	player_name_display(player_name, my_name);
	
	card_display(L1, 1);
	card_display(L2, 2);
	card_display(L3, 3);
	card_display(L4, 4);

	Sleep(300);

	colors(white_black);
	gotoxy(24,27);		printf("ษอออออออออออออออออออออออออออออออออออออออออออออออออป");
	gotoxy(24,28);		printf("บ               Press Anykey to Start             บ");
	gotoxy(24,29);		printf("ศอออออออออออออออออออออออออออออออออออออออออออออออออผ");

	gotoxy(98, 49); 	printf(" ");	getch();

	gotoxy(24,27);		printf("                                                   ");
	gotoxy(24,28);		printf("                                                   ");
	gotoxy(24,29);		printf("                                                   ");

	bool turn[4];
	turn[0] = balak_3(&L1, 1); // mengembalikan nilai true bila balak 3 ada di player 1 
	turn[1] = balak_3(&L2, 2); // mengembalikan nilai true bila balak 3 ada di player 2 
	turn[2] = balak_3(&L3, 3); // mengembalikan nilai true bila balak 3 ada di player 3 
	turn[3] = balak_3(&L4, 4); // mengembalikan nilai true bila balak 3 ada di player 4 

	value_card_arena(3,3); // menampilkan angka balak 3 di tengah arena 

	/* == menampilkan turn ball setelah balak keluar == */
	for(int i=0; i<4; i++)
	{
		if(turn[i] == true)
		{
			turn_display((i+1)%4 + 1 ,i%4 + 1);
			turn[i] = false;
			turn[(i+1)%4] = true;
			i = 4;
		}
	}
	
	/* == deklarsi == */
	int winner = 0; // untuk cek pemenang 
	int card_arena1 = 3; // untuk pertama main, nilai kartu 1 di arena 3 
	int card_arena2 = 3; // untuk pertama main, nilai kartu 2 di arena 3 
	int card_arena_before1 = 3;
	int card_arena_before2 = 3;
	int choice = 0;
	int draw = 0;

	int player[4] = {0,0,0,0};

	while(winner == 0)
	{
		if (turn[0] == true) // == giliran player 1 
		{
			card_arena_before1 = card_arena1;
			card_arena_before2 = card_arena2;
			choice = cursor(); // khusus untuk player 1 bisa milih kartunya 
			card_check(&(L1), 1, choice, &card_arena1, &card_arena2); // apakah kartu yang dipilih ada di arena 
			turn[0] = false; turn[1] = true; // giliran berpindah ke player 2 
			turn_display(2,1); // turn ball berpindah ke player 2 
			value_card_arena(card_arena1, card_arena2); // kartu pada arena berubah 

			/* == ngecek siapakah yang menang == */
			player[0] = check_winner(L1);
	
			if(card_arena1 == card_arena_before1 && card_arena2 == card_arena_before2)
				draw++;
			Sleep(500);
			if (player[0] == 1)
			{
				winner = 1;
				goto end;
			}
		}

		if (turn[1] == true)
		{
			card_arena_before1 = card_arena1;
			card_arena_before2 = card_arena2;
			enemy_card_check(&L2, 2, &card_arena1, &card_arena2); // player 2 cek kartu 
			turn[1] = false; turn[2] = true; // giliran berpindah ke player 3 
			turn_display(3,2); // turn ball berpindah ke player 3 
			value_card_arena(card_arena1, card_arena2); // kartu pada arena berubah

			/* == ngecek siapakah yang menang == */
			player[1] = check_winner(L2);

			if(card_arena1 == card_arena_before1 && card_arena2 == card_arena_before2)
				draw++;
			Sleep(500);
			if (player[1] == 1)
			{
				winner = 2;
				goto end;
			}
		}

		if (turn[2] == true)
		{
			card_arena_before1 = card_arena1;
			card_arena_before2 = card_arena2;

			enemy_card_check(&L3, 3, &card_arena1, &card_arena2);
			turn[2] = false; turn[3] = true;
			turn_display(4,3);
			value_card_arena(card_arena1, card_arena2);

			/* == ngecek siapakah yang menang == */
			player[2] = check_winner(L3);

			if(card_arena1 == card_arena_before1 && card_arena2 == card_arena_before2)
				draw++;
			Sleep(500);
			if (player[2] == 1)
			{
				winner = 3;
				goto end;
			}
		}

		if (turn[3] == true)
		{
			card_arena_before1 = card_arena1;
			card_arena_before2 = card_arena2;

			enemy_card_check(&L4, 4, &card_arena1, &card_arena2);
			turn[3] = false; turn[0] = true;
			turn_display(1,4);
			value_card_arena(card_arena1, card_arena2);

			/* == ngecek siapakah yang menang == */
			player[3] = check_winner(L4);		
			if(card_arena1 == card_arena_before1 && card_arena2 == card_arena_before2)
				draw++;
			Sleep(500);
			if (player[3] == 1)
			{
				winner = 4;
				goto end;
			}
		}

		if(draw >= 8)
			winner = 5;
		else if(draw > 4 && draw < 8)
			draw = 0;
			
		end:;
	}

	congratulation(winner, player_name, my_name);

	bool play = true;
	play_again(&play);
	if(play == true)
		goto awal;

	return 0;
}
