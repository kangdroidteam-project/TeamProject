#include "game.h"	

void now_total_score(struct difficulty_var *diff_var);
void player_win();				// ����� �¸�
void player_lose();				// ����� �й�
void fight_computer_prolog();	// ���

struct difficulty_var {					// ���̵� ���� ���
	int sleep_time;
	int game_duration;
	int time_attack;
	int com_penalty;
};

struct minigame_score mini_score;

void fight_computer() {
	int input_user_menu, exit_sig = 0;	// input_user_menu : ����ڰ� ������ �޴�, exit_sig : 1 �϶� ���ӿ��� ������
	char fc_ch;		//	fc_ch : Sleep�� �ٸ��� �Է������� �������� �Ѿ �� �ֵ��� ���� ����
	srand(time(NULL));	// rand �õ尪 �ʱ�ȭ
	static struct difficulty_var diff_var = { 0, 0, 0, 0 };

	fight_computer_prolog();			// ���� �������� �� ��� �����ֱ�
	do {
		game_title_headline(0,"��ǻ�Ϳ� ����ϱ�");
		
		gotoxy(30, 12);
		printf("1. ����");	

		gotoxy(30, 14);
		printf("2. ��Ģ");

		gotoxy(30, 16);
		printf("3. ���̵� ����");

		gotoxy(30, 18);
		printf("4. ȹ���� ���� ����");

		gotoxy(30, 20);
		printf("5. ��� �ٽú���");

		gotoxy(30, 22);
		printf("6. ������");

		gotoxy(30, 26);
		printf("����� ������? ");
		scanf("%d", &input_user_menu);	// ����� �޴� ����
		while (getchar() != '\n');

		switch (input_user_menu) {
		case 1:									// ���� ����
			if (diff_var.sleep_time == 0) {			// diff_var.sleep_time�� 0�̸� ���̵� ������ �ȵ� ���̹Ƿ� �����ؾ߸� ������ �� ����
				game_title_headline(0,"��ǻ�Ϳ� ����ϱ�");
				gotoxy(30, 18);
				printf("���̵��� �������ּ���!");
				Sleep(1000);
				break;
			} else {
				start_game(&diff_var);			// diff_var.sleep_time�� 0�� �ƴ� ��� ����
			}
			break;
		case 2:							// ��Ģ
			show_rule();
			break;
		case 3:							// ���̵� ����
			set_difficulty(&diff_var);
			break;
		case 4:							// ���� ����
			now_total_score(&diff_var);
			break;
		case 5:							// ��� �ٽú���
			fight_computer_prolog();
			break;
		case 6:							// ������
			exit_sig = 1;
			game_title_headline(0, "��ǻ�Ϳ� ����ϱ�");
			gotoxy(30, 18);
			printf("������ �� ���ʼ�!!");
			Sleep(1500);
			break;
		default:						// �߸��� �� �Է�
			game_title_headline(0, "��ǻ�Ϳ� ����ϱ�");
			gotoxy(30, 18);
			printf("�߸� �Է��ϼ̽��ϴ�.");
			Sleep(1000);
			break;
		}
	} while (exit_sig != 1);			// exit_sig = 1�϶� ���� ����
	return 0;
}

void show_rule() {			// ��Ģ
	char fc_ch;

	game_title_headline(0, "��ǻ�Ϳ� ����ϱ�");
	gotoxy(10, 12);
	printf("exit �� �Է��ϸ� ���� �� �ֽ��ϴ�.");
	gotoxy(10, 13);
	printf("��ǻ�Ϳ��Դ� ���̵��� ���� �г�Ƽ�� �־����ϴ�.");
	gotoxy(10, 14);
	printf("�ܾ� �Է� �� �������� ������ �־����ϴ�.");
	gotoxy(10, 15);
	printf("�ܾ� �Է� �� 5���� �ܾ ���õ˴ϴ�.");
	gotoxy(10, 16);
	printf("���õ� 5���� �ܾ� �� �ϳ��� �ð� ���� �Է��ؾ� �մϴ�.");
	gotoxy(10, 17);
	printf("���� ���ݷ¿� ���� ���а� �����˴ϴ�.");
	gotoxy(10, 19);
	printf("���� : �ܾ�� ���ĺ��� �� �ֽ��ϴ�.");
	gotoxy(10, 21);
	printf("���� : �ܾ� ���� �ð��� �÷��̽ð��� ���Ե˴ϴ�.");

	gotoxy(19, 25);
	printf("�޴��� ���ư����� �ƹ�Ű�� �Է��ϼ���.");
	scanf("%c", &fc_ch);
}

