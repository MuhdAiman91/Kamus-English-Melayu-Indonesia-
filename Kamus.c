#include <stdio.h>	//Mengakses file library stdio.h
#include <stdlib.h>	//Mengakses file library stdlib.h
#include <conio.h>
#include <string.h>

void main_menu()
{
	system("cls");
	printf("App Translator\n\n");
	printf("Menu:\n");
	printf("[1] Add Data\n");
	printf("[2] Read Data\n");
	printf("[3] Translate\n");
	printf("[4] About\n");
	printf("[5] Quit\n\n");
	printf("Choice : ");
}

void menu_terjemahan()
{
	system("cls");
	printf ("Menu Bahasa\n");
	printf ("[1] Indonesia\n");
	printf ("[2] Melayu\n");
	printf ("[3] English\n");
	printf ("[4] Back\n");
	printf ("Choice : ");
}

void about()
{
	system("cls");
	printf("\nMADE BY:\n\n");
	printf("MUHAMMAD AIMAN BIN ABD AZIS\n");
}

void menu_finish()
{
	printf("\n[1] Repeat\n");
	printf("[2] Back\n");
	printf("[3] Quit\n");
	printf ("Choice : ");
}

int main(void) 		//Fungsi yang harus ada pada setiap program C
{
	FILE *akses;        //deklarasi variabel bertipe pointer ke file
	int i, n, pilih;
	char Ind[20], Eng[20], Mel[20], msg[1000][15];
	//int umur;
	menu :
	main_menu();
	fflush(stdin);
	scanf("%d", &pilih);
	switch (pilih)
	{
		case 1:
			write:
			if ((akses = fopen("Data_terjemahan.txt", "a+")) == NULL)    //buka file
			{
				printf("ERROR: File tidak dapat dibuka!\n");
			}
			system("cls");
			printf("Total data = "); 
			scanf("%d", &n); 
			// tulis ke file -> copy data dari variabel
			for(i=1; i<=n; i++)
			{
				printf("Data %d: \n", i);
				printf("Indonesia : "); fflush(stdin); scanf("%s", &Ind);
				printf("Melayu    : "); fflush(stdin); scanf("%s", &Mel);
				printf("English   : "); fflush(stdin); scanf("%s", &Eng);
				printf("\n");
				fprintf(akses, "%s\n", Ind);
				fprintf(akses, "%s\n", Mel);
				fprintf(akses, "%s\n", Eng);
			}
			system ("pause");
			fclose(akses);        //tutup file
			menu_finish();
			fflush(stdin);
			scanf_s ("%d", &pilih);
			if (pilih == 1 )
			{
				goto write;
			}
			else if (pilih == 2)
			{
				goto menu;
			}
			else if (pilih == 3)
			{
				exit(0);
			}
			break;
		case 2:
			read:
			i=0;
			if ((akses = fopen("Data_terjemahan.txt", "r")) == NULL)	
			{
				printf("ERROR: File tidak dapat dibuka!\n");
			}
			system("cls");
			// baca dari file -> copy data ke variabel
			while(fscanf(akses, "%s %s %s", &Ind, &Mel, &Eng) != EOF)
			{
				printf("Data %d:\n", ++i);
				printf("Indonesia : %s\n", Ind);
				printf("Melayu    : %s\n", Mel);
				printf("English   : %s\n\n", Eng);
			}
			system ("pause");
			fclose(akses);
			menu_finish();
			fflush(stdin);
			scanf_s ("%d", &pilih);
			if (pilih == 1 )
			{
				goto read;
			}
			else if (pilih == 2)
			{
				goto menu;
			}
			else if (pilih == 3)
			{
				exit(0);
			}
			break;
		case 3:
			terjemahan:
			if ((akses = fopen("Data_terjemahan.txt", "a+")) == NULL)    //buka file
			{
				printf("ERROR: File tidak dapat dibuka!\n");
			}
			system ("cls");
			menu_terjemahan();
			fflush(stdin);
			scanf("%d", &pilih);
			switch(pilih)
			{
				case 1:
					ind:
					system("cls");
					{
						for (i=1;i<=1000;i++)
						fgets(msg[i],sizeof(msg),akses);
						printf("Indonesia :");
						fflush(stdin);
						scanf("%s",&Ind);
						strcat(Ind,"\n");
						printf("\nMelayu : ");
						for (i=1;i<=1000;i++)
						if(strcmp(Ind,msg[i])==0)
						printf("%s",msg[i+1]);
						printf("\nEnglish : ");
						for (i=1;i<=1000;i++)
						if(strcmp(Ind,msg[i])==0)
						printf("%s\n",msg[i+2]);
					}
					system ("pause");
					fclose(akses);
					menu_finish();
					fflush(stdin);
					scanf_s ("%d", &pilih);
					if (pilih == 1 )
					{
						goto ind;
					}
					else if (pilih == 2)
					{
						goto terjemahan;
					}
					else if (pilih == 3)
					{
						exit(0);
					}
					break;
				case 2:
					mel:
					system("cls");
					{
						for (i=1;i<=1000;i++)
						fgets(msg[i],sizeof(msg),akses);
						printf("Melayu :");
						fflush(stdin);
						scanf("%s",&Mel);
						strcat(Mel,"\n");
						printf("\nIndonesia : ");
						for (i=1;i<=1000;i++)
						if(strcmp(Mel,msg[i])==0)
						printf("%s",msg[i-1]);
						printf("\nEnglish : ");
						for (i=1;i<=1000;i++)
						if(strcmp(Mel,msg[i])==0)
						printf("%s\n",msg[i+1]);
					}
					system ("pause");
					fclose(akses);
					menu_finish();
					fflush(stdin);
					scanf_s ("%d", &pilih);
					if (pilih == 1 )
					{
						goto mel;
					}
					else if (pilih == 2)
					{
						goto terjemahan;
					}
					else if (pilih == 3)
					{
						exit(0);
					}
					break;
				case 3:
					eng:
					system("cls");
					{
						for (i=1;i<=1000;i++)
						fgets(msg[i],sizeof(msg),akses);
						printf("English :");
						fflush(stdin);
						scanf("%s",&Eng);
						strcat(Eng,"\n");
						printf("\nIndonesia : ");
						for (i=1;i<=1000;i++)
						if(strcmp(Eng,msg[i])==0)
						printf("%s",msg[i-2]);
						printf("\nMelayu : ");
						for (i=1;i<=1000;i++)
						if(strcmp(Eng,msg[i])==0)
						printf("%s\n",msg[i-1]);
					}
					system ("pause");
					fclose(akses);
					menu_finish();
					fflush(stdin);
					scanf_s ("%d", &pilih);
					if (pilih == 1 )
					{
						goto eng;
					}
					else if (pilih == 2)
					{
						goto terjemahan;
					}
					else if (pilih == 3)
					{
						exit(0);
					}
					break;
				case 4:
				goto menu;
				break;
			}
			system ("pause");
			break;
		case 4:
			about();
			system ("pause");
			goto menu;
			break;
		case 5:
			exit (0);
			break;
		default:
			printf("Unidentified Choice\n");
			system ("pause");
			goto menu;
		}		
	system("pause");
	return (0);
}