#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
void randomize() {
	srand(time(NULL));
}
void print_board(int board[]){
	printf("+---------+---------+---------+\n");
	for (int line=0; line<9; line++) {
		putchar('|');
		for (int col=0; col<9; col++) {
			int c= board[line*9+col];
			if (0==c) {
				printf(" . ");
			} else {
				printf(" %d ",c);
			}
			if (0==(col+1)%3) {
				putchar('|');
			}
		}
		printf("\n");
		if (0==(line+1)%3) {
			printf("+---------+---------+---------+\n");
		}
	}
}
int convert_bitwise(long matches){
	for (int i=0; i<9; i++) {
		long mask = 1 << i;
		if (mask == (mask & matches)) {
			return i+1;
		}
	}
	return 0;
}
int random_convert_bitwise(long matches){
	int count = 0;
	int m[10]= { 0 };
	for (int i=0; i<9; i++) {
		long mask = 1 << i;
		if (mask == (mask & matches)) {
			m[count]=i+1;
			count++;
		}
	}
	if (count==0) {
		return 0;
	} else {
		int match;
		int randint=0;
		do {
			randint = rand() % 9;
		} while (m[randint]==0);
		match=m[randint];
		return match;
	}
}
long poss_matches(int* board, int position) {
	if (board[position]!=0) {
		return 0;
	}
	int row = floor((double)position / 9.0);
	int row_offset = row % 3;
	int column = position % 9;
	int column_offset = column % 3;
	long mask = 0x1FF;
	for (int i=0; i<9; i++) {
		int pos = i+(row*9);
		if (board[pos] != 0) {
			long eliminate_number = 1 << (board[pos]-1);
			mask &= ~eliminate_number;
		}
	}
	for (int i=0; i<9; i++) {
		int pos = (i*9)+column;
		if (board[pos] !=0) {
			long eliminate_number = 1 << (board[pos]-1);
			mask &= ~eliminate_number;
		}
	}
	for (int rowc=0; rowc<3; rowc++) {
		for (int colc=0; colc<3; colc++) {
			int pos=(row-row_offset+rowc)*9+(column-column_offset+colc);
			if (board[pos]!=0) {
			long eliminate_number = 1 << (board[pos]-1);
			mask &= ~eliminate_number;
			}
		}
	}
	return mask;
}
int check_solution(int board[]){
	for (int i=0; i<81; i++){
		if (0==board[i]){
			return 0;
		}
	}
	return 1;
}
int recursive_iterate(int board[]){
	for (int i=0; i<81; i++) {
		if (0==board[i]) {
			long remaining_matches = poss_matches(board,i);
			if (!remaining_matches) {
				return 0;
			}
			while (remaining_matches) {
				int first_match = random_convert_bitwise(remaining_matches);
				remaining_matches = remaining_matches ^ (1 << (first_match-1));
				board[i]=first_match;
				if (check_solution(board)) {
					printf("Board is solved!\n");
					return 99;
				} else {
					int solution = recursive_iterate(board);
					if (99==solution) {
						return solution;
					}
					if (0==solution) {
						board[i]=0;
					}
				}
			}
			return 0;
		}
	}
	return 0;
}	
int main (int argc, char* argv[]) {
	int board[81] = { 0 };
	randomize();
	for (int i=1; i<10; i++) {
		int val;
		do {
			val = (rand() % 9);
		} while (board[val]!=0);
		board[val]=i;
	}
	print_board(board);
	int result = recursive_iterate(board);
	print_board(board);
}