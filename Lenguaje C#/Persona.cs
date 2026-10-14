using System;

namespace UniversidadApp
{
    public class Persona
    {
        private string nombre;
        private int edad;

        public Persona() { }

        public Persona(string nombre, int edad)
        {
            this.nombre = nombre;
            this.edad = edad;
        }

        public string Nombre
        {
            get { return nombre; }
            set { nombre = value; }
        }

        public int Edad
        {
            get { return edad; }
            set
            {
                if (value < 0)
                    throw new ArgumentException("La edad no puede ser negativa");
                edad = value;
            }
        }

        public override string ToString()
        {
            return $"Persona{{nombre={nombre}, edad={edad}}}";
        }
    }
}
