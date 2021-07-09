#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#include <stdlib.h>
#include "definitions.h"

void client_side(int);
void user_handler(int, int);
void admin_handler(int, int);

int main(int argc, char const *argv[]) 
{ 
	int sock = 0; 
	struct sockaddr_in serv_addr;
	char buffer[1024] = {0}; 
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
	{ 
		perror("Socket");
		return -1; 
	} 

	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_port = htons(PORT); 

	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
	{ 
		perror("Address"); 
		return -1; 
	} 

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
	{ 
		perror("connection");
		return -1; 
	} 
	client_side(sock);
	return 0; 
} 

void client_side(int sock){
	int option;
	char* option_string = malloc(10*sizeof(char));
	char* return_message = malloc(BUF_SIZE*sizeof(char));
	printf("Hello! Select from the following options...\n");
	printf("1 : Sign Up for normal account\n");
	printf("2 : Sign Up for joint account\n");
	printf("3 : Sign Up for admin account\n");
	printf("4 : Sign In for normal account\n");
	printf("5 : Sign In for joint account\n");
	printf("6 : Sign In for admin account\n");
	printf("any other key to exit!\n");
	scanf("%d",&option);
	switch (option) 
	{
		case SIGN_UP_AS_USER : 
			user_handler(sock, option);
			break;
		case SIGN_UP_AS_JOINT :
			user_handler(sock, option);
			break;
		case SIGN_UP_AS_ADMIN :
			admin_handler(sock, option);
			break;
		case SIGN_IN_AS_USER :
			user_handler(sock, option);
			break;
		case SIGN_IN_AS_ADMIN :
			admin_handler(sock, option);
			break;
		case SIGN_IN_AS_JOINT :
			user_handler(sock, option);
			break;
		default:
			printf("Closing..\n");
			close(sock);
	}
	
}

void user_handler(int sock, int option){

	char* username = malloc(BUF_SIZE*sizeof(char));
	char* password = malloc(BUF_SIZE*sizeof(char));
	char* sec_username = malloc(BUF_SIZE*sizeof(char));
	char* return_message = malloc(BUF_SIZE*sizeof(char));
	char* option_string = malloc(10*sizeof(char));
	int deposit_amt;
	int withdraw_amt;
	char* amt_string = malloc(BUF_SIZE*sizeof(char));

	sprintf(option_string,"%d",option);

	printf("Enter username : ");
	scanf("%s",username);
	printf("Enter password : ");
	scanf("%s",password);
	if (option == SIGN_UP_AS_JOINT)
	{
		printf("Enter secondary username : ");
		scanf("%s", sec_username);
	}
	send(sock , option_string , sizeof(option_string) , 0 );
	send(sock , username , sizeof(username) , 0 ); 
	send(sock , password , sizeof(password) , 0 ); 
	if(option < 4)
	{
		send(sock , sec_username , sizeof(sec_username) , 0 );
	}
	read(sock , return_message, BUF_SIZE * sizeof(char));

	printf("%s\n",return_message); 

	if(!strcmp(return_message,"Wrong Details!\n"))
	{
		shutdown(sock, SHUT_RDWR);
		close(sock);
		return;
	}
	//signup or signin done.

	while(1)
	{
		int user_option;
		printf("What would you like to do?\n");
		printf("1 : Deposit\n");
		printf("2 : Withdraw\n");
		printf("3 : Check Balance\n");
		printf("4 : Change Password\n");
		printf("5 : View Details\n");
		printf("6 : Exit\n");
		scanf("%d",&user_option);
		// printf("%d\n",user_option);
		switch(user_option) {
			case 1 : user_option =  DEPOSIT; break;
			case 2 : user_option =  WITHDRAW; break;
			case 3 : user_option =  CHECK_BALANCE; break;
			case 4 : user_option =  CHANGE_PASSWORD; break;
			case 5 : user_option =  GET_DETAILS; break;
			case 6 : user_option =  EXIT; break;
			default : user_option =  -1;
		}
		sprintf(option_string,"%d",user_option);
		send(sock, option_string, sizeof(option_string), 0 ); 

		switch (user_option) {
			case DEPOSIT : 
				printf("Enter amount to be deposited : ");
				scanf("%d",&deposit_amt);
				sprintf(amt_string,"%d",deposit_amt);	
				printf("%s\n",amt_string);
				send(sock, amt_string, sizeof(amt_string), 0);
				break;
			case WITHDRAW :
				printf("Enter amount to withdraw : ");
				scanf("%d",&withdraw_amt);
				sprintf(amt_string,"%d",withdraw_amt);
				send(sock, amt_string, sizeof(amt_string), 0);
				break;
			case CHECK_BALANCE : 
				break;
			case CHANGE_PASSWORD : 
				printf("Enter new password\n");
				scanf("%s",password);
				send(sock, password, sizeof(password), 0);
				break;
			case GET_DETAILS : 
				break;
			case EXIT :
				shutdown(sock, SHUT_RDWR);
				close(sock);
				return;
			default:
				shutdown(sock, SHUT_RDWR);
				close(sock);
				return;
		}
		read( sock , return_message, BUF_SIZE * sizeof(char)); 
		printf("%s\n",return_message);
	}
	shutdown(sock, SHUT_RDWR);
	close(sock);
}

void admin_handler(int sock, int option){
	char* username = malloc(BUF_SIZE*sizeof(char));
	char* password = malloc(BUF_SIZE*sizeof(char));
	char* sec_username = malloc(BUF_SIZE*sizeof(char));
	char* option_string = malloc(10*sizeof(char));
	char* return_message = malloc(BUF_SIZE*sizeof(char));
	char* sec_username_flag = malloc(BUF_SIZE*sizeof(char));
	char* new_username = malloc(BUF_SIZE*sizeof(char));

	sprintf(option_string,"%d",option);

	printf("Enter username : ");
	scanf("%s",username);
	printf("Enter password : ");
	scanf("%s",password);
	send(sock , option_string , sizeof(option_string) , 0 ); 
	send(sock , username , sizeof(username) , 0 ); 
	send(sock , password , sizeof(password) , 0 );
	if(option == 3){
		send(sock , sec_username , sizeof(sec_username) , 0 );
	}
	read(sock , return_message, BUF_SIZE * sizeof(char));

	printf("%s\n",return_message); 
	if(!strcmp(return_message,"Wrong Details!\n"))
	{
		shutdown(sock, SHUT_RDWR);
		close(sock);
		return;
	}
	while(1){
		int admin_option, type;
		printf("1 : Add User\n");
		printf("2 : Delete User\n");
		printf("3 : Modify User\n");
		printf("4 : Search for Account Details\n");
		printf("5 : Exit\n") ;
		scanf("%d",&admin_option);
		switch (admin_option) {
			case 1 : admin_option = ADD_USER; break;
			case 2 : admin_option = DEL_USER; break;
			case 3 : admin_option = MOD_USER; break;
			case 4 : admin_option = GET_USER_DETAILS; break;
			case 5 : admin_option = EXIT; break;
			default : admin_option = -1;
		}
		
		sprintf(option_string,"%d",admin_option);
		send(sock , option_string , sizeof(option_string) , 0 ); 
		switch (admin_option) {
			case ADD_USER :
				printf("Enter User Type\n");
				printf("1 : Normal\n");
				printf("2 : Joint\n");
				scanf("%d",&type);
				printf("Enter username : ");
				scanf("%s",username);
				printf("Enter password : ");
				scanf("%s",password);
				switch (type) {
					case 1 : 
						send(sock , "1" , sizeof("1") , 0 ); 
						break;
					case 2 :
						send(sock , "2" , sizeof("2") , 0 ); 
						break;
					default :
						printf("Invalid Type\n");
						close(sock);
						return;
				}
				printf("username = %s\n",username);
				printf("password = %s\n",password);
				if (type == 2)
				{
					printf("Enter secondary username : ");
					scanf("%s", sec_username);
				}
				send(sock , username , sizeof(username) , 0 ); 
				send(sock , password , sizeof(password) , 0 );
				send(sock , sec_username , sizeof(sec_username) , 0 ); 
				break;
			case DEL_USER : 
				printf("Enter username : ");
				scanf("%s",username);
				send(sock , username , sizeof(username) , 0 ); 
				break;
			case MOD_USER :
				printf("Modifying Secondary username?\n");
				scanf("%s", sec_username_flag);
				send(sock , sec_username_flag , sizeof(sec_username_flag) , 0 );
				printf("Enter old main username : " );
				scanf("%s",username);
				send(sock , username , sizeof(username) , 0 ); 
				if(strcmp(sec_username_flag, "Yes") == 0){
					printf("Enter new secondary username : ");
					scanf("%s",new_username);
				}
				else{
					printf("Enter new username : ");
					scanf("%s",new_username);
				}
				send(sock , new_username , sizeof(new_username) , 0 ); 
				printf("Enter new password : ");
				scanf("%s",password);
				send(sock , password , sizeof(password) , 0 ); 
				break;
			case GET_USER_DETAILS : 
				printf("Enter username : ");
				scanf("%s",username);
				send(sock , username , sizeof(username) , 0 ); 
				break;
			case EXIT : 
				close(sock);
				return;
			default :
				printf("Invalid input\n");
				close(sock);
				return;
		}
		read( sock , return_message, BUF_SIZE * sizeof(char)); 
		printf("%s\n",return_message); 
	}
}