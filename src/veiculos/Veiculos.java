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


    public void parseVeiculo(String linha)
    {

    }

    @override
    public String toString()
    {

    }
}

class Data
{
    private int ano = 0;
    private int mes = 0;
    private int dia = 0;

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
}



public class Veiculos
{
    public static String filePath = "./data/veiculos.csv";
    public static String filePathSimple = "./data/veiculos_sim.csv";

    public static void main(String[] args)
    {

        LeitorCSV csv = new LeitorCSV();
        csv.openFile(filePath);
        System.out.println(csv.readNextLine());
        System.out.println(csv.readNextLine());

    }
}
