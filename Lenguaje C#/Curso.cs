namespace UniversidadApp
{
    // COMPOSICION: el Horario es parte de Curso; no se comparte con nadie mas
    // y su ciclo de vida depende del Curso que lo contiene.
    public class Curso
    {
        private string nombre;
        private readonly Horario horario;

        public Curso() { }

        public Curso(string nombre, Horario horario)
        {
            this.nombre = nombre;
            this.horario = horario;
        }

        public string Nombre
        {
            get { return nombre; }
            set { nombre = value; }
        }

        public Horario Horario
        {
            get { return horario; }
        }

        public override string ToString()
        {
            return $"Curso{{nombre={nombre}, horario={horario}}}";
        }
    }
}
