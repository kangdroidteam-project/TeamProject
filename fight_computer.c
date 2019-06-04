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
		printf("1. 시작\n");	

		gotoxy(30, 14);
		printf("2. 규칙\n");

		gotoxy(30, 16);
		printf("3. 난이도 설정\n");

		gotoxy(30, 18);
		printf("4. 획득한 점수 보기\n");

		gotoxy(30, 20);
		printf("5. 나가기\n");

		gotoxy(30, 22);
		printf("당신의 선택은? ");
		scanf("%d", &input_user_menu);
		while (getchar() != '\n');

		switch (input_user_menu) {
		case 1:
			if (diff_var.sleep_time == 0) {
				game_title(0);
				gotoxy(30, 16);
				printf("난이도를 선택해주세요!");
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
			printf("메뉴로 돌아가려면 아무키나 입력하세요.");
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
			printf("다음에 또 오십쇼!!");
			Sleep(1500);
			break;
		default:
			printf("잘못 입력하셨습니다.\n");
			Sleep(1000);
			break;
		}
	} while (exit_sig != 1);
	return 0;
}

void show_rule() {
	gotoxy(6, 12);
	printf("40초동안 빠르게 단어를 입력하세요.");
	gotoxy(6, 13);
	printf("단어입력이 4초이상 걸리면 공격력이 증가하지 않습니다.");
	gotoxy(6, 14);
	printf("컴퓨터는 당신과 같이 입력하지만 난이도에 따라 패널티가 주어집니다.");
	gotoxy(6, 15);
	printf("단어 입력 전 랜덤으로 버프가 주어집니다.");
	gotoxy(6, 16);
	printf("단어 입력 전 3초 동안 5개의 단어가 제시됩니다.");
	gotoxy(6, 17);
	printf("제시된 5개의 단어 중 하나를 입력해야 합니다.");
	gotoxy(6, 18);
	printf("최종 공격력에 따라 승패가 결정됩니다.");
	gotoxy(6, 19);
	printf("단어는 겹쳐보일 수 있습니다.");
	gotoxy(6, 21);
	printf("주의 : 단어 제시 시간도 플레이시간에 포함됩니다.");
}

