#include "lightcpptest.h"


int mul_by_two(int i) {
	return i * 2;
}

float mul_by_two(float f1, float f2) {
	return f1 * f2 * 2;
}

void void_function(int i) {
	i = 42;
}

int sum(int i1, int i2) {
	return i1 + i2;
}

int nonzero() {
	return 1;
}


int main(int argc, char const *argv[]) {

	TEST_STARTUP();

	TEST_BEGIN_MODULE(mymodule);


		TEST_BEGIN(sum);

			TEST_EXEC(1, 3); // Parameters
			TEST_EQUALS(4); // Check the result

		TEST_END();


		// This lets you test overloaded functions
		TEST_BEGIN_OVERLOAD(mul_by_two, int /* Return value*/, int /* Parameters */);

			TEST_EXEC(1);
			TEST_EQUALS(2);

		TEST_END();


		TEST_BEGIN_OVERLOAD(mul_by_two, float, float, float);

			TEST_EXEC(2.f, 3.f);
			TEST_EQUALS(12.f);

		TEST_END();


		TEST_BEGIN_VOID(void_function);

			TEST_EXEC_VOID(10);

		TEST_END();


		TEST_BEGIN(nonzero);

			TEST_EXEC();
			TEST_DISEQUALS(0);

			if(result == 0)
				TEST_ERROR(); // Manually catch an error

			// Manual check
			TEST_MANUAL_DISEQUALS(result, 0);

		TEST_END();


	TEST_END_MODULE();


	TEST_EXIT();
}
