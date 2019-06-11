#include "game.h"	

void now_total_score(struct difficulty_var *diff_var);
void player_win();				// 사용자 승리
void player_lose();				// 사용자 패배
void fight_computer_prolog();	// 배경

struct difficulty_var {					// 난이도 변경 요소
	int sleep_time;
	int game_duration;
	int time_attack;
	int com_penalty;
};

struct minigame_score mini_score;

void fight_computer() {
	int input_user_menu, exit_sig = 0;	// input_user_menu : 사용자가 선택한 메뉴, exit_sig : 1 일때 게임에서 나가짐
	char fc_ch;		//	fc_ch : Sleep과 다르게 입력했을때 다음으로 넘어갈 수 있도록 위한 변수
	srand(time(NULL));	// rand 시드값 초기화
	static struct difficulty_var diff_var = { 0, 0, 0, 0 };

	fight_computer_prolog();			// 게임 시작했을 때 배경 보여주기
	do {
		game_title_headline(0,"컴퓨터와 대결하기");
		
		gotoxy(30, 12);
		printf("1. 시작");	

		gotoxy(30, 14);
		printf("2. 규칙");

		gotoxy(30, 16);
		printf("3. 난이도 설정");

		gotoxy(30, 18);
		printf("4. 획득한 점수 보기");

		gotoxy(30, 20);
		printf("5. 배경 다시보기");

		gotoxy(30, 22);
		printf("6. 나가기");

		gotoxy(30, 26);
		printf("당신의 선택은? ");
		scanf("%d", &input_user_menu);	// 사용자 메뉴 선택
		while (getchar() != '\n');

		switch (input_user_menu) {
		case 1:									// 게임 시작
			if (diff_var.sleep_time == 0) {			// diff_var.sleep_time가 0이면 난이도 설정이 안된 것이므로 설정해야만 시작할 수 있음
				game_title_headline(0,"컴퓨터와 대결하기");
				gotoxy(30, 18);
				printf("난이도를 선택해주세요!");
				Sleep(1000);
				break;
			} else {
				start_game(&diff_var);			// diff_var.sleep_time이 0이 아닐 경우 시작
			}
			break;
		case 2:							// 규칙
			show_rule();
			break;
		case 3:							// 난이도 설정
			set_difficulty(&diff_var);
			break;
		case 4:							// 점수 보기
			now_total_score(&diff_var);
			break;
		case 5:							// 배경 다시보기
			fight_computer_prolog();
			break;
		case 6:							// 나가기
			exit_sig = 1;
			game_title_headline(0, "컴퓨터와 대결하기");
			gotoxy(30, 18);
			printf("다음에 또 오십쇼!!");
			Sleep(1500);
			break;
		default:						// 잘못된 값 입력
			game_title_headline(0, "컴퓨터와 대결하기");
			gotoxy(30, 18);
			printf("잘못 입력하셨습니다.");
			Sleep(1000);
			break;
		}
	} while (exit_sig != 1);			// exit_sig = 1일때 게임 종료
	return 0;
}

void show_rule() {			// 규칙
	char fc_ch;

	game_title_headline(0, "컴퓨터와 대결하기");
	gotoxy(10, 12);
	printf("exit 를 입력하면 나갈 수 있습니다.");
	gotoxy(10, 13);
	printf("컴퓨터에게는 난이도에 따라 패널티가 주어집니다.");
	gotoxy(10, 14);
	printf("단어 입력 전 랜덤으로 버프가 주어집니다.");
	gotoxy(10, 15);
	printf("단어 입력 전 5개의 단어가 제시됩니다.");
	gotoxy(10, 16);
	printf("제시된 5개의 단어 중 하나를 시간 내에 입력해야 합니다.");
	gotoxy(10, 17);
	printf("최종 공격력에 따라 승패가 결정됩니다.");
	gotoxy(10, 19);
	printf("주의 : 단어는 겹쳐보일 수 있습니다.");
	gotoxy(10, 21);
	printf("주의 : 단어 제시 시간도 플레이시간에 포함됩니다.");

	gotoxy(19, 25);
	printf("메뉴로 돌아가려면 아무키나 입력하세요.");
	scanf("%c", &fc_ch);
}

