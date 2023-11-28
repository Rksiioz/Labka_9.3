#include "pch.h"
#include "CppUnitTest.h"
#include "../Laba 9.3/Laba 9.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            const int initialSize = 3; 
            Students* students = new Students[initialSize];

            for (int i = 0; i < initialSize; i++) {
                students[i].ap = 5;
                students[i].oop = 5;
                students[i].math = 5;
                students[i].english = 5;
                students[i].history = 5;
            }

            int N = initialSize;

            std::stringstream outputStream;
            std::streambuf* oldCout = std::cout.rdbuf();
            std::cout.rdbuf(outputStream.rdbuf()); 

            ListOnly5(students, N);

            std::cout.rdbuf(oldCout); 

            std::string output = outputStream.str();
            std::string expectedOutput = "Список студентів які склали іспити тільки на «5»:\n";
            for (int i = 0; i < initialSize; i++) {
                expectedOutput += students[i].surname + ", ";
            }
            expectedOutput += "\n";

            Assert::AreEqual(expectedOutput, output);

            delete[] students;
		}
	};
}
