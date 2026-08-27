import java.util.Scanner;


public class cifraCesar 
{

    public static void main(String[] args)
    {
        final int offset = 3;
        Boolean loop = true;
        String stringLine = "";
        String cifraString = "";
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
                    for(int i = 0; i < stringLine.length(); i++)
                    {
                        cifraString = cifraString + (char)(stringLine.charAt(i) + offset);
                    }


                    System.out.println(cifraString);
                    cifraString = "";
                }

            }
        } while(loop);
    }
}
