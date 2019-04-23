


//	PROJECT BOOK LIBRARY


#include <iostream.h>
#include <fstream.h>
#include <process.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <dos.h>




class MENU
{
	public :
			void main_menu(void) ;
			void introduction(void) ;
	private :
			void edit_menu(void) ;
			void edit_book(void) ;
			void edit_member(void) ;
} ;


//**********************************************************
// THIS CLASS CONTAINS FUNCTIONS RELATED TO BOOKS
//**********************************************************

class BOOK
{
	public :
			void list(void) ;
			char *bookname(int) ;
	protected :
			void add_new_book(int, char tname[33], char tauthor[26], float, int, int) ;
			void update_copies(int, int, int) ;
			void modify(int, char[], char[], float) ;
			void deletion(void) ;
			int  book_found(int) ;
			int  bookname_found(char []) ;
			int  recordno(int) ;
			int  available(int) ;
			char *authorname(int) ;
			float bookprice(int) ;
			int  no_of_copies(int) ;
			int  bookcodeof(char[]) ;
			void display(int) ;
			int  reccount(void) ;
			void delete_rec(int) ;
	private :
			int   bookcode, copies ;
			char  name[33], author[26] ;
			float price ;
			int   avail ;
} ;


//**********************************************************
// THIS CLASS CONTAINS FUNCTIONS RELATED TO MEMBERS
//**********************************************************

class MEMBER
{
	public :
			void list(void) ;
	protected :
			void add_mem(int, int, char [], char [], char[], int, int, int) ;
			void modify(int, char[], char[], char[]) ;
			int  member_found(int) ;
			void update_book(int, int, int, int, int) ;
			char *membername(int) ;
			char *memberphone(int) ;
			char *memberaddress(int) ;
			int  recordno(int) ;
			int  lastcode(void) ;
			int  issued(int) ;
			int  fine(int) ;
			void display(int) ;
			void delete_rec(int) ;
	private :
			int  memcode, bookcode ;
			char name[26], phone[10], address[33] ;
			int  dd, mm, yy ;   // DATE OF RETURNING THE BOOK //
} ;


//**********************************************************
// THIS IS DERIVED FROM CLASS BOOK & MEMBER AND CONTAINS
// FUNCTIONS FOR WORKING (ISSUE,RETURN,ETC).
//**********************************************************

class WORKING : public BOOK, public MEMBER
{
	public :
			void issuebook(void) ;
			void returnbook(void) ;
			void add_book(void) ;
			void add_member(void) ;
			void modify_book(void) ;
			void modify_member(void) ;
			void delete_book(void) ;
			void delete_member(void) ;
} ;


//**********************************************************
// THIS CLASS CONTAINS FUNCTIONS RELATED DATE & FINE
//**********************************************************

class DATE
{
	public :
			void extend_date(int,int,int,int) ;
			int  diff(int, int, int, int, int, int) ;
			int  day, mon, year ;
} ;



void DATE :: extend_date(int d1, int m1, int y1, int days)
{
	static int month[] = {31,29,31,30,31,30,31,31,30,31,30,31} ;
	for (int i=1; i<=days; i++)
	{
		d1++ ;
		if ((d1 > month[m1-1]) || (y1%4 != 0 && m1 == 2 && d1 > 28))
		{
			d1 = 1 ;
			m1++ ;
		}
		if (m1 > 12)
		{
			m1 = 1 ;
			y1++ ;
		}
	}
	day  = d1 ;
	mon  = m1 ;
	year = y1 ;
}


int DATE :: diff(int d1, int m1, int y1, int d2, int m2, int y2)
{
	int days = 0 ;
	if ((y2<y1) || (y2==y1 && m2<m1) || (y2==y1 && m2==m1 && d2<d1))
		return days ;
	static int month[] = {31,29,31,30,31,30,31,31,30,31,30,31} ;
	while (d1 != d2 || m1 != m2 || y1 != y2)
	{
		days++ ;
		d1++ ;
		if ((d1 > month[m1-1]) || (y1%4 != 0 && m1 == 2 && d1 > 28))
		{
			d1 = 1 ;
			m1++ ;
		}
		if (m1 > 12)
		{
			m1 = 1 ;
			y1++ ;
		}
	}
	return days ;
}


