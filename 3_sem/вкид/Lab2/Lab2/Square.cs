using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Lab2
{
    class Square: Rectangle, IPrint
    {
        public Square(double yourlength)
        {
            _length1 = _length2 = yourlength;
        }
        public override string ToString()
        {
            return "Length of the side: " + _length1.ToString() + "; Square: " + area.ToString() + ";";
        }
    }
}
