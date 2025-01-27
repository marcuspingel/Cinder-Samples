/*
 Copyright (c) 2010-2012, Paul Houx - All rights reserved.
 This code is intended for use with the Cinder C++ library: http://libcinder.org

 Redistribution and use in source and binary forms, with or without modification, are permitted provided that
 the following conditions are met:

	* Redistributions of source code must retain the above copyright notice, this list of conditions and
	the following disclaimer.
	* Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
	the following disclaimer in the documentation and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
 WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 POSSIBILITY OF SUCH DAMAGE.
*/

#pragma once

#include "cinder/Color.h"
#include "cinder/DataSource.h"
#include "cinder/DataTarget.h"
#include "cinder/Utilities.h"

class Conversions {
public:
	//! converts a hexadecimal color (0xRRGGBB) to a Color
	static ci::Color toColor( uint32_t hex );
	//! converts a hexadecimal color (0xAARRGGBB) to a ColorA
	static ci::ColorA toColorA( uint32_t hex );
	//! converts a string to an integer
	static int toInt( const std::string &str );
	//! converts a string to a float
	static float toFloat( const std::string &str );
	//! converts a string to a double
	static double toDouble( const std::string &str );
	//!
	template<typename T>
	static T wrap( T value, T min, T max )
	{
		T range = ( max - min );
		T frac = ( ( value - min ) / range );
		frac -= ci::math<T>::floor( frac );

		return min + ( frac * range );
	};

	//! merges a "Cartes du Ciel" file (StarNames.txt) with the HYG database CSV
	static void mergeNames( ci::DataSourceRef hyg, ci::DataSourceRef ciel );
};

