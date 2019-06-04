#include"game.h"

void showInitScreen();
void doSomethingWithRank(int timespent, int mode, int word_count);
void startGame(int count, int mode);

struct timeattack_score timeat_score;

void showDefMenu(void) {
	int number1, number2; //�޴� ���� ����, ���� ���� ����

	srand(time(0));

	do {
		do {
			printf("�ߡޡߡޡߡޡߡޡߡޡߡޡߡ�\n");
			printf("��  1) ���ĺ� Ÿ�Ӿ���    ��\n");
			printf("��  2) �ܾ� Ÿ�Ӿ���      ��\n");
			printf("��  3) �ڷ� ����          ��\n");
			printf("�ߡޡߡޡߡޡߡޡߡޡߡޡߡ�\n");

			scanf("%d", &number1);
			while (getchar() != '\n');
			system("cls");

		} while (number1 != 1 && number1 != 2 && number1 != 3);

		if (number1 == 3) {
			break;
		}

		do {
			printf("�ߡޡߡޡߡޡߡޡߡޡߡޡߡ�\n");
			printf("��  1) 5�� �ѽñ�         ��\n");
			printf("��  2) 8�� �ѽñ�         ��\n");
			printf("��  3) 10�� �ѽñ�        ��\n");
			printf("�ߡޡߡޡߡޡߡޡߡޡߡޡߡ�\n");

			scanf("%d", &number2);
			while (getchar() != '\n');
			system("cls");

		} while (number2 != 1 && number2 != 2 && number2 != 3);

		//showInitScreen();

		switch (number1) { // Select Alphabet
		case 1: // alphabet
			if (number2 == 1) { //���ĺ� 5��
				startGame(5, 1);
			} else if (number2 == 2) { //���ĺ� 8��
				startGame(8, 1);
			} else if (number2 == 3) {  //���ĺ� 10��
				startGame(10, 1);
			}
			break;
		case 2: //�ܾ� ����
			if (number2 == 1) { //�ܾ� 5��
				startGame(5, 0);
			} else if (number2 == 2) {
				startGame(8, 0);
			} else if (number2 == 3) {
				startGame(10, 0);
			}
			break;
		}
		printf("\n������ ���� �����մϴ�.\n ��ø� ��ٷ��ּ���");
		Sleep(5000);
		system("cls");
	} while (1);
}

void showInitScreen() {
	//3,2,1 ���� �� ����
	printf("  ���������\n");
	printf("                ��\n");
	printf("                ��\n");
	printf("  ���������\n");
	printf("                ��\n");
	printf("                ��\n");
	printf("  ���������\n");
	Sleep(1000);
	system("cls");

	printf("  ���������\n");
	printf("                ��\n");
	printf("                ��\n");
	printf("  ���������\n");
	printf("  ��              \n");
	printf("  ��              \n");
	printf("  ���������\n");

	Sleep(1000);
	system("cls");

	printf("           ��     \n");
	printf("      ��   ��     \n");
	printf("           ��       \n");
	printf("           ��      \n");
	printf("           ��      \n");
	printf("           ��      \n");
	printf("     ��������   \n");

	Sleep(1000);
	system("cls");
}

void doSomethingWithRank(int timespent, int mode, int word_count) {
	char input_rank;
	int score;

	if (timespent < 11) {
		score = 10 - timespent;
	} else {
		score = 0;
	}

	if (mode) { //alp
		switch (word_count) {
		case 5:
			timeat_score.alp_n1 = score;
			break;
		case 8:
			timeat_score.alp_n2 = score;
			break;
		case 10:
			timeat_score.alp_n3 = score;
			break;
		}
	} else { // word
		switch (word_count) {
		case 5:
			timeat_score.word_n1 = score;
			break;
		case 8:
			timeat_score.word_n2 = score;
			break;
		case 10:
			timeat_score.word_n3 = score;
			break;
		}
	}

	printf("\n�ɸ��ð��� %d �� �̰� ������ %d �� �Դϴ�..\n", timespent, score);
}

void startGame(int count, int isAlphabet) {
	int start, end, timespent, life; //�ð� ��� ����
	int disap[11], arr[11]; //�ܾ� ��������ϴ� ����
	int answer_counter = 0, counter_end = 0; //word count
	char user_input[30], alp[11], answer1; //���ĺ�, �ܾ� ���� �迭

	life = 3; //����ο�

	for (int i = 0; i < 11; i++) { //������� ���� �ʱ�ȭ, ���� ���ĺ� ����
		if (isAlphabet) {
			disap[i] = 0;
			alp[i] = 'a' + rand() % 26;
		} else {
			disap[i] = 0;
			arr[i] = rand() % 9800;
		}
	}

	start = time(0); //�ð� ����

	do {
		printf("�ߡޡߡޡߡޡߡޡߡޡߡޡߡ�\n\n");
		printf("life : ");//����
		if (life == 3) {
			printf("������");
		}
		else if (life == 2) {
			printf("����");
		}
		else if (life == 1) {
			printf("��");
		}

		printf("\n\n");

		for (int i = 0; i < count; i++) {
			if (disap[i] == 0) {
				if (isAlphabet) {
					printf(" %d)    %c      \n\n", i + 1, alp[i]);
				} else {
					printf(" %d)    %s      \n\n", i + 1, word_list[arr[i]]);
				}
			}
		}

		printf("�ߡޡߡޡߡޡߡޡߡޡߡޡߡ�\n\n");

		printf("�Է��Ͻÿ�:");
		if (isAlphabet) {
			scanf("%c", &answer1);
		} else {
			scanf("%s", user_input);
		}
		while (getchar() != '\n');

		for (int i = 0; i < count; i++) {
			if (isAlphabet) {
				if (alp[i] == answer1) {
					disap[i]++;
					answer_counter++;
					counter_end++;
				}
			} else {
				if (!(strcmp(word_list[arr[i]], user_input))) {
					disap[i]++;
					answer_counter++;
					counter_end++;
				}
			}
		}

		if (answer_counter == 0) {
			life--;
		}

		system("cls");

		if (life < 1)
			break;

	} while (counter_end != count);

	end = time(0);//�ð� ��
	timespent = end - start;

	if (life > 1) { //�ɸ��ð� �����ֱ�, ��ŷ���, Ż��
		doSomethingWithRank(timespent, isAlphabet, count);
	}
	else {
		printf("\n�ƽ����� Ż���Դϴ�.\n");
	}
}