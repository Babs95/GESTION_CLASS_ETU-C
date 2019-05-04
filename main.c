#include <stdio.h>
#include <stdlib.h>
#include"LBI_CLASS_ETU.h"

/**Auteur BABACAR NDIAYE ETUDIANT EN 3EME ANNNE Licence 3 Genie Logiciel
Dakar,Senegal
Email:Babsco95@gmail.com
Tel:77 144 02 91
**/
enum {CREATION_CLASSE=1,INSCRIPTION_MODIFICAITON_SUPPRESSION_ETUDIANT,
       STATISTIQUES_CLASSES,QUITTER
       };
int main()
{
   int wish;
   int wish2;
   int wish3;
   int wish4;
control Liste;
Liste=(control)malloc(sizeof(controlElt));
Initiate_Liste(Liste);
do{
wish=Main_menu();

    switch (wish){

    case CREATION_CLASSE:
         system("cls");
                         do{
                wish2= Menu1();

                    switch (wish2){

                    case 1:
                         system("cls");
                         puts("AJOUT D UNE CLASSE");
                         ADD_CLASS(Liste);
                         system("pause");
                        break;
                    case 2:
                         system("cls");
                         puts("Afficher les Etudiants Par Classe");
                         if(Liste->T==NULL ){
                         system("cls");
                         printf("La liste est vide!!!!!!\n");
                         system("pause");
                        break;
                        }
                        Print_ETudiant(Liste);
                        break;
                    case 3:
                         system("cls");
                         puts("Supprimer une Classe");
                         Delete_Class(Liste);
                         system("pause");
                        break;
                    case 4:
                         system("cls");
                         wish2=5;
                         system("pause");
                        break;
                    case 5:
                        exit(0);
                        //wish=4;
                        break;
                    }

                }while(wish2!=5);
         system("pause");
        break;
    case INSCRIPTION_MODIFICAITON_SUPPRESSION_ETUDIANT:
         system("cls");
          do{
                wish3= Menu2();

                    switch (wish3){

                    case 1:
                         system("cls");
                         puts("같같INSCRIPTION D UN ETUDIANT같같");
                         Subscribe_Etudiant(Liste);
                         system("pause");
                        break;
                    case 2:
                         system("cls");
                         puts("Modifier Un Etudiant");
                         Modify_Student(Liste);
                         system("pause");
                        break;
                    case 3:
                         system("cls");
                         puts("Supprimer Un Etudiant");
                         Delete_Student(Liste);
                         system("pause");
                        break;
                    case 4:
                         system("cls");
                         wish3=5;
                         system("pause");
                        break;
                    case 5:
                         wish=4;
                        break;
                    }

                }while(wish3!=5);
         system("pause");
        break;
    case STATISTIQUES_CLASSES:
         system("cls");
          do{
                wish4= Menu3();

                    switch (wish4){

                    case 1:
                         system("cls");
                         puts("NOMBRE D ETUDIANT PAR CLASSE");
                         Among_Student_By_Class(Liste);
                         system("pause");
                        break;
                    case 2:
                         system("cls");
                         puts("NOMBRE D ETUDIANT PAR SEXE ET PAR CLASSE");
                         Among_Student_By_Sex_Class(Liste);
                         system("pause");
                        break;
                    case 3:
                         system("cls");
                         puts("LISTE D ETUDIANT PAR CLASSE");
                         Liste_Student_By_Class(Liste);
                         system("pause");
                        break;
                    case 4:
                         system("cls");
                         wish4=5;
                         system("pause");
                        break;
                    case 5:
                        wish=4;
                        break;
                    }

                }while(wish4!=5);
         system("pause");
        break;
    case QUITTER:
        exit(0);
        break;
    }

}while(wish!=4);
   return 0;
}
