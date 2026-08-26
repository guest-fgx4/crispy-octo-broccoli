import java.io.*;


public class cifraCesar 
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
        final int offset = 3;
        Boolean loop = true;
        String stringLine = "";
        String cifraString = "";

        do {

            stringLine = readLine();

            if (stringLine != "")
            {
                for(int i = 0; i < stringLine.length(); i++)
                {
                    cifraString = cifraString + (char)(stringLine.charAt(i) + offset);
                }


                System.out.println(cifraString);
                cifraString = "";
            }
            else
            {
                if (stringLine.charAt(0) == 'F' &&
                    stringLine.charAt(0) == 'I' &&
                    stringLine.charAt(0) == 'M' &&
                    stringLine.charAt(0) == '\n')
                {
                    loop = false;
                }

            }



        } while(loop);

        System.out.println(readLine().charAt(0));
    }
}
