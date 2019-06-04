#include "game.h"	

void now_total_score(struct difficulty_var *diff_var);
void game_title(int);

struct difficulty_var {
	int sleep_time;
	int game_duration;
	int time_attack;
	int com_penalty;
};

struct minigame_score mini_score;

void fight_computer() {
	int input_user_menu, exit_sig = 0;
	int i, x, y;
	char ch;
	srand(time(NULL));
	static struct difficulty_var diff_var = { 0, 0, 0, 0 };

	do {
		game_title(0);
		
		gotoxy(30, 12);
		printf("1. ����\n");	

		gotoxy(30, 14);
		printf("2. ��Ģ\n");

		gotoxy(30, 16);
		printf("3. ���̵� ����\n");

		gotoxy(30, 18);
		printf("4. ȹ���� ���� ����\n");

		gotoxy(30, 20);
		printf("5. ������\n");

		gotoxy(30, 22);
		printf("����� ������? ");
		scanf("%d", &input_user_menu);
		while (getchar() != '\n');

		switch (input_user_menu) {
		case 1:
			if (diff_var.sleep_time == 0) {
				game_title(0);
				gotoxy(30, 16);
				printf("���̵��� �������ּ���!");
				Sleep(1000);
				break;
			} else {
				start_game(&diff_var);
			}
			break;
		case 2:
			game_title(0);
			gotoxy(0, 11);
			show_rule();
			gotoxy(6, 23);
			printf("�޴��� ���ư����� �ƹ�Ű�� �Է��ϼ���.");
			scanf("%c", &ch);
			break;
		case 3:
			set_difficulty(&diff_var);
			break;
		case 4:
			now_total_score(&diff_var);
			break;
		case 5: // exit
			exit_sig = 1;
			game_title(0);
			gotoxy(30, 15);
			printf("������ �� ���ʼ�!!");
			Sleep(1500);
			break;
		default:
			printf("�߸� �Է��ϼ̽��ϴ�.\n");
			Sleep(1000);
			break;
		}
	} while (exit_sig != 1);
	return 0;
}

void show_rule() {
	gotoxy(6, 12);
	printf("40�ʵ��� ������ �ܾ �Է��ϼ���.");
	gotoxy(6, 13);
	printf("�ܾ��Է��� 4���̻� �ɸ��� ���ݷ��� �������� �ʽ��ϴ�.");
	gotoxy(6, 14);
	printf("��ǻ�ʹ� ��Ű� ���� �Է������� ���̵��� ���� �г�Ƽ�� �־����ϴ�.");
	gotoxy(6, 15);
	printf("�ܾ� �Է� �� �������� ������ �־����ϴ�.");
	gotoxy(6, 16);
	printf("�ܾ� �Է� �� 3�� ���� 5���� �ܾ ���õ˴ϴ�.");
	gotoxy(6, 17);
	printf("���õ� 5���� �ܾ� �� �ϳ��� �Է��ؾ� �մϴ�.");
	gotoxy(6, 18);
	printf("���� ���ݷ¿� ���� ���а� �����˴ϴ�.");
	gotoxy(6, 19);
	printf("�ܾ�� ���ĺ��� �� �ֽ��ϴ�.");
	gotoxy(6, 21);
	printf("���� : �ܾ� ���� �ð��� �÷��̽ð��� ���Ե˴ϴ�.");
}

void set_difficulty(struct difficulty_var *diff_var) {
	int exit_sig_dif = 0, user_difficult;

	do { // 3�� ȹ���ؾ� ����� ���� ����
		game_title(0);

		gotoxy(34, 13);
		printf("���̵� ����");

		gotoxy(21, 15);
		printf("normal �� 1��, hard�� 2�� �����ϼ���!");

		gotoxy(22, 17);
		printf("�ش��ϴ� ���̵� ��ȣ�� �Է��ϼ���: ");
		scanf("%d", &user_difficult);
		while (getchar() != '\n');
		switch (user_difficult) {
		case 1: //normal
			diff_var->sleep_time = 7000;
			diff_var->game_duration = 50;
			diff_var->time_attack = 7;
			diff_var->com_penalty = 3;
			exit_sig_dif = 1;
			break;
		case 2: //Hard
			if (mini_score.fight_computer_lock_info < 2) {
				gotoxy(3, 19);
				printf("����� ���̵��� ���� ���̵����� 2�� �̻� �÷����ϼž� ������ �� �ֽ��ϴ�.");
				Sleep(3000);
				break;
			}
			else {
				diff_var->sleep_time = 3000;
				diff_var->game_duration = 30;
				diff_var->time_attack = 4;
				diff_var->com_penalty = 1;
				exit_sig_dif = 1;
				break;
			}
		default:
			printf("�߸� �Է��ϼ̽��ϴ�.\n");
		}
	} while (exit_sig_dif != 1);
}

