#include "game.h"
#include <math.h>

void scrambleArray(char *arr);
void restoreArray(char *arr);

struct typing_score type_score;
struct minigame_score mini_score;
struct timeattack_score timeat_score;

int slMenu() {
    int user_input_typing;
    static char save_file_dir[100] = {0}, info_file[] = "현재 파일 경로: %s\n";

	game_title_headline(0, "저장 메뉴\n");

	gotoxy(30, 12);
    printf("1. 저장파일 경로 입력.\n");

	gotoxy(30, 14);
    printf("2. 경로에 저장하기!\n");

	gotoxy(30, 16);
    printf("3. 경로에서 불러오기!\n");

	gotoxy(30, 18);
    printf("0. 전 메뉴로 돌아가기\n");

	gotoxy(30, 20);
    printf(info_file, save_file_dir);

	gotoxy(30, 22);
    printf("원하는 단계를 입력해주세요! ");
    scanf("%d", &user_input_typing);
	while (getchar() != '\n');

    switch (user_input_typing) {
        case 1:
            // Input save-load file directory
            while(getchar() != '\n');
            printf("저장파일의 경로를 입력하세요: ");
            fgets(save_file_dir, sizeof(save_file_dir), stdin);
            save_file_dir[strlen(save_file_dir) - 1] = 0;
        return 1;
        case 2:
            // Save
            if (strlen(save_file_dir) == 0) {
				gotoxy(30, 24);
                printf("1번 메뉴를 통해 파일 경로를 입력해주세요!\n");
                Sleep(2000);
            } else {
                saveLogic(save_file_dir);
				gotoxy(30, 24);
                printf("파일 저장이 완료되었습니다!\n");
                Sleep(2000);
            }
        return 1;
        case 3:
            // Load
            if (strlen(save_file_dir) == 0) {
				gotoxy(30, 24);
                printf("1번 메뉴를 통해 파일 경로를 입력해주세요!\n");
                Sleep(2000);
            } else {
                load(save_file_dir);
				gotoxy(30, 24);
                printf("로딩이 완료되었습니다!\n");
                Sleep(2000);
            }
        return 0;
        case 0:
            // Return to last menu
        return 0;
        default:
            // Get another input;
        return 10;
    }
}

void saveLogic(char *save_dir) {
    char test[50] = {0};

	/*
	  If we modify at least one of those elements below, we need to update whole thing again
	  in 'load' function. So if you know what you are doing, then, do it. 
	  Make array containing every information in structure value in game.h(eg: score, unlock info)
	*/

    // type_score
    makeArray(type_score.easy, test);
    makeArray(type_score.moderate, test);
    makeArray(type_score.hard, test);
    makeArray(type_score.extreme, test);

    // mini_score
	makeArray(mini_score.timecalc_try, test);
    makeArray(mini_score.timecalc_ans, test);
    makeArray(mini_score.find_road, test);
    makeArray(mini_score.fight_computer, test);
	makeArray(mini_score.fight_computer_lock_info, test);
    makeArray(mini_score.mem_word, test);

    // timeat_score
	makeArray(timeat_score.alp_n1, test);
	makeArray(timeat_score.alp_n2, test);
	makeArray(timeat_score.alp_n3, test);

    makeArray(timeat_score.word_n1, test);
    makeArray(timeat_score.word_n2, test);
    makeArray(timeat_score.word_n3, test);

	/*
	  Why we are scrambling?
	  If we save value in plain text, that means everyone can access data file and modify it.
	  That is not gonna happen in this program.
	  Scramble it before save it.
	*/
	scrambleArray(test);

	// Save it to save_dir
    save(test, save_dir);
}

/*
  How it works?
  Get char array from arr, modify each element using below's equation.
*/
void scrambleArray(char *arr) {
	int a = strlen(arr);
	for (int i = 0; i < a; i++) {
		arr[i] = (arr[i] - pow(i + 1, 2) + i + 1) + 5; // equation
	}
}

/*
  How it works?
  Get char array from arr, modify each element using below's equation.(Restoration)
*/
void restoreArray(char *arr) {
	int a = strlen(arr);
	for (int i = 0; i < a; i++) {
		arr[i] = arr[i] - 5 - 1 - i + pow(i + 1, 2);
	}
}

/*
  Basically make array with value.
  value goes in to char wtf array. So it means basically saving "value" to array.
  We are appending each value by space because otherwise, there is no way to determine each score-value when loading.
*/
void makeArray(int value, char* wtf) {
    char temp[20] = {0};
    int temp_counter = 0, wtf_counter = strlen(wtf);

    if (value == 0) {
        temp[temp_counter] = '0';
    } else {
        while (value != 0) {
            temp[temp_counter] = (value % 10) + '0'; // just in case when score is above 10
            value = value / 10;
            temp_counter++;
        }
    }

    // Roll back to positive way.(Because temp array above saved in opposite - way)
    for (int i = strlen(temp); i >= 0; i--) {
        if (i != 0) {
            wtf[wtf_counter] = temp[i-1];
        }
        wtf_counter++;
    }

    // Put blank on last bits(So we can determine when loading)
    wtf[strlen(wtf)] = ' ';
}

/*
  Write encrypted char array to a file
*/
void save(char* wtf, char *save_file_dir) {
    //int temp_counter = 0, wtf_counter = 0;
    FILE *test_file = fopen(save_file_dir, "w");
    fputs(wtf, test_file);
    fclose(test_file);
}

/*
  Get value from fgets<file>, restore Array, and PARSE each value & save to each structure variable.
*/
void load(char *save_file_dir) {
    FILE *test_file = fopen(save_file_dir, "r");
    char test[40];
    int score_saved[40] = {0,}, counter = 0, res = 0, intcounter = 0;

    fgets(test, sizeof(test), test_file);
	restoreArray(test);
	test[strlen(test) - 1] = 0; // Last bit is 32(space), so we trail it in here.

	// Core functions of parsing value on test
    while (counter != strlen(test)) {
        if (test[counter] == ' ') {
            score_saved[intcounter] = res;
            res = 0;
            counter++;
            intcounter++;
            continue;
        }
        res = res * 10 + (test[counter] - '0');
        counter++;
    }

    //last bit calculated
    score_saved[intcounter] = res;

	// Now, all information is loaded by array score_saved.
	// So now what? Save to each structure variable.
	// WARNING. IF SOME STRUCTURE OR OTHER VALUE MODIFIED, WE MUST UPDATE score_saved array's index.
	type_score.easy = score_saved[0];
	type_score.moderate = score_saved[1];
	type_score.hard = score_saved[2];
	type_score.extreme = score_saved[3];

	mini_score.timecalc_try = score_saved[4];
	mini_score.timecalc_ans = score_saved[5];
	mini_score.find_road = score_saved[6];
	mini_score.fight_computer = score_saved[7];
	mini_score.fight_computer_lock_info = score_saved[8];
	mini_score.mem_word = score_saved[9];

	timeat_score.alp_n1 = score_saved[10];
	timeat_score.alp_n2 = score_saved[11];
	timeat_score.alp_n3 = score_saved[12];
	timeat_score.word_n1 = score_saved[13];
	timeat_score.word_n1 = score_saved[14];
	timeat_score.word_n1 = score_saved[15];

    fclose(test_file);
}