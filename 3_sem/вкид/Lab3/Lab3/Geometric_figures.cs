using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;

namespace Lab3
{
    abstract class Geometric_figures: IComparable
    {
        protected double area;

        public abstract double Area {get;}

        public virtual void finding_area()
        { }

        public int CompareTo(object o)
        {
            if (Area > ((Geometric_figures)o).Area)
                return 1;
            else
                return 0;
        }
    }
}