void set_difficulty(struct difficulty_var *diff_var) {
	int exit_sig_dif = 0, user_difficult;		// exit_sig_dif = 1 �϶� �޴��� ���ư� �� ����
												// user_difficult : ����� ���̵� ����

	do { // 3�� ȹ���ؾ� ����� ���� ����
		game_title_headline(0, "��ǻ�Ϳ� ����ϱ�");

		gotoxy(34, 12);
		printf("���̵� ����");

		gotoxy(21, 15);
		printf("normal �� 1��, hard�� 2�� �����ϼ���!");

		gotoxy(26, 17);
		printf("< ���̵��� ���� �޶����� �� >");

		gotoxy(10, 18);
		printf("�ܾ����ýð�, ���ӽð�, �Է����ѽð�, ��ǻ���г�Ƽ�� ����");

		gotoxy(22, 24);
		printf("�ش��ϴ� ���̵� ��ȣ�� �Է��ϼ���: ");
		scanf("%d", &user_difficult);
		while (getchar() != '\n');
		switch (user_difficult) {
		case 1:				// normal
			diff_var->sleep_time = 6000;
			diff_var->game_duration = 40;
			diff_var->time_attack = 7;
			diff_var->com_penalty = 3;
			exit_sig_dif = 1;
			game_title_headline(0, "��ǻ�Ϳ� ����ϱ�");
			gotoxy(28, 18);
			printf("normal�� �����Ǿ����ϴ�.");
			Sleep(1500);
			break;
		case 2:				// hard
			if (mini_score.fight_computer_lock_info < 2) {	// normal���� �ι� �̻� �÷����ؾ� hard ���� ����
				gotoxy(3, 26);
				printf("����� ���̵��� ���� ���̵����� 2�� �̻� �÷����ϼž� ������ �� �ֽ��ϴ�.");
				Sleep(2500);
				break;
			}
			else {
				diff_var->sleep_time = 3000;
				diff_var->game_duration = 30;
				diff_var->time_attack = 4;
				diff_var->com_penalty = 1;
				exit_sig_dif = 1;
				gotoxy(26, 18);
				game_title_headline(0, "��ǻ�Ϳ� ����ϱ�");
				printf("hard �� �����Ǿ����ϴ�.");
				Sleep(1500);
				break;
			}
		default:
			printf("�߸� �Է��ϼ̽��ϴ�.");
		}
	} while (exit_sig_dif != 1);
}