void set_difficulty(struct difficulty_var *diff_var) {
	int exit_sig_dif = 0, user_difficult;		// exit_sig_dif = 1 일때 메뉴로 돌아갈 수 있음
												// user_difficult : 사용자 난이도 선택

	do { // 3점 획득해야 어려움 설정 가능
		game_title_headline(0, "컴퓨터와 대결하기");

		gotoxy(34, 12);
		printf("난이도 설정");

		gotoxy(21, 15);
		printf("normal 은 1을, hard는 2를 선택하세요!");

		gotoxy(26, 17);
		printf("< 난이도에 따라 달라지는 것 >");

		gotoxy(10, 18);
		printf("단어제시시간, 게임시간, 입력제한시간, 컴퓨터패널티의 강도");

		gotoxy(22, 24);
		printf("해당하는 난이도 번호를 입력하세요: ");
		scanf("%d", &user_difficult);
		while (getchar() != '\n');
		switch (user_difficult) {
		case 1:				// normal
			diff_var->sleep_time = 6000;
			diff_var->game_duration = 40;
			diff_var->time_attack = 7;
			diff_var->com_penalty = 3;
			exit_sig_dif = 1;
			game_title_headline(0, "컴퓨터와 대결하기");
			gotoxy(28, 18);
			printf("normal로 설정되었습니다.");
			Sleep(1500);
			break;
		case 2:				// hard
			if (mini_score.fight_computer_lock_info < 2) {	// normal에서 두번 이상 플레이해야 hard 선택 가능
				gotoxy(3, 26);
				printf("어려움 난이도는 보통 난이도에서 2번 이상 플레이하셔야 선택할 수 있습니다.");
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
				game_title_headline(0, "컴퓨터와 대결하기");
				printf("hard 로 설정되었습니다.");
				Sleep(1500);
				break;
			}
		default:
			printf("잘못 입력하셨습니다.");
		}
	} while (exit_sig_dif != 1);
}

