#include "square.h"  
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_SIZE 1024

int current_question;

/*PRE-COMPUTATION PART*/
char question_list[100][500] = {
	//"2 + 3 =", "Combine terms: 12a + 26b -4b – 16a", "Simplify: (4 – 5) – (13 – 18 + 2)", "What is |-26|?", "Multiply: (x – 4)(x + 5)", "345 + 289 =", "If you add 100 to 29898, you obtain?", "Q8)123 + 345 + 723 = ", "Q9)If 15 + 20 = 20 + n, n is equal to ", "Q10)If z + y = 20 and y = 5, what is z?", "Q11)What will be the ones digit in the number 79?", "Q12)What will be the tens digit in number 53?", "Q13)What will be the number obtained on addition of 5 and 3?", "Q14)Ram had 3 oranges in Box A and 4 oranges in Box B. How many total oranges Ram had?", "Q15)Find the missing number. 5 +___ = 11", "Q16)Age of Kishore is 11 years. His elder brother is 10 years older than Kishore what is the age of Kishore's elder brother?", "Q17)Find the missing number. 2 +___ = 5+2", "Q18)Sam has 15 chocolates. Rohan takes 9 chocolates from Sam. How many chocolates Sam have now?", "Q19)There are 32 students in Class 2 Section A. 28 in Section B. How many total students are there in Section A and B?", "Q20)Sonu had Rs. 50 in his wallet. He went to a shop to purchase a notebook of Rs 65. How much less amount Sonu had to purchase the notebook?", "Q21)Find the missing number. 3 +___= 3", "Q22)Find the missing number. 63 - 54 = ____", "Q23)Find the missing number. 27 - ____ = 22", "Q24)43 - ____ = 22", "Q25)How much should be subtracted from 61 to get 29?", "Q26)There are 15 English books and 12 Hindi books in a rack. How many total English and Hindi books are present in the rack?", "Q27)Akshay has 6 red balls, 9 blue balls and 4 white balls. How many balls Akshay has?", "Q28)Raghu had 41 mangoes. Out of 41. 12 mangoes were rotten. How many fresh mangoes Raghu has?", "Q29)Find the missing number. 23 + 12 = 10 + ____", "Q30)In the series. 40. 37. 34. 31. ........ What is the difference between each numbers?", "Q31)A book has 98 pages. Gauri has read 59 pages out of them. How many more pages does she has to read to finish the book?", "Q32)What will be the value of tens digit after the addition of number 53 and 29?", "Q33)Rahul got Rs. 55 as pocket money from his mother and Rs. 22 from his father. How much money Rahul has?", "Q34)Answer the following questions value of a = 19. b = 43 and c = 15 What is the value of a + b?", "Q35)Answer the following questions value of a = 19. b = 43 and c = 15 Fill the correct value in the blank. a + b =  ____- c?", "Q36)Amandeep is reading a story book that has 78 pages. To complete the book. Amandeep has to read 23 more pages. How many pages has Amandeep read so far?", "Q37)40 -____= 24", "Q38)The next number in the series is 34, 29, 24, .....?", "Q39)A truck driver covered a distance of 34 km on Monday. 43 km on Tuesday. How much distance he covered in two days?", "Q40)Sameer has 40 pencils in a box. Joy has 68 pencils in another box. How many pencils do Sameer and Joy have in all?", "Q41)Find the missing ones digit. 5____-35 = 21", "Q42)Shreya has 35 stamps, which is 15 more than the number of stamps Akhill has. How many stamps Akhil has?", "Q43)Ravi invited 67 friends on his birthday.Only 44 of them came. How man' friends did not come?", "Q44)7 + 7 + 7 + 7 + 7 + 7 =____x 7.What is the value of ____?", "Q45)50-25=____?", "Q46)45-24-1=____?", "Q47)49-12-2-1=____?", "Q48)24+59____?", "Q49)35+48+12=____?", "Q50)10*10*10=____?"
	"2 + 3 =", "Combine terms: 12a + 26b -4b – 16a", "Simplify: (4 – 5) – (13 – 18 + 2)", "What is |-26|?", "Multiply: (x – 4)(x + 5)", "345 + 289 =", "If you add 100 to 29898, you obtain?", "123 + 345 + 723 = ", "If 15 + 20 = 20 + n, n is equal to ", "If z + y = 20 and y = 5, what is z?", "What will be the ones digit in the number 79?", "What will be the tens digit in number 53?", "What will be the number obtained on addition of 5 and 3?", "Ram had 3 oranges in Box A and 4 oranges in Box B. How many total oranges Ram had?", "Find the missing number. 5 +___ = 11", "Age of Kishore is 11 years. His elder brother is 10 years older than Kishore what is the age of Kishore's elder brother?", "Find the missing number. 2 +___ = 5+2", "Sam has 15 chocolates. Rohan takes 9 chocolates from Sam. How many chocolates Sam have now?", "There are 32 students in Class 2 Section A. 28 in Section B. How many total students are there in Section A and B?", "Sonu had Rs. 50 in his wallet. He went to a shop to purchase a notebook of Rs 65. How much less amount Sonu had to purchase the notebook?", "Find the missing number. 3 +___= 3", "Find the missing number. 63 - 54 = ____", "Find the missing number. 27 - ____ = 22", "43 - ____ = 22", "How much should be subtracted from 61 to get 29?", "There are 15 English books and 12 Hindi books in a rack. How many total English and Hindi books are present in the rack?", "Akshay has 6 red balls, 9 blue balls and 4 white balls. How many balls Akshay has?", "Raghu had 41 mangoes. Out of 41. 12 mangoes were rotten. How many fresh mangoes Raghu has?", "Find the missing number. 23 + 12 = 10 + ____", "In the series. 40. 37. 34. 31. ........ What is the difference between each numbers?", "A book has 98 pages. Gauri has read 59 pages out of them. How many more pages does she has to read to finish the book?", "What will be the value of tens digit after the addition of number 53 and 29?", "Rahul got Rs. 55 as pocket money from his mother and Rs. 22 from his father. How much money Rahul has?", "Answer the following questions value of a = 19. b = 43 and c = 15 What is the value of a + b?", "Answer the following questions value of a = 19. b = 43 and c = 15 Fill the correct value in the blank. a + b =  ____- c?", "Amandeep is reading a story book that has 78 pages. To complete the book. Amandeep has to read 23 more pages. How many pages has Amandeep read so far?", "40 -____= 24", "The next number in the series is 34, 29, 24, .....?", "A truck driver covered a distance of 34 km on Monday. 43 km on Tuesday. How much distance he covered in two days?", "Sameer has 40 pencils in a box. Joy has 68 pencils in another box. How many pencils do Sameer and Joy have in all?", "Find the missing ones digit. 5____-35 = 21", "Shreya has 35 stamps, which is 15 more than the number of stamps Akhill has. How many stamps Akhil has?", "Ravi invited 67 friends on his birthday.Only 44 of them came. How man' friends did not come?", "7 + 7 + 7 + 7 + 7 + 7 =____x 7.What is the value of ____?", "50-25=____?", "45-24-1=____?", "49-12-2-1=____?", "24+59____?", "35+48+12=____?", "10*10*10=____?"
};

