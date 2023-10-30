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
	
	printf("<table>\n");
	printf("<tr>\n");
	printf("<th>Nom d'utilisateur</th>\n");
/*	printf("<th>Mot de passe crypte</th>");
	printf("<th>ID de l'utilisateur</th>\n");
	printf("<th>ID du groupe</th>\n");
	printf("<th>Commentaire</th>\n");
	printf("<th>Repertoire de connexion</th>\n");      */
	printf("<th>Interpreteur de commande shell</th>\n");
	printf("</tr>\n");
	
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
		//	sscanf(line,"%[*:]:%[*:]:%[*:]:%[*:]:%[*:]:%[*:]:%s",username,crypted_passwd,uid,gid,comment,connectDir,shell);
			printf("<tr>\n");
			printf("<td>%s</td>\n",username);
		/*	printf("<td>%s</td>\n",crypted_passwd);
			printf("<td>%s</td>\n",uid);
			printf("<td>%s</td>\n",gid);
			printf("<td>%s</td>\n",comment);
			printf("<td>%s</td>\n",connectDir);           */
			printf("<td>%s</td>\n",shell);
			printf("</tr>\n");
		}
	}
	fclose(fp);
	
	printf("</table>\n");
	
	printf("</body>\n");
	printf("</html>\n");
	
	return 0;
}
