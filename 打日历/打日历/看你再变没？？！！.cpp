/*
 * File: calendar.cpp
 * ----------------
 * This program is used to generate a calendar for a year
 * entered by the user.
 */
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;


/* Function prototypes */
/*
 * Function: GiveInstructions
 * Usage: GiveInstructions();
 * --------------------------
 * This procedure prints out instructions to the user.
 */
void GiveInstructions(void);

/*
 * Function: GetYearFromUser
 * Usage: year = GetYearFromUser();
 * --------------------------------
 * This function reads in a year from the user and returns
 * that value.  If the user enters a year before 1900, the
 * function gives the user another chance.
 */
int GetYearFromUser(void);

/*
 * Function: PrintCalendar
 * Usage: PrintCalendar(year);
 * ---------------------------
 * This procedure prints a calendar for an entire year.
 */
void PrintCalendar(int year);

/*
 * Function: PrintCalendarMonth
 * Usage: PrintCalendarMonth(month, year);
 * ---------------------------------------
 * This procedure prints a calendar for the given month
 * and year.
 */
void PrintCalendarMonth(int month, int year);

/*
 * Function: IndentFirstLine
 * Usage: IndentFirstLine(weekday);
 * --------------------------------
 * This procedure indents the first line of the calendar
 * by printing enough blank spaces to get to the position
 * on the line corresponding to weekday.
 */
void IndentFirstLine(int weekday);

/*
 * Function: MonthDays
 * Usage: ndays = MonthDays(month, year);
 * --------------------------------------
 * MonthDays returns the number of days in the indicated
 * month and year.  The year is required to handle leap years.
 */
int MonthDays(int month, int year);

/*
 * Function: FirstDayOfMonth
 * Usage: weekday = FirstDayOfMonth(month, year);
 * ----------------------------------------------
 * This function returns the day of the week on which the
 * indicated month begins.  This program simply counts
 * forward from January 1, 1900, which was a Monday.
 */
int FirstDayOfMonth(int month, int year);

/*
 * Function: MonthName
 * Usage: name = MonthName(month);
 * -------------------------------
 * MonthName converts a numeric month in the range 1-12
 * into the string name for that month.
 */
string MonthName(int month);


/*
 * Function: IsLeapYear
 * Usage: if (IsLeapYear(year)) . . .
 * ----------------------------------
 * This function returns TRUE if year is a leap year.
 */
bool IsLeapYear(int year);

/* Main program */
int main()
{
int year;
GiveInstructions();
year = GetYearFromUser();
PrintCalendar(year);
return 0;
}

bool IsLeapYear(int year)
{
	return((year%4==0&&year%100!=0)||year%400==0);
}	

string MonthName(int month)
{
	string a;
	switch(month)
	{
	case 1:a="January";break;
	case 2:a="February";break;
	case 3:a="March";break;
	case 4:a="April";break;
	case 5:a="May";break;
	case 6:a="June";break;
	case 7:a="July";break;
	case 8:a="August";break;
	case 9:a="September";break;
	case 10:a="October";break;
	case 11:a="November";break;
	case 12:a="December";break;
	}
	return a;
}

int FirstDayOfMonth(int month, int year)
{
	int a,b,c,d;
	a=(year-1901)/4;
	b=(365*4+1)*a+(year-4*a-1900)*365;
	d=(year-1900)/400;
	c=0;
	for(int i=1;i<month;i++)
	c=c+MonthDays(i,year);
	return((b+c-3*d+1)%7);
}

int MonthDays(int month, int year)
{
int c;	
switch(month)
	{
		case 1:c=31;break;
		case 2:c=28+IsLeapYear(year);break;
		case 3:c=31;break;
		case 4:c=30;break;
		case 5:c=31;break;
		case 6:c=30;break;
		case 7:c=31;break;
		case 8:c=31;break;
		case 9:c=30;break;
		case 10:c=31;break;
		case 11:c=30;break;
		case 12:c=31;break;
	}
return (c);
}

void IndentFirstLine(int weekday)
{
	for(int i=1;i<=3*weekday;i++)
	cout<<" ";
}

void PrintCalendarMonth(int month, int year)
{
	int weekday,ndays,n;
	string name;
	name=MonthName(month);
	weekday=FirstDayOfMonth(month, year);
	ndays=MonthDays(month, year);
	cout<<"   ";
	cout<<left<<setw(9)<<name;
	cout<<right<<setw(5)<<year<<"\n";
	cout<<"Su Mo Tu We Th Fr Sa\n";
	IndentFirstLine(weekday);
	n=7-FirstDayOfMonth(month, year);
	for(int i=1;i<=ndays;i++)
	{
		cout<<setw(2)<<i;
		if((i-n)%7)
			cout<<" ";
		else
			cout<<"\n";
	}
	cout<<"\n";
}

void PrintCalendar(int year)
{
	for(int i=1;i<=12;i++)
	PrintCalendarMonth(i,year);
}

int GetYearFromUser(void)
{
	int year;
	cin>>year;
	while(year<1900)
	{	
		cout<<"This year is before 1900.Please type again.\n";
		cin>>year;
	}
	return(year);
}

void GiveInstructions(void)
{
	cout<<"This program is used to generate a calendar for a year after 1900.Please enter a year.\n";
}