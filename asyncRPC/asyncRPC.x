struct authenticateDatatype{
	int userId;
	int password;
	int portNo;
};

struct showAllBooksDatatype{
	int portNo;
};

struct isuueBookDatatype{
	int userId;
	int bookId;
	int portNo;
};

struct returnBookDatatype{
	int userId;
	int bookId;
	int portNo;
};

program ASYNCHRONOUSRPC_PROG{
	version ASYNCHRONOUSRPC_VERS{
		void authenticate(authenticateDatatype)=1;
		void showAllBooks(showAllBooksDatatype)=2;
		void isuueBook(isuueBookDatatype)=3;
		void returnBook(returnBookDatatype)=4;
	}=1;
}=0x56843572;