void start_game(struct difficulty_var *diff_var) {
	char user_input[30];		// user_input : 사용자 입력 단어
	char fc_ch;
	int user_power = 0, computer_power = 0, rand_number = 0, array[5], judgement, user_burf, computer_burf, burf, exit_sig = 0;
	// user_power : 사용자 공격력, computer_power : 컴퓨터 공격력, rand_number : 컴퓨터가 입력할 단어를 word_list에서 랜덤으로 고름
	// array[5] : 사용자에게 제시할 5개 단어를 랜덤으로 고름, judgement : 0일 때 정답, exit_sig : exit 를 눌렀을때 1이 되어 게임을 종료할수 있도록 함.
	int t1 = 0, t2 = 0, t3 = 0, t4 = 0;	// t1, t2 : 사용자의 단어 입력 시간 측정, t3, t4 : 게임 진행 시간 측정
	int i, n = 0;

	game_title_headline(1, "컴퓨터와 대결하기");

	for (i = 0; i < 3; i++) {
		gotoxy(36, 5);
		printf("%d...", 3 - i);
		Sleep(1000);
	}
	gotoxy(36, 5);
	printf("시작!");
	Sleep(1000);

	game_title_headline(1, "컴퓨터와 대결하기");

	t3 = time(0);
	do {
		user_burf = 0;			// 버프 초기화
		computer_burf = 0;
		for (i = 0; i < 5; i++) {
			array[i] = rand() % MAX_WORD;
			gotoxy((rand() % 60) + 5, (rand() % 8) + 2);	// 5개의 단어가 랜덤한 위치에 출력
			printf("%s", word_list[array[i]]);
		}
		Sleep(diff_var->sleep_time);		// 난이도에 따른 시간 동안 5개 단어 출력
		game_title_headline(1, "컴퓨터와 대결하기");
		burf = rand() % 6;		// 버프 결정
		switch (burf) {			// 33% 확률로 버프 없음(0~5 중에서 0,1 꽝)	
		case(0):
			gotoxy(28, 5);
			printf("흠... 이번엔 이 단어를");
			break;
		case(1):
			gotoxy(24, 5);
			printf("너무 오래 걸리는거 아니야?");
			break;
		case(2):
			gotoxy(12, 4);
			printf("지나가던 나그네가 당신에게 무언가를 던졌습니다.");
			gotoxy(12, 6);
			printf("중독! 당신의 공격력이 1 감소합니다.");
			user_burf--;		// 사용자 공격력 감소
			break;
		case(3):
			gotoxy(12, 4);
			printf("지나가던 나그네가 당신에게 무언가를 던졌습니다.");
			gotoxy(12, 6);
			printf("강해진 기분이 듭니다. 당신의 공격력이 1 증가합니다.");
			user_burf++;		// 사용자 공격력 증가
			break;
		case(4):
			gotoxy(12, 4);
			printf("지나가던 나그네가 컴퓨터에게 무언가를 던졌습니다.");
			gotoxy(12, 6);
			printf("emp발동! 컴퓨터의 공격력이 2 감소합니다.");
			computer_burf -= 2;	// 컴퓨터 공격력 감소
			break;
		case(5):
			gotoxy(12, 4);
			printf("지나가던 나그네가 컴퓨터에게 무언가를 던졌습니다.");
			gotoxy(12, 6);
			printf("컴퓨터가 배터리를 얻었습니다. 컴퓨터의 공격력이 1 증가합니다.");
			computer_burf++;	// 컴퓨터 공격력 증가
		}

		gotoxy(18, 17);
		printf("단어를 입력하세요(exit : 저장하지 않고 나가기)");
		gotoxy(35, 19);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		t1 = time(0);
		fgets(user_input, 30, stdin);	// 사용자 단어 입력
		t2 = time(0);
		user_input[strlen(user_input) - 1] = 0;	// 사용자가 입력한 단어 바로 뒤에 NULL값 입력(남아있는 버퍼 초기화 필요 x)

		for (i = 0; i < 30; i++) {		// 선택한 단어에 따른 증가될 공격력 결정
			if (user_input[i] == 0) {
				n = i + user_burf;
				break;
			}
		}
		judgement = 0;
		if (!(strcmp(user_input, "exit"))) {	// exit를 입력하면 종료
			exit_sig = 1;
			game_title_headline(1, "컴퓨터와 대결하기");
			gotoxy(28, 5);
			printf("나가기 버튼을 누르셨습니다.");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));	// 버퍼 초기화
			Sleep(1000);
			break;
		}
		if (t2 - t1 >= diff_var->time_attack) {	// 단어 입력 시간 측정
			game_title_headline(1, "컴퓨터와 대결하기");
			gotoxy(30, 14);
			printf("시간 초과되었습니다.");
			judgement++;
		}
		else if (!(!strcmp(user_input, word_list[array[0]]) || !strcmp(user_input, word_list[array[1]]) || !strcmp(user_input, word_list[array[2]]) || !strcmp(user_input, word_list[array[3]]) || !strcmp(user_input, word_list[array[4]]))) {
			game_title_headline(1, "컴퓨터와 대결하기");
			gotoxy(26, 14);
			printf("제시된 단어와 같지 않습니다.");
			judgement++;
		}
		if (judgement == 0) {	// judgement 가 0 초과일 경우 공격력 증가하지 않음
			game_title_headline(1, "컴퓨터와 대결하기");
			user_power += n;
		}

		rand_number = rand() % MAX_WORD;	// 컴퓨터가 입력할 단어 결정

		for (i = 0; i < 30; i++) {
			if (word_list[rand_number][i] == 0) {
				n = i - (diff_var->com_penalty) + computer_burf;	// 증가될 컴퓨터 공격력 결정
				break;
			}
		}
		computer_power += n;

		gotoxy(12, 17);
		printf("사용자가 %s 를 입력하여 공격력이 %d 가 되었습니다.", user_input, user_power);
		gotoxy(12, 19);
		printf("컴퓨터가 %s 를 입력하여 공격력이 %d 가 되었습니다.", word_list[rand_number], computer_power);
		t4 = time(0);
	} while (t4 - t3 < (diff_var->game_duration));	// 게임시간이 지났으면 종료
	if (exit_sig == 0) {
		Sleep(2000);
		game_title_headline(1, "컴퓨터와 대결하기");
		gotoxy(15, 17);
		printf("당신의 공격력은 %d 이고 컴퓨터의 공격력은 %d 입니다.", user_power, computer_power);		// 결과 출력
		(mini_score.fight_computer_lock_info)++;	// hard난이도를 플레이하기 위한 값 증가
		gotoxy(19, 19);
		if (user_power > computer_power) {
			printf("압도적인 힘의 차이로 당신이 승리하셨습니다.");
			player_win();		// 사용자 승리했을때 이펙트
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
			player_lose();		// 사용자 패배했을때 이펙트
			if (diff_var->sleep_time == 7000)
				(mini_score.fight_computer) -= 3;
			else
				(mini_score.fight_computer) -= 5;
		}
		gotoxy(19, 23);
		printf("메뉴로 돌아가려면 아무키나 입력하세요.");
		scanf("%c", &fc_ch);
	}
}

