#include<stdio.h>

int n=0;

struct pagetable{
	int pageno;
	int frameno;
}p[15];

void init_pagetable(struct pagetable *p){
	p[0].pageno=1;
	p[0].frameno=0;
	p[1].pageno=6;
	p[1].frameno=1;
	p[2].pageno=3;
	p[2].frameno=2;
	p[3].pageno=7;
	p[3].frameno=3;
	p[4].pageno=8;
	p[4].frameno=4;
	n=5;
}

void init(int *frame){
	frame[0]=1;
	frame[1]=6;
	frame[2]=3;
	frame[3]=7;
	frame[4]=8;
}

void display(){
  for(int i=0;i<n;i++){
	printf("\n    %d             %d",p[i].pageno,p[i].frameno);
  }
}

void insert_frame(int *frame){
	int num;
	printf("\nEnter a page no to inserted : ");
	scanf("%d",&num);
	if(n!=15){
		frame[n]=num;
		p[n].pageno=num;
		p[n].frameno=n;
		n++;
	}
	else
		printf("\nFRAME FILLED!");
}

void search(int *frame){
	int num;
	printf("\nEnter a frame no to be searched : ");
	scanf("%d",&num);
	for(int i=0;i<n;i++){
		if(i==num){
			printf("\nThe FRAME No. : %d \nThe Page No. : %d",i,frame[i]);
			break;
		}
	}
}

int main(){
	int frame[15];
	init(frame);
	init_pagetable(p);
	int choice,ch=0;
	while(ch==0){
		printf("\n\n\t1.TO INSERT A PAGE NO. \n\t2.To display page table\n\t3.To search for specific frame\n\t4.To exit\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1: insert_frame(frame);
				printf("\nElement INSERTED!!");
				break;
			case 2: printf("\n__PAGE TABLE__\n");
				printf("\nPage No.   |  Frame no.");
				display();
                printf("\n");
				break;
			case 3: search(frame);
				break;
			case 4: ch=1;
				break;
			default: printf("\nINVALID CASE");
		}
	}
	return 0;
}