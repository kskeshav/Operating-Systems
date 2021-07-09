#define PORT 8080 
#define SIGN_UP_AS_USER 1
#define SIGN_UP_AS_JOINT 2
#define SIGN_UP_AS_ADMIN 3
#define SIGN_IN_AS_USER 4
#define SIGN_IN_AS_JOINT 5
#define SIGN_IN_AS_ADMIN 6
#define DEPOSIT 7
#define WITHDRAW 8
#define CHECK_BALANCE 9
#define CHANGE_PASSWORD 10
#define GET_DETAILS 11
#define EXIT 12
#define ADD_USER 13
#define DEL_USER 14
#define MOD_USER 15
#define GET_USER_DETAILS 16
#define INVALID -1
#define BUF_SIZE 1000

struct user {
    char type[BUF_SIZE];
    char password[BUF_SIZE];
    char sec_username[BUF_SIZE];
    char username[BUF_SIZE];
    int balance;
    int active;
};