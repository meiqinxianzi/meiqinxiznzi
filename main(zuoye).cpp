#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <time.h>

char da[1002700][400] = {'\0'};

struct wuliu
{char xsb[13][30];}outt[1002700];

int main()
{
    FILE*fp;char *ab;
    clock_t start1, finish1,start2, finish2,start3, finish3;
 	double time1,time2,time3;
    char inpu1[20],inpu2[20],inpu3[20];
    char inpu1_1[20],inpu2_2[20];
    char* pEnd;
    double f1,zhongliang,discount; 
    char filename[40],fat[]={"�ػ�"},light[]={"���"};
    int i,j,m,n,k,a,b,c,d,h1,h2;
	
    printf("�������ļ���:");gets(filename);
    printf("���ڲ����Ƿ�����������\n");
    fp=fopen(filename,"r");
    if(NULL==fp){
    	printf("��"); 
	} 
    fseek(fp, 0L, SEEK_SET);
    for(i = 0 ;i < 1002700 ; i++)
       {ab=fgets(da[i],400,fp);if(ab==NULL)break;}
           h1=i; 
           for(j = 0 ;j < h1 ; j++)
    {int a=-1,h2=0;
        for(b=a+1;b<strlen(da[j]);b++)
        {
            if(da[j][b]==',')
            {
                c=0;memset(outt[j].xsb[h2],0,50);
                for(i=a+1;i<b;i++)
                {outt[j].xsb[h2][c]=da[j][i];c++;}a=b;h2++;
            }
        }
    }
    
    for(i=0;i<1;i++)  //�����Ƿ�������,���ԵĻ�������������� 
    {
        printf("%s %s\n",outt[i].xsb[0],outt[i].xsb[1]);
    }
    while(1){
    	//����һ 
    printf("������������У�");
    scanf("%s",inpu1);
    if(strcmp("END",inpu1)==0){
    	break;
	}
	strcpy(inpu1_1,inpu1);
	strcat(inpu1_1," "); 

    start1 = clock();
	//�жϵ�һ������Ҫ�����λ�ò������һ������ 
	for(i=0;i<1002700;i++){
		if(strcmp(outt[i].xsb[1],inpu1)==0||strcmp(outt[i].xsb[1],inpu1_1)==0){
			printf("%s\n",outt[i].xsb[0]); 
			n=i; k=n;
			break;
		} 
	}
	if(i>=1002700){
    	printf("δ�ҵ���\n");
    	continue; 
	}  
	for(i=k+1;i<1002700;i++){
		if(strcmp(outt[i].xsb[1],inpu1)==0||strcmp(outt[i].xsb[1],inpu1_1)==0){
			for(;n<i;n++){
				if(strcmp(outt[i].xsb[0],outt[n].xsb[0])==0){  //�ж��Ƿ��ظ� 
				break;
				}	 
			} 
			if(n==i){
				printf("%s\n",outt[i].xsb[0]);
				n=k;
			}
			else{
				n=k;	
			}
		}	 
	} 
	finish1 = clock();
 	time1 = (double)(finish1-start1) / CLOCKS_PER_SEC;
 	
 	start2 = clock();
//���ܶ�
	printf("�����뵽����У�");
    scanf("%s",inpu2);
    if(strcmp("END",inpu2)==0){
    	break;
	}
    strcpy(inpu2_2,inpu2);
	strcat(inpu2_2," "); 
	//�жϵ�һ������Ҫ�����λ�ò������һ������ 
	for(i=0;i<1002700;i++){
		if((strcmp(outt[i].xsb[1],inpu1)==0||strcmp(outt[i].xsb[1],inpu1_1)==0)&&(strcmp(outt[i].xsb[3],inpu2)==0||strcmp(outt[i].xsb[3],inpu2_2)==0)){
			printf("%s �ػ��۸�%s ����۸�%s\n",outt[i].xsb[0],outt[i].xsb[7],outt[i].xsb[9]); 
			n=i; k=n;
			break;
		} 
	}
	if(i>=1002700){
    	printf("δ�ҵ���\n");
    	continue; 
	}  
	for(i=k+1;i<1002700;i++){
		if((strcmp(outt[i].xsb[1],inpu1)==0||strcmp(outt[i].xsb[1],inpu1_1)==0)&&(strcmp(outt[i].xsb[3],inpu2)==0||strcmp(outt[i].xsb[3],inpu2_2)==0)){
			for(;n<i;n++){
				if(strcmp(outt[i].xsb[0],outt[n].xsb[0])==0){  //�ж��Ƿ��ظ� 
				break;
				}	 
			} 
			if(n==i){
				printf("%s �ػ��۸�%s ����۸�%s\n",outt[i].xsb[0],outt[i].xsb[7],outt[i].xsb[9]);
				n=k;
			}
			else{
				n=k;	
			}
		}	 
	}
	finish2 = clock();
 	time2 = (double)(finish2-start2) / CLOCKS_PER_SEC;
 	
 	start3=clock();
//������	
	printf("���������������������");
    scanf("%s %lf",inpu3,&zhongliang);
    if(strcmp("END",inpu3)==0){
    	break;
	}
	//�жϵ�һ������Ҫ�����λ�ò������һ������ 
	for(i=0;i<1002700;i++){
		if((strcmp(outt[i].xsb[1],inpu1)==0||strcmp(outt[i].xsb[1],inpu1_1)==0)&&(strcmp(outt[i].xsb[3],inpu2)==0||strcmp(outt[i].xsb[3],inpu2_2)==0)){
			if(strcmp(fat,inpu3)==0){
				f1 = strtof (outt[i].xsb[7], &pEnd);    //��char�����������������ת����double���� 
				discount = f1*(strtof (outt[i].xsb[8], &pEnd))/10; 
				printf("%s ԭ�ۣ� %.2lf �ۺ�ۣ� %.2lf\n",outt[i].xsb[0],zhongliang*f1,discount*zhongliang); 
			} 
			if(strcmp(light,inpu3)==0){
				f1 = strtof (outt[i].xsb[9], &pEnd);
				discount = f1*(strtof (outt[i].xsb[10], &pEnd))/10; 
				printf("%s ԭ�ۣ� %.2lf �ۺ�ۣ� %lf.2\n",outt[i].xsb[0],zhongliang*f1,discount*zhongliang); 
			} 
			n=i; k=n;
			break;
		} 
	}
	if(i>=1002700){
    	printf("δ�ҵ���\n");
    	continue;
	}  
	for(i=k+1;i<1002700;i++){
		if((strcmp(outt[i].xsb[1],inpu1)==0||strcmp(outt[i].xsb[1],inpu1_1)==0)&&(strcmp(outt[i].xsb[3],inpu2)==0||strcmp(outt[i].xsb[3],inpu2_2)==0)){
			for(;n<i;n++){
				if(strcmp(outt[i].xsb[0],outt[n].xsb[0])==0){  //�ж��Ƿ��ظ� 
				break;
				}	 
			} 
			if(n==i){
				if(strcmp(fat,inpu3)==0){
					f1 = strtof (outt[i].xsb[7], &pEnd);
				discount = f1*(strtof (outt[i].xsb[8], &pEnd))/10; 
				printf("%s ԭ��:%.2lf �ۺ��:%.2lf\n",outt[i].xsb[0],zhongliang*f1,discount*zhongliang);  
				} 
				if(strcmp(light,inpu3)==0){
					f1 = strtof (outt[i].xsb[9], &pEnd);
					discount = f1*(strtof (outt[i].xsb[10], &pEnd))/10; 
				printf("%s ԭ��:%.2lf �ۺ��:%.2lf\n",outt[i].xsb[0],zhongliang*f1,discount*zhongliang); 
				} 
				n=k;
			}
			else{
				n=k;	
			}
		}	 
	} 
	finish3 = clock();
 	time3 = (double)(finish3-start3) / CLOCKS_PER_SEC;
 	printf( "The time1 is %lf seconds\n", time1);
 	printf( "The time2 is %lf seconds\n", time2);
 	printf( "The time3 is %lf seconds\n", time3);
	}	
	 
    return 0;
}