void start_game(struct difficulty_var *diff_var) {
	char user_input[30];		// user_input : ����� �Է� �ܾ�
	char fc_ch;
	int user_power = 0, computer_power = 0, rand_number = 0, array[5], judgement, user_burf, computer_burf, burf, exit_sig = 0;
	// user_power : ����� ���ݷ�, computer_power : ��ǻ�� ���ݷ�, rand_number : ��ǻ�Ͱ� �Է��� �ܾ word_list���� �������� ��
	// array[5] : ����ڿ��� ������ 5�� �ܾ �������� ��, judgement : 0�� �� ����, exit_sig : exit �� �������� 1�� �Ǿ� ������ �����Ҽ� �ֵ��� ��.
	int t1 = 0, t2 = 0, t3 = 0, t4 = 0;	// t1, t2 : ������� �ܾ� �Է� �ð� ����, t3, t4 : ���� ���� �ð� ����
	int i, n = 0;

	game_title_headline(1, "��ǻ�Ϳ� ����ϱ�");

	for (i = 0; i < 3; i++) {
		gotoxy(36, 5);
		printf("%d...", 3 - i);
		Sleep(1000);
	}
	gotoxy(36, 5);
	printf("����!");
	Sleep(1000);

	game_title_headline(1, "��ǻ�Ϳ� ����ϱ�");

	t3 = time(0);
	do {
		user_burf = 0;			// ���� �ʱ�ȭ
		computer_burf = 0;
		for (i = 0; i < 5; i++) {
			array[i] = rand() % MAX_WORD;
			gotoxy((rand() % 60) + 5, (rand() % 8) + 2);	// 5���� �ܾ ������ ��ġ�� ���
			printf("%s", word_list[array[i]]);
		}
		Sleep(diff_var->sleep_time);		// ���̵��� ���� �ð� ���� 5�� �ܾ� ���
		game_title_headline(1, "��ǻ�Ϳ� ����ϱ�");
		burf = rand() % 6;		// ���� ����
		switch (burf) {			// 33% Ȯ���� ���� ����(0~5 �߿��� 0,1 ��)	
		case(0):
			gotoxy(28, 5);
			printf("��... �̹��� �� �ܾ");
			break;
		case(1):
			gotoxy(24, 5);
			printf("�ʹ� ���� �ɸ��°� �ƴϾ�?");
			break;
		case(2):
			gotoxy(12, 4);
			printf("�������� ���׳װ� ��ſ��� ���𰡸� �������ϴ�.");
			gotoxy(12, 6);
			printf("�ߵ�! ����� ���ݷ��� 1 �����մϴ�.");
			user_burf--;		// ����� ���ݷ� ����
			break;
		case(3):
			gotoxy(12, 4);
			printf("�������� ���׳װ� ��ſ��� ���𰡸� �������ϴ�.");
			gotoxy(12, 6);
			printf("������ ����� ��ϴ�. ����� ���ݷ��� 1 �����մϴ�.");
			user_burf++;		// ����� ���ݷ� ����
			break;
		case(4):
			gotoxy(12, 4);
			printf("�������� ���׳װ� ��ǻ�Ϳ��� ���𰡸� �������ϴ�.");
			gotoxy(12, 6);
			printf("emp�ߵ�! ��ǻ���� ���ݷ��� 2 �����մϴ�.");
			computer_burf -= 2;	// ��ǻ�� ���ݷ� ����
			break;
		case(5):
			gotoxy(12, 4);
			printf("�������� ���׳װ� ��ǻ�Ϳ��� ���𰡸� �������ϴ�.");
			gotoxy(12, 6);
			printf("��ǻ�Ͱ� ���͸��� ������ϴ�. ��ǻ���� ���ݷ��� 1 �����մϴ�.");
			computer_burf++;	// ��ǻ�� ���ݷ� ����
		}

		gotoxy(18, 17);
		printf("�ܾ �Է��ϼ���(exit : �������� �ʰ� ������)");
		gotoxy(35, 19);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		t1 = time(0);
		fgets(user_input, 30, stdin);	// ����� �ܾ� �Է�
		t2 = time(0);
		user_input[strlen(user_input) - 1] = 0;	// ����ڰ� �Է��� �ܾ� �ٷ� �ڿ� NULL�� �Է�(�����ִ� ���� �ʱ�ȭ �ʿ� x)

		for (i = 0; i < 30; i++) {		// ������ �ܾ ���� ������ ���ݷ� ����
			if (user_input[i] == 0) {
				n = i + user_burf;
				break;
			}
		}
		judgement = 0;
		if (!(strcmp(user_input, "exit"))) {	// exit�� �Է��ϸ� ����
			exit_sig = 1;
			game_title_headline(1, "��ǻ�Ϳ� ����ϱ�");
			gotoxy(28, 5);
			printf("������ ��ư�� �����̽��ϴ�.");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));	// ���� �ʱ�ȭ
			Sleep(1000);
			break;
		}
		if (t2 - t1 >= diff_var->time_attack) {	// �ܾ� �Է� �ð� ����
			game_title_headline(1, "��ǻ�Ϳ� ����ϱ�");
			gotoxy(30, 14);
			printf("�ð� �ʰ��Ǿ����ϴ�.");
			judgement++;
		}
		else if (!(!strcmp(user_input, word_list[array[0]]) || !strcmp(user_input, word_list[array[1]]) || !strcmp(user_input, word_list[array[2]]) || !strcmp(user_input, word_list[array[3]]) || !strcmp(user_input, word_list[array[4]]))) {
			game_title_headline(1, "��ǻ�Ϳ� ����ϱ�");
			gotoxy(26, 14);
			printf("���õ� �ܾ�� ���� �ʽ��ϴ�.");
			judgement++;
		}
		if (judgement == 0) {	// judgement �� 0 �ʰ��� ��� ���ݷ� �������� ����
			game_title_headline(1, "��ǻ�Ϳ� ����ϱ�");
			user_power += n;
		}

		rand_number = rand() % MAX_WORD;	// ��ǻ�Ͱ� �Է��� �ܾ� ����

		for (i = 0; i < 30; i++) {
			if (word_list[rand_number][i] == 0) {
				n = i - (diff_var->com_penalty) + computer_burf;	// ������ ��ǻ�� ���ݷ� ����
				break;
			}
		}
		computer_power += n;

		gotoxy(12, 17);
		printf("����ڰ� %s �� �Է��Ͽ� ���ݷ��� %d �� �Ǿ����ϴ�.", user_input, user_power);
		gotoxy(12, 19);
		printf("��ǻ�Ͱ� %s �� �Է��Ͽ� ���ݷ��� %d �� �Ǿ����ϴ�.", word_list[rand_number], computer_power);
		t4 = time(0);
	} while (t4 - t3 < (diff_var->game_duration));	// ���ӽð��� �������� ����
	if (exit_sig == 0) {
		Sleep(2000);
		game_title_headline(1, "��ǻ�Ϳ� ����ϱ�");
		gotoxy(15, 17);
		printf("����� ���ݷ��� %d �̰� ��ǻ���� ���ݷ��� %d �Դϴ�.", user_power, computer_power);		// ��� ���
		(mini_score.fight_computer_lock_info)++;	// hard���̵��� �÷����ϱ� ���� �� ����
		gotoxy(19, 19);
		if (user_power > computer_power) {
			printf("�е����� ���� ���̷� ����� �¸��ϼ̽��ϴ�.");
			player_win();		// ����� �¸������� ����Ʈ
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
			player_lose();		// ����� �й������� ����Ʈ
			if (diff_var->sleep_time == 7000)
				(mini_score.fight_computer) -= 3;
			else
				(mini_score.fight_computer) -= 5;
		}
		gotoxy(19, 23);
		printf("�޴��� ���ư����� �ƹ�Ű�� �Է��ϼ���.");
		scanf("%c", &fc_ch);
	}
}

