// CodingAssessment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "DoublyLinkedList.h"
#include <gtest/gtest.h>


// Google Test case for DoublyLinkedList functionalities
TEST(DoublyLinkedListTest, AddAndRemoveNodes) {
    DoublyLinkedList<int> list;

    EXPECT_EQ(list.getSize(), 0);

    list.addNode(1);
    list.addNode(2);
    list.addNode(3);

    EXPECT_EQ(list.getSize(), 3);

    list.removeNode(2);
    EXPECT_EQ(list.getSize(), 2);
    list.removeNode(1);
    EXPECT_EQ(list.getSize(), 1);
    list.removeNode(3);
    EXPECT_EQ(list.getSize(), 0);
}

// Google Test case for printing list forward and backward
TEST(DoublyLinkedListTest, PrintListForwardAndBackward) {
    DoublyLinkedList<int> list;
    std::ostringstream forwardOutput;
    std::ostringstream backwardOutput;

    list.addNode(1);
    list.addNode(2);
    list.addNode(3);

    // Redirect cout to ostringstream
    auto coutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(forwardOutput.rdbuf());
    list.printForward();
    std::cout.rdbuf(coutBuffer);  // Restore cout

    std::cout.rdbuf(backwardOutput.rdbuf());
    list.printBackward();
    std::cout.rdbuf(coutBuffer);  // Restore cout

    EXPECT_EQ(forwardOutput.str(), "1 2 3 \n");
    EXPECT_EQ(backwardOutput.str(), "3 2 1 \n");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
