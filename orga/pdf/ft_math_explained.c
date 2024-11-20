double acos(double);       									// Returns the arc cosine of a number in radians.
float acosf(float);        									// Returns the arc cosine of a float in radians.
double acosh(double);      									// Returns the inverse hyperbolic cosine of a number.
float acoshf(float);       									// Returns the inverse hyperbolic cosine of a float.
long double acoshl(long double); 							// Returns the inverse hyperbolic cosine of a long double.
long double acosl(long double);  							// Returns the arc cosine of a long double in radians.
double asin(double);       									// Returns the arc sine of a number in radians.
float asinf(float);        									// Returns the arc sine of a float in radians.
double asinh(double);      									// Returns the inverse hyperbolic sine of a number.
float asinhf(float);       									// Returns the inverse hyperbolic sine of a float.
long double asinhl(long double); 							// Returns the inverse hyperbolic sine of a long double.
long double asinl(long double);  							// Returns the arc sine of a long double in radians.
double atan(double);       									// Returns the arc tangent of a number in radians.
double atan2(double, double); 								// Returns the arc tangent of y/x considering the quadrant.
float atan2f(float, float);   								// Returns the arc tangent of y/x for floats, considering the quadrant.
long double atan2l(long double, long double); 				// Returns the arc tangent of y/x for long doubles.
float atanf(float);        									// Returns the arc tangent of a float in radians.
double atanh(double);      									// Returns the inverse hyperbolic tangent of a number.
float atanhf(float);       									// Returns the inverse hyperbolic tangent of a float.
long double atanhl(long double); 							// Returns the inverse hyperbolic tangent of a long double.
long double atanl(long double);  							// Returns the arc tangent of a long double in radians.
double cbrt(double);       									// Returns the cube root of a number.
float cbrtf(float);        									// Returns the cube root of a float.
long double cbrtl(long double); 							// Returns the cube root of a long double.
double ceil(double);       									// Rounds a number up to the nearest integer.
float ceilf(float);        									// Rounds a float up to the nearest integer.
long double ceill(long double); 							// Rounds a long double up to the nearest integer.
double copysign(double, double); 							// Returns a number with the magnitude of the first and sign of the second.
float copysignf(float, float);   							// Returns a float with the magnitude of the first and sign of the second.
long double copysignl(long double, long double); 			// Returns a long double with the magnitude of the first and sign of the second.
double cos(double);        									// Returns the cosine of an angle in radians.
float cosf(float);         									// Returns the cosine of a float angle in radians.
double cosh(double);       									// Returns the hyperbolic cosine of a number.
float coshf(float);        									// Returns the hyperbolic cosine of a float.
long double coshl(long double); 							// Returns the hyperbolic cosine of a long double.
long double cosl(long double);  							// Returns the cosine of a long double angle in radians.
double erf(double);        									// Returns the error function of a number.
double erfc(double);       									// Returns the complementary error function of a number.
float erfcf(float);        									// Returns the complementary error function of a float.
long double erfcl(long double); 							// Returns the complementary error function of a long double.
float erff(float);         									// Returns the error function of a float.
long double erfl(long double);  							// Returns the error function of a long double.
double exp(double);        									// Returns \( e^x \), the exponential function.
double exp2(double);       									// Returns \( 2^x \), the base-2 exponential function.
float exp2f(float);        									// Returns \( 2^x \) for floats.
long double exp2l(long double); 							// Returns \( 2^x \) for long doubles.
float expf(float);         									// Returns \( e^x \) for floats.
long double expl(long double);  							// Returns \( e^x \) for long doubles.
double expm1(double);      									// Returns \( e^x - 1 \), the exponential minus 1.
float expm1f(float);       									// Returns \( e^x - 1 \) for floats.
long double expm1l(long double); 							// Returns \( e^x - 1 \) for long doubles.
double fabs(double);       									// Returns the absolute value of a number.
float fabsf(float);        									// Returns the absolute value of a float.
long double fabsl(long double); 							// Returns the absolute value of a long double.
double fdim(double, double); 								// Returns the positive difference between two numbers.
float fdimf(float, float);   								// Returns the positive difference between two floats.
long double fdiml(long double, long double); 				// Returns the positive difference between two long doubles.
double floor(double);      									// Rounds a number down to the nearest integer.
float floorf(float);       									// Rounds a float down to the nearest integer.
long double floorl(long double); 							// Rounds a long double down to the nearest integer.
double fma(double, double, double); 						// Performs fused multiply-add operation.
float fmaf(float, float, float);   							// Performs fused multiply-add for floats.
long double fmal(long double, long double, long double);	// Performs fused multiply-add for long doubles.
double fmax(double, double); 								// Returns the maximum of two numbers.
float fmaxf(float, float);   								// Returns the maximum of two floats.
long double fmaxl(long double, long double); 				// Returns the maximum of two long doubles.
double fmin(double, double); 								// Returns the minimum of two numbers.
float fminf(float, float);   								// Returns the minimum of two floats.
long double fminl(long double, long double); 				// Returns the minimum of two long doubles.
double fmod(double, double); 								// Returns the remainder of division of two numbers.
float fmodf(float, float);   								// Returns the remainder of division of two floats.
long double fmodl(long double, long double); 				// Returns the remainder of division of two long doubles.
double frexp(double, int *); 								// Breaks a number into its normalized fraction and exponent.
float frexpf(float, int *);  								// Breaks a float into its normalized fraction and exponent.
long double frexpl(long double, int *); 					// Breaks a long double into its normalized fraction and exponent.
double hypot(double, double); 								// Returns the hypotenuse of a right triangle given its two sides.
float hypotf(float, float);   								// Returns the hypotenuse for float sides.
long double hypotl(long double, long double); 				// Returns the hypotenuse for long double sides.
int ilogb(double);        									// Returns the exponent of a number as an integer.
int ilogbf(float);        									// Returns the exponent of a float as an integer.
int ilogbl(long double);  									// Returns the exponent of a long double as an integer.
double j0(double);        									// Returns the Bessel function of the first kind of order 0.
double j1(double);        									// Returns the Bessel function of the first kind of order 1.
double jn(int, double);   									// Returns the Bessel function of the first kind of order n.
double ldexp(double, int); 									// Multiplies a number by 2 raised to the power of an integer.
float ldexpf(float, int);  									// Multiplies a float by 2 raised to the power of an integer.
long double ldexpl(long double, int); 						// Multiplies a long double by 2 raised to the power of an integer.
double lgamma(double);       								// Returns the logarithm of the absolute value of the gamma function.
float lgammaf(float);        								// Returns the logarithm of the absolute value of the gamma function for floats.
long double lgammal(long double); 							// Returns the logarithm of the absolute value of the gamma function for long doubles.
long long llrint(double);    								// Rounds a number to the nearest integer using the current rounding mode.
long long llrintf(float);    								// Rounds a float to the nearest integer using the current rounding mode.
long long llrintl(long double); 							// Rounds a long double to the nearest integer using the current rounding mode.
long long llround(double);   								// Rounds a number to the nearest integer, halfway cases rounded away from zero.
long long llroundf(float);   								// Rounds a float to the nearest integer, halfway cases rounded away from zero.
long long llroundl(long double); 							// Rounds a long double to the nearest integer, halfway cases rounded away from zero.
double log(double);          								// Returns the natural logarithm (base e) of a number.
double log10(double);        								// Returns the base-10 logarithm of a number.
float log10f(float);         								// Returns the base-10 logarithm of a float.
long double log10l(long double); 							// Returns the base-10 logarithm of a long double.
double log1p(double);        								// Returns the natural logarithm of 1 plus the input.
float log1pf(float);         								// Returns the natural logarithm of 1 plus a float input.
long double log1pl(long double); 							// Returns the natural logarithm of 1 plus a long double input.
double log2(double);         								// Returns the base-2 logarithm of a number.
float log2f(float);          								// Returns the base-2 logarithm of a float.
long double log2l(long double); 							// Returns the base-2 logarithm of a long double.
double logb(double);         								// Returns the exponent of the number as a floating-point value.
float logbf(float);          								// Returns the exponent of a float as a floating-point value.
long double logbl(long double); 							// Returns the exponent of a long double as a floating-point value.
float logf(float);           								// Returns the natural logarithm of a float.
long double logl(long double); 								// Returns the natural logarithm of a long double.
long lrint(double);          								// Rounds a number to the nearest integer using the current rounding mode.
long lrintf(float);          								// Rounds a float to the nearest integer using the current rounding mode.
long lrintl(long double);    								// Rounds a long double to the nearest integer using the current rounding mode.
long lround(double);         								// Rounds a number to the nearest integer, halfway cases rounded away from zero.
long lroundf(float);         								// Rounds a float to the nearest integer, halfway cases rounded away from zero.
long lroundl(long double);   								// Rounds a long double to the nearest integer, halfway cases rounded away from zero.
double modf(double, double *); 								// Splits a number into integer and fractional parts.
float modff(float, float *); 								// Splits a float into integer and fractional parts.
long double modfl(long double, long double *); 				// Splits a long double into integer and fractional parts.
double nan(const char *);    								// Generates a NaN (Not-a-Number) value.
float nanf(const char *);    								// Generates a NaN value for floats.
long double nanl(const char *); 							// Generates a NaN value for long doubles.
double nearbyint(double);    								// Rounds a number to the nearest integer without changing the floating-point environment.
float nearbyintf(float);     								// Rounds a float to the nearest integer without changing the floating-point environment.
long double nearbyintl(long double); 						// Rounds a long double to the nearest integer without changing the floating-point environment.
double nextafter(double, double); 							// Returns the next representable value after the first argument toward the second.
float nextafterf(float, float); 							// Returns the next representable value after a float toward another float.
long double nextafterl(long double, long double); 			// Returns the next representable value after a long double toward another long double.
double nexttoward(double, long double); 					// Returns the next representable value after a double toward a long double.
float nexttowardf(float, long double); 						// Returns the next representable value after a float toward a long double.
long double nexttowardl(long double, long double); 			// Returns the next representable value after a long double toward another long double.
double pow(double, double); 								// Returns the first number raised to the power of the second.
float powf(float, float);   								// Returns the first float raised to the power of the second.
long double powl(long double, long double); 				// Returns the first long double raised to the power of the second.
double remainder(double, double); 							// Returns the remainder of the division of two numbers.
float remainderf(float, float); 							// Returns the remainder of the division of two floats.
long double remainderl(long double, long double); 			// Returns the remainder of the division of two long doubles.
double remquo(double, double, int *); 						// Returns the remainder of the division and updates the quotient's low bits.
float remquof(float, float, int *); 						// Returns the remainder of float division and updates the quotient's low bits.
long double remquol(long double, long double, int *); 		// Returns the remainder of long double division and updates the quotient's low bits.
double rint(double);        								// Rounds a number to the nearest integer using the current rounding mode.
float rintf(float);         								// Rounds a float to the nearest integer using the current rounding mode.
long double rintl(long double); 							// Rounds a long double to the nearest integer using the current rounding mode.
double round(double);       								// Rounds a number to the nearest integer, halfway cases rounded away from zero.
float roundf(float);        								// Rounds a float to the nearest integer, halfway cases rounded away from zero.
long double roundl(long double); 							// Rounds a long double to the nearest integer, halfway cases rounded away from zero.
double scalbln(double, long); 								// Multiplies a number by 2 raised to the power of the given long integer.
float scalblnf(float, long); 								// Multiplies a float by 2 raised to the power of the given long integer.
long double scalblnl(long double, long); 					// Multiplies a long double by 2 raised to the power of the given long integer.
double scalbn(double, int); 								// Multiplies a number by 2 raised to the power of the given integer.
float scalbnf(float, int);  								// Multiplies a float by 2 raised to the power of the given integer.
long double scalbnl(long double, int); 						// Multiplies a long double by 2 raised to the power of the given integer.
double sin(double);         								// Returns the sine of an angle in radians.
float sinf(float);          								// Returns the sine of a float angle in radians.
double sinh(double);        								// Returns the hyperbolic sine of a number.
float sinhf(float);         								// Returns the hyperbolic sine of a float.
long double sinhl(long double); 							// Returns the hyperbolic sine of a long double.
long double sinl(long double);  							// Returns the sine of a long double angle in radians.
double sqrt(double);        								// Returns the square root of a number.
float sqrtf(float);         								// Returns the square root of a float.
long double sqrtl(long double); 							// Returns the square root of a long double.
double tan(double);         								// Returns the tangent of an angle in radians.
float tanf(float);          								// Returns the tangent of a float angle in radians.
double tanh(double);        								// Returns the hyperbolic tangent of a number.
float tanhf(float);         								// Returns the hyperbolic tangent of a float.
long double tanhl(long double); 							// Returns the hyperbolic tangent of a long double.
long double tanl(long double);  							// Returns the tangent of a long double angle in radians.
double tgamma(double);      								// Returns the gamma function of a number.
float tgammaf(float);       								// Returns the gamma function of a float.
long double tgammal(long double); 							// Returns the gamma function of a long double.
double trunc(double);       								// Truncates a number, removing its fractional part.
float truncf(float);        								// Truncates a float, removing its fractional part.
long double truncl(long double); 							// Truncates a long double, removing its fractional part.
double y0(double);          								// Returns the Bessel function of the second kind of order 0.
double y1(double);          								// Returns the Bessel function of the second kind of order 1.
double yn(int, double);     								// Returns the Bessel function of the second kind of order n.