char question_finished[500] = "All Questions are attempted !!";

char ans_list[100][500] = {
	"5", "-4a + 22b", "2", "26", "x2 + x - 20", "634", "30898", "1191", "20", "15", "9", "5", "8", "7", "6", "21", "5", "6", "60", "15","0", "9", "5", "21", "32", "27", "19", "29", "25", "3", "39","8", "77", "62", "77", "55", "16", "19", "77", "108","6", "20", "23","6", "25", "20", "34", "83", "95", "1000"
};

int choose_index[50] = {
	32, 21, 22, 16, 7, 14, 10, 36, 44, 35, 24, 6, 13, 29, 49, 8, 48, 20, 38, 0, 18, 23, 3, 45, 47, 19, 2, 31, 40, 34, 28, 30, 41, 33, 11, 17, 9, 42, 4, 46, 37, 1, 15, 25, 5, 27, 39, 12, 43, 26
};

int active_clients[BUFFER_SIZE];
int client_marks[BUFFER_SIZE];
int client_attempted_questions[BUFFER_SIZE];

/*MAIN*/
square_out *squareproc_1_svc (square_in *inp, struct  svc_req *rqstp) {
	static square_out outp;
	outp.is_finished = 0;

	active_clients[inp->client_id] = 1;

	/*RE-SET USER DATA*/
	if (inp->choice == 5) {
		active_clients[inp->client_id] = 0;
		client_attempted_questions[inp->client_id] = 0;
		client_marks[inp->client_id] = 0;

		outp.last_question = client_attempted_questions[inp->client_id];
		outp.last_marks = client_marks[inp->client_id];
		outp.RANK = 0;
		return (&outp);
	}

	/*IF CHECK IS TRUE THEN CLIENT IS ASKING ABOUT HIS LAST STATUS*/
	if (inp->check == 1) {
		outp.last_question = client_attempted_questions[inp->client_id];
		outp.last_marks = client_marks[inp->client_id];
		return (&outp);
	}

	int randomly_select = 0;
	int total_active_clients, i, cur_rank;
	int current_question = inp->cur_question - 1;

	/*UPDATE MARKS*/
	if (inp->update_marks == 1) {
		client_attempted_questions[inp->client_id] = current_question;
		client_marks[inp->client_id] = inp->send_marks;
	}

	/*FIND RANK OF USER*/
	if (inp->choice == 2) {
		client_attempted_questions[inp->client_id] = current_question;
		client_marks[inp->client_id] = inp->send_marks;

		total_active_clients = 0, i = 0;
		cur_rank = 1;
		for (i = 0; i < BUFFER_SIZE; i++)
			if (active_clients[i] == 1) total_active_clients++;

		for (i = 0; i < BUFFER_SIZE; i++)
			if (i != inp->client_id)
				if (client_marks[i] > client_marks[inp->client_id])
					cur_rank++;

		outp.RANK = cur_rank;
		return (&outp);
	}

	/*SEND NEXT QUESTION*/
	client_attempted_questions[inp->client_id] = current_question;
	client_marks[inp->client_id] = inp->send_marks;

	outp.last_question = client_attempted_questions[inp->client_id];
	outp.last_marks = client_marks[inp->client_id];

	if (current_question >= 50) {
		outp.is_finished = 1;
		strcpy(outp.question, question_finished);
	} else {
		/*RANDOMLY SELECTING QUESTIONS*/

		srand(time(0));
		randomly_select = rand() % 50;
		randomly_select = choose_index[randomly_select];

		strcpy(outp.ans, ans_list[randomly_select]);
		strcpy(outp.question, question_list[randomly_select]);

		//strcpy(outp.ans, ans_list[current_question]);
		//strcpy(outp.question, question_list[current_question]);
	}
	return (&outp);
}