void MENU :: main_menu(void)
{
	char ch ;
	while (1)
	{
		clrscr() ;
		gotoxy(29,6) ;
		cout <<"B O O K  L I B R A R Y" ;
		gotoxy(29,7) ;
		cout <<"~~~~~~~~~~~~~~~~~~~~~~" ;
		gotoxy(30,10) ;
		cout <<"1. INTRODUCTION" ;
		gotoxy(30,11) ;
		cout <<"2. ADD NEW BOOK" ;
		gotoxy(30,12) ;
		cout <<"3. ADD NEW MEMBER" ;
		gotoxy(30,13) ;
		cout <<"4. ISSUE BOOK" ;
		gotoxy(30,14) ;
		cout <<"5. RETURN BOOK" ;
		gotoxy(30,15) ;
		cout <<"6. LIST OF BOOKS" ;
		gotoxy(30,16) ;
		cout <<"7. LIST OF MEMBERS" ;
		gotoxy(30,17) ;
		cout <<"8. EDIT" ;
		gotoxy(30,18) ;
		cout <<"0. QUIT" ;
		gotoxy(30,20) ;
		cout <<"Enter your choice : " ;
		ch = getche() ;
		if (ch == 27)
			break ;
		else
		if (ch == '1')
			introduction() ;
		else
		if (ch == '2')
		{
			WORKING W ;
			W.add_book() ;
		}
		else
		if (ch == '3')
		{
			WORKING W ;
			W.add_member() ;
		}
		else
		if (ch == '4')
		{
			WORKING W ;
			W.issuebook() ;
		}
		else
		if (ch == '5')
		{
			WORKING W ;
			W.returnbook() ;
		}
		else
		if (ch == '6')
		{
			BOOK B ;
			B.list() ;
		}
		else
		if (ch == '7')
		{
			MEMBER M ;
			M.list() ;
		}
		else
		if (ch == '8')
			edit_menu() ;
		else
		if (ch == '0')
			break ;
	}
}


void MENU :: edit_menu(void)
{
	char ch ;
	while (1)
	{
		clrscr() ;
		gotoxy(32,9) ;
		cout <<"E D I T  M E N U";
		gotoxy(32,10) ;
		cout <<"~~~~~~~~~~~~~~~~" ;
		gotoxy(34,13) ;
		cout <<"1. BOOKS" ;
		gotoxy(34,14) ;
		cout <<"2. MEMBERS" ;
		gotoxy(34,15) ;
		cout <<"0. EXIT" ;
		gotoxy(31,17) ;
		cout <<"Enter your choice : " ;
		ch = getche() ;
		if (ch == 27)
			break ;
		else
		if (ch =='1')
			edit_book() ;
		else
		if (ch == '2')
			edit_member() ;
		else
		if (ch == '0')
			break ;
	}
}



void MENU :: edit_book(void)
{
	char ch ;
	while (1)
	{
		clrscr() ;
		gotoxy(31,9) ;
		cout <<"E D I T  B O O K S";
		gotoxy(31,10) ;
		cout <<"~~~~~~~~~~~~~~~~~~" ;
		gotoxy(34,13) ;
		cout <<"1. MODIFY" ;
		gotoxy(34,14) ;
		cout <<"2. DELETE" ;
		gotoxy(34,15) ;
		cout <<"0. EXIT" ;
		gotoxy(31,17) ;
		cout <<"Enter your choice : " ;
		ch = getche() ;
		if (ch == 27)
			break ;
		else
		if (ch == '1')
		{
			WORKING W ;
			W.modify_book() ;
		}
		else
		if (ch == '2')
		{
			WORKING W ;
			W.delete_book() ;
		}
		else
		if (ch == '0')
			break ;
	}
}

