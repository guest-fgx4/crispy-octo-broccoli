import java.io.*;
import java.util.Random;
import java.util.Scanner;


public class Is
{
    //public static String readLine()
    //{
    //    String line = "";

    //    try
    //    {
    //        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    //        line = br.readLine();
    //    } catch (Exception e) {}

    //    return line;
    //}

    public static Boolean isVogal(char letra)
    {
        Boolean resp = false;

        final char[] vogais = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};

        for(int i = 0; i < vogais.length; i++)
        {
            if (vogais[i] == letra)
            {
                resp = true;
            }
        }

        return resp;
    }

    public static Boolean vogal(String string)
    {
        Boolean resp = true;

        int index = 0;
        while(resp && index < string.length())
        {
            resp = resp && (isVogal(string.charAt(index)));
            index++;
        }

        return resp;
    }

    public static Boolean nonVogal(String string)
    {
        Boolean resp = true;

        int index = 0;
		char currentChar = ' ';
        while(resp && index < string.length())
        {
			currentChar = string.charAt(index);
            resp = resp && !(isVogal(currentChar));
            resp = resp && ((currentChar >= 'b' && currentChar <= 'z') || (currentChar >= 'B' && currentChar <= 'Z'));
            index++;
        }

        return resp;
    }

    public static Boolean isNumber(String string)
    {
        Boolean resp = true;

        for(int i = 0; i < string.length(); i++)
        {
            resp = resp && (string.charAt(i) >= '0' && string.charAt(i) <= '9'); 
        }

        return resp;
    }

    //TODO: DO THIS
    public static Boolean isReal(String string)
    {
        Boolean resp = true;
		short dot = 0;

        for(int i = 0; i < string.length(); i++)
        {
				if ((string.charAt(i) == '.' || string.charAt(i) == ','))
				{
						dot++;
				}
				else
				{
					resp = resp && isNumber(string.charAt(i) + "");
				}
        }

		if (dot <= 0 || dot > 1)
		{
				resp = false;
		}

        return resp;
    }

    public static void main(String[] args)
    {
        Boolean loop = true;
        String stringLine = "";
		Scanner sc = new Scanner(System.in);
        do {

            stringLine = sc.nextLine();

            if (stringLine != "")
            {
					if (stringLine.length() == 3 && 
									stringLine.charAt(0) == 'F' &&
									stringLine.charAt(1) == 'I' &&
									stringLine.charAt(2) == 'M')
					{
							loop = false;
                }
                else
                {
						if (vogal(stringLine))
						{
								System.out.print("SIM ");
						}
						else
						{
								System.out.print("NAO ");
						}

						if (nonVogal(stringLine))
						{
								System.out.print("SIM ");
						}
						else
						{
								System.out.print("NAO ");
						}
 
						if (isNumber(stringLine))
						{
								System.out.print("SIM ");
						}
						else
						{
								System.out.print("NAO ");
						}   

						if (isReal(stringLine))
						{
								System.out.println("SIM");
						}
						else
						{
								System.out.println("NAO");
						}   
                }
            }

        } while(loop);
    }
}
