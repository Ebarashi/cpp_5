#include "doctest.h"
#include "OrgChart.hpp"
#include <iostream>
#include <vector>

using namespace ariel;
using namespace std;


TEST_CASE("TEST")
{
    OrgChart org;

    SUBCASE("CREATE ORG_CHART")
    {
        CHECK_NOTHROW(org.add_root("CEO")); 
        CHECK_NOTHROW(org.add_sub("CEO", "CTO"));
        CHECK_NOTHROW(org.add_sub("CEO", "CFO"));
        CHECK_NOTHROW(org.add_sub("CEO", "COO"));
        CHECK_NOTHROW(org.add_sub("CTO", "VP_SW"));
        CHECK_NOTHROW(org.add_sub("COO", "VP_BI"));
        vector<string> level_order = {"CEO" ,"CTO", "CFO", "COO" ,"VP_SW" ,"VP_BI"};
        size_t i = 0;
        for (auto employ : org)
        {
            CHECK_EQ(level_order[i], employ);
            i++;
        }
    }

    SUBCASE("level_order")
    {
        OrgChart org2;
        org2.add_root("CEO")
            .add_sub("CEO", "CTO")
            .add_sub("CEO", "CFO")
            .add_sub("CEO", "COO")
            .add_sub("CTO", "VP_SW")
            .add_sub("COO", "VP_BI");

        vector<string> checker = {"CEO", "CTO", "CFO", "COO", "VP_SW" ,"VP_BI"};
        size_t count = 0;
        for (auto it = org2.begin_level_order(); it != org2.end_level_order(); ++it)
        {
            CHECK_EQ((*it), checker.at(count));
            count++;
        }

    }

    SUBCASE("reverse_order")
    {
        OrgChart org3;

        CHECK_NOTHROW(org3.add_root("CEO")); 
        CHECK_NOTHROW(org3.add_sub("CEO", "CTO"));
        CHECK_NOTHROW(org3.add_sub("CEO", "CFO"));
        CHECK_NOTHROW(org3.add_sub("CEO", "COO"));
        CHECK_NOTHROW(org3.add_sub("CTO", "VP_SW"));
        CHECK_NOTHROW(org3.add_sub("COO", "VP_BI"));

        vector<string> checker = {"VP_SW", "VP_BI", "CTO", "CFO", "COO" ,"CEO"};
        size_t count = 0;
        for (auto it = org3.begin_reverse_order(); it != org3.reverse_order(); ++it)
        {
            CHECK_EQ((*it), checker.at(count));
            count++;
        }
    }

    SUBCASE("pre_order")
    {
        OrgChart org4;

        CHECK_NOTHROW(org4.add_root("CEO")); 
        CHECK_NOTHROW(org4.add_sub("CEO", "CTO"));
        CHECK_NOTHROW(org4.add_sub("CEO", "CFO"));
        CHECK_NOTHROW(org4.add_sub("CEO", "COO"));
        CHECK_NOTHROW(org4.add_sub("CTO", "VP_SW"));
        CHECK_NOTHROW(org4.add_sub("COO", "VP_BI"));

        vector<string> checker = {"CEO", "CTO", "VP_SW", "CFO", "COO" ,"VP_BI"};
        size_t count = 0;
        for (auto it = org4.begin_preorder(); it != org4.end_preorder(); ++it)
        {
            CHECK_EQ((*it), checker.at(count));
            count++;
        }

        //CHANGE ROOT
        org4.add_root("CBB"); 
        vector<string> checker2 = {"CBB", "CTO", "VP_SW", "CFO", "COO", "VP_BI"};
        count = 0;
        for (auto it = org4.begin_preorder(); it != org4.end_preorder(); ++it)
        {
            CHECK_EQ((*it), checker2.at(count));
            count++;
        }
    }
}

    


