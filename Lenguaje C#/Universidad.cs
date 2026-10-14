using System.Collections.Generic;
using System.Linq;

namespace UniversidadApp
{
    // AGREGACION: la Universidad tiene una lista de Cursos, pero los Cursos
    // pueden existir de forma independiente (no los crea ni los destruye).
    public class Universidad
    {
        private string nombre;
        private readonly List<Curso> cursos;

        public Universidad(string nombre)
        {
            this.nombre = nombre;
            this.cursos = new List<Curso>();
        }

        public string Nombre
        {
            get { return nombre; }
            set { nombre = value; }
        }

        public List<Curso> Cursos
        {
            get { return cursos; }
        }

        public void AgregarCurso(Curso curso)
        {
            cursos.Add(curso);
        }

        public override string ToString()
        {
            string cursosStr = "[" + string.Join(", ", cursos.Select(c => c.ToString())) + "]";
            return $"Universidad{{nombre={nombre}, cursos={cursosStr}}}";
        }
    }
}
