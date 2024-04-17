#ifndef CIRCLE_H //include guards
#define CIRCLE_H

#include <iostream>

class Circle {
    private:
        float radius;
        int x, y;

    public:
        Circle();
        Circle(float, int=0, int=0);
        ~Circle() { }

        // funcoes membro interface
        float	area();
        float	diameter();
        void	set_radius(float); //setter
				void	set_origin(int, int);
				float get_radius(); //getter
				void	print();
};

#endif