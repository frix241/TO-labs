namespace UniversidadApp
{
    public class Horario
    {
        private string dia;
        private string horaInicio;
        private string horaFin;

        public Horario() { }

        public Horario(string dia, string horaInicio, string horaFin)
        {
            this.dia = dia;
            this.horaInicio = horaInicio;
            this.horaFin = horaFin;
        }

        public string Dia
        {
            get { return dia; }
            set { dia = value; }
        }

        public string HoraInicio
        {
            get { return horaInicio; }
            set { horaInicio = value; }
        }

        public string HoraFin
        {
            get { return horaFin; }
            set { horaFin = value; }
        }

        public override string ToString()
        {
            return $"Horario{{dia={dia}, {horaInicio}-{horaFin}}}";
        }
    }
}
