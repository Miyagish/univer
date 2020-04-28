using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;

namespace Lab3
{
    class Circle : Geometric_figures,IPrint
    {
        private double _radius;

        public override double Area
        {
            get
            {
                return area;
            }
        }

        public Circle(double yourradius)
        {
            _radius = yourradius;
        }

        public double radius
        {
            get { return _radius; }
            set
            {
                _radius = value;
                area = Math.Pow(value, 2) * Math.PI;
            }
        }

        public override string ToString()
        {
            return "Radius of the circle  " + _radius.ToString() + "; Square: " + area.ToString() + ";";
        }

        public void Print()
        {
            Console.WriteLine(ToString());
        }
    }
}
