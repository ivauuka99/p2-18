//Даны положительные числа A и B (A > B). На отрезке длины A размещено максимально
// возможное количество отрезков длины B (без наложений). Не используя
// операции умножения и деления, найти длину незанятой части отрезка A.



public class Main {

    public static void main(String[] args) {
       int a = 7, b = 3;// a глвный отрезок, b вложенный отрезок

       while(a > b){
           a -= b;
       }
       System.out.println("answer = " + a);
    }
}