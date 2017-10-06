#include <windef.h>
#include "Include_and_constants.h"


void ReadString( char *String ) //алгоритм чтения строки из буфера , получает адрес строки по которому будет лежать строка
{
    char  ch ; //символ для временной записи
    int i = 0 ; //счетчик
    scanf( "%c" , &ch ) ; //читаем первый символ
    while ( ch != '\n' ) //жрем символы из буфера пока нет перехода на слледующую строку
    {
        String[ i ] = ch  ; //кладем прочитанный символ в позицию в строке
        i ++ ; //обновляем счетчик
        scanf( "%c" , &ch ) ; //обновляем символ
    }
    String[ i + 1 ] = '\0' ; //все строки в си должны заканчиваться нулевым символом
    fflush( stdin ) ; //чистим буфер чтения
}


int SearchStringInString(char *MainString , char *String) //исщет в первой строке вторую и возвращает номер начала второй строки в первой ,
// на вход получает адреса главной строки и подстроки
{
    int i = 0 , j = 0 , k = 0 ; //три счетчика
    for ( i = 0 ; MainString[ i ] != '\0' ; i ++ ) //цикл продолжается пока строка не коньчится
        {
            for ( j = i , k = 0 ; String[ k ] != '\0' && MainString[ j ] == String[ k ] ; j ++ , k ++ ) ; //пока строки не закончились и символы под намерами совподают увеличиваем счетчики
            if ( k > 0 && String[ k + 1 ] == '\0' ) //если предыдущий цикл дошел до предпоследнего элемента , то значит совпадение начинается с i элемента строки
                return i ;

        }

    return -1 ;
}

void CopyString( char *MainString , int Start , int End , char *CopiedString ) //копирует подстроку из подстроки по номерам
{
    int j = 0 ; //счетчик
    for( int i = Start ; i <= End ; i ++ ) //цикл отвечающий за копированние
    {
        CopiedString[ j ] = MainString [ i ] ; //само копированние, происходит по символьно
        j ++ ;
    }
    CopiedString [ j + 1 ] = '\0' ; //закрываем строку нулевым элементом , как этого требует си
}



void ConnectString( char *String1 , char *String2 , char *MainString ) //соеденяет две строки в одну
// на вход получает адреса строк для объеденения и адрес строки в которой должен быть результат
{
    strncat( MainString , String1 , strlen( String1 ) ) ; //засовываем в резулбтирующую строку все кроме нулевого элемента
    strcat( MainString , String2 ) ; //засовываем всю строку чтобы не прибовлять нулевой элемент заного
}

void ReverseString( char *String ) //печать строки в обратном порядке
// на вход получает адрес строки
{
    for( int i = strlen( String ) - 2 ; i >= 0 ; i -- ) //цикл для выведения всего кроме нулевого элемента
    {
        printf("%c" , String[ i ]);
    }
    printf("\n");
}


int main()
{
    char *String1 = ( char* )malloc( 255 * sizeof( char ) ) , *String2 = ( char* )malloc( 255 * sizeof( char ) ) , *ResultString =( char* )malloc( 510 * sizeof( char ) ) ;
    // выделение памяти динамическим образом под строки для дальнейшего удобства работы с памятью
    int Point = 0 , Start = 0 , End = 0 ; //создаем и инициализируем переменные для:точки вхождения,начала копированния ,конца копированния
    while (TRUE) //меню
    {
        system( "cls" ) ;
        fflush( stdin ) ; //чистим буфер
        memset( String1 , 0 , sizeof( String1 ) ) ; //обнуляем наши строки, нужно для неоднократного использования программы
        memset( String2 , 0 , sizeof( String2 ) ) ;
        memset( ResultString , 0 , sizeof( ResultString ) ) ;
        printf( "1.Search string in string\n2.Copy string from string\n3.Connect 2 strings into 1\n4.Reverse your string\n5.Compare 2 strings\n6.Exit\n" ) ;
        char Choose = getch() ;
        switch ( Choose )
        {
            case '1' : //поиск подстроки в строке
                system( "cls" );
                printf( "Add main string_\n" ) ;
                ReadString( String1 ) ; //читаем строку в string1
                printf( "Add additional string_ \n" ) ;
                ReadString( String2 ) ; //читаем подстроку в string2
                Point = SearchStringInString( String1 , String2 ) ; //получаем андрес точки вхожения и храним его в point
                if( Point != -1 ) //в случае отсутствия подстроки в строке функция возращает -1
                printf( "%d\n" , Point + 1 ) ;
                else printf( "There is no such element\n" ) ;
                printf( "Press any button to restart the programme_" ) ;
                getch() ;
                break;
            case '2' : //копированние подстроки из строки по андресам
                system( "cls" ) ;
                printf( "Add main string_\n" ) ;
                ReadString( String1 ) ; //читаем строку в string1
                printf( "Add start of part for copy_\n" ) ;
                Start = In() ; //читаем точку начала копированния с помощью фкнкции из include and constants
                printf( "Add end of part for copy_\n" ) ;
                Start = In() ; //читаем точку окончания копированния с помощью фкнкции из include and constants
                CopyString( String1 , Start - 1 , End - 1 , ResultString  ) ; //вызываем функцию копированния
                //по адресу resultstring будет находитьсяч результат копированния
                printf( "%s\n" , ResultString ) ;
                printf( "Press any button to restart the programme_" ) ;
                getch() ;
                break ;
            case '3' : //объеденение строк
                system( "cls" ) ;
                printf( "Add first string_\n" ) ;
                fflush( stdin ) ; //чистим буфер на всякий случай
                ReadString( String1 ) ; //читаем строку в string1
                printf( "Add second string_\n" ) ;
                ReadString( String2 ) ; //читаем строку в string2
                ConnectString( String1 , String2 , ResultString ) ; //вызываем функцию объеденения
                //по адресу resultstring будет находитьсяч результат объеденения
                printf( "%s\n" , ResultString ) ;
                printf( "Press any button to restart the programme_" ) ;
                getch() ;
                break ;
            case '4' : //печать строки в обратном порядке
                system( "cls" ) ;
                printf( "Add your string_\n" ) ;
                ReadString( String1 ) ; //читаем строку в string1
                ReverseString( String1 ) ; //вызываем функцию печати в обратном порядке
                printf( "Press any button to restart the programme_" ) ;
                getch() ;
                break ;
            case '5' : //сравнение двух строк
                system( "cls" ) ;
                printf( "Add first string_\n" ) ;
                ReadString( String1 ) ; //читаем строку в string1
                printf( "Add second string_\n" ) ;
                ReadString( String2 ) ; //читаем строку в string2
                if( strcmp( String1 , String2 ) == 0 ) printf( "Your strings are same\n" ) ; //сравниваем строки стандартными си-шгыми функциями прямо в условии
                else printf( "Your strings are different\n" ) ;
                printf( "Press any button to restart the programme_" ) ;
                getch() ;
                break ;
            case '6' :
                return 0 ;
            default:
                break ;
        }
    }
}