int BOOK :: recordno(int tcode)
{
	fstream file ;
	file.open("BOOK.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	int count=0 ;
	while (file.read((char *) this, sizeof(BOOK)))
	{
		count++ ;
		if (bookcode == tcode)
			break ;
	}
	file.close() ;
	return count ;
}


int BOOK :: available(int tcode)
{
	fstream file ;
	file.open("BOOK.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	int tavail=0 ;
	while (file.read((char *) this, sizeof(BOOK)))
	{
		if (bookcode == tcode)
		{
			tavail = avail ;
			break ;
		}
	}
	file.close() ;
	return tavail ;
}

//<<<<<<< AMAN

int BOOK :: recordno(int tcode)
{
	fstream file ;
	file.open("BOOK.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	int count=0 ;
	while (file.read((char *) this, sizeof(BOOK)))
	{
		count++ ;
		if (bookcode == tcode)
			break ;
	}
	file.close() ;
	return count ;
}


//**********************************************************
// THIS FUNCTION RETURNS THE AVAILABLE COPIES FOR THE GIVEN
// BOOK CODE.
//**********************************************************

int BOOK :: available(int tcode)
{
	fstream file ;
	file.open("BOOK.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	int tavail=0 ;
	while (file.read((char *) this, sizeof(BOOK)))
	{
		if (bookcode == tcode)
		{
			tavail = avail ;
			break ;
		}
	}
	file.close() ;
	return tavail ;
}


//**********************************************************
// THIS FUNCTION RETURNS THE NO. OF COPIES FOR THE GIVEN
// BOOK CODE.
//**********************************************************

int BOOK :: no_of_copies(int tcode)
{
	fstream file ;
	file.open("BOOK.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	int tcopies=0 ;
	while (file.read((char *) this, sizeof(BOOK)))
	{
		if (bookcode == tcode)
		{
			tcopies = copies ;
			break ;
		}
	}
	file.close() ;
	return tcopies ;
}


//**********************************************************
// THIS FUNCTION RETURNS THE BOOK NAME OF THE GIVEN BOOK
// CODE.
//**********************************************************

char *BOOK :: bookname(int tcode)
{
	fstream file ;
	file.open("BOOK.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	char tname[33] ;
	while (file.read((char *) this, sizeof(BOOK)))
	{
		if (bookcode == tcode)
		{
			strcpy(tname,name) ;
			break ;
		}
	}
	file.close() ;
	return tname ;
}


//**********************************************************
// THIS FUNCTION RETURNS THE AUTHOR NAME OF THE GIVEN BOOK
// CODE.
//**********************************************************

char *BOOK :: authorname(int tcode)
{
	fstream file ;
	file.open("BOOK.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	char tauthor[26] ;
	while (file.read((char *) this, sizeof(BOOK)))
	{
		if (bookcode == tcode)
		{
			strcpy(tauthor,author) ;
			break ;
		}
	}
	file.close() ;
	return tauthor ;
}


//**********************************************************
// THIS FUNCTION RETURNS THE BOOK PRICE OF THE GIVEN BOOK
// CODE.
//**********************************************************

float BOOK :: bookprice(int tcode)
{
	fstream file ;
	file.open("BOOK.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	float tprice=0.0 ;
	while (file.read((char *) this, sizeof(BOOK)))
	{
		if (bookcode == tcode)
		{
			tprice = price ;
			break ;
		}
	}
	file.close() ;
	return tprice ;
}


//**********************************************************
// THIS FUNCTION RETURNS THE BOOK CODE OF THE GIVEN BOOK
// NAME.
//**********************************************************

int BOOK :: bookcodeof(char t1code[33])
{
	fstream file ;
	file.open("BOOK.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	int tcode=0 ;
	while (file.read((char *) this, sizeof(BOOK)))
	{
		if (!strcmpi(name,t1code))
		{
			tcode = bookcode ;
			break ;
		}
	}
	file.close() ;
	return tcode ;
}


//**********************************************************
// THIS FUNCTION RETURNS THE NO. OF THE RECORDS IN THE BOOK
// FILE.
//**********************************************************

int BOOK :: reccount(void)
{
	fstream file ;
	file.open("BOOK.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	int count=0 ;
	while (file.read((char *) this, sizeof(BOOK)))
		count++ ;
	file.close() ;
	return count ;
}


//**********************************************************
// THIS FUNCTION DELETES THE RECORD OF THE GIVEN BOOK CODE.
//**********************************************************

void BOOK :: delete_rec(int tcode)
{
	fstream file ;
	file.open("BOOK.DAT", ios::in) ;
	fstream temp ;
	temp.open("temp.dat", ios::out) ;
	file.seekg(0,ios::beg) ;
	while ( !file.eof() )
	{
		file.read((char *) this, sizeof(BOOK)) ;
		if ( file.eof() )
			break ;
		if ( bookcode != tcode )
			temp.write((char *) this, sizeof(BOOK)) ;
	}
	file.close() ;
	temp.close() ;
	file.open("BOOK.DAT", ios::out) ;
	temp.open("temp.dat", ios::in) ;
	temp.seekg(0,ios::beg) ;
	while ( !temp.eof() )
	{
		temp.read((char *) this, sizeof(BOOK)) ;
		if ( temp.eof() )
			break ;
		file.write((char *) this, sizeof(BOOK)) ;
	}
	file.close() ;
	temp.close() ;
}


//**********************************************************
// THIS FUNCTION ADD THE RECORD IN THE BOOK FILE
//**********************************************************

void BOOK :: add_new_book(int tcode,char tname[33], char tauthor[26], float tprice, int tcopies, int tavail)
{
	fstream file ;
	file.open("BOOK.DAT", ios::app) ;
	bookcode = tcode ;
	strcpy(name,tname) ;
	strcpy(author,tauthor) ;
	price = tprice ;
	copies = tcopies ;
	avail = tavail ;
	file.write((char *) this, sizeof(BOOK)) ;
	file.close() ;
}

void BOOK :: update_copies(int tcode, int tcopies, int tavail)
{
	fstream file ;
	file.open("BOOK.DAT", ios::in) ;
	fstream temp ;
	temp.open("temp.dat", ios::out) ;
	file.seekg(0,ios::beg) ;
	while ( !file.eof() )
	{
		file.read((char *) this, sizeof(BOOK)) ;
		if ( file.eof() )
			break ;
		if ( bookcode == tcode )
		{
			copies = tcopies ;
			avail = tavail ;
			temp.write((char *) this, sizeof(BOOK)) ;
		}
		else
			temp.write((char *) this, sizeof(BOOK)) ;
	}
	file.close() ;
	temp.close() ;
	file.open("BOOK.DAT", ios::out) ;
	temp.open("temp.dat", ios::in) ;
	temp.seekg(0,ios::beg) ;
	while ( !temp.eof() )
	{
		temp.read((char *) this, sizeof(BOOK)) ;
		if ( temp.eof() )
			break ;
		file.write((char *) this, sizeof(BOOK)) ;
	}
	file.close() ;
	temp.close() ;
}


//**********************************************************
// THIS FUNCTION MODIFY THE RECORD IN THE BOOK FILE FOR THE
// GIVEN BOOK CODE
//**********************************************************

void BOOK :: modify(int tcode, char tname[33], char tauthor[26], float tprice)
{
	fstream file ;
	file.open("BOOK.DAT", ios::in) ;
	fstream temp ;
	temp.open("temp.dat", ios::out) ;
	file.seekg(0,ios::beg) ;
	while ( !file.eof() )
	{
		file.read((char *) this, sizeof(BOOK)) ;
		if ( file.eof() )
			break ;
		if ( bookcode == tcode )
		{
			strcpy(name,tname) ;
			strcpy(author,tauthor) ;
			price = tprice ;
			temp.write((char *) this, sizeof(BOOK)) ;
		}
		else
			temp.write((char *) this, sizeof(BOOK)) ;
	}
	file.close() ;
	temp.close() ;
	file.open("BOOK.DAT", ios::out) ;
	temp.open("temp.dat", ios::in) ;
	temp.seekg(0,ios::beg) ;
	while ( !temp.eof() )
	{
		temp.read((char *) this, sizeof(BOOK)) ;
		if ( temp.eof() )
			break ;
		file.write((char *) this, sizeof(BOOK)) ;
	}
	file.close() ;
	temp.close() ;
}


//**********************************************************
// THIS FUNCTION DISPLAY THE RECORD FROM THE BOOK FILE
// FOR THE GIVEN BOOK CODE
//**********************************************************

void BOOK :: display(int tcode)
{
	fstream file ;
	file.open("BOOK.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	while (file.read((char *) this, sizeof(BOOK)))
	{
		if (bookcode == tcode)
		{
			gotoxy(5,5) ;
			cout <<"Book Code   : " <<bookcode ;
			gotoxy(5,7) ;
			cout <<"Book Name   : " <<name ;
			gotoxy(5,8) ;
			cout <<"Author Name : " <<author ;
			gotoxy(5,9) ;
			cout <<"Price       : Rs." <<price ;
			gotoxy(5,10) ;
			cout <<"Copies      : " <<price ;
			gotoxy(5,11) ;
			cout <<"Available   : " <<avail ;
			break ;
		}
	}
	file.close() ;
}


//**********************************************************
// THIS FUNCTION DISPLAY THE LIST OF BOOKS.
//**********************************************************

void BOOK :: list(void)
{
	clrscr() ;
	int row = 6 , found=0, flag=0 ;
	char ch ;
	gotoxy(33,2) ;
	cout <<"LIST OF BOOKS" ;
	gotoxy(32,3) ;
	cout <<"~~~~~~~~~~~~~~~" ;
	gotoxy(1,4) ;
	cout <<"CODE  BOOK NAME                        AUTHOR                    PRICE  COPIES" ;
	gotoxy(1,5) ;
	cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
	fstream file ;
	file.open("BOOK.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	while (file.read((char *) this, sizeof(BOOK)))
	{
		flag = 0 ;
		delay(20) ;
		found = 1 ;
		gotoxy(2,row) ;
		cout <<bookcode ;
		gotoxy(7,row) ;
		cout	<<name ;
		gotoxy(40,row) ;
		cout	<<author ;
		gotoxy(66,row) ;
		cout	<<price ;
		gotoxy(73,row) ;
		cout <<copies ;
		textbackground(WHITE) ; textcolor(BLACK) ;
		gotoxy(40,row+1) ;
		cprintf("STATUS: ") ;
		textcolor(BLACK+BLINK) ;
		cprintf("%d copies available",avail) ;
		textbackground(BLACK) ; textcolor(LIGHTGRAY) ;
		if ( row == 22 )
		{
			flag = 1 ;
			row = 6 ;
			gotoxy(1,25) ;
			cout <<"Press any key to continue or Press <ESC> to exit" ;
			ch = getch() ;
			if (ch == 27)
				break ;
			clrscr() ;
			gotoxy(33,2) ;
			cout <<"LIST OF BOOKS" ;
			gotoxy(32,3) ;
			cout <<"~~~~~~~~~~~~~~~" ;
			gotoxy(1,4) ;
			cout <<"CODE  BOOK NAME                        AUTHOR                    PRICE  COPIES" ;
			gotoxy(1,5) ;
			cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
		}
		else
			row = row + 2 ;
	}
	if (!found)
	{
		gotoxy(5,10) ;
		cout <<"\7Records not found" ;
	}
	if (!flag)
	{
		gotoxy(1,25) ;
		cout <<"Press any key to continue..." ;
		getche() ;
	}
	file.close () ;
}

//=======
//>>>>>>> parallel
