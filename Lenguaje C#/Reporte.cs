namespace UniversidadApp
{
    // DEPENDENCIA: Reporte usa un Estudiante solo de forma temporal
    // (como parametro de un metodo), sin guardar una referencia permanente.
    public static class Reporte
    {
        public static string GenerarReporte(Estudiante estudiante)
        {
            return "===== REPORTE ACADEMICO =====\n" +
                   $"Estudiante: {estudiante.Nombre}\n" +
                   $"Edad: {estudiante.Edad}\n" +
                   $"Matricula: {estudiante.Matricula}\n" +
                   $"Promedio: {estudiante.Promedio}\n" +
                   "=============================";
        }
    }
}
