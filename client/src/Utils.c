#include "../headers/Utils.h"

int choice1, choice2, choice3, sockfd, show1, show2, show3;
int recvBytes, sendBytes;
char sendBuff[MAX_LINE] = {0}, recvBuff[MAX_LINE];
struct sockaddr_in server, client;
Account acc;

/*--------------------- Ultilities -------------------------*/


int connect_to_server(char serverIP[], int serverPort)
{
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
    printf("\n Socket creation error \n");
    return 0;
  }
  printf("Server Address: %s", serverIP);

  memset(&server, 0, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr(serverIP);
  inet_aton(serverIP, &server.sin_addr);
  server.sin_port = htons(serverPort);

  printf("\n************************************\n\nConnecting....\n\n");
  if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0)
  {
    printf("\nConnection Failed \n");
    return 0;
  }
  printf("Connected!\n");
  return 1;
}

int disconnect_to_server()
{
  printf("Disconnect...\n");
  close(sockfd);
  return 1;
}

int login(char username[], char password[])
{
  Message msg;
  msg.type = LOGIN;
  strcpy(msg.data_type, "string");
  strcpy(msg.value, username);
  strcat(msg.value, " ");
  strcat(msg.value, password);
  msg.length = strlen(msg.value);
  if (send(sockfd, &msg, sizeof(Message), 0) < 0)
  {
    printf("Send failed");
  }

  if (recv(sockfd, &msg, sizeof(Message), 0) < 0)
  {
    printf("Receive failed");
  }

  return msg.type;
}

int signup(char username[], char password[])
{
  Message msg;
  msg.type = SIGNUP;
  strcpy(msg.data_type, "string");
  strcpy(msg.value, username);
  strcat(msg.value, " ");
  strcat(msg.value, password);
  msg.length = strlen(msg.value);
  if (send(sockfd, &msg, sizeof(Message), 0) < 0)
  {
    printf("Send failed");
  }

  if (recv(sockfd, &msg, sizeof(Message), 0) < 0)
  {
    printf("Receive failed");
  }

  return msg.type;
}

int logout(){
  Message msg;
  msg.type = LOGOUT;
  if (send(sockfd, &msg, sizeof(Message), 0) < 0)
  {
    printf("Send failed");
  }
  return msg.type;
}

int change_password(char password[]){
  Message msg;
  msg.type = CHANGE_PASSWORD;
  strcpy(msg.data_type, "string");
  strcat(msg.value, password);
  msg.length = strlen(msg.value);
  if (send(sockfd, &msg, sizeof(Message), 0) < 0)
  {
    printf("Send failed");
  }

  if (recv(sockfd, &msg, sizeof(Message), 0) < 0)
  {
    printf("Receive failed");
  }

  return msg.type;
}

