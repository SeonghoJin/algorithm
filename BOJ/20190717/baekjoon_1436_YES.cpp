/*
#include <stdio.h>

int count_six(int num) {

	int div = 10;
	int count = 0;
	int x = 0;
	int flag = -1;
	int result = 0;

	while (num != 0) {

		x = num % div;
		num /= div;

		if (x == 6 && count == 0) {
			flag = 0;
			count++;
		}
		else if (x == 6 && (flag == 0 || flag == 1)) {
			count++;
			if (count >= 3) {
				flag = 1;
				result = count;
			}
		}
		else {
			flag = -1;
			count = 0;
		}
	}
		return result;
}

int last_six(int num) {

	int div = 10;
	int count = 0;
	int x = 0;
	int tmp = 1;
	int flag = -1;
	int result = 0;
	int index = 0;
	int last_index = 0;

	while (num != 0) {

		x = num % div;
		num /= div;
		index++;

		if (x == 6 && count == 0) {
			flag = 0;
			count++;
		}
		else if (x == 6 && (flag == 0 || flag == 1)) {
			count++;
			if (count >= 3) {
				flag = 1;
				result = count;
				last_index = index;
			}
		}
		else {
			flag = -1;
			count = 0;
		}
	}

	for (int i = 0; i < last_index - 3; i++) {
		tmp *= 10;
	}
	return tmp;

}

int main() {

	int num;
	int evil_num = 666;
	int result = evil_num;
	int mul = 1;

	scanf("%d", &num);
	num -= 1;

	while (num--) {


		if (result % 1000 == evil_num && count_six(result) == 3) {
			result += 1000;

			if (result % 1000 == evil_num && count_six(result) > 3) {
				result = result / last_six(result)*last_six(result);
			}

		}
		else if (count_six(result) >= 3) {
			result++;
			
			if (count_six(result) < 3) {
				result = (result-1)/1000*1000 + evil_num+1000;
			}
		}


	}

	printf("%d", result);

	return 0;
}*/
