#ifndef ONE_FORM_H
#define ONE_FORM_H

#include "../Components/one_layered_canvas.h"


class One_Form {
// Constructor
public:

    One_Form(One_Layered_Canvas& app_canvas) : canvas(app_canvas) {}


// Data Member
protected:

    One_Layered_Canvas& canvas;
};


#endif // ONE_FORM_H
