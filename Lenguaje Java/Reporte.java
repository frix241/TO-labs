public class Reporte {
    public static String generarReporte(Estudiante estudiante) {
        return "===== REPORTE ACADEMICO =====\n"
                + "Estudiante: " + estudiante.getNombre() + "\n"
                + "Edad: " + estudiante.getEdad() + "\n"
                + "Matricula: " + estudiante.getMatricula() + "\n"
                + "Promedio: " + estudiante.getPromedio() + "\n"
                + "=============================";
    }
}
