/**************************************************************************************
Copyright 2015 Applied Research Associates, Inc.
Licensed under the Apache License, Version 2.0 (the "License"); you may not use
this file except in compliance with the License. You may obtain a copy of the License
at:
http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software distributed under
the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License.
**************************************************************************************/

#pragma once
#include <biogears/cdm/properties/SEScalar.h>
#include <biogears/schema/cdm/Properties.hxx>

namespace biogears {
class BIOGEARS_API PowerUnit : public CCompoundUnit {
public:
  PowerUnit(const std::string& u)
    : CCompoundUnit(u)
  {
  }
  virtual ~PowerUnit() = default;

  static bool IsValidUnit(const std::string& unit);
  static const PowerUnit& GetCompoundUnit(const std::string& unit);

  static const PowerUnit W;
  static const PowerUnit kcal_Per_s;
  static const PowerUnit kcal_Per_hr;
  static const PowerUnit kcal_Per_day;
  static const PowerUnit J_Per_s;
  static const PowerUnit BTU_Per_hr;
};

class BIOGEARS_API SEScalarPower : public SEScalarQuantity<PowerUnit> {
public:
  SEScalarPower() = default;
  virtual ~SEScalarPower() = default;

  CDM::ScalarPowerData* Unload() const override ;
};
}