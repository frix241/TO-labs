import scala.io.StdIn

object CountingBack {

  def countChange(money: Int, coins: List[Int]): Int = {
    if (money == 0) {
      1
    } else if (money < 0 || coins.isEmpty) {
      0
    } else {
      countChange(money - coins.head, coins) +
        countChange(money, coins.tail)
    }
  }

  def getCombinations(money: Int, coins: List[Int]): List[List[Int]] = {
    if (money == 0) {
      List(Nil)
    } else if (money < 0 || coins.isEmpty) {
      Nil
    } else {
      val usarMoneda =
        getCombinations(money - coins.head, coins)
          .map(combinacion => coins.head :: combinacion)

      val noUsarMoneda =
        getCombinations(money, coins.tail)

      usarMoneda ++ noUsarMoneda
    }
  }

  def main(args: Array[String]): Unit = {
    val monedasPeruanas = List(1, 2, 5)

    print("Ingrese la cantidad de dinero: ")
    val cantidad = StdIn.readInt()

    if (cantidad < 0) {
      println("La cantidad debe ser un entero mayor o igual que cero.")
    } else {
      val combinaciones = getCombinations(cantidad, monedasPeruanas)
      val totalFormas = countChange(cantidad, monedasPeruanas)

      println(s"\nCantidad a cambiar: S/ $cantidad")
      println(s"Denominaciones: ${monedasPeruanas.mkString(", ")}")
      println(s"Número de formas diferentes: $totalFormas")
      println("\nCombinaciones:")

      combinaciones.zipWithIndex.foreach {
        case (combinacion, indice) =>
          println(s"${indice + 1}. ${combinacion.mkString("+")}")
      }
    }
  }
}