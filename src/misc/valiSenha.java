import java.io.*;
import java.util.Scanner;
import java.util.Random;


public class valiSenha
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

		
	private static Random gen = new Random();
    public static void main(String[] args)
    {
        Boolean loop = true;
        String stringLine = "";
		Scanner sc = new Scanner(System.in);

        gen.setSeed(4);

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
                    Boolean res = true;

                    if (stringLine.length() < 8) res = false;

                    Boolean test1 = false;
                    Boolean test2 = false;
                    Boolean test3 = false;
                    Boolean test4 = false;
                    for (int i = 0; i < stringLine.length(); i++)
                    {
                        if (stringLine.charAt(i) >= 'a' && stringLine.charAt(i) <= 'z') { test1 = true; }
                        if (stringLine.charAt(i) >= 'A' && stringLine.charAt(i) <= 'Z') { test2 = true; }
                        if (stringLine.charAt(i) >= '0' && stringLine.charAt(i) <= '9') { test3 = true; }
                        if (stringLine.charAt(i) >= '!' && stringLine.charAt(i) <= '/' ||
                            stringLine.charAt(i) >= ';' && stringLine.charAt(i) <= '@' ||
                            stringLine.charAt(i) >= '[' && stringLine.charAt(i) <= '`' ||
                            stringLine.charAt(i) >= '{' && stringLine.charAt(i) <= '~') { test4 = true; }
                    }

                    res = res && ( test1 && test2 && test3 && test4);

                    if (res)
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
