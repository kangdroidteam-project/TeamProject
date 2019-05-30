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

	printf("컴퓨터와 대결하기 게임을 시작합니다.\n");

	do {
		printf("1. 시작\n");				// 메뉴
		printf("2. 규칙\n");
		printf("3. 난이도 설정\n");
		printf("4. 획득한 점수 보기\n");
		printf("5. 나가기\n");
		scanf("%d", &input_user_menu);
		while (getchar() != '\n');

		switch (input_user_menu) {
		case 1:
			if (diff_var.sleep_time == 0) {
				system("cls");
				printf("난이도를 선택해주세요.\n");
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
			printf("잘못 입력하셨습니다.\n");
			Sleep(1000);
			break;
		}
	} while (exit_sig != 1);
	return 0;
}

void show_rule() {
	printf("--------------------------------------------------------------------------\n");
	printf("컴퓨터와 대결하기\n");
	printf("40초동안 빠르게 단어를 입력하세요.\n");
	printf("단어입력이 4초이상 걸리면 공격력이 증가하지 않습니다.\n");
	printf("컴퓨터는 당신과 같이 입력하지만 난이도에 따라 패널티가 주어집니다.\n");
	printf("단어 입력 전 랜덤으로 버프가 주어집니다.\n");
	printf("단어 입력 전 3초 동안 5개의 단어가 제시됩니다.\n");
	printf("제시된 5개의 단어 중 하나를 입력해야 합니다.\n");
	printf("최종 공격력에 따라 승패가 결정됩니다.\n\n");
	printf("주의 : 단어 제시 시간도 플레이시간에 포함됩니다.\n");
	printf("--------------------------------------------------------------------------\n");
}

void set_difficulty(struct difficulty_var *diff_var) {
	int exit_sig_dif = 0, user_difficult;

	printf("---------------------------------------------\n");
	printf("난이도 설정\n");
	printf("---------------------------------------------\n");
	printf("normal 은 1을, hard는 2를 선택하세요!\n");
	printf("---------------------------------------------\n");
	do { // 3점 획득해야 어려움 설정 가능
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
			if (mini_score.fight_computer_lock_info < 3) {
				printf("어려움 난이도는 보통 난이도에서 3점 이상 획득하셔야 선택할 수 있습니다.\n");
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

	for (i = 0; i < 3; i++) {
		system("cls");
		printf("%d...\n", 3 - i);
		Sleep(1000);
	}
	system("cls");
	printf("시작!\n");
	Sleep(1000);

	t3 = time(0);
	do {
		user_burf = 0;
		computer_burf = 0;
		for (i = 0; i < 5; i++) {
			array[i] = rand() % MAX_WORD;
		}
		printf("%s %s %s %s %s\n", word_list[array[0]], word_list[array[1]], word_list[array[2]], word_list[array[3]], word_list[array[4]]);
		Sleep(diff_var->sleep_time);		// 난이도에 따른 시간 동안 5개 단어 출력
		system("cls");
		burf = rand() % 6;		// 버프 결정
		switch (burf) {
		case(0):
		case(1):
			break;		// 33% 확률로 버프 X
		case(2):
			printf("************************************************\n");
			printf("지나가던 나그네가 당신에게 무언가를 던졌습니다.\n");
			printf("중독! 당신의 공격력이 1 감소합니다.\n");
			printf("************************************************\n\n");
			user_burf--;
			break;
		case(3):
			printf("************************************************\n");
			printf("지나가던 나그네가 당신에게 무언가를 던졌습니다.\n");
			printf("강해진 기분이 듭니다. 당신의 공격력이 1 증가합니다.\n");
			printf("************************************************\n\n");
			user_burf++;
			break;
		case(4):
			printf("************************************************\n");
			printf("지나가던 나그네가 컴퓨터에게 무언가를 던졌습니다.\n");
			printf("emp발동! 컴퓨터의 공격력이 2 감소합니다.\n");
			printf("************************************************\n\n");
			computer_burf -= 2;
			break;
		case(5):
			printf("************************************************\n");
			printf("지나가던 나그네가 컴퓨터에게 무언가를 던졌습니다.\n");
			printf("컴퓨터가 배터리를 얻었습니다. 컴퓨터의 공격력이 1 증가합니다.\n");
			printf("************************************************\n\n");
			computer_burf++;
		}

		printf("단어를 입력하세요 : ");
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
			printf("시간 초과되었습니다.\n");
			judgement++;
		}
		if (!(!strcmp(user_input, word_list[array[0]]) || !strcmp(user_input, word_list[array[1]]) || !strcmp(user_input, word_list[array[2]]) || !strcmp(user_input, word_list[array[3]]) || !strcmp(user_input, word_list[array[4]]))) {
			printf("제시된 단어와 같지 않습니다.\n");
			judgement++;
		}
		if (judgement == 0) {	// judgement 가 0이상일 경우 공격력 증가하지 않음
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

		printf("사용자가 %s 를 입력하여 공격력이 %d 가 되었습니다.\n", user_input, user_power);
		printf("컴퓨터가 %s 를 입력하여 공격력이 %d 가 되었습니다.\n\n", word_list[rand_number], computer_power);
		t4 = time(0);
	} while (t4 - t3 < (diff_var->game_duration));
	printf("당신의 공격력은 %d 이고 컴퓨터의 공격력은 %d 입니다.\n", user_power, computer_power);		// 입력에 따른 결과 출력
	if (user_power > computer_power) {
		printf("압도적인 힘의 차이로 당신이 승리하셨습니다.\n\n");
		(mini_score.fight_computer_lock_info) += 2;
		if (diff_var->sleep_time == 7000) // 난이도 따른 점수 획득 차별화
			(mini_score.fight_computer) += 2;
		else
			(mini_score.fight_computer) += 3;
	}
	else if (user_power == computer_power) {
		printf("컴퓨터를 무찔렀지만 당신도 이내 쓰러지고 맙니다.\n\n");
		(mini_score.fight_computer_lock_info)++;
		if (diff_var->sleep_time == 3000)
			(mini_score.fight_computer) -= 1;
	}
	else if (user_power < computer_power) {
		printf("쓰러진 당신을 보고 컴퓨터는 기뻐합니다.\n\n");
		if (diff_var->sleep_time == 7000)
			(mini_score.fight_computer) -= 3;
		else
			(mini_score.fight_computer) -= 5;
	}
}

void now_total_score(struct difficulty_var *diff_var) {
	printf("현재 스코어 : %d\n", mini_score.fight_computer);
	printf("현재 스코어에 따른 호칭\n");
	if (mini_score.fight_computer < -20)					// ~ -20
		printf("컴퓨터의 하수인\n");
	else if (mini_score.fight_computer < 0)				// -20 ~ 0
		printf("컴퓨터에 굴복한 자\n");
	else if (mini_score.fight_computer < 5)				// 0~5
		printf("생존자\n");
	else if (mini_score.fight_computer < 10)				// 5~10
		printf("컴퓨터를 굴복시킨 자\n");
	else
		printf("컴퓨터에 벌레를 풀어놓는 자\n");	// 10~
}