#include <stdio.h>

int yearCal ( int yseperator );
int monthCal ( int mseperator, int array1[] );
int dateCal ( int mseperator,int month, int array1[] );
void genderCal ( int mseperator );
int ageCal ( int year , int month , int date, int cYear, int cMonth, int cDate );
int main ( void )
{

	int id, cYear, cMonth, cDate;

	int array1[12] = { 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 }; 

	printf( "Enter Your ID:" );
	scanf( "%9d", &id );

	printf( "Enter Current Year:" );
	scanf( "%d", &cYear );

	printf( "Enter Current Month:" );
	scanf( "%d", &cMonth );

	printf( "Enter Current Date:" );
	scanf( "%d", &cDate );


	int yseperator = id / 10000000 ;
	int mseperator = ( id / 10000 ) % 1000;

	int year = yearCal ( yseperator );
	int month = monthCal ( mseperator, array1 );
	int date = dateCal ( mseperator, month, array1 );

	printf( "*******************************************************\n" );
	printf( "\tID No\t\t:%d\n", id );
	printf( "\tDate of Birth\t:%d-%d-%d\n", year, month, date ); 
	
	/*if ( gender == 1 )
		printf( "\tGender\t\t:Male\n" );
	else
		printf( "\tGender\t\t:Female\n" );*/
	
	genderCal ( mseperator );
	
	int tot = ageCal ( year, month, date, cYear, cMonth, cDate );

	int y = tot / 10000;
	int m = ( tot / 100 ) % 100;
	int d = tot % 100;

	printf( "\tAge\t\t:%d Years %d Months %d Days\n", y, m, d );
        printf( "*******************************************************\n" );

	return 0;
}

int yearCal ( int yseperator )
{

	return (1900 + yseperator );
}

int monthCal ( int mseperator, int array1[] )
{	
	int i = 1;
	int month = 0;
	int count = 1;
	int monthVar = 31;

	if( mseperator > 500 )
		mseperator -= 500;

	
	while( count <= 11 )
	{
		if ( mseperator <= monthVar )
		{
			month = count;
			break;
		}
		else
		{
			monthVar = array1[i];
			++i;
		}
			
		++count;
	}
	return month;
}

int dateCal ( int mseperator,int month, int array1[] )
{
	int date, count;
	int monthVar = 2;
	int i = 1;

	if ( mseperator > 500 )
		mseperator -= 500;
	
	if ( month == 1 )
		date = mseperator;
	else
	{
		date = mseperator - array1 [ month - 2 ];
	}

	return date;
}

void genderCal ( int mseperator )
{
	
	char string1[10];


	if( mseperator > 500 )
	{
		char string1[10] = "Female";
		printf( "\tGender\t\t:%s\n", string1 );
	}
	else 
	{
		char string1[10] = "Male";;
		printf( "\tGender\t\t:%s\n", string1 );
	}	

}

int ageCal ( year, month, date, cYear, cMonth, cDate )
{
	int y, m, d;

	
	if( cDate < date )
	{
		cDate = cDate + 31;
		cMonth = cMonth - 1;
	}

	d = cDate - date;

	if( cMonth < month )
	{

		cMonth = cMonth + 12;
		cYear = cYear - 1;
	}	
	
	m = cMonth - month;
	y = cYear - year;

	int tot = y*10000 + m*100 + d;

	return tot;
}
