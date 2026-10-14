namespace UniversidadApp
{
    public class Estudiante : Persona
    {
        private string matricula;
        private double promedio;

        public Estudiante() : base() { }

        public Estudiante(string nombre, int edad, string matricula, double promedio)
        : base(nombre, edad)
        {
            this.matricula = matricula;
            this.promedio = promedio;
        }

        public string Matricula
        {
            get { return matricula; }
            set { matricula = value; }
        }

        public double Promedio
        {
            get { return promedio; }
            set { promedio = value; }
        }

        public override string ToString()
        {
            return $"Estudiante{{nombre={Nombre}, edad={Edad}, " +
            $"matricula={matricula}, promedio={promedio}}}";
        }
    }
}
