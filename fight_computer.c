#include "game.h"

void fight_computer()
{
	char user_input[30], computer_input[30], start[10] = "start", quit[10] = "quit", rule[10] = "rule", normal[15] = "normal", difficulty[15] = "difficulty", difficult[15] = "difficult", user_start[20], user_difficult[15];
	//	사용자 입력			컴퓨터 입력																	보통					난이도 선택						어려움
	int user_power = 0, computer_power = 0, i, n = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, rand_number = 0, array[5], judgement, user_burf, computer_burf, com_penalty, burf, difficult_lock = 0, sleep_time = 0, game_duration = 0, time_attack = 0;
	//	사용자 공격력	컴퓨터 공격력				t1,t2 단어입력시간 t3,t4 게임시간				랜덤 숫자 저장						com_penalty: 컴퓨터 공격력 증가량의 감소			단어 보여주는 시간					단어 입력 시간
	//																										시간 초과, 오답 처리																			게임 진행 시간
	srand(time(NULL));

	printf("컴퓨터와 대결하기 게임을 시작합니다.\n");

	do
	{
		printf("시작 : start, 규칙 : rule, 난이도 설정 : difficulty, 나가기 : quit\n");	// 메뉴

		fgets(user_start, 20, stdin);
		for (i = 0; user_start[i] != 0; i++)
		{
			if (user_start[i] == '\n')
			{
				user_start[i] = 0;
				break;
			}
		}
		if (!(strcmp(user_start, start)) && sleep_time == 0)	// 난이도 설정 없이 게임 시작 불가
		{
			printf("난이도를 선택해주세요.\n");
			continue;
		}

		else if (!(strcmp(user_start, rule)))	// 룰
		{
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
		else if (!(strcmp(user_start, difficulty)))	// 난이도 설정
		{
			printf("---------------------------------------------\n");
			printf("난이도 설정\n");
			printf("---------------------------------------------\n");
			printf("\'normal\' 또는 \'difficult\' 를 입력하세요.\n");
			printf("---------------------------------------------\n");
			do                            // 3점 획득해야 어려움 설정 가능
			{
				fgets(user_difficult, 15, stdin);
				for (i = 0; user_start[i] != 0; i++)
				{
					if (user_difficult[i] == '\n')
					{
						user_difficult[i] = 0;
						break;
					}
				}
				if (!(strcmp(user_difficult, normal)))	// 보통 난이도 설정
				{
					sleep_time = 7000;
					game_duration = 50;
					time_attack = 7;
					com_penalty = 3;
					break;
				}
				else if (!(strcmp(user_difficult, difficult)) && difficult_lock < 3)
				{
					printf("어려움 난이도는 보통 난이도에서 3점 이상 획득하셔야 선택할 수 있습니다.\n");
					continue;
				}
				else if (!(strcmp(user_difficult, difficult)))	// 어려움 난이도 설정
				{
					sleep_time = 3000;
					game_duration = 30;
					time_attack = 4;
					com_penalty = 1;
					break;
				}
				else
					printf("잘못 입력하셨습니다.\n");
			} while (1);

		}
		else if (!(strcmp(user_start, start)))	// 시작
		{
			for (i = 0; i < 3; i++)			// 3초 뒤 시작
			{
				system("cls");
				printf("%d...\n", 3 - i);
				Sleep(1000);
			}
			system("cls");
			printf("시작!\n");
			Sleep(1000);

			t3 = time(0);
			do
			{
				user_burf = 0;
				computer_burf = 0;
				for (i = 0; i < 5; i++)
				{
					array[i] = rand() % MAX_WORD;
				}
				printf("%s %s %s %s %s\n", word_list[array[0]], word_list[array[1]], word_list[array[2]], word_list[array[3]], word_list[array[4]]);
				Sleep(sleep_time);		// 난이도에 따른 시간 동안 5개 단어 출력
				system("cls");
				burf = rand() % 6;		// 버프 결정
				switch (burf)
				{
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
				for (i = 0; user_input[i] != 0; i++)
				{
					if (user_input[i] == '\n')
					{
						user_input[i] = 0;
						break;
					}
				}

				for (i = 0; i < 30; i++)
				{
					if (user_input[i] == 0)
					{
						n = i + user_burf;
						break;
					}
				}
				judgement = 0;
				if (t2 - t1 >= time_attack)
				{
					printf("시간 초과되었습니다.\n");
					judgement++;
				}
				if (!(!strcmp(user_input, word_list[array[0]]) || !strcmp(user_input, word_list[array[1]]) || !strcmp(user_input, word_list[array[2]]) || !strcmp(user_input, word_list[array[3]]) || !strcmp(user_input, word_list[array[4]])))
				{
					printf("제시된 단어와 같지 않습니다.\n");
					judgement++;
				}
				if (judgement == 0)		// judgement 가 0이상일 경우 공격력 증가하지 않음
					user_power += n;

				rand_number = rand() % MAX_WORD;
				word_list[rand_number];


				for (i = 0; i < 30; i++)
				{
					if (word_list[rand_number][i] == 0)
					{
						n = i - com_penalty + computer_burf;
						break;
					}
				}
				computer_power += n;

				printf("사용자가 %s 를 입력하여 공격력이 %d 가 되었습니다.\n", user_input, user_power);
				printf("컴퓨터가 %s 를 입력하여 공격력이 %d 가 되었습니다.\n\n", word_list[rand_number], computer_power);
				t4 = time(0);
			} while (t4 - t3 < game_duration);
			printf("당신의 공격력은 %d 이고 컴퓨터의 공격력은 %d 입니다.\n", user_power, computer_power);		// 입력에 따른 결과 출력
			if (user_power > computer_power)
			{
				printf("압도적인 힘의 차이로 당신이 승리하셨습니다.\n\n");
				difficult_lock += 2;
				// 전체 스코어 +2점
			}
			else if (user_power == computer_power)
			{
				printf("컴퓨터를 무찔렀지만 당신도 이내 쓰러지고 맙니다.\n\n");
				difficult_lock++;
				// 전체 스코어 +1점
			}
			else if (user_power < computer_power)
			{
				printf("쓰러진 당신을 보고 컴퓨터는 기뻐합니다.\n\n");
				// 전체 스코어 +0점
			}
		}
		else if (!(strcmp(user_start, quit)))
			break;
		else
			printf("잘못입력하셨습니다.\n");
	} while (1);
	return 0;
}