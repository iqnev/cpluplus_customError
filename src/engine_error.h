/**
 * Copyright (c) 2017 Ivelin Ynev <bgfortran@gmail.com>.
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110, USA
**/

//============================================================================
// Name        : EngineError.h
// Author      : Ivelin Ynev <bgfortran@gmail.com>
// Version     : 1.0
// Since       : 2017
// Description :
//============================================================================
#ifndef ENGINE_ERROR_H_
#define ENGINE_ERROR_H_

#include <system_error>

enum class EngineError {
  Timeout,
  ProtocolError = 2,
  ConnectBlock,
  Fuel= 1
};

namespace std {
  template <> struct is_error_code_enum<EngineError> : public true_type {};
}

std::error_code make_error_code(EngineError);

#endif /* ENGINE_ERROR_H_ */
