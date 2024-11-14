#include <stdio.h>
int Add(int x, int y) {

	return x + y;
}
int Sub(int x, int y) {
	return x - y;
}
int Mul(int x, int y) {
	return x * y;
}
int Div(int x, int y) {
	return x / y;
}
int Load(int (*pfun)(int,int)){
	int a=0,b=0;
	printf("请输入操作数：");
	scanf("%d %d",&a,&b);
	return (*pfun)(a,b);
}
int main() {
	int n = 0;
	int a, b;
	int ret=0;
	printf("***********************\n"
		   "******1:Add, 2:Sub*****\n"
		   "******3:Mul, 4:Div*****\n"
		   "******    0:Exit  *****\n"
		   "***********************\n");

	do {
		printf("请输入操作：");
		scanf("%d", &n);
		switch (n) {
		case 1:
			ret=Load(Add);
			printf("%d\n",ret);
			break;
		case 2:
			ret=Load(Sub);
			printf("%d\n",ret);
			break;
		case 3:
			ret=Load(Mul);
			printf("%d\n",ret);
			break;
		case 4:
			ret=Load(Div);
			printf("%d\n",ret);
			break;

		case 0:
			printf("End program.");
			break;
		default:
			printf("重新输入。\n");
			break;
		}
	}while(n);
	return 0;
}
