#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"LBI_CLASS_ETU.h"

char niv[][7]={"L1","L2","L3","M1","M2"};
char spec[][6]={"GL","RISp","RTSp","RI","RT","GDA","II",};
char code[][3]={"Cj","Cs"};
int idclass=0;
int idetu=0;

/******************* MENU **********************/
int Main_menu(){
int choix;
    do{
        system("cls");
        puts("****MAIN MENU*****\n");
        puts("1- CLASSE");
        puts("2- ETUDIANT");
        puts("3- STATISTIQUES");
        puts("4- QUITTER");
        puts("Faites votre choix:");
        scanf("%d",&choix);
    }while(choix<1 || choix>4);

    return choix;
}
int Menu1(){
int choix;
    do{
        system("cls");
        puts("****MENU_CLASSE*****\n");
        puts("1- Ajout d une classe");
        puts("2- Afficher les Etudiants Par Classe");
        puts("3- Supprimer une Classe");
        puts("4- Retour");
        puts("5- Quitter");
        puts("Faites votre choix:");
        scanf("%d",&choix);
    }while(choix<1 || choix>4);

    return choix;
}
int Menu2(){
int choix;
    do{
        system("cls");
        puts("****MENU_ETUDIANT*****\n");
        puts("1- Inscrire un Etudiant");
        puts("2- Modifier un Etudiant");
        puts("3- Supprimer un Etudiant");
        puts("4- Retour");
        puts("5- Quitter");
        puts("Faites votre choix:");
        scanf("%d",&choix);
    }while(choix<1 || choix>4);

    return choix;
}

int Menu3(){
int choix;
    do{
        system("cls");
        puts("****MENU_STATISTIQUE*****\n");
        puts("1- Nombre Etudiant Par Classe");
        puts("2- Nombre Etudiant Par sexe et Par Classe");
        puts("3- Liste Etudiant Par Classe");
        puts("4- Retour");
        puts("5- Quitter");
        puts("Faites votre choix:");
        scanf("%d",&choix);
    }while(choix<1 || choix>4);

    return choix;
}
void Initiate_Liste(control Liste){
Liste->T=NULL;
Liste->Q=NULL;
}

