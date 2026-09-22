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

        sort.insercao(dados);
        sort.print(dados);

    }
}
