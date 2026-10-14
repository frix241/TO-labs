using System;

namespace UniversidadApp
{
    public class Program
    {
        public static void Main(string[] args)
        {
            // 2 profesores
            var p1 = new Profesor("Carlos Ruiz", 45, "Matematicas");
            var p2 = new Profesor("Ana Lopez", 38, "Programacion");

            // 3 estudiantes
            var e1 = new Estudiante("Juan Perez", 20, "A001", 8.5);
            var e2 = new Estudiante("Maria Garcia", 22, "A002", 9.1);
            var e3 = new Estudiante("Luis Torres", 21, "A003", 7.8);

            // 2 cursos, cada uno con su horario (COMPOSICION)
            var c1 = new Curso("Programacion Orientada a Objetos",
                               new Horario("Lunes", "08:00", "10:00"));
            var c2 = new Curso("Estructuras de Datos",
                               new Horario("Miercoles", "10:00", "12:00"));

            // AGREGACION: se agregan los cursos a la universidad
            var universidad = new Universidad("Universidad Nacional");
            universidad.AgregarCurso(c1);
            universidad.AgregarCurso(c2);

            Console.WriteLine(p1);
            Console.WriteLine(p2);
            Console.WriteLine(e1);
            Console.WriteLine(e2);
            Console.WriteLine(e3);
            Console.WriteLine(c1);
            Console.WriteLine(c2);
            Console.WriteLine(universidad);

            // DEPENDENCIA: reporte temporal de un estudiante
            Console.WriteLine(Reporte.GenerarReporte(e1));
        }
    }
}