/**************************CLASSE*************************/
void ADD_CLASS(control Liste){
    char *ch;
    listB P;
    int N;
    system("cls");
     P=(listB)malloc(sizeof(listecl));
     P->infos=(classe*)malloc(sizeof(classe));
     Scan_Class(P->infos);
     P->suiv=NULL;
     P->prec=NULL;
    if(Liste->T==NULL){
    Liste->T=P;
    Liste->Q=P;
    }
    else{
    P->prec=Liste->Q;
    Liste->Q->suiv=P;
    Liste->Q=P;

    }
    P=NULL;
}
char * get_specialite(classe *CL){
    char *ch;
    int t;
    int i;
    do{
    CL->specialite=(char*)malloc(sizeof(char));
    system("cls");
    printf("Choississez la specialite de la classe\n");
    for(i=0;i<7;i++){
    printf("%d-%s\n",i+1,spec[i]);
    }
    ch=(char*)malloc(5*sizeof(char));
    fflush(stdin);
    gets(ch);
    t=*ch-48;
    strcpy(CL->specialite,spec[t-1]);
        if(t<1 || t>7 || strlen(ch)>1){
            system("cls");
            printf("DESOLE SPECIALITE NON-DISPONIBLE\n");
            system("pause");
            system("cls");
        }
    }while(t<1 || t>7 || strlen(ch)>1);
    return CL->specialite;
}
char * get_niveau(classe *CL){
    char *ch;
    int t;
    int i;
    do{
    CL->niveau=(char*)malloc(sizeof(char));
    system("cls");
    printf("Choississez le niveau de la classe\n");
    for(i=0;i<5;i++){
    printf("%d-%s\n",i+1,niv[i]);
    }
    ch=(char*)malloc(5*sizeof(char));
    fflush(stdin);
    gets(ch);
    t=*ch-48;
    strcpy(CL->niveau,niv[t-1]);
        if(t<1 || t>5 || strlen(ch)>1){
            system("cls");
            printf("DESOLE NIVEAU NON-DISPONIBLE\n");
            system("pause");
            system("cls");
        }
    }while(t<1 || t>5 || strlen(ch)>1);
    return CL->niveau;
}
char * get_code(classe *CL){
    int i;
    char *ch;
    int t;
    CL->code=(char*)malloc(sizeof(char));
    do{
    system("cls");
    printf("Choississez le code de la classe\n");
    for(i=0;i<2;i++){
    printf("%d-%s\n",i+1,code[i]);
    }
    ch=(char*)malloc(5*sizeof(char));
    fflush(stdin);
    gets(ch);
    t=*ch-48;
        if(t<1 || t>2 || strlen(ch)>1){
            system("cls");
            printf("DESOLE CODE NON-DISPONIBLE\n");
            system("pause");
            system("cls");
        }
    }while(t<1 || t>2 || strlen(ch)>1);
    strcpy(CL->code,code[t-1]);

    return CL->code;
}
void Scan_Class(classe * CL){
        char *ch;
        int verif;
        CL->idclasse=++idclass;
        CL->libclasse=(char*)malloc(20*sizeof(char));
        strcpy(CL->libclasse,get_niveau(CL));
        //system("cls");
        strcat(CL->libclasse,get_specialite(CL));
        //system("cls");
        strcat(CL->libclasse,get_code(CL));
        //system("cls");
        //printf("%s",cl->libclass);
        //ADDING(CL);
        do{
        system("cls");
        printf("Voullez-vous ajouter un Etudiant ?\n");
        printf("1-Oui\n");
        printf("2-Non\n");
        CL->TEtud=NULL;
        ch=(char*)malloc(5*sizeof(char));
        fflush(stdin);
        gets(ch);
        verif=*ch-48;
        if((verif<1 || verif>2) || strlen(ch)>1){
            system("cls");
            printf("DESOLE CHOIX NON-DISPONIBLE\n");
            system("pause");
            system("cls");
        }
        }while(verif<1 || verif>2 || strlen(ch)>1);
        CL->Q=NULL;
        CL->lenght=0;
        if(verif==1){
            ADD_Etudiant(CL);
        }
}
void Print_Class(control Liste){
    listB P;
    P=Liste->T;
    if(P == NULL){
    system("cls");
    printf("Il n y a pas de classe dans la liste\n");
    return 0;
    }
    system("cls");
    printf("LES CLASSES DISPONIBLES:\n");
    do{
    Liste_Class(P->infos);
    P=P->suiv;
    }while(P!=NULL);
}
void Liste_Class(classe *CL){
printf("IdClass:%d\n",CL->idclasse);
printf("LibelleClass:%s\n",CL->libclasse);
}

void Delete_Class(control Liste){
    listB p,pp;
    int N,i=1;
    char *ch;
    if(Liste->T==NULL){
    printf("Il n y a aucune classe a suppprimer\n");
    system("pause");
    return 0;
    }

    do{
        system("cls");
    Print_Class(Liste);
    printf("Saississez l id de la classe a supprimmer\t");
    p=Liste->T;
    fflush(stdin);
    ch=(char*)malloc(5*sizeof(char));
    gets(ch);
    N = *ch - 48;
        if(Check_Id_Class(Liste,N)==1){
            system("cls");
            printf("DESOLE CHOIX NON DISPONIBLE\n");
            system("pause");
        }
    }while(Check_Id_Class(Liste,N)==1);

    do{
        if(N == p->infos->idclasse){
        break;
        }
        pp=p;
        p=p->suiv;
        i++;
    }while(p!= NULL);
    if(Liste->T==p){

    if(Liste->T!=Liste->Q){
     Liste->T=Liste->T->suiv;
     Liste->T->prec = NULL;
    }
    else{
        Initiate_Liste(Liste);
    }

    }
    else{
        if(p==Liste->Q){
        Liste->Q=Liste->Q->prec;
        Liste->Q->suiv = NULL;
        }
        else{
    p = p->suiv;
    pp->suiv = NULL;
    pp->suiv = p;
    p->prec=pp;
    }
    }
    system("cls");
printf("La classe a ete supprime\n");
system("pause");

}
/*************************ETUDIANT********************************/
void ADD_Etudiant(classe *CL){
    listeMEtu p=(listeMEtu)malloc(sizeof(liste));
    int N;
    char *ch;
    do{
        fflush(stdin);
        p->infos=(Etudiant*)malloc(sizeof(Etudiant));
        Scan_Student(p->infos);
        p->suiv = NULL;
        if(CL->TEtud==NULL){
         CL->TEtud=p;
         CL->Q=p;
         CL->lenght=1;
        }
        else{
        CL->lenght++;
        CL->Q->suiv=p;
        CL->Q=p;
        }
        p=NULL;
        do{
            system("cls");
            printf("Voulez vous encore ajouter ?\n");
            printf("1-Oui\n");
            printf("2-Non\t");
            ch=(char*)malloc(5*sizeof(char));
            fflush(stdin);
            gets(ch);
            N = *ch - 48;
            if((N<1 || N>2) || strlen(ch)>1){
                system("cls");
                printf("DESOLE CHOIX NON-DISPONIBLE\n");
                system("pause");
            }
        }while(N<1 || N>2 || strlen(ch)>1);
        if(N!=1){
        break;
        }
    }while(1);
    CL->Q->suiv=CL->TEtud ;
}

