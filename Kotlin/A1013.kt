import kotlin.math.abs

fun main(args: Array<String>) {
    val input = readLine();
    val valores = input!!.split(" ").map(String::toInt);
    val maiorValor= calcularMaior(valores);
    println("$maiorValor eh o maior")

}

fun calcularMaior(valores:List<Int>):Int{
    var maior = valores.get(0);
    for(i in  0 until 2){
        maior=( maior +valores[i+1] + abs(valores[i+1]- maior)) / 2;
    }
    return maior;
}