#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <pthread.h>
#include "definitions.h"

extern int sign_up(int, char*, char*, char*); 
extern int sign_in(int,char*,char*);
extern int deposit(char*,int);
extern int withdraw(char*,int);
extern int check_balance(char*);
extern int change_password(char*,char*);
extern char* get_details(char*);
extern int modify_user(char*, char*,char*,char*);
extern int delete_user(char*);
extern int exit_user(char*);
void *server_side(void *);

int main(int argc, char const *argv[]) 
{ 
	int server_fd, new_socket; 
	struct sockaddr_in address; 
	int opt = 1;
	int addrslen = sizeof(address);
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
	{ 
		perror("socket failed"); 
		exit(EXIT_FAILURE); 
	} 

	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
	{ 
		perror("setsockopt"); 
		exit(EXIT_FAILURE); 
	} 
	address.sin_family = AF_INET; 
	address.sin_addr.s_addr = INADDR_ANY; 
	address.sin_port = htons(PORT); 
	
	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) { 
		perror("binding failed"); 
		exit(EXIT_FAILURE); 
	} 
	if (listen(server_fd, 3) < 0) { 
		perror("listening failed"); 
		exit(EXIT_FAILURE); 
	} 
    printf("Accepting connections....\n");
    while(1)
    {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrslen))<0) 
        { 
            perror("accept"); 
            exit(EXIT_FAILURE); 
        } 

        //threading.
        pthread_t thread_id;
        if( pthread_create( &thread_id , NULL ,  server_side , (void*) &new_socket) < 0)
        {
            perror("thread");
            return 1;
        }
        puts("A client is connected.");
    }
	return 0; 
} 

void *server_side(void *socket_desc)
{
	int sock = *(int*)socket_desc;
	int option, deposit_amt, withdraw_amt, received, balance_amt;
	char* username = malloc(BUF_SIZE*sizeof(char));
	char* password = malloc(BUF_SIZE*sizeof(char));
	char* sec_username = malloc(BUF_SIZE*sizeof(char));
	while(1)
	{
		char* type = malloc(BUF_SIZE*sizeof(char));
		char* send_msg = malloc(BUF_SIZE*sizeof(char));
		char* received_option = malloc(BUF_SIZE*sizeof(char));

		read( sock , received_option, sizeof(received_option)); 
		option = atoi(received_option);
		if (option == SIGN_UP_AS_USER || option == SIGN_UP_AS_ADMIN || option == SIGN_UP_AS_JOINT){
			read( sock , username, sizeof(username));
			read( sock , password, sizeof(password));
			read( sock , sec_username, sizeof(sec_username));
			received = sign_up(option, username, sec_username, password);
			if(received == -1) 
			{
				send_msg = "Wrong Details!\n";
				send(sock , send_msg , BUF_SIZE * sizeof(char) , 0 );
				close(sock);
				break;
			}
			else send_msg = "User SignedUp successfully!\n";
		}
		else if (option == SIGN_IN_AS_USER || option == SIGN_IN_AS_ADMIN || option == SIGN_IN_AS_JOINT){
			read( sock , username, sizeof(username));
			read( sock , password, sizeof(password));
			received = sign_in(option,username,password);
			if(received == -1) 
			{
				send_msg = "Wrong Details!\n";
				send(sock , send_msg , BUF_SIZE * sizeof(char) , 0 );
				close(sock);
				break;
			}
			else send_msg = "User SignedIn successfully!\n";
		}
		else if (option == DEPOSIT) {
			char* deposit_amount = malloc(BUF_SIZE*sizeof(char));
			read(sock,deposit_amount,sizeof(deposit_amount));
			deposit_amt = atoi(deposit_amount);
			received = deposit(username,deposit_amt);
			if (received == -1) send_msg = "Amount not deposited!\n";
			else send_msg = "Amount deposited successfully!\n";
		}
		else if (option == WITHDRAW) {
			char* withdraw_amount = malloc(BUF_SIZE*sizeof(char));
			read(sock,withdraw_amount,sizeof(withdraw_amount));
			withdraw_amt = atoi(withdraw_amount);
			received = withdraw(username,withdraw_amt);
			if (received == -1) send_msg = "Amount not withdrawn!\n";
			else send_msg = "Amount withdrew successfully!\n";
		}
		else if (option == CHECK_BALANCE) {
			balance_amt = check_balance(username);
			sprintf(send_msg,"%d",balance_amt);
		}
		else if (option == CHANGE_PASSWORD) {
			read(sock, password, sizeof(password));
			received = change_password (username, password);
			if (received == -1) send_msg = "Password not changed!\n";
			else send_msg = "Password changed successfully!\n";
		}
		else if (option == GET_DETAILS) {
			send_msg = get_details(username);
		}
		else if(option == DEL_USER) {
			char* username = malloc(BUF_SIZE*sizeof(char));
			read( sock , username, sizeof(username));
			received = delete_user(username);
			if (received == -1) send_msg = "User not deleted!\n";
			else send_msg = "User deleted successfully!\n";
		}
		else if(option == MOD_USER) {
			char* sec_username_flag = malloc(BUF_SIZE*sizeof(char));
			char* username = malloc(BUF_SIZE*sizeof(char));
			char* password = malloc(BUF_SIZE*sizeof(char));
			char* new_username = malloc(BUF_SIZE*sizeof(char));
			read( sock , sec_username_flag, sizeof(sec_username_flag));
			read( sock , username, sizeof(username));
			read( sock , new_username, sizeof(new_username));
			read( sock , password, sizeof(password));

			received = modify_user (sec_username_flag, username, new_username, password);
			if (received == -1) send_msg = "User not changed!\n";
			else send_msg = "User changed successfully!\n";
		}
		else if (option == GET_USER_DETAILS) {
			char* username = malloc(BUF_SIZE*sizeof(char));
			read( sock , username, sizeof(username));
			send_msg = get_details(username);
		}
		else if (option == ADD_USER) {
			char* username = malloc(BUF_SIZE*sizeof(char));
			char* password = malloc(BUF_SIZE*sizeof(char));
			char* sec_username = malloc(BUF_SIZE*sizeof(char));
			read( sock , type, sizeof(type));
			read( sock , username, sizeof(username));
			read( sock , password, sizeof(password));
			read( sock , sec_username, sizeof(sec_username));
			if(!strcmp(type,"1")) option = SIGN_UP_AS_USER;
			else option = SIGN_UP_AS_JOINT;
			received = sign_up(option, username, sec_username, password);
			if(received == -1) 
			{
				send_msg = "Wrong Details!\n";
				send(sock , send_msg , BUF_SIZE * sizeof(char) , 0 );
				close(sock);
				break;
			}
			else send_msg = "Account added successfully!\n";
		}
		else if (option == EXIT){
			received = exit_user(username);
			close(sock);
			break;
		}
		else{
			close(sock);
			break;
		}
		send(sock , send_msg , BUF_SIZE * sizeof(char) , 0);
	}
	printf("socket %d is closed\n", sock);
    return 0;
} 