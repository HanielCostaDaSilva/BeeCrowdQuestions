import java.util.*
import kotlin.math.abs

fun main(args: Array<String>) {
    var vencedor="";
    val caracteresPermitidos = setOf('X', 'O')

    val tabuleiro: String = readLine().toString();
    
    val quantidadeDeO = tabuleiro.count { it == 'O' };
    val quantidadeDeX = tabuleiro.count { it == 'X' };

    val checkCaracter = tabuleiro.all { it in caracteresPermitidos }

    if(quantidadeDeO > 1 || quantidadeDeX > 2 || !checkCaracter ){
        vencedor ="?"
    }
    else{
        vencedor = encontrarVencedor(tabuleiro);
    }
    println(vencedor);
}
fun encontrarVencedor(jogada:String):String{
    var quadro = jogada[0];
    var resultado ="*";

    for(i in  0 until 2){
        if(quadro == jogada[i+1]){
            resultado = if(quadro == 'X') "Alice" else "Bob";
            break;
        }
        quadro = jogada[i+1];

    }
    return resultado;
}