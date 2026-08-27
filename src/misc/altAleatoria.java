import java.io.*;
import java.util.Random;


public class altAleatoria
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
