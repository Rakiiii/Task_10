#include <windef.h>
#include "Include_and_constants.h"


char ReadString()
{
    char *String = (char*)malloc( 255 * sizeof( char ) ) , ch;
    int i = 0;
    scanf("%c" , &ch);
    while ( ch != '\n' )
    {
        String[ i ] = ch ;
        i++;
        scanf( "%c" , &ch );
    }
    String[ i + 1] = '\0';
    return *String;
}


int SearchStringInString(char MainString[] , char String[]) //исщет в первой строке вторую и возвращает номер начала второй строки в первой
{
    int i = 0 , j = 0 , k = 0 ;

    for( i = 0 ; MainString[ i ] != '\0' ; i++ )
    {
        for( j = i , k = 0 ; String[ k ] != '\0' && MainString[ j ] == String[ k ]; j++, k++);
        if( k > 0 && String[ k ] == '\0' )
            return i;
    }
    return -1;
}

char CopyString( char *MainString , int Start , int End )
{
    char *CopiedString = (char*)malloc( ( ( End - Start) - 1) * sizeof( char ) );
    int j = 0;
    for(int i = Start ; i <= End ; i++)
    {
        CopiedString[ j ] = MainString [ i ];
        j++;
    }
    return *CopiedString;
}



char ConnectString( char *String1 , char *String2 )
{
    char *MainString = (char*)malloc( ( strlen( String1 ) + strlen( String2 ) + 2 ) * sizeof( char ) );
    strcat( MainString , String1 );
    strcat( MainString , String2 );
    return  *MainString;
}

void ReverseString(char *String)
{
    for( int i = strlen( String ) - 1 ; i > 0 ; i--)
    {
        printf("%c" , String[ i ]);
    }
}

int CompareString(char *String1 , char *String2 )
{
    int i = 0 ;
    while ( String1[ i ] == String2[ i ] && String1[ i ] != '\0' && String2[ i ] != '\0' )i++;
    if ( ( i + 1) == strlen( String1 ) && ( i + 1) == strlen( String2 ) )return 1;
    else return 0;
}

int main()
{
    char *String1 = (char*)malloc( 255 * sizeof( char ) ) , *String2 = (char*)malloc( 255 * sizeof( char ) ) , *ResultString = (char*)malloc( 510 * sizeof( char ) );
    int Point = 0 , Start = 0 , End = 0 ;
    while (TRUE)
    {
        system("cls");
        printf("1.Search string in string\n2.Copy string from string\n3.Connect 2 strings into 1\n4.Reverse your string\n5.Compare 2 strings\n6.Exit\n");
        char Choose = getch();
        switch (Choose)
        {
            case '1' :
                system("cls");
                printf("Add main string_\n");
                String1 = ReadString();
                printf("Add additional string_ \n");
                String2 = ReadString();
                Point = SearchStringInString(String1 , String2);
                printf("%d" , Point);
                printf("Press any button to restart the programme_");
                getch();
                break;
            case '2' :
                system("cls");
                printf("Add main string_\n");
                String1 = ReadString();
                printf("Add start of part for copy_\n");
                scanf( "%d" , &Start );
                printf("Add end of part foe copy_\n");
                scanf( "%d" , &End );
                ResultString = CopyString( String1 , Start , End );
                printf("%s" , ResultString );
                printf("Press any button to restart the programme_");
                getch();
                break;
            case '3' :
                system("cls");
                printf("Add first string_\n");
                String1 = ReadString();
                printf("Add second string_\n");
                String2 = ReadString();
                ResultString = ConnectString( String1 , String2 );
                printf("%s" , ResultString );
                printf("Press any button to restart the programme_");
                getch();
                break;
            case '4' :
                system("cls");
                printf("Add your string_\n");
                String1 = ReadString();
                ReverseString( String1 );
                printf("Press any button to restart the programme_");
                getch();
                break;
            case '5' :
                printf("Add first string_\n");
                String1 = ReadString();
                printf("Add second string_\n");
                String2 = ReadString();
                if( CompareString( String1 , String2 ) )printf("Your strings are same\n");
                else printf("Your strings are different\n");
                printf("Press any button to restart the programme_");
                getch();
                break;
            case '6' :
                return 0;
            default:
                break;
        }
    }
}