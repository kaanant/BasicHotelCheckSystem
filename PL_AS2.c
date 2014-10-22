#include <stdio.h>
#include <stdlib.h>
    
long int * oteleGiris(long int *,int *);		
long int * oteldenCikis(long int *,int *,long int *);
void misafirList(int ,long int *);

int main(){
	int menu;
	long int *ptrdizi,*newptr2;
	int toplamMisafir=0;

	ptrdizi=(long int *)malloc(sizeof(long int));

	do{	
		printf("\t\tMenu\n1-oteleGiris\n2-oteldenCikis\n3-MisafirListesi\n4-EXIT\n");
		scanf("%d",&menu);
	
		if (menu==1){
			ptrdizi=oteleGiris(ptrdizi,&toplamMisafir);	
		}
		else if(menu==2){
			ptrdizi=oteldenCikis(ptrdizi,&toplamMisafir,newptr2);
		}
		else if(menu==3){
			misafirList(toplamMisafir,ptrdizi);	
		}		
	}while(menu!=4);		
	return 0;  
}
 
long int * oteleGiris(long int *ptrdizi,int *ptrToplamMisafir){
	int gelenMisafir=0,i=0;
	printf("Misafir sayisini giriniz\n");
	scanf("%d",&gelenMisafir);
	long int *newptr=(long int*)realloc(ptrdizi,*ptrToplamMisafir+gelenMisafir);
	if(!newptr){
		printf("Otelde Yer Yok");
		return ;
	}
	ptrdizi=newptr;
	for(i=0;i<gelenMisafir;i++){
		printf("Müsteri TC no\n");
		scanf("%ld",ptrdizi + *ptrToplamMisafir + i);
				
	}

	*ptrToplamMisafir += gelenMisafir;
	return ptrdizi;
}
long int * oteldenCikis(long int *ptrdizi,int *toplamMisafir, long int *newptr2){
	int cikanMisafir=0,i=0,j=0,k=0;
	int sonMisafir=0;
	long int Tc=0;

	printf("Otelden cikis yapan kisi sayisini giriniz");
	scanf("%d",&cikanMisafir);
	for(i=0;i<cikanMisafir;i++){
		printf("cikanMisafir'in Tc no giriniz");
		scanf("%ld",&Tc);
		for(j=0;j<(*toplamMisafir);j++){
			if(Tc==*(ptrdizi+j))
				*(ptrdizi+j)=0;
		}
	}
	sonMisafir=(*toplamMisafir)-cikanMisafir;
	//printf("%d\n",sonMisafir);
	newptr2=(long int*)malloc(sonMisafir*sizeof(long int));
		if(!newptr2){
		printf("\nOtelde Yer Yok");
		return;
	}
	for(i=0;i<(*toplamMisafir);i++){
		if((*(ptrdizi+i))!=0){
			*(newptr2+k)=*(ptrdizi+i);
			k++;
		}
	}
	free(ptrdizi);
	ptrdizi=newptr2;
	return ptrdizi;
}
void misafirList(int toplamMisafir,long int *ptrdizi){
	int i;
	for ( i=0;i<toplamMisafir;i++){
		printf("%d--%ld\n",i+1,*(ptrdizi+i));
	}
}
