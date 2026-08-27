import java.io.*;
import java.util.Random;


public class Is
{
    public static String readLine()
    {
        String line = "";

        try
        {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            line = br.readLine();
        } catch (Exception e) {}

        return line;
    }

    public static Boolean isVogal(char letra)
    {
        Boolean resp = false;

        final char[] vogais = ['a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'];

        for(int i = 0; i < vogais.length(); i++)
        {
            if (vogais.charAt(i) == letra)
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
        while(resp && index < string.length())
        {
            resp = resp && !(isVogal(string.charAt(index)));
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

        for(int i = 0; i < string.length(); i++)
        {
            resp = resp && (string.charAt(i) >= '0' && string.charAt(i) <= '9'); 
        }

        return resp;
    }

    public static void main(String[] args)
    {
        Boolean loop = true;
        String stringLine = "";
        String resp = "";
        char letraA = ' ';
        char letraB = ' ';

        Random gen = new Random();
        gen.setSeed(4);

        do {

            stringLine = readLine();

            if (stringLine != "")
            {
                if (stringLine.charAt(0) == 'F' &&
                        stringLine.charAt(1) == 'I' &&
                        stringLine.charAt(2) == 'M')
                {
                    loop = false;
                }
                else
                {
                    letraA = (char)('a' + (Math.abs(gen.nextInt()) % 26));
                    letraB = (char)('a' + (Math.abs(gen.nextInt()) % 26));

                    for(int i = 0; i < stringLine.length(); i++)
                    {
                        if (stringLine.charAt(i) == letraA)
                        {
                            resp = resp + letraB;
                        }
                        else
                        {
                            resp = resp + stringLine.charAt(i);
                        }
                    }


                    System.out.println(resp);
                    resp = "";

                }
            }

        } while(loop);
    }
}
