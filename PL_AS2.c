#include <stdio.h>
#include <stdlib.h>
    
								
int main(){
	int menu;
	long int *ptrdizi;
	int toplamMisafir=0;

	ptrdizi=(long int *)malloc(sizeof(long int)*0);
	do{	
	printf("	Menu\n1-oteleGiris\n2-oteldenCikis\n3-MisafirListesi\n4-EXIT\n");
	scanf("%d",&menu);
	}while(menu>4);	
	if (menu==1){
		oteleGiris(*ptrdizi,toplamMisafir);	
	}
	else if(menu==2){
		oteldenCikis()	
	}
	else if(menu==3){
		misafirList()	
	}
	else if(menu==4){	
	}	
	return 0;
}

int oteleGiris(long int *ptrdizi,int toplamMisafir){
	long int TcNo;
	printf("Misafir sayisini giriniz\n");
	scanf("%d",&gelenMisafir);
	newptr=(long int*)realloc(ptrdizi,toplamMisafir+gelenMisafir);
	for(i=0;i<gelenMisafir;i++){
		printf("Müsteri TC no\n);
		scanf("%ld",&TcNo);
		*newptr+i=TcNo;	
	}	
}