void Scan_Student(Etudiant *ET){

    system("cls");
    ET->idET=++idetu;
    fflush(stdin);
    ET->nom=(char*)malloc(10*sizeof(char));
    system("cls");
    printf("Entrer le nom de l etudiant :");
    gets(ET->nom);
    printf("Entrer son prenom :");
    ET->prenom=(char*)malloc(30*sizeof(char));
    gets(ET->prenom);
    do{
    printf("Donner son sexe (m/f) :");
    ET->sexe=(char*)malloc(10*sizeof(char));
    gets(ET->sexe);
    if((strcmp(ET->sexe,"M")!=0) && (strcmp(ET->sexe,"m")!=0) &&  (strcmp(ET->sexe,"F")!=0) &&  (strcmp(ET->sexe,"f")!=0)){
        system("cls");
        printf("Veuillez bien entrer m ou f!!!!\n");
        system("pause");
        }
    }while((strcmp(ET->sexe,"M")!=0)&&  (strcmp(ET->sexe,"m")!=0) &&  (strcmp(ET->sexe,"F")!=0) &&  (strcmp(ET->sexe,"f")!=0));
}

void Print_ETudiant(control Liste){
    listB LB;
    LB=Liste->T;
    if(LB!=NULL){
        system("cls");
    do{
        Liste_Etudiant(LB->infos);
        LB=LB->suiv;
    }while(LB!=NULL);
    system("pause");
    }
}
//POUR LISTER LES ETUDIANTS
void Liste_Etudiant(classe *CL){
    listeMEtu p;
    if(CL->TEtud==NULL){
    return 0;
    }
    p=(listeMEtu*)malloc(sizeof(listeMEtu));
    p=CL->TEtud;
    do{

    printf("Id:%d\n",p->infos->idET);
    printf("Nom:%s\n",p->infos->nom);
    printf("Prenom:%s\n",p->infos->prenom);
    printf("Sexe:%s\n\n",p->infos->sexe);
    p = p->suiv;
    }while(p!= CL->TEtud);

}

void Subscribe_Etudiant(control Liste){
    system("cls");
    char *ch;
    int N;
    listB p;
    if(Liste->T ==NULL){
    printf("CREER D ABORD UNE CLASSE POUR INSCRIRE UN ETDIANT\n");
    system("pause");
    ADD_CLASS(Liste);
    return;
    }
    system("cls");

    p = Liste->T;
    do{
        system("cls");
        Print_Class(Liste);
    printf("Choississez la Classe ou inscrire l'Etudiant en entrant l'id:");
    ch=(char*)malloc(5*sizeof(char));
    fflush(stdin);
    gets(ch);
    N = *ch - 48;
    if(Check_Id_Class(Liste,N)==1){
    system("cls");
    printf("DESOLE CETTE CLASSE N EXISTE PAS\n");
    system("pause");

}

}while(Check_Id_Class(Liste,N)==1);
    system("cls");
    do{
        if(N==p->infos->idclasse){
        ADD_Etudiant(p->infos);
        system("cls");
        Liste_Etudiant(p->infos);
        system("pause");
        break;
        }
        p = p->suiv;
    }while(p!= NULL);
   Liste_Etudiant(Liste->T->infos);

}
void Delete_Student(control Liste){
    char *ch;
    int N;
    listB p;
    listeMEtu pp;
    p=Liste->T;
    if(p==NULL){
        system("cls");
    printf("La liste ne contient rien!!!!\n");
    system("pause");
    return 0;
    }

    do{
        system("cls");
     Print_Class(Liste);
    printf("Entrer l id de la classe de l etudiant a supprimer:");
    ch=(char*)malloc(5*sizeof(char));
    fflush(stdin);
    gets(ch);
    N = *ch - 48;
    if(Check_Id_Class(Liste,N)==1){
        system("cls");
    printf("CETTE CLASSE N EXISTE PAS\n");
    system("pause");
    }
    }while(Check_Id_Class(Liste,N)==1);
    do{
            if(N == p->infos->idclasse){
            Delete_Student_From_Classe( p->infos);
            break;
    }
            pp=p;
            p = p->suiv;

        }while(p!= NULL);
    }
