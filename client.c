#include "square.h"  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR printf ("Error");  exit(1);

#define CLIENT_ADDRESS 1
#define BUFFER_SIZE 500

CLIENT *cl;  
square_in in;  
square_out *out;

int questions;
int current_question;
int user_ans;
int user_marks = 0;

char user_answer_temp[BUFFER_SIZE];
char user_answer[BUFFER_SIZE];

void print_line();
void print_options();

void check_status() {
	
	if ((out = squareproc_1(&in, cl)) == NULL) {ERROR;}

	current_question = out->last_question;
	user_marks = out->last_marks;
}

int check_ans(char temp[]) {
	int i = 0;
	int N = strlen(temp);
	int M = strlen(user_answer);
	int equal = 1;

	if (N != M) return 0;

	for (i = 0; i < N; i++)
		if (user_answer[i] != temp[i])
			equal = 0;

	return equal;
}

void starting_phase() {
	print_line();
	printf("Press 1 to START TEST.\n");
	printf("Press 2 to Exit.\n");
	print_line();

	char c[BUFFER_SIZE];
	scanf("%s", c);

	if (c[0] == '1' && c[1] == '\0') return ;
	if (c[0] == '2' && c[1] == '\0') {
		printf("Exited !!");
		print_line();
		exit(0);
	} else {
		printf("Invalid choice\n");
		print_line();
	}
}

int main (int argc, char **argv) {

	in.check = 1;
	starting_phase();

	in.client_id = CLIENT_ADDRESS;
	if (argc != 2) {  printf("client <localhost> <integer>"); exit (1); }
	cl = clnt_create (argv[1], SQUARE_PROG, SQUARE_VERS, "tcp");

	questions = 50;

	/*GETTING LAST LOGGED IN DATA*/
	check_status();

	in.check = 0;
	current_question += 1;
	in.cur_question = current_question;
	in.send_marks = user_marks;

	/*CANNOT UNDERSTAND WITHOUT PRACTICAL IMPLEMENTATION*/
	while (getchar() != '\n');

	while (1) {

		print_options();

		char x[BUFFER_SIZE];
		scanf("%s", x);

		while (getchar() != '\n');

		if (x[0] == '1' && x[1] == '\0') {
			/*USER SELECTED TO CONTINUE*/
			if ((out = squareproc_1(&in, cl)) == NULL) {ERROR;}

			if (out->is_finished == 1) {
				printf("%s\n", out->question);
			} else {

				printf("Q.%d) %s\n", current_question, out->question);

				fgets(user_answer, BUFFER_SIZE, stdin);

				int N = strlen(user_answer);
				user_answer[N-1] = '\0';

				if (strcmp(out->ans, user_answer) == 0) {
					printf("Correct Ans !!\n");
					user_marks++;
				} else printf("Incorrect Ans !!\n");

				current_question++;

				in.cur_question = current_question;
				in.send_marks = user_marks;

				in.update_marks = 1;
				if ((out = squareproc_1(&in, cl)) == NULL) {ERROR;}
				in.update_marks = 0;
			}
		}

		else if (x[0] == '2' && x[1] == '\0') {
			/*USER WANT TO SEE RANK*/
			in.choice = 2;
			in.cur_question = current_question;
			in.send_marks = user_marks;

			if ((out = squareproc_1(&in, cl)) == NULL) {ERROR;}

			printf("Your Rank = %d\n", out->RANK);

			in.choice = 1;
		}

		else if (x[0] == '3' && x[1] == '\0') {
			/*USER WANT TO SEE MARKS*/
			in.cur_question = current_question;
			in.send_marks = user_marks;

			if ((out = squareproc_1(&in, cl)) == NULL) {ERROR;}

			printf("Your Marks = %d\n", out->last_marks);
		}

		else if (x[0] == '4' && x[1] == '\0') {
			/*USER WANTS TO EXIT*/
			printf("Exited !!");
			print_line();
			exit(0);
		} 

		else if (x[0] == '5' && x[1] == '\0') {
			in.choice = 5;

			current_question = 1;
			user_marks = 0;

			in.cur_question = current_question;
			in.send_marks = user_marks;

			if ((out = squareproc_1(&in, cl)) == NULL) {ERROR;}

			printf("Re-starting . . .!!\n");

			in.choice = 1;
		}

		else {
			printf("Enter Valid input !!\n");
		}
	}

	return 0;
}

void print_line() {
	printf("-------------------------------------------------------------\n");
}

void print_options() {
	print_line();
	printf("press 1 for Continue.\n");
	printf("press 2 to check current Rank.\n");
	printf("press 3 for user's Marks.\n");
	printf("press 4 to EXIT.\n");
	printf("press 5 to Re-start.\n");
	print_line();
}