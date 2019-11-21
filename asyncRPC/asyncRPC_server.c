

#include "asyncRPC.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <time.h>



//Initializing the library..
char str[5][100] = {"Introduction to Machine Learning", "Topics in Distributed System", "Mathematics for Computer Science", "Cyber Security", "Parallel Computing"};


int arr[5] = {15, 10, 8, 5, 11}; 



int bookid[5] = {1028, 2047, 6478, 6987, 3245};





//Call to callSocketServer..

int callSocketServer(int portNumber)
{
		int sockfd, newsockfd, portno, clilen,count=0;
		char buffer[1024];
		struct sockaddr_in serv_addr, cli_addr;
		int n, m;
		// Exit if port number is not provided.
		//if (argc < 2) 
	
		sockfd = socket(AF_INET, SOCK_STREAM, 0); // Create a socket
		if (sockfd < 0)
			printf("ERROR opening socket"); // Exit on error in creation
		bzero((char *) &serv_addr, sizeof(serv_addr));
		portno = portNumber; // Convert portno to integer
		printf("My port: %d\n",portno);
	
		serv_addr.sin_family = AF_INET; // Address family
		serv_addr.sin_addr.s_addr = INADDR_ANY; // Can connect to any
		serv_addr.sin_port = htons(portno); // Change to n/w byte order
		if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
		printf("ERROR on binding"); // Exit on error in binding
		listen(sockfd,5); // Set up backlog or queue
		
		clilen = sizeof(cli_addr); // Required for accept call
		newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
		if (newsockfd < 0)
			printf("ERROR on accept"); // Exit on error in accept
		bzero(buffer,1024); // Initialize to 0
		n = read(newsockfd,buffer,1024);
		if (n < 0)
			printf("ERROR reading from socket"); // Exit on error in read
		
		printf("Here is the message: %s\n",buffer);
		int username = atoi(buffer);
		
		
		bzero(buffer,1024); // Initialize to 0
		n = read(newsockfd,buffer,1024);
		if (n < 0)
			printf("ERROR reading from socket"); // Exit on error in read
		
		printf("Here is the message: %s\n",buffer);
		int password = atoi(buffer);
		
		
		bzero(buffer,1024);
		if(username == 12345 && password == 12345)
		{
			buffer[0] = '0';
		}
		else
		{
			buffer[0] = '1';
		}
		
		//printf("%d",username);
		
		
		
		m = write(newsockfd, buffer,n); // Echo back same message
		if (m < 0)
			printf("ERROR writing to socket"); // Exit on error in writing
		close(newsockfd); // Close client socket
		close(sockfd); // Close server socket
		count++;
		return 1;
}





int call_issue_book(int portNumber)
{
		int sockfd, newsockfd, portno, clilen,count=0;
		char buffer[1024];
		struct sockaddr_in serv_addr, cli_addr;
		int n, m;
		
	
		sockfd = socket(AF_INET, SOCK_STREAM, 0); // Create a socket
		if (sockfd < 0)
			printf("ERROR opening socket"); // Exit on error in creation
		bzero((char *) &serv_addr, sizeof(serv_addr));
		portno = portNumber; // Convert portno to integer
		printf("My port: %d\n",portno);
	
		serv_addr.sin_family = AF_INET; // Address family
		serv_addr.sin_addr.s_addr = INADDR_ANY; // Can connect to any
		serv_addr.sin_port = htons(portno); // Change to n/w byte order
		if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
		printf("ERROR on binding"); // Exit on error in binding
		listen(sockfd,5); // Set up backlog or queue
		
		clilen = sizeof(cli_addr); // Required for accept call
		newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
		if (newsockfd < 0)
			printf("ERROR on accept"); // Exit on error in accept
		
		
		bzero(buffer,1024); // Initialize to 0
		n = read(newsockfd,buffer,1024);
		if (n < 0)
			printf("ERROR reading from socket"); // Exit on error in read
		
		printf("Here is the message: %s\n",buffer);
		int book_id = atoi(buffer);
		
		
		
		
		
		
		int index, count1 = 0;
		
		//printf("%d",username);
		
		for(int j=0;j<5;j++)
		{
			if(bookid[j] == book_id)
			{
				index = j;
				count1++;
				break;
			}
		}
		if(count1 == 0)
		{
			bzero(buffer,1024);
			//strcpy(buffer,"No_book_exists!");
			buffer[0] = '0';
		}
		else
		{
			bzero(buffer,1024);
			arr[index]--;
			//strcpy(buffer,"Book_issued_successfully.");
			char str[20];
			sprintf(str, "%d", arr[index]);
			printf("%s",str);
			strcpy(buffer,str);
		}
		
		m = write(newsockfd, buffer,n); // Echo back same message
		if (m < 0)
			printf("ERROR writing to socket"); // Exit on error in writing
		printf("%s",buffer);
		
		time_t t;
		time(&t);
		//printf("%s \n",ctime(&t));
		char *array = ctime(&t);
		printf("%s \n",ctime(&t));
		
		
		
		FILE *fptr;
		fptr = fopen("file.txt", "a");
		if(fptr == NULL)
		{
			printf("Error!\n");
			
		}
		
		fprintf(fptr,"%s     ",str[index]);
		fprintf(fptr,"%s\n",array);
		
		fclose(fptr);
		
		close(newsockfd); // Close client socket
		close(sockfd); // Close server socket
		count++;
		return 1;
}




