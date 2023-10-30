#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>

int main(){
	printf("Content-type:text/html\n\n");
	printf("<html>\n");
	printf("<head>\n");
	printf("<title>Liste des utilisateurs</title>\n");
	printf("</head>\n");
	printf("<body>\n");
	
	printf("<h1>Liste des utilisateurs dans Lubuntu18.04.5</h1>\n");
	
	//printf("<form action=\"display_session_utilisateur.cgi\" method=\"get\">\n");
	printf("<form action=\"session_utilisateur.cgi\" method=\"get\">\n");
	
	FILE*fp;
	char line[256];
	fp=fopen("/etc/passwd","r");
	if(fp==NULL){
		printf("<p>Erreur lors de l'ouverture du fichier</p>\n");
		return 1;
	}
	else{
		rewind(fp);
		while(fgets(line,sizeof(line),fp)!=NULL){
			char*username=strtok(line,":");
			char*crypted_passwd=strtok(NULL,":");
			char*uid=strtok(NULL,":");
			char*gid=strtok(NULL,":");
			char*comment=strtok(NULL,":");
			char*connectDir=strtok(NULL,":");
			char*shell=strtok(NULL,"\n");
			printf("<input type=\"submit\" value=\"%s\" name=\"user\">\n",username);          
		}
	}
	fclose(fp);
	
	printf("</form>\n");
	
	printf("</body>\n");
	printf("</html>\n");
	
	return 0;
}

