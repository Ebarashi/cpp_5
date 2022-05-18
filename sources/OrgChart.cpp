#include "OrgChart.hpp"
using namespace std;

namespace ariel
{
    OrgChart::OrgChart(){
        this->iter = "iter";
    }

    OrgChart::~OrgChart(){}
    
    OrgChart &OrgChart::add_root(string name)
    {
        this->root.name = name;
        return *this;
    }
    
    OrgChart &OrgChart::add_sub(string father, string son)
    {
        return *this;
    }

    string *OrgChart::begin_level_order()
    {
        return &this->iter;
    }
    string *OrgChart::end_level_order()
    {
        return &this->iter;
    }
    string *OrgChart::begin_reverse_order()
    {
        return &this->iter;
    }
    string *OrgChart::reverse_order()
    {
        return &this->iter;
    }
    string* OrgChart::begin_preorder()
    {
        return &this->iter;
    }
    string* OrgChart::end_preorder()
    {
        return &this->iter;
    }
    ostream &operator<<(ostream &out, OrgChart &root)
    {
        return out;
    }

    
}


