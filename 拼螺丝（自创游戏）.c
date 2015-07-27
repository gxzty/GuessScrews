#include <stdio.h>

void rule();
void Wal(int win,int lose);

int main(int argc, char *argv[])
{
    rule();
	int screw1 = 20,screw2 = 20,put1 = 1,put2 = 1,boom1 = 0,boom2 = 0;
	while ( (5 < screw1 && 5 < screw2 ) || (screw1 <= 5 && screw2 <= 5 && screw1 == screw2)){
		puts("请输入你要放置的螺丝数：\n");
	    scanf("%d",&put1);
		while (put1 < 1 ||  5 < put1){
		    puts("放置错误，只能放置1-5个螺丝，请重新输入：\n");
	        scanf("%d",&put1);
		}
		if (put1 == 1) boom1++;
		while (boom1 > 3){
		    puts("你已经没有放置一个的机会，请选择放置2-5个：\n");
	        scanf("%d",&put1);
			if(put1 != 1) boom1--;
		}

    	srand((unsigned)time(NULL));
	    put2 = rand()%(5-1+1)+1;
		if (put2 == 1) boom2++;
		while (boom2 > 3){
			srand((unsigned)time(NULL));
		    put2 = rand()%(5-2+2)+2;
			boom2--;
		}
		printf("你放置了%d个，你对手放置了%d个\n\n",put1,put2);
		if (put1 < put2){
			screw1 -= put1;
			screw2 = screw2 - put2 + 2;
			puts("该回合你对手赢了！\n\n");
		}
		else if (put2 < put1){
			screw2 -= put2;
			screw1 = screw1 - put1 + 2;
            puts("该回合你赢了！\n\n");
		}
		else {screw1 -= put1; screw2 -= put2;}
		printf("你还剩余%d个螺丝，对手还剩余%d个螺丝\n\n",screw1,screw2);
	}
	int lose = 0, win = 0;
	if (screw1 < screw2){
		puts("你输了！");
		lose = 1;
	}
	else {
		puts("你赢了！");
	    win = 1;
	}
    Wal(win,lose);
	return 0;
}


void rule(){
	puts("规则如下： \n");
	puts("    1.游戏开始时，双方各分配20个螺丝作为初始条件。\n");
	puts("    2.每回合双方各放置1-5个螺丝（只有三次放置1个的机会），然后比较双方放置螺丝的数目。\n");
	puts("    3.双方将所有螺丝弃置，但是该回合放置数目多的一方可以拿回2颗螺丝。\n");
	puts("    4.回合结束。\n");
	puts("    5.重复步骤2-4。\n");
	puts("    6.若只有一方剩余螺丝不大于5，则另一方获胜；若双方螺丝同时不大于5，则剩余螺丝较多的一方获胜；若双方螺丝同时到0，则平局\n");
}

void Wal(int win,int lose){
	FILE *fr,*fw;
	float w,l,wr;
	fr = fopen("win.dat","r");
    fscanf(fr,"%g,%g",&w,&l);
	fclose(fr);
	fw = fopen("win.dat","w+");
	w += win; l += lose; wr = w/(w+l);
	printf("win:%g\nlose:%g\nwinrate:%.4g%%\n",w,l,(100*wr));
	fprintf(fw,"%g,%g,%.2g",w,l,wr);
	fclose(fw);
}