//
// Created by loinp on 02/02/2018.
//

#include "Testing.h"

using testing::Eq;

namespace {
    class ClassDeclaration : public testing::Test{
    public:
        Testing obj;
        ClassDeclaration(){
            obj;

        }

    };

}

TEST(TESTCASE01, ClassDeclaration) {
    //expectedResut = result you need
    //actualResult = FUNC
    //ASSERT_EQ(exceptedResult, actualResult);

    ASSERT_EQ(1, 1);
}

TEST(TESTCASE02, ClassDeclaration){

    ASSERT_EQ(1, 1);
}