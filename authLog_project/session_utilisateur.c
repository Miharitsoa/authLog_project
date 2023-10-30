#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"date.h"
#include"mois.h"


//<>
//#define LOGFILE "/home/tsoa/auth.txt"

typedef struct{
	char mois[5];
	char jour[3];
	char heure[15];
	char session[80];
	char username[40];
} Log; 

int countLine_inLogFile_for_EachUser(FILE*fp,char*value);

int main(){
	//Programme en C affichant les sessions d'utilisateurs et l'affichant dans un navigateur à l'aide du CGI(Common Gateway Interface)
	printf("Content-type:text/html\n\n");
	printf("<html>\n");
	printf("<head>\n");
	printf("<title>Sessions des utilisateurs dans Lubuntu18.04.5 issu de /var/log/auth.log</title>\n");
	printf("<meta charset=\"utf-8\">\n");
	printf("</head>\n");
	printf("<body>\n");
	printf("<h1>Sessions ouvertes et fermees des utilisateurs sur Lubuntu18.04.5</h1>\n");
/* 	printf("<table>\n");
	printf("<tr>\n");
	printf("<th>Date de session</th>\n");
	printf("<th>Heure de session</th>\n");
	printf("<th>Type de session</th>\n");
	printf("<th>Nom d'utilisateur</th>\n");
	printf("</tr>\n");
*/
	
	
	
 	
	
	char*utilisateur=getenv("QUERY_STRING");
	char*name=strtok(utilisateur,"=");
	char*value=strtok(NULL,"\n");
//	printf("<p>value=%s</p>\n",value);;
	char line[1500];	
//	system("sudo cat /var/log/auth.log > /home/tsoa/auth.txt");
 	FILE*fp=fopen("/var/log/auth.log","r");
		if(fp==NULL){
			printf("Erreur lors de l'ouverture du fichier /var/log/auth.log\n");
			return EXIT_FAILURE;
	}
	 int nb_button=(countLine_inLogFile_for_EachUser(fp,value)/10);
	printf("%d\n",nb_button);
	
	 printf("<form action=\"display_session_utilisateur.cgi\" method=\"get\">\n");
	for(int i=0;i<nb_button;i++){
		printf("<input type=\"submit\" value=\"%d\" name=%s>\n",i+1,value);
	}
	printf("</form>\n");
	
			

// 	printf("</table>\n");
	printf("</body>\n");
	printf("</html>\n"); 
	fclose(fp);
	return 0;
}
  int countLine_inLogFile_for_EachUser(FILE*fp,char*value){
	char line[1024];
	int count=0;
	while(fgets(line,sizeof(line),fp)){
		if(strstr(line,"session opened") || strstr(line,"session closed")){
				if(strstr(line,value))
					count++;
		}
	}
	return count;
}
