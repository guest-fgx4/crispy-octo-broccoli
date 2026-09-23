import java.io.*;
import java.util.Scanner;
import java.util.Random;


class LeitorCSV
{
    public static Scanner fileScanner = null;


    public void openFile(String filePath)
    {
        try
        {
            File file = new File(filePath);
            fileScanner = new Scanner(file);
        }
        catch (Exception e) { System.out.println(e);}
    }

    public String readNextLine()
    {

        if (fileScanner.hasNextLine())
        {
            return fileScanner.nextLine();
        }
        else
        {
            return "EOF";
        }
    }

}

class Veiculo
{
    private int      id          = 0;
    private int      ano         = 0;
    private int      cilindros   = 0;
    private String   categoria   = "";
    private String   modelo      = "";
    private String   marca       = "";
    private String   transmisao  = "";
    private String   tracao      = "";
    private String[] combustivel;
    private double   cilindradas = 0.0;
    private double   c02         = 0.0;
    private double   consumoCidade = 0.0;
    private double   consumoEstrada = 0.0;
    private Boolean  turbo       = false;
    private Data data;


    public Veiculo ()
    {
    }


    public Veiculo(
            int id, int ano, int cilindros, String categoria, String modelo, String marca,
            String transmisao, String tracao, String[] combustivel, double cilindradas,
            double c02, double consumoCidade, double consumoEstrada, Boolean turbo, Data data)
    {
        this.id = id;
        this.ano = ano;
        this.cilindros = cilindros;
        this.categoria = categoria;
        this.modelo = modelo;
        this.marca = marca;
        this.transmisao = transmisao;
        this.tracao = tracao;
        this.combustivel = combustivel;
        this.cilindradas = cilindradas;
        this.c02 = c02;
        this.consumoCidade = consumoCidade;
        this.consumoEstrada = consumoEstrada;
        this.turbo = turbo;
        this.data = data;
    }

    public int getId() {
        return id;
    }
    public void setId(int id) {
        this.id = id;
    }

    public int getAno() {
        return ano;
    }
    public void setAno(int ano) {
        this.ano = ano;
    }

    public int getCilindros() {
        return cilindros;
    }
    public void setCilindros(int cilindros) {
        this.cilindros = cilindros;
    }

    public String getCategoria() {
        return categoria;
    }
    public void setCategoria(String categoria) {
        this.categoria = categoria;
    }

    public String getModelo() {
        return modelo;
    }
    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public String getMarca() {
        return marca;
    }
    public void setMarca(String marca) {
        this.marca = marca;
    }

    public String getTransmisao() {
        return transmisao;
    }
    public void setTransmisao(String transmisao) {
        this.transmisao = transmisao;
    }

    public String getTracao() {
        return tracao;
    }
    public void setTracao(String tracao) {
        this.tracao = tracao;
    }

    public String[] getCombustivel() {
        return combustivel;
    }
    public void setCombustivel(String[] combustivel) {
        this.combustivel = combustivel;
    }

    public double getCilindradas() {
        return cilindradas;
    }
    public void setCilindradas(double cilindradas) {
        this.cilindradas = cilindradas;
    }

    public double getC02() {
        return c02;
    }
    public void setC02(double c02) {
        this.c02 = c02;
    }

    public double getConsumoCidade() {
        return consumoCidade;
    }
    public void setConsumoCidade(double consumoCidade) {
        this.consumoCidade = consumoCidade;
    }

    public double getConsumoEstrada() {
        return consumoEstrada;
    }
    public void setConsumoEstrada(double consumoEstrada) {
        this.consumoEstrada = consumoEstrada;
    }

    public Boolean getTurbo() {
        return turbo;
    }
    public void setTurbo(Boolean turbo) {
        this.turbo = turbo;
    }

    public Data getData() {
        return data;
    }
    public void setData(Data data) {
        this.data = data;
    }

    public void incrementId()
    {
        this.id = this.id + 1;
    }

    public Veiculo clone()
    {
        return new Veiculo (
                    this.id, this.ano, this.cilindros, this.categoria, this.modelo, this.marca,
                this.transmisao, this.tracao, this.combustivel, this.cilindradas,
                this.c02, this.consumoCidade, this.consumoEstrada, this.turbo, this.data);

                
    }


    public boolean parseVeiculo(String linha)
    {
        String[] dados;
        boolean res = false;

        if (linha == "" || linha == null) return res;

        dados = linha.split(",");

        for(int i = 0; i < dados.length; i++)
        {
            //System.out.println(dados[i]);
        }

        this.id = Integer.parseInt(dados[0]);
        this.marca = dados[1];
        this.modelo = dados[2];
        this.ano = Integer.parseInt(dados[3]);
        this.categoria = dados[4];
        this.combustivel = dados[5].split(";");
        this.cilindros = Integer.parseInt(dados[6]);
        this.cilindradas = Double.parseDouble(dados[7]);
        this.transmisao = dados[8];
        this.tracao = dados[9];
        this.consumoCidade = Double.parseDouble(dados[10]);
        this.consumoEstrada = Double.parseDouble(dados[11]);
        this.c02 = Double.parseDouble(dados[12]);
        this.turbo = Boolean.parseBoolean(dados[13]);
        
        this.data = new Data(dados[14]);
        

        return res;
    }