void Delete_Student_From_Classe(classe *CL){
        int N;
        char *ch;
        listeMEtu p,pp;
        p = CL->TEtud;
        if(p==NULL){
        system("cls");
        printf("Cette Classe ne contient pas d Etudiant\n");
        system("pause");
        }
    do{
         system("cls");
         Liste_Etudiant(CL);
         printf("Entrer l id de l Etudiant a Supprimer\t");
         ch=(char*)malloc(5*sizeof(char));
         fflush(stdin);
         gets(ch);
         N = *ch - 48;
        if(Check_Id_Student(CL->TEtud,N)==1){
             system("cls");
        printf("DESOLE CHOIX NON DISPONIBLE\n");
        system("pause");
        }
    }while(Check_Id_Student(CL->TEtud,N)==1);
            pp = CL->TEtud;
            do{
            if(N == p->infos->idET){

            break;
            }
            pp=p;
            p = p->suiv;

        }while(p!= CL->TEtud);
        if(p == CL->TEtud && CL->lenght==1 ){
        CL->TEtud=NULL;
        CL->Q=NULL;
        CL->lenght--;
             system("cls");
             printf("Cet etudiant a ete supprimer de la classe.");
             system("pause");
        }
        if(p == CL->TEtud){
        CL->TEtud=CL->TEtud->suiv;
        CL->Q->suiv = CL->TEtud;
        }
        else{
        if(p==CL->Q){
        CL->Q = pp;
        CL->Q->suiv = NULL;
        CL->Q->suiv =CL->TEtud;
        }
        else{
        p=p->suiv;
        pp->suiv = NULL;
        pp->suiv = p;
        }
    }
        system("cls");
        puts("Cet etudiant a ete supprimer de la classe.");
        system("pause");
        CL->lenght--;
        if(CL->TEtud==NULL){
            system("cls");
            puts("Cette classe ne contient pas d etudiant");
            system("pause");
        }
        Liste_Etudiant(CL);
    }
void Modify_Student(control Liste){
     int N;
     char *ch;
     listB p;
     listeMEtu pp;
     p=Liste->T;

    if(p==NULL){
        system("cls");
        printf("La liste est vide\n");
        system("pause");
    }
    do{
        system("cls");
        Print_Class(Liste);
        printf("Entrer l id de la Classe de l Etudiant a modifier:");
        ch=(char*)malloc(5*sizeof(char));
        fflush(stdin);
        gets(ch);
        N = *ch - 48;
        if(Check_Id_Class(Liste,N)==1){
        printf("Desole Cette classe n existe pas!!!!\n");
        system("pause");
        }
    }while(Check_Id_Class(Liste,N)==1);
        system("cls");
    do{
        if(N==p->infos->idclasse){
            Modify_Student_From_Classe( p->infos);
        }
            pp=p;
            p = p->suiv;
        }while(p!= NULL);
    }

