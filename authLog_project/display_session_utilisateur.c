#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"date.h"
#include"mois.h"

typedef struct{
	char mois[5];
	char jour[3];
	char heure[15];
	char session[80];
	char username[40];
} Log;

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
int main(){
	
	int button=1;
	char*query=getenv("QUERY_STRING");
	char*user_value=strtok(query,"=");
	char*button_value=strtok(NULL,"\n");
	printf("Content-type:text/html\n\n");
	printf("<html>\n");
	printf("<head>\n");
	printf("<title>session de l'utilisateur %s</title>\n",user_value);
	printf("<meta charset=\"utf-8\">\n");
	printf("</head>\n");
	printf("<body>\n");
	printf("<p>Sessions de l'utilisateur %s</p>\n",user_value);
	printf("</body>\n");
	printf("</head>\n");
	printf("<body>\n");
	printf("<p><strong><center>Session de l'utilisateur %s</center></strong></p>\n",user_value);
	
	//FILE*fp=fopen("/home/tsoa/auth.txt","r");
	FILE*fp=fopen("/var/log/auth.log","r");
	if(fp==NULL) exit(1);
	char userValue[30];
	strcpy(userValue,user_value);
	button=atoi(button_value);
	//printf("<p>%s %s %d</p>\n",userValue,user_value,button);
	char line[1500];
	Log*s=malloc((countLine_inLogFile_for_EachUser(fp,user_value)+10)*sizeof(Log));
	//int count=countLine_inLogFile_for_EachUser(fp,user_value);
	int count=0;
	//char mois[10];
    //char jour[5];
    //char heure[20];
    //char session[40];
    //char username[30];
	char prompt[100];
	char process[100];
	char describe[100];
	char sessionType[150];
	char ununused_string[10];
	char ununused_string1[20];
	while(fgets(line,sizeof(line),fp)!=NULL && count<countLine_inLogFile_for_EachUser(fp,user_value)){	
		if(strstr(line,"session opened") || strstr(line,"session closed")){
			
			strcpy(s[count].mois,strtok(line," "));
			strcpy(s[count].jour,strtok(NULL," "));
			strcpy(s[count].heure,strtok(NULL," "));
			strcpy(prompt,strtok(NULL," "));
			strcpy(process,strtok(NULL,":"));
			strcpy(describe,strtok(NULL,":"));
			strcpy(sessionType,strtok(NULL,"\n"));
			if(strstr(line,userValue)){
			 	if(!strstr(line,"by")){
					strcpy(s[count].session,strtok(sessionType,"f"));
					strcpy(ununused_string,strtok(NULL," "));
					strcpy(ununused_string1,strtok(NULL," "));
					strcpy(s[count].username,strtok(NULL,"\n"));
					//printf("<p>%s %s %s %s %s</p>\n",mois,jour,heure,session,username);
				}
				else{
					strcpy(s[count].session,strtok(sessionType,"f"));
					strcpy(ununused_string,strtok(NULL," "));
					strcpy(ununused_string1,strtok(NULL," "));
					strcpy(s[count].username,strtok(NULL,"b"));
					//printf("<p>%s %s %s %s %s</p>\n",mois,jour,heure,session,username);
				}
			}
			
		}
		
		count++;	
		//printf("<p>%d</p>\n",count);	
	}
	printf("<table>\n");
	printf("<tr>\n");
	printf("<th>Date de session</th>\n");
	printf("<th>Heure de session</th>\n");
	printf("<th>Type de session</th>\n");
	printf("<th>Nom d'utilisateur</th>\n");
	printf("</tr>\n");
	printf("<tr>\n");
	for(count=(10*button)-10;count<10*button;count++){
		printf("<td>%s&nbsp%snbsp%s</td>\n",getJourSemaine(determineJourSemaine(atoi(s[count].jour),monthToInteger(s[count].mois),2023)),s[count].jour,integerToMonths(monthToInteger(s[count].mois)));
		printf("<td>%s</td>\n",s[count].heure);
		printf("<td>%s</td>\n",s[count].session);
		printf("<td>%s</td>\n",s[count].username);
	}
	printf("</tr>\n");
	printf("</table>\n");
	//printf("<p>%d</p>\n",count);
	fclose(fp);
	printf("</body>\n");
	printf("</html>\n");
    return 0;
}