void now_total_score(struct difficulty_var *diff_var) {
	char fc_ch;

	game_title_headline(0, "컴퓨터와 대결하기");
	gotoxy(31, 13);
	printf("현재 스코어 : %d", mini_score.fight_computer);	// 현재 점수

	gotoxy(27, 15);
	printf("현재 스코어에 따른 호칭");

	if (mini_score.fight_computer < -20) {					// ~ -20
		gotoxy(31, 19);
		printf("컴퓨터의 하수인");
	}
	else if (mini_score.fight_computer < 0) {				// -20 ~ 0
		gotoxy(30, 19);
		printf("컴퓨터에 굴복한 자");
	}
	else if (mini_score.fight_computer < 5) {				// 0~5
		gotoxy(34, 19);								
		printf("생존자");
	}
	else if (mini_score.fight_computer < 10) {				// 5~10
		gotoxy(28, 19);
		printf("컴퓨터를 굴복시킨 자");
	}
	else {													// 10~
		gotoxy(25, 19);
		printf("컴퓨터에 벌레를 풀어놓는 자");
	}
	gotoxy(19, 23);
	printf("메뉴로 돌아가려면 아무키나 입력하세요.");
	scanf("%c", &fc_ch);
}

void player_win()	// 사용자의 승리
{
	int i;
	for (i = 0; i < 10; i++)
	{
		gotoxy(rand() % 75, rand() % 11);
		printf("ERROR!!!");
		gotoxy(rand() % 75, rand() % 11);
		printf("┌");
		gotoxy(rand() % 75, rand() % 11);
		printf("┐");
		gotoxy(rand() % 75, rand() % 11);
		printf("┘");
		gotoxy(rand() % 75, rand() % 11);
		printf("└");
		gotoxy(rand() % 75, rand() % 11);
		printf("랂");
		gotoxy(rand() % 75, rand() % 11);
		printf("끏");
		gotoxy(rand() % 75, rand() % 11);
		printf("깞");
		gotoxy(rand() % 75, rand() % 11);
		printf("숋");
	}
	Sleep(1500);
	gotoxy(30, 7);
	printf("!! 장비를 정지합니다 !!");
}

void player_lose()		// 사용자의 패배
{
	gotoxy(29, 5);
	printf("## DEBUG COMPLETE ##");
}

void fight_computer_prolog()	// 배경
{
	char fc_ch;

	game_title_headline(0, "컴퓨터와 대결하기 (배경)");
	gotoxy(12, 14);
	printf("서기 이십 이백 이천년 후, 컴퓨터의 딥러닝 발전으로");
	gotoxy(12, 16);
	printf("컴퓨터 스스로 독립하면서 사람과 대립되는 구도가 만들어졌다.");
	gotoxy(12, 18);
	printf("이에 사람들이 컴퓨터를 굴복시키려 나서게 되는데...");
	gotoxy(26, 22);
	printf("아무키나 입력하여 다음으로");
	scanf("%c", &fc_ch);
}