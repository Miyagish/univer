using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Lab3
{
    class FigureMatrixCheckEmpty : IMatrixCheckEmpty<Geometric_figures>
    {
        public Geometric_figures getEmptyElement()
        {
            return null;
        }

        public bool checkEmptyElement(Geometric_figures element)
        {
            bool Result = false;
            if (element == null)
            {
                Result = true;
            }
            return Result;
        }
    }
}