    @Override
    public String toString()
    {
        return "[ " +
            id              +   " ## "+
            marca           +   " ## "+
            modelo          +   " ## "+
            categoria       + " ## "+
            cilindros       + " ## "+
            cilindradas     +" ## "+
            transmisao      +" ## "+
            tracao          +" ## "+
            consumoCidade   +" ## "+
            consumoEstrada  +" ## "+
            c02             +" ## "+
            turbo           +" ## "+
            data      +""+
            " ]";

    }
}

class Data
{
    private int ano = 0;
    private int mes = 0;
    private int dia = 0;

    public Data(String linha)
    {
        
        if (linha == "" || linha == null) 
        {
            ano = -1;
            mes = -1;
            dia = -1;
        }
        else
        {
            String[] data = linha.split("-");
            ano = Integer.parseInt(data[0]);
            mes = Integer.parseInt(data[1]);
            dia = Integer.parseInt(data[2]);
        }
    }

    public int getAno() {
        return ano;
    }
    public void setAno(int ano) {
        this.ano = ano;
    }

    public int getMes() {
        return mes;
    }
    public void setMes(int mes) {
        this.mes = mes;
    }

    public int getDia() {
        return dia;
    }
    public void setDia(int dia) {
        this.dia = dia;
    }

    @Override
    public String toString()
    {
        return "(" + ano + "/" + mes + "/" + dia + ")";
    }
}


class Ordenar
{

    public void insercao(Veiculo[] dados)
    {
        if ( dados == null || dados.length == 0) return;
        Veiculo atual = dados[0];

        for (int i = 1; i < dados.length; i++)
        {
            atual = dados[i];
            int j = i - 1;
            while (j >= 0 && (dados[j].getMarca().compareTo(atual.getMarca()) > 0))
            {
                dados[j + 1] = dados[j];
                j--;
            }
            dados[j+1] = atual;
        }

    }

    public void insercao(Veiculo[] dados, int a)
    {
        if ( dados == null || dados.length == 0) return;
        int size = dados[0].getId();

        for (int i = 2; i < size; i++)
        {
            Veiculo atual = dados[i];
            int j = i - 1;
            while (j >= 1 && (dados[j].getCilindradas() * 10) > (atual.getCilindradas() * 10))
            {
                dados[j + 1] = dados[j];
                j--;
            }
            dados[j+1] = atual;
        }

    }

    public Veiculo[] bucketsort(Veiculo[] dados)
    {
        //primeiramente instanciar os buckets
        //seprar cada dado em seu bucket devido
        //ordenrar cada buket
        //cilindrada sort var

        Veiculo[][] baldes = new Veiculo[10][501];
        final int BUCKET_SIZE = 10;
        final double NORMALIZED_VALUE = 8.1;
        
        for (int i = 0; i < BUCKET_SIZE; i++)
        {
            baldes[i][0] = new Veiculo();
            baldes[i][0].incrementId();
        }

        for (int i = 0; i < dados.length; i++)
        {
            int position = ((int) Math.floor(dados[i].getCilindradas()));
            baldes[position][baldes[position][0].getId()] = dados[i].clone();
            baldes[position][0].incrementId();
            //System.out.println(baldes[position][0].getId());
        }

        // printBucket(baldes);        
        //

        for (int i = 0; i < BUCKET_SIZE; i++)
        {
            insercao(baldes[i], i);
        }


        // printBucket(baldes);        

        int index = 0;
        for(int linha = 0; linha < 10; linha++)
        {
            for(int coluna = 1; coluna < 500; coluna++)
            {
                if (baldes[linha][coluna] != null)
                {
                    dados[index] = baldes[linha][coluna];
                    index++;
                }
            }
        }


        return dados;
    }

    public void printBucket(Veiculo[][] bucket)
    {
        for(int coluna = 1; coluna < 500; coluna++)
        {
            for(int linha = 0; linha < 10; linha++)
            {
                if (bucket[linha][coluna] != null)
                {
                    System.out.print(bucket[linha][coluna].getCilindradas() + "\t");
                }
                else
                {
                    System.out.print(" " + "\t");
                }
            }
            System.out.println();
        }
    }

    public void insercao(int[] dados)
    {

        int atual = dados[0];

        for (int i = 1; i < dados.length; i++)
        {

            atual = dados[i];
            int j = i - 1;
            while (j >= 0 && dados[j] > atual)
            {
                dados[j + 1] = dados[j];
                j--;
            }

            dados[j+1] = atual;
            
        }

        for (int i = 0; i < dados.length; i++)
        {
            System.out.println(dados[i]);
        }
    }

    public void print(Veiculo[] dados)
    {
        for (int i = 0; i < dados.length; i++)
        {
            System.out.println(dados[i]);
        }
    }
}

public class Veiculos
{
    public static String filePath = "./data/veiculos.csv";
    public static String filePathSimple = "./data/veiculos_sim.csv";
    public static String filePathVerde = "/tmp/veiculos.csv";

    public static void main(String[] args)
    {

        Veiculo[] dados = new Veiculo[500];

        LeitorCSV csv = new LeitorCSV();
        csv.openFile(filePath);
        //System.out.println(csv.readNextLine());
        csv.readNextLine();

        int count = 0;
        while (csv.fileScanner.hasNextLine())
        {
            Veiculo vrom = new Veiculo();
            vrom.parseVeiculo(csv.readNextLine());
            //System.out.println(vrom);
            dados[count] = vrom;
            count++;
        }

        Ordenar sort = new Ordenar();

        //sort.insercao(dados);
        //sort.print(dados);


        sort.bucketsort(dados);
        sort.print(dados);
    }
}