void start_game(struct difficulty_var *diff_var) {
	char user_input[30], computer_input[30];
	int user_power = 0, computer_power = 0, i, n = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, rand_number = 0, array[5], judgement, user_burf, computer_burf, burf;

	game_title(1);

	for (i = 0; i < 3; i++) {
		gotoxy(36, 5);
		printf("%d...", 3 - i);
		Sleep(1000);
	}
	gotoxy(36, 5);
	printf("����!");
	Sleep(1000);

	game_title(1);

	t3 = time(0);
	do {
		user_burf = 0;
		computer_burf = 0;
		for (i = 0; i < 5; i++) {
			array[i] = rand() % MAX_WORD;
			gotoxy((rand() % 60) + 5, (rand() % 8) + 2);
			printf("%s", word_list[array[i]]);
		}
		Sleep(diff_var->sleep_time);		// ���̵��� ���� �ð� ���� 5�� �ܾ� ���
		game_title(1);
		burf = rand() % 6;		// ���� ����
		switch (burf) {
		case(0):
			gotoxy(28, 5);
			printf("��... �̹��� �� �ܾ");
			break;
		case(1):
			gotoxy(24, 5);
			printf("�ʹ� ���� �ɸ��°� �ƴϾ�?");
			break;		// 33% Ȯ���� ���� X
		case(2):
			gotoxy(12, 4);
			printf("�������� ���׳װ� ��ſ��� ���𰡸� �������ϴ�.");
			gotoxy(12, 6);
			printf("�ߵ�! ����� ���ݷ��� 1 �����մϴ�.");
			user_burf--;
			break;
		case(3):
			gotoxy(12, 4);
			printf("�������� ���׳װ� ��ſ��� ���𰡸� �������ϴ�.");
			gotoxy(12, 6);
			printf("������ ����� ��ϴ�. ����� ���ݷ��� 1 �����մϴ�.");
			user_burf++;
			break;
		case(4):
			gotoxy(12, 4);
			printf("�������� ���׳װ� ��ǻ�Ϳ��� ���𰡸� �������ϴ�.");
			gotoxy(12, 6);
			printf("emp�ߵ�! ��ǻ���� ���ݷ��� 2 �����մϴ�.");
			computer_burf -= 2;
			break;
		case(5):
			gotoxy(12, 4);
			printf("�������� ���׳װ� ��ǻ�Ϳ��� ���𰡸� �������ϴ�.");
			gotoxy(12, 6);
			printf("��ǻ�Ͱ� ���͸��� ������ϴ�. ��ǻ���� ���ݷ��� 1 �����մϴ�.");
			computer_burf++;
		}

		gotoxy(18, 14);
		printf("�ܾ �Է��ϼ���(exit : �������� �ʰ� ������)");
		gotoxy(35, 15);
		t1 = time(0);
		fgets(user_input, 30, stdin);
		t2 = time(0);
		user_input[strlen(user_input) - 1] = 0;

		for (i = 0; i < 30; i++) {
			if (user_input[i] == 0) {
				n = i + user_burf;
				break;
			}
		}
		judgement = 0;
		if (!(strcmp(user_input, "exit"))) {
			break;
		}
		if (t2 - t1 >= diff_var->time_attack) {
			game_title(1);
			gotoxy(30, 12);
			printf("�ð� �ʰ��Ǿ����ϴ�.");
			judgement++;
		}
		else if (!(!strcmp(user_input, word_list[array[0]]) || !strcmp(user_input, word_list[array[1]]) || !strcmp(user_input, word_list[array[2]]) || !strcmp(user_input, word_list[array[3]]) || !strcmp(user_input, word_list[array[4]]))) {
			game_title(1);
			gotoxy(26, 12);
			printf("���õ� �ܾ�� ���� �ʽ��ϴ�.");
			judgement++;
		}
		if (judgement == 0) {	// judgement �� 0 �ʰ��� ��� ���ݷ� �������� ����
			game_title(1);
			user_power += n;
		}

		rand_number = rand() % MAX_WORD;
		word_list[rand_number];


		for (i = 0; i < 30; i++) {
			if (word_list[rand_number][i] == 0) {
				n = i - (diff_var->com_penalty) + computer_burf;
				break;
			}
		}
		computer_power += n;

		gotoxy(10, 14);
		printf("����ڰ� %s �� �Է��Ͽ� ���ݷ��� %d �� �Ǿ����ϴ�.", user_input, user_power);
		gotoxy(10, 16);
		printf("��ǻ�Ͱ� %s �� �Է��Ͽ� ���ݷ��� %d �� �Ǿ����ϴ�.", word_list[rand_number], computer_power);
		t4 = time(0);
	} while (t4 - t3 < (diff_var->game_duration));
	Sleep(2000);
	game_title(1);
	gotoxy(15, 14);
	printf("����� ���ݷ��� %d �̰� ��ǻ���� ���ݷ��� %d �Դϴ�.", user_power, computer_power);		// �Է¿� ���� ��� ���
	(mini_score.fight_computer_lock_info)++;
	gotoxy(19, 17);
	if (user_power > computer_power) {
		printf("�е����� ���� ���̷� ����� �¸��ϼ̽��ϴ�.");
		if (diff_var->sleep_time == 7000) // ���̵� ���� ���� ȹ�� ����ȭ
			(mini_score.fight_computer) += 2;
		else
			(mini_score.fight_computer) += 3;
	}
	else if (user_power == computer_power) {
		printf("��ǻ�͸� �������� ��ŵ� �̳� �������� ���ϴ�.");
		if (diff_var->sleep_time == 3000)
			(mini_score.fight_computer) -= 1;
	}
	else if (user_power < computer_power) {
		printf("������ ����� ���� ��ǻ�ʹ� �⻵�մϴ�.");
		if (diff_var->sleep_time == 7000)
			(mini_score.fight_computer) -= 3;
		else
			(mini_score.fight_computer) -= 5;
	}
	Sleep(3000);
}

