#include<stdio.h>


int isVogal(char letra,const char* vogais, int index)
{
    int resp = 1;
    if (resp && index < 10)
    {
        resp = (vogais[index] == letra);
        if (!resp)
        {
            resp = isVogal(letra, vogais, index + 1);
        }
    }
    else
    {
        resp = 0;
    }

    return resp;
}



//public static Boolean vogal(String string)
//{
//    Boolean resp = true;
//
//    int index = 0;
//    while(resp && index < string.length())
//    {
//        resp = resp && (isVogal(string.charAt(index)));
//        index++;
//    }
//
//    return resp;
//}
//
//public static Boolean nonVogal(String string)
//{
//    Boolean resp = true;
//
//    int index = 0;
//    char currentChar = ' ';
//    while(resp && index < string.length())
//    {
//        currentChar = string.charAt(index);
//        resp = resp && !(isVogal(currentChar));
//        resp = resp && ((currentChar >= 'b' && currentChar <= 'z') || (currentChar >= 'B' && currentChar <= 'Z'));
//        index++;
//    }
//
//    return resp;
//}
//
//public static Boolean isNumber(String string)
//{
//    Boolean resp = true;
//
//    for(int i = 0; i < string.length(); i++)
//    {
//        resp = resp && (string.charAt(i) >= '0' && string.charAt(i) <= '9'); 
//    }
//
//    return resp;
//}
//
////TODO: DO THIS
//public static Boolean isReal(String string)
//{
//    Boolean resp = true;
//    short dot = 0;
//
//    for(int i = 0; i < string.length(); i++)
//    {
//        if ((string.charAt(i) == '.' || string.charAt(i) == ','))
//        {
//            dot++;
//        }
//        else
//        {
//            resp = resp && isNumber(string.charAt(i) + "");
//        }
//    }
//
//    if (dot <= 0 || dot > 1)
//    {
//        resp = false;
//    }
//
//    return resp;
//}


int main()
{
    const char vogais[] = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
    const int tamMax = 1000;
    char array[tamMax];
    int endedloop = 0;

    while (!endedloop)
    {
        fgets(array, tamMax, stdin);

        if (array[0] == 'F' && array[1] == 'I' && array[2] == 'M' && ( array[3] == '\n'|| array[3] == '\0'))
        {
            endedloop = 1;
        }
        else
        {
            printf("%d\n", isVogal('a', vogais, 0));
            printf("%d\n", isVogal('b', vogais, 0));
            printf("%d\n", isVogal('c', vogais, 0));
            printf("%d\n", isVogal('i', vogais, 0));
        }
    }

    return 0;
}
