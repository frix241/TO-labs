public class Estudiante extends Persona {
    private String matricula;
    private double promedio;

    public Estudiante() { super(); }

    public Estudiante(String nombre, int edad, String matricula, double promedio) {
        super(nombre, edad);
        this.matricula = matricula;
        this.promedio = promedio;
    }

    public String getMatricula() { return matricula; }
    public void setMatricula(String matricula) { this.matricula = matricula; }
    public double getPromedio() { return promedio; }
    public void setPromedio(double promedio) { this.promedio = promedio; }

    @Override
    public String toString() {
        return "Estudiante{nombre=" + getNombre() + ", edad=" + getEdad()
                + ", matricula=" + matricula + ", promedio=" + promedio + "}";
    }
}
