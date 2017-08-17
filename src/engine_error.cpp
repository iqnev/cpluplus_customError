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
// Name        : engine_error.cpp
// Author      : Ivelin Ynev <bgfortran@gmail.com>
// Version     : 1.0
// Since       : 2017
// Description : Custom error code
//============================================================================
#include "engine_error.h"

namespace {

struct EngineErrorCategory : std::error_category {
  const char* name() const noexcept override;
  std::string message(int ev) const override;
};

const char* EngineErrorCategory::name() const noexcept {
  return "engine fail";
}

std::string EngineErrorCategory::message(int ev) const {
  switch (static_cast<EngineError>(ev)) {
    case EngineError::ConnectBlock:
      return "connection refuse";
    case EngineError::Fuel:
      return "fuel error";
    case EngineError::ProtocolError:
      return "no protocol found";
    case EngineError::Timeout:
      return "processing timed out";
    default:
      return "[unrecognized error]";
  }
}
const EngineErrorCategory _engineErrorCategory {};
}

std::error_code make_error_code(EngineError e){
  return {static_cast<int>(e), _engineErrorCategory};
}

