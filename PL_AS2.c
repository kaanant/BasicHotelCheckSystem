#include <stdio.h>
#include <stdlib.h>
    
void oteleGiris(long int *ptrdizi,int *toplamMisafir);							
int main(){
	int menu;
	long int *ptrdizi;
	int toplamMisafir=0;

	ptrdizi=(long int *)malloc(0);
	do{	
	printf("	Menu\n1-oteleGiris\n2-oteldenCikis\n3-MisafirListesi\n4-EXIT\n");
	scanf("%d",&menu);
	
	if (menu==1){
		oteleGiris(ptrdizi,toplamMisafir);	
	}
	else if(menu==2){
		//oteldenCikis();
	}
	else if(menu==3){
		//misafirList();	
	}
	else{}
	}while(menu!=4);		
	return 0;  
}
 
void oteleGiris(long int *ptrdizi,int *toplamMisafir){
	long int TcNo;
	int gelenMisafir,i;
	printf("Misafir sayisini giriniz\n");
	scanf("%d",&gelenMisafir);
	newptr=(long int*)realloc(ptrdizi,toplamMisafir+gelenMisafir);
	if(!newptr){
		printf("Otelde Yer Yok");
		return ;
	}
	ptrdizi=newptr;
	for(i=0;i<gelenMisafir;i++){
		printf("Müsteri TC no\n);
		scanf("%ld",&TcNo);
		*(ptrdizi+i)=TcNo;		
	}
	*toplamMisafir=toplamMisafir+gelenMisafir;
	return ;
}