void set_difficulty(struct difficulty_var *diff_var) {
	int exit_sig_dif = 0, user_difficult;

	do { // 3점 획득해야 어려움 설정 가능
		game_title(0);

		gotoxy(34, 13);
		printf("난이도 설정");

		gotoxy(21, 15);
		printf("normal 은 1을, hard는 2를 선택하세요!");

		gotoxy(22, 17);
		printf("해당하는 난이도 번호를 입력하세요: ");
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
				printf("어려움 난이도는 보통 난이도에서 2번 이상 플레이하셔야 선택할 수 있습니다.");
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
			printf("잘못 입력하셨습니다.\n");
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
	printf("시작!");
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
		Sleep(diff_var->sleep_time);		// 난이도에 따른 시간 동안 5개 단어 출력
		game_title(1);
		burf = rand() % 6;		// 버프 결정
		switch (burf) {
		case(0):
			gotoxy(28, 5);
			printf("흠... 이번엔 이 단어를");
			break;
		case(1):
			gotoxy(24, 5);
			printf("너무 오래 걸리는거 아니야?");
			break;		// 33% 확률로 버프 X
		case(2):
			gotoxy(12, 4);
			printf("지나가던 나그네가 당신에게 무언가를 던졌습니다.");
			gotoxy(12, 6);
			printf("중독! 당신의 공격력이 1 감소합니다.");
			user_burf--;
			break;
		case(3):
			gotoxy(12, 4);
			printf("지나가던 나그네가 당신에게 무언가를 던졌습니다.");
			gotoxy(12, 6);
			printf("강해진 기분이 듭니다. 당신의 공격력이 1 증가합니다.");
			user_burf++;
			break;
		case(4):
			gotoxy(12, 4);
			printf("지나가던 나그네가 컴퓨터에게 무언가를 던졌습니다.");
			gotoxy(12, 6);
			printf("emp발동! 컴퓨터의 공격력이 2 감소합니다.");
			computer_burf -= 2;
			break;
		case(5):
			gotoxy(12, 4);
			printf("지나가던 나그네가 컴퓨터에게 무언가를 던졌습니다.");
			gotoxy(12, 6);
			printf("컴퓨터가 배터리를 얻었습니다. 컴퓨터의 공격력이 1 증가합니다.");
			computer_burf++;
		}

		gotoxy(18, 14);
		printf("단어를 입력하세요(exit : 저장하지 않고 나가기)");
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
			printf("시간 초과되었습니다.");
			judgement++;
		}
		else if (!(!strcmp(user_input, word_list[array[0]]) || !strcmp(user_input, word_list[array[1]]) || !strcmp(user_input, word_list[array[2]]) || !strcmp(user_input, word_list[array[3]]) || !strcmp(user_input, word_list[array[4]]))) {
			game_title(1);
			gotoxy(26, 12);
			printf("제시된 단어와 같지 않습니다.");
			judgement++;
		}
		if (judgement == 0) {	// judgement 가 0 초과일 경우 공격력 증가하지 않음
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
		printf("사용자가 %s 를 입력하여 공격력이 %d 가 되었습니다.", user_input, user_power);
		gotoxy(10, 16);
		printf("컴퓨터가 %s 를 입력하여 공격력이 %d 가 되었습니다.", word_list[rand_number], computer_power);
		t4 = time(0);
	} while (t4 - t3 < (diff_var->game_duration));
	Sleep(2000);
	game_title(1);
	gotoxy(15, 14);
	printf("당신의 공격력은 %d 이고 컴퓨터의 공격력은 %d 입니다.", user_power, computer_power);		// 입력에 따른 결과 출력
	(mini_score.fight_computer_lock_info)++;
	gotoxy(19, 17);
	if (user_power > computer_power) {
		printf("압도적인 힘의 차이로 당신이 승리하셨습니다.");
		if (diff_var->sleep_time == 7000) // 난이도 따른 점수 획득 차별화
			(mini_score.fight_computer) += 2;
		else
			(mini_score.fight_computer) += 3;
	}
	else if (user_power == computer_power) {
		printf("컴퓨터를 무찔렀지만 당신도 이내 쓰러지고 맙니다.");
		if (diff_var->sleep_time == 3000)
			(mini_score.fight_computer) -= 1;
	}
	else if (user_power < computer_power) {
		printf("쓰러진 당신을 보고 컴퓨터는 기뻐합니다.");
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
	printf("현재 스코어 : %d", mini_score.fight_computer);

	gotoxy(27, 14);
	printf("현재 스코어에 따른 호칭");

	if (mini_score.fight_computer < -20) {					// ~ -20
		gotoxy(31, 16);
		printf("컴퓨터의 하수인");
	}
	else if (mini_score.fight_computer < 0) {				// -20 ~ 0
		gotoxy(30, 16);
		printf("컴퓨터에 굴복한 자");
	}
	else if (mini_score.fight_computer < 5) {				// 0~5
		gotoxy(34, 16);								
		printf("생존자");
	}
	else if (mini_score.fight_computer < 10) {				// 5~10
		gotoxy(28, 16);
		printf("컴퓨터를 굴복시킨 자");
	}
	else {													// 10~
		gotoxy(25, 16);
		printf("컴퓨터에 벌레를 풀어놓는 자");
	}
	gotoxy(19, 18);
	printf("메뉴로 돌아가려면 아무키나 입력하세요.");
	scanf("%c", &ch);
}

void game_title(int select)
{
	int i, x, y;

	system("cls");

	x = 0;
	y = 0;
	gotoxy(x, y);
	printf("┌");
	for (i = 0; i < 38; i++)
		printf("─");
	printf("┐");

	for (i = 1; i < 11; i++)
	{
		y++;
		gotoxy(x, y);
		printf("│");

		if (i == 5 && select==0)
		{
			gotoxy(31, i);
			printf("컴퓨터와 대결하기\n");
		}

		x += 78;
		gotoxy(x, y);
		printf("│");
		x = 0;
	}

	gotoxy(x, y);
	printf("└");
	for (i = 0; i < 38; i++)
		printf("─");
	printf("┘");

	gotoxy(0, 0);
}