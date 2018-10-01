struct square_in {
	int client_id;
	int cur_question;
	int send_marks;
	int choice;
	int check;
	int update_marks;
};

struct square_out {
	char ans[500];
	char question[500];
	int RANK;
	int last_question;
	int last_marks;
	int is_finished;
};

program
SQUARE_PROG 
	{  version 
	   SQUARE_VERS {
	   square_out SQUAREPROC(square_in) = 1;
		       } = 1;
	} = 0x13451111;