int call_return_book(int portNumber)
{
		int sockfd, newsockfd, portno, clilen,count=0;
		char buffer[1024];
		struct sockaddr_in serv_addr, cli_addr;
		int n, m;
		// Exit if port number is not provided.
		
	
		sockfd = socket(AF_INET, SOCK_STREAM, 0); // Create a socket
		if (sockfd < 0)
			printf("ERROR opening socket"); // Exit on error in creation
		bzero((char *) &serv_addr, sizeof(serv_addr));
		portno = portNumber; // Convert portno to integer
		printf("My port: %d\n",portno);
	
		serv_addr.sin_family = AF_INET; // Address family
		serv_addr.sin_addr.s_addr = INADDR_ANY; // Can connect to any
		serv_addr.sin_port = htons(portno); // Change to n/w byte order
		if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
		printf("ERROR on binding"); // Exit on error in binding
		listen(sockfd,5); // Set up backlog or queue
		
		clilen = sizeof(cli_addr); // Required for accept call
		newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
		if (newsockfd < 0)
			printf("ERROR on accept"); // Exit on error in accept
		
		
		bzero(buffer,1024); // Initialize to 0
		n = read(newsockfd,buffer,1024);
		if (n < 0)
			printf("ERROR reading from socket"); // Exit on error in read
		
		printf("Here is the message: %s\n",buffer);
		int book_id = atoi(buffer);
		
		
		
		
		
		
		int index, count1 = 0;
		
		//printf("%d",username);
		
		for(int j=0;j<5;j++)
		{
			if(bookid[j] == book_id)
			{
				index = j;
				count1++;
				break;
			}
		}
		if(count1 == 0)
		{
			bzero(buffer,1024);
			//strcpy(buffer,"No_book_exists!");
			buffer[0] = '0';
		}
		else
		{
			bzero(buffer,1024);
			arr[index]++;
			//strcpy(buffer,"Book_issued_successfully.");
			char str[20];
			sprintf(str, "%d", arr[index]);
			printf("%s",str);
			strcpy(buffer,str);
		}
		
		m = write(newsockfd, buffer,n); // Echo back same message
		if (m < 0)
			printf("ERROR writing to socket"); // Exit on error in writing
		printf("%s",buffer);
		close(newsockfd); // Close client socket
		close(sockfd); // Close server socket
		count++;
		return 1;
}




int call_showall_book(int portNumber)
{
		int sockfd, newsockfd, portno, clilen,count=0;
		char buffer[1024];
		struct sockaddr_in serv_addr, cli_addr;
		int n, m;
		// Exit if port number is not provided.
		//if (argc < 2) 
		
		
	
		sockfd = socket(AF_INET, SOCK_STREAM, 0); // Create a socket
		if (sockfd < 0)
			printf("ERROR opening socket"); // Exit on error in creation
		bzero((char *) &serv_addr, sizeof(serv_addr));
		portno = portNumber; // Convert portno to integer
		printf("My port: %d\n",portno);
	
		serv_addr.sin_family = AF_INET; // Address family
		serv_addr.sin_addr.s_addr = INADDR_ANY; // Can connect to any
		serv_addr.sin_port = htons(portno); // Change to n/w byte order
		if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
			printf("ERROR on binding"); // Exit on error in binding
		listen(sockfd,5); // Set up backlog or queue
		
		clilen = sizeof(cli_addr); // Required for accept call
		newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
		if (newsockfd < 0)
			printf("ERROR on accept"); // Exit on error in accept
		
		
		
		
		char *buffer1 = "Introduction to ML";
		strcpy(buffer,buffer1);
		printf("Here is the message: %s\n",buffer);
		m = write(newsockfd, buffer,n); // Echo back same message
		if (m < 0)
			printf("ERROR writing to socket"); // Exit on error in writing
		
		int index, count1 = 0;
		
		//printf("%d",username);
		
		
		
		m = write(newsockfd, buffer,n); // Echo back same message
		if (m < 0)
			printf("ERROR writing to socket"); // Exit on error in writing*/
		close(newsockfd); // Close client socket
		close(sockfd); // Close server socket
		count++;
		return 1;
}





void *
authenticate_1_svc(authenticateDatatype *argp, struct svc_req *rqstp)
{
	static int  result,count=0;
	printf("Abcd %d",argp->portNo);
	callSocketServer(argp->portNo);
	return (void *) &result;


}

void *
showallbooks_1_svc(showAllBooksDatatype *argp, struct svc_req *rqstp)
{
	//static char * result;
	
	static int  result,count=0;
	
	call_showall_book(argp->portNo);
	printf("Call comes..\n");
	
	
	//return &result;

	

	return (void *) &result;
}

void *
isuuebook_1_svc(isuueBookDatatype *argp, struct svc_req *rqstp)
{
	static char * result;

	
	call_issue_book(argp->portNo);
	printf("Call comes at issuebook..\n");
	 
	

	return (void *) &result;
}

void *
returnbook_1_svc(returnBookDatatype *argp, struct svc_req *rqstp)
{
	static char * result;

	
	 
	
	 
	call_return_book(argp->portNo);
	printf("Call comes at issuebook..\n");
	return (void *) &result;
}
