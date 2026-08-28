import java.util.Scanner;


public class inverString
{

    public static String inverFn(int index, String origin)
    {
        String resp = "";

        if (index < origin.length())
        {
            resp = resp + inverFn(index + 1, origin);
            resp = resp + origin.charAt(index);
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
                    System.out.println(inverFn(0, stringLine));
                }

            }
        } while(loop);
    }
}
