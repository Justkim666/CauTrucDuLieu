#include<stdio.h>

int hopLe(int ngay, int thang, int nam) {
	printf("check %d/%d/%d\n", ngay, thang, nam);
	int check = 0;
	int max[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (thang == 2) {
		//Kiem tra nam nhuan
		if (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0)) {
			max[2] = 29;
		}
	}
	if (ngay > 0 && ngay <= max[thang] && thang > 0 && thang < 13 && nam > 0) {
		check = 1;
	}
	return check;
}

void cong(int *ngay, int *thang, int *nam) {
	*ngay = *ngay + 1;
	printf("ngay = %d\n", *ngay);
	if (!hopLe(*ngay, *thang, *nam)) {
		*ngay = 1;
		*thang = *thang + 1;
		printf("%d/%d/%d\n", *ngay, *thang, *nam);
		if (!hopLe(*ngay, *thang, *nam)) {
			*thang = 1;
			*nam = *nam + 1;
			printf("%d/%d/%d\n", *ngay, *thang, *nam);
		}
	}
}

int main(){
	int ngay = 31, thang = 1, nam = 1999;
	cong(&ngay, &thang, &nam);
	printf("%d/%d/%d", ngay, thang, nam);
	return 0;
}
	
	
	
