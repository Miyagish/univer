using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Lab2
{
    class Rectangle : Geometric_figures, IPrint
    {
        protected double area;

        protected double _length1=0;
        protected double _length2=0;

        public Rectangle()
        { }

        public Rectangle(double yourlength1, double yourlength2)
        {
            _length1 = yourlength1;
            _length2 = yourlength2;
        }

        public double length1
        {
            get { return _length1; }
            set { _length1 = value; }
        }

        public double length2
        {
            get { return _length2; }
            set { _length2 = value; }
        }

        public override void finding_area()
        {
            area = _length1 * _length2;
        }

        public override string ToString()
        {
            return "Length of the sides: " + _length1.ToString() +", "+ _length2.ToString() + "; Square: " + area.ToString() + ";";
        }

        public void Print()
        {
            Console.WriteLine(ToString());
        }
    }
}
