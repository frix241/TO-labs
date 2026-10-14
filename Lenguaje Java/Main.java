public class Main {
    public static void main(String[] args) {
        // 2 profesores
        Profesor p1 = new Profesor("Carlos Ruiz", 45, "Matematicas");
        Profesor p2 = new Profesor("Ana Lopez", 38, "Programacion");

        // 3 estudiantes
        Estudiante e1 = new Estudiante("Juan Perez", 20, "A001", 8.5);
        Estudiante e2 = new Estudiante("Maria Garcia", 22, "A002", 9.1);
        Estudiante e3 = new Estudiante("Luis Torres", 21, "A003", 7.8);

        // 2 cursos, cada uno con su horario (COMPOSICION)
        Curso c1 = new Curso("Programacion Orientada a Objetos",
                new Horario("Lunes", "08:00", "10:00"));
        Curso c2 = new Curso("Estructuras de Datos",
                new Horario("Miercoles", "10:00", "12:00"));

        // AGREGACION: se agregan los cursos a la universidad
        Universidad universidad = new Universidad("Universidad Nacional");
        universidad.agregarCurso(c1);
        universidad.agregarCurso(c2);

        System.out.println(p1);  System.out.println(p2);
        System.out.println(e1);  System.out.println(e2);  System.out.println(e3);
        System.out.println(c1);  System.out.println(c2);
        System.out.println(universidad);

        // DEPENDENCIA: reporte temporal de un estudiante
        System.out.println(Reporte.generarReporte(e1));
    }
}
