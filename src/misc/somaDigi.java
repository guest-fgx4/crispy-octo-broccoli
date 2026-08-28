import java.util.Scanner;


public class somaDigi
{

    public static int somaDi(int digi)
    {
        int resp = 0;

        if (digi > 0)
        {
            resp = resp + somaDi(digi / 10);
            resp = resp + (digi % 10);
        }

        return resp;
    }

    public static void main(String[] args)
    {
        Boolean loop = true;
        int numero = 0;
        Scanner sc = new Scanner(System.in);

        do {

            numero = sc.nextInt();
            System.out.println(numero);

            if (numero < 0)
            {
                numero *= -1;
            }

            if (numero == 0 ) loop = false;

            System.out.println(somaDi(numero));
            
        } while(loop);
    }
}