void now_total_score(struct difficulty_var *diff_var) {
	char ch;

	game_title(0);
	gotoxy(31, 12);
	printf("���� ���ھ� : %d", mini_score.fight_computer);

	gotoxy(27, 14);
	printf("���� ���ھ ���� ȣĪ");

	if (mini_score.fight_computer < -20) {					// ~ -20
		gotoxy(31, 16);
		printf("��ǻ���� �ϼ���");
	}
	else if (mini_score.fight_computer < 0) {				// -20 ~ 0
		gotoxy(30, 16);
		printf("��ǻ�Ϳ� ������ ��");
	}
	else if (mini_score.fight_computer < 5) {				// 0~5
		gotoxy(34, 16);								
		printf("������");
	}
	else if (mini_score.fight_computer < 10) {				// 5~10
		gotoxy(28, 16);
		printf("��ǻ�͸� ������Ų ��");
	}
	else {													// 10~
		gotoxy(25, 16);
		printf("��ǻ�Ϳ� ������ Ǯ����� ��");
	}
	gotoxy(19, 18);
	printf("�޴��� ���ư����� �ƹ�Ű�� �Է��ϼ���.");
	scanf("%c", &ch);
}

void game_title(int select)
{
	int i, x, y;

	system("cls");

	x = 0;
	y = 0;
	gotoxy(x, y);
	printf("��");
	for (i = 0; i < 38; i++)
		printf("��");
	printf("��");

	for (i = 1; i < 11; i++)
	{
		y++;
		gotoxy(x, y);
		printf("��");

		if (i == 5 && select==0)
		{
			gotoxy(31, i);
			printf("��ǻ�Ϳ� ����ϱ�\n");
		}

		x += 78;
		gotoxy(x, y);
		printf("��");
		x = 0;
	}

	gotoxy(x, y);
	printf("��");
	for (i = 0; i < 38; i++)
		printf("��");
	printf("��");

	gotoxy(0, 0);
}