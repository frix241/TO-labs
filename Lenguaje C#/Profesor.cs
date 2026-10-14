namespace UniversidadApp
{
    public class Profesor : Persona
    {
        private string especialidad;

        public Profesor() : base() { }

        public Profesor(string nombre, int edad, string especialidad)
        : base(nombre, edad)
        {
            this.especialidad = especialidad;
        }

        public string Especialidad
        {
            get { return especialidad; }
            set { especialidad = value; }
        }

        public override string ToString()
        {
            return $"Profesor{{nombre={Nombre}, edad={Edad}, especialidad={especialidad}}}";
        }
    }
}