void now_total_score(struct difficulty_var *diff_var) {
	char fc_ch;

	game_title_headline(0, "��ǻ�Ϳ� ����ϱ�");
	gotoxy(31, 13);
	printf("���� ���ھ� : %d", mini_score.fight_computer);	// ���� ����

	gotoxy(27, 15);
	printf("���� ���ھ ���� ȣĪ");

	if (mini_score.fight_computer < -20) {					// ~ -20
		gotoxy(31, 19);
		printf("��ǻ���� �ϼ���");
	}
	else if (mini_score.fight_computer < 0) {				// -20 ~ 0
		gotoxy(30, 19);
		printf("��ǻ�Ϳ� ������ ��");
	}
	else if (mini_score.fight_computer < 5) {				// 0~5
		gotoxy(34, 19);								
		printf("������");
	}
	else if (mini_score.fight_computer < 10) {				// 5~10
		gotoxy(28, 19);
		printf("��ǻ�͸� ������Ų ��");
	}
	else {													// 10~
		gotoxy(25, 19);
		printf("��ǻ�Ϳ� ������ Ǯ����� ��");
	}
	gotoxy(19, 23);
	printf("�޴��� ���ư����� �ƹ�Ű�� �Է��ϼ���.");
	scanf("%c", &fc_ch);
}

void player_win()	// ������� �¸�
{
	int i;
	for (i = 0; i < 10; i++)
	{
		gotoxy(rand() % 75, rand() % 11);
		printf("ERROR!!!");
		gotoxy(rand() % 75, rand() % 11);
		printf("��");
		gotoxy(rand() % 75, rand() % 11);
		printf("��");
		gotoxy(rand() % 75, rand() % 11);
		printf("��");
		gotoxy(rand() % 75, rand() % 11);
		printf("��");
		gotoxy(rand() % 75, rand() % 11);
		printf("��");
		gotoxy(rand() % 75, rand() % 11);
		printf("��");
		gotoxy(rand() % 75, rand() % 11);
		printf("��");
		gotoxy(rand() % 75, rand() % 11);
		printf("��");
	}
	Sleep(1500);
	gotoxy(30, 7);
	printf("!! ��� �����մϴ� !!");
}

void player_lose()		// ������� �й�
{
	gotoxy(29, 5);
	printf("## DEBUG COMPLETE ##");
}

void fight_computer_prolog()	// ���
{
	char fc_ch;

	game_title_headline(0, "��ǻ�Ϳ� ����ϱ� (���)");
	gotoxy(12, 14);
	printf("���� �̽� �̹� ��õ�� ��, ��ǻ���� ������ ��������");
	gotoxy(12, 16);
	printf("��ǻ�� ������ �����ϸ鼭 ����� �븳�Ǵ� ������ ���������.");
	gotoxy(12, 18);
	printf("�̿� ������� ��ǻ�͸� ������Ű�� ������ �Ǵµ�...");
	gotoxy(26, 22);
	printf("�ƹ�Ű�� �Է��Ͽ� ��������");
	scanf("%c", &fc_ch);
}