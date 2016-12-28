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

	};
}