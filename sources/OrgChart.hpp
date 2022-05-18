#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
using namespace std;

namespace ariel
{
    struct ChartNode
    {
        string name;
        vector<ChartNode> sones;
    };

    class OrgChart
    {
        private:
            ChartNode root;
            string iter;

        public:
            
            OrgChart();
            ~OrgChart();

            OrgChart &add_root(string name);
            OrgChart &add_sub(string father, string son);
        

            string* begin_level_order();
            string* end_level_order(); 
            string* begin_reverse_order();
            string* reverse_order();
            string* begin_preorder();
            string* end_preorder();

            string* begin()
            {
                return begin_level_order();
            }
            
            string* end()
            {
                return end_level_order();
            }
            
            friend ostream &operator<<(ostream &out,OrgChart &root);
            

    };


}
