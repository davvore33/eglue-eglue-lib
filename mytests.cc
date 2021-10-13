#include <gtest/gtest.h>
#include "library.h"

// Demonstrate some basic assertions.
TEST(LOADTest, BasicAssertions) {
    Loader m_loader = Loader();

    EXPECT_EQ(m_loader.load_resource("wrong"), 1);
    EXPECT_EQ(m_loader.load_resource("../test.ini"), 0);
}

TEST(GetTest, BasicAssertions) {
    Loader m_loader = Loader();
    EXPECT_EQ(m_loader.get_value("wrong"), 4);

    m_loader.load_resource("../test.ini");

    EXPECT_EQ(m_loader.get_value("wrong"), 3);
    EXPECT_EQ(m_loader.get_value("Test.wrong"), 3);
    EXPECT_EQ(m_loader.get_value("Test.Value1"), 0);
}

TEST(SetTest, BasicAssertions) {
    Loader m_loader = Loader();
    EXPECT_EQ(m_loader.set_value("wrong", "0"), 4);

    m_loader.load_resource("../test.ini");

    const std::string wanted_value = "0";
    m_loader.set_value("Test.Value1", wanted_value);
    m_loader.get_value("Test.Value1");
    EXPECT_EQ(m_loader.value, wanted_value);
}
