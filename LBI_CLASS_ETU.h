#include<stdio.h>
#include<stdlib.h>
/*******STRUCTURE ETUDIANT*******/
typedef struct{
int idET;
char * nom;
char * prenom;
char * sexe;
}Etudiant;
/******liste Mono Etudiant*********/
typedef struct liste liste;
typedef liste* listeMEtu;
struct liste{
Etudiant *infos;
listeMEtu suiv;
};
/************STRUCTURE CLASSE**************/
typedef struct{
int idclasse;
char * libclasse;
char * niveau;
char * specialite;
char * code;
listeMEtu TEtud;
listeMEtu Q;
int lenght;
}classe;
/******liste Bidirectionnele Classe*********/
typedef struct listecl listecl;
typedef listecl* listB;
struct listecl{
classe *infos;
listB prec;
listB suiv;
};
/******STRUCTURE DE CONTROLLE DE LA LISTE******/
struct control{
listB T;
listB Q;
};
typedef struct control* control;
typedef struct control controlElt;
int Main_menu();
int Menu1();
int Menu2();
int Menu3();
void ADD_CLASS(control Liste);
void Print_ETudiant(control Liste);
void Liste_Etudiant(classe *CL);
void Delete_Class(control Liste);
void ADD_Etudiant(classe *CL);
void Subscribe_Etudiant(control Liste);
void Modify_Student(control Liste);
void Delete_Student(control Liste);
int Check_Id_Student(listeMEtu Liste,int matricule);
int Check_Id_Class(control Liste,int matricule);
char * Get_specialite(classe *CL);
char * get_code(classe *CL);
char * Get_Code(classe *CL);
void Scan_Student(Etudiant *ET);
void Scan_Class(classe * CL);
void Initiate_Liste(control Liste);
void Print_Class(control Liste);
void Delete_Student_From_Classe(classe *CL);
void Count_Student_By_Sex(classe *CL);
void Modify_Student_From_Classe(classe *CL);
void Liste_Class(classe *CL);
void Among_Student_By_Class(control Liste);
void Among_Student_By_Sex_Class(control Liste);
void Liste_Student_By_Class(control Liste);