void Modify_Student_From_Classe(classe *CL){
        int N;
        char *ch;
        listeMEtu p,pp;
        p=CL->TEtud;
        if(p==NULL){
            system("cls");
            printf("Cette classe est vide!!!!!\n");
            system("pause");
        }
        do{
            system("cls");
             Liste_Etudiant(CL);
             printf("Entrer l'id de l'Etudiant a Modifier :");
             ch=(char*)malloc(5*sizeof(char));
             fflush(stdin);
            gets(ch);
            N = *ch - 48;
            if(Check_Id_Student(CL->TEtud,N)==1){
                system("cls");
                printf("DESOLE CHOIX NON DISPONIBLE\n");
                system("pause");
            }
        }while(Check_Id_Student(CL->TEtud,N)==1);
        system("cls");
                pp=CL->TEtud;
            do{
                if(N==p->infos->idET){
                break;
                }
                pp=p;
                p = p->suiv;
            }while(p!= CL->TEtud);
        if(p!= NULL){
            fflush(stdin);
            system("cls");
            printf("Entrer le nom de l'etudiant:");
            gets(p->infos->nom);
             system("cls");
            printf("Entrer son prenom:");
            gets(p->infos->prenom);
             system("cls");
             do{
                system("cls");
                printf("Donner son sexe (m/f):");
                gets(p->infos->sexe);
                if((strcmp(p->infos->sexe,"M")!=0) && (strcmp(p->infos->sexe,"m")!=0) &&  (strcmp(p->infos->sexe,"F")!=0) &&  (strcmp(p->infos->sexe,"f")!=0)){
                    system("cls");
                    printf("Veuillez bien entrer m ou f!!!!\n");
                    system("pause");
                }
            }while((strcmp(p->infos->sexe,"M")!=0) && (strcmp(p->infos->sexe,"m")!=0) &&  (strcmp(p->infos->sexe,"F")!=0) &&  (strcmp(p->infos->sexe,"f")!=0));
        }
}
/****************************STATISTIQUES*****************************/
void Among_Student_By_Class(control Liste){
    listB P;
    P=Liste->T;
    if(P == NULL){
        system("cls");
        printf("La liste est vide!!!!!!\n");
        system("pause");
        return 0;
    }
    system("cls");
    printf("LES CLASSES DISPONIBLES:\n ");
    do{
    printf("IdClass:%d\n",P->infos->idclasse);
    printf("LibellesClass:%s\n",P->infos->libclasse);
    printf("Effectifs:%d\n",P->infos->lenght);
    printf("\n");
    P=P->suiv;
    }while(P!=NULL);
    system("pause");
}
void Among_Student_By_Sex_Class(control Liste){
    listB P;
    P=Liste->T;
    if(P == NULL){
        system("cls");
        printf("La liste est vide\n");
        system("pause");
        return 0;
    }
    system("cls");
    printf("LES CLASSES DISPONIBLES:\n ");
    do{
    printf("IdClass:%d\n",P->infos->idclasse);
    printf("LibellesClass:%s\n",P->infos->libclasse);
    printf("Effectifs:%d\n",P->infos->lenght);
    Count_Student_By_Sex(P->infos);
    printf("\n\n");
    P=P->suiv;
    }while(P!=NULL);
    system("pause");
  }

void Count_Student_By_Sex(classe *CL){
    int i=0,j=0;
    listeMEtu p;
    if(CL->TEtud==NULL){
        return 0;
    }
    p=(listeMEtu*)malloc(sizeof(listeMEtu));
    p=CL->TEtud;
    do{

    if(strcmp(p->infos->sexe,"M")==0 || strcmp(p->infos->sexe,"m")==0){
    i++;
    }
    else j++;
    p = p->suiv;
    }while(p!= CL->TEtud);
    printf("LE NOMNRE D'ETUDIANT MASCULIN EST DE: %d\n",i);
    printf("LE NOMBRE D'ETUDIANT FEMININ EST DE: %d\n",j);
}
void Liste_Student_By_Class(control Liste){
    if(Liste->T==NULL){
        system("cls");
        printf("La liste est vide!!!!!\n");
        system("pause");

    }
    listB LB;
    LB=Liste->T;
    if(LB!=NULL){
        system("cls");
    do{
        if(LB->infos->lenght!=0){
        Liste_Class(LB->infos);
        }
        Liste_Etudiant(LB->infos);
        printf("\n\n");
        LB = LB->suiv;
    }while(LB!=NULL);
    system("pause");

    }

 }
/***************************Verification ID***************************/
int Check_Id_Class(control Liste,int matricule){
    int test=0;
    listB p;
    p=Liste->T;
    do{
       if(p->infos->idclasse==matricule){
           p=NULL;
       return test;
       }
        p= p->suiv;
    }while(p!=NULL);
    test=1;
    p=NULL;
    return test;
    }

int Check_Id_Student(listeMEtu LC,int matricule){
    int test=0;
    listeMEtu p;
    p=LC;
    do{
       if(p->infos->idET==matricule){
           p=NULL;
       return test;
       }
        p = p->suiv;
    }while(p!=LC);
    p =NULL;
    test=1;
    return test;
}
/*void ADDING(classe *CL){
char rep;
do{
        system("cls");
         ADD_Etudiant(CL);
         fflush(stdin);
        puts("Voulez vous Continuez O/N");
         rep=getchar();
}while(rep=='O' || rep=='o');

}*/
