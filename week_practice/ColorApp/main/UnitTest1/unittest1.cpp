#include "stdafx.h"
#include "CppUnitTest.h"

#include "../main/Color.h"
#include "../main/Blend.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(ConvertHexToDecimal)
		{
      Color color("#59A27A");
      color.hex_to_rgb();
      Assert::AreEqual(color.get_red(), 89);
      Assert::AreEqual(color.get_green(), 162);
      Assert::AreEqual(color.get_blue(), 122);
		}

    TEST_METHOD(Blending) {
      Color color("#59A27A");
      color.hex_to_rgb();
      Color color2(46, 54, 134);
      Blend blend(color, color2);
      color = blend.make_the_blend();
      Assert::AreEqual(color.get_green(), 108);
    }

    TEST_METHOD(LightenDarken) {
      Color color(30, 30, 30);
      color.darken(0.5);
      Assert::AreEqual(color.get_red(), 15);
      Assert::AreEqual(color.get_green(), 15);
      Assert::AreEqual(color.get_blue(), 15);
    }

    TEST_METHOD(Operators) {
      Color color(10, 10, 10);
      ++color;
      Assert::AreEqual(color.get_red(), 11);
      Assert::AreEqual(color.get_green(), 11);
      Assert::AreEqual(color.get_blue(), 11);
      color*1;
      Assert::AreEqual(color.get_red(), 22);
      Assert::AreEqual(color.get_green(), 22);
      Assert::AreEqual(color.get_blue(), 22);
    }
	};
}