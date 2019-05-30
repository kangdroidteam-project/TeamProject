#include "game.h"	

void now_total_score(struct difficulty_var *diff_var);

struct difficulty_var {
	int sleep_time;
	int game_duration;
	int time_attack;
	int com_penalty;
};

struct minigame_score mini_score;

void fight_computer() {
	int input_user_menu, exit_sig = 0;
	srand(time(NULL));
	static struct difficulty_var diff_var = { 0, 0, 0, 0 };

	system("cls");

	printf("��ǻ�Ϳ� ����ϱ� ������ �����մϴ�.\n");

	do {
		printf("1. ����\n");				// �޴�
		printf("2. ��Ģ\n");
		printf("3. ���̵� ����\n");
		printf("4. ȹ���� ���� ����\n");
		printf("5. ������\n");
		scanf("%d", &input_user_menu);
		while (getchar() != '\n');

		switch (input_user_menu) {
		case 1:
			if (diff_var.sleep_time == 0) {
				system("cls");
				printf("���̵��� �������ּ���.\n");
				break;
			} else {
				start_game(&diff_var);
			}
			break;
		case 2:
			show_rule();
			break;
		case 3:
			set_difficulty(&diff_var);
			break;
		case 4:
			now_total_score(&diff_var);
			break;
		case 5: // exit
			exit_sig = 1;
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
	printf("--------------------------------------------------------------------------\n");
	printf("��ǻ�Ϳ� ����ϱ�\n");
	printf("40�ʵ��� ������ �ܾ �Է��ϼ���.\n");
	printf("�ܾ��Է��� 4���̻� �ɸ��� ���ݷ��� �������� �ʽ��ϴ�.\n");
	printf("��ǻ�ʹ� ��Ű� ���� �Է������� ���̵��� ���� �г�Ƽ�� �־����ϴ�.\n");
	printf("�ܾ� �Է� �� �������� ������ �־����ϴ�.\n");
	printf("�ܾ� �Է� �� 3�� ���� 5���� �ܾ ���õ˴ϴ�.\n");
	printf("���õ� 5���� �ܾ� �� �ϳ��� �Է��ؾ� �մϴ�.\n");
	printf("���� ���ݷ¿� ���� ���а� �����˴ϴ�.\n\n");
	printf("���� : �ܾ� ���� �ð��� �÷��̽ð��� ���Ե˴ϴ�.\n");
	printf("--------------------------------------------------------------------------\n");
}

void set_difficulty(struct difficulty_var *diff_var) {
	int exit_sig_dif = 0, user_difficult;

	printf("---------------------------------------------\n");
	printf("���̵� ����\n");
	printf("---------------------------------------------\n");
	printf("normal �� 1��, hard�� 2�� �����ϼ���!\n");
	printf("---------------------------------------------\n");
	do { // 3�� ȹ���ؾ� ����� ���� ����
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
			if (mini_score.fight_computer_lock_info < 3) {
				printf("����� ���̵��� ���� ���̵����� 3�� �̻� ȹ���ϼž� ������ �� �ֽ��ϴ�.\n");
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

	for (i = 0; i < 3; i++) {
		system("cls");
		printf("%d...\n", 3 - i);
		Sleep(1000);
	}
	system("cls");
	printf("����!\n");
	Sleep(1000);

	t3 = time(0);
	do {
		user_burf = 0;
		computer_burf = 0;
		for (i = 0; i < 5; i++) {
			array[i] = rand() % MAX_WORD;
		}
		printf("%s %s %s %s %s\n", word_list[array[0]], word_list[array[1]], word_list[array[2]], word_list[array[3]], word_list[array[4]]);
		Sleep(diff_var->sleep_time);		// ���̵��� ���� �ð� ���� 5�� �ܾ� ���
		system("cls");
		burf = rand() % 6;		// ���� ����
		switch (burf) {
		case(0):
		case(1):
			break;		// 33% Ȯ���� ���� X
		case(2):
			printf("************************************************\n");
			printf("�������� ���׳װ� ��ſ��� ���𰡸� �������ϴ�.\n");
			printf("�ߵ�! ����� ���ݷ��� 1 �����մϴ�.\n");
			printf("************************************************\n\n");
			user_burf--;
			break;
		case(3):
			printf("************************************************\n");
			printf("�������� ���׳װ� ��ſ��� ���𰡸� �������ϴ�.\n");
			printf("������ ����� ��ϴ�. ����� ���ݷ��� 1 �����մϴ�.\n");
			printf("************************************************\n\n");
			user_burf++;
			break;
		case(4):
			printf("************************************************\n");
			printf("�������� ���׳װ� ��ǻ�Ϳ��� ���𰡸� �������ϴ�.\n");
			printf("emp�ߵ�! ��ǻ���� ���ݷ��� 2 �����մϴ�.\n");
			printf("************************************************\n\n");
			computer_burf -= 2;
			break;
		case(5):
			printf("************************************************\n");
			printf("�������� ���׳װ� ��ǻ�Ϳ��� ���𰡸� �������ϴ�.\n");
			printf("��ǻ�Ͱ� ���͸��� ������ϴ�. ��ǻ���� ���ݷ��� 1 �����մϴ�.\n");
			printf("************************************************\n\n");
			computer_burf++;
		}

		printf("�ܾ �Է��ϼ��� : ");
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
		if (t2 - t1 >= diff_var->time_attack) {
			printf("�ð� �ʰ��Ǿ����ϴ�.\n");
			judgement++;
		}
		if (!(!strcmp(user_input, word_list[array[0]]) || !strcmp(user_input, word_list[array[1]]) || !strcmp(user_input, word_list[array[2]]) || !strcmp(user_input, word_list[array[3]]) || !strcmp(user_input, word_list[array[4]]))) {
			printf("���õ� �ܾ�� ���� �ʽ��ϴ�.\n");
			judgement++;
		}
		if (judgement == 0) {	// judgement �� 0�̻��� ��� ���ݷ� �������� ����
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

		printf("����ڰ� %s �� �Է��Ͽ� ���ݷ��� %d �� �Ǿ����ϴ�.\n", user_input, user_power);
		printf("��ǻ�Ͱ� %s �� �Է��Ͽ� ���ݷ��� %d �� �Ǿ����ϴ�.\n\n", word_list[rand_number], computer_power);
		t4 = time(0);
	} while (t4 - t3 < (diff_var->game_duration));
	printf("����� ���ݷ��� %d �̰� ��ǻ���� ���ݷ��� %d �Դϴ�.\n", user_power, computer_power);		// �Է¿� ���� ��� ���
	if (user_power > computer_power) {
		printf("�е����� ���� ���̷� ����� �¸��ϼ̽��ϴ�.\n\n");
		(mini_score.fight_computer_lock_info) += 2;
		if (diff_var->sleep_time == 7000) // ���̵� ���� ���� ȹ�� ����ȭ
			(mini_score.fight_computer) += 2;
		else
			(mini_score.fight_computer) += 3;
	}
	else if (user_power == computer_power) {
		printf("��ǻ�͸� �������� ��ŵ� �̳� �������� ���ϴ�.\n\n");
		(mini_score.fight_computer_lock_info)++;
		if (diff_var->sleep_time == 3000)
			(mini_score.fight_computer) -= 1;
	}
	else if (user_power < computer_power) {
		printf("������ ����� ���� ��ǻ�ʹ� �⻵�մϴ�.\n\n");
		if (diff_var->sleep_time == 7000)
			(mini_score.fight_computer) -= 3;
		else
			(mini_score.fight_computer) -= 5;
	}
}

void now_total_score(struct difficulty_var *diff_var) {
	printf("���� ���ھ� : %d\n", mini_score.fight_computer);
	printf("���� ���ھ ���� ȣĪ\n");
	if (mini_score.fight_computer < -20)					// ~ -20
		printf("��ǻ���� �ϼ���\n");
	else if (mini_score.fight_computer < 0)				// -20 ~ 0
		printf("��ǻ�Ϳ� ������ ��\n");
	else if (mini_score.fight_computer < 5)				// 0~5
		printf("������\n");
	else if (mini_score.fight_computer < 10)				// 5~10
		printf("��ǻ�͸� ������Ų ��\n");
	else
		printf("��ǻ�Ϳ� ������ Ǯ����� ��\n");	// 10~
}