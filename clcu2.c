#include <stdio.h>

int Add(int x,int y){
	return x+y;
}
int Sub(int x,int y){
	return x-y;
}
int Mlt(int x,int y){
	return x*y;
}
int Div(int x,int y){
	if(y==0){
		printf("Syntax ERROR\n");
		return 0;
	}else{
	return x/y;
	}
}
void Load(int (*c)(int,int)){
	int x,y;
	int result;
	printf("输入两个数字："); 
	scanf("%d %d",&x,&y);
	result=(*c)(x,y);
	if(y!=0||c!=Div){
		printf("%d\n",result);
	}
}

int main(){
	int x,y;
	int o;

	do{
		printf("请输入操作：");
		scanf("%d",&o);
		switch(o){
			case 1:
				Load(Add);
				break;
			case 2:
				Load(Sub);
				break;
			case 3:
				Load(Mlt);
				break;
			case 4:
				Load(Div);
				break;
			case 0:
				break;
			default:
				printf("重新输入！\n"); 
				break;
		}
	}while(o!=0);
	return 0;
}
