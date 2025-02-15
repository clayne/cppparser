// Copyright (C) 2022 Satya Das and CppParser contributors
// SPDX-License-Identifier: MIT

#include "cppast/cpp_attribute_specifier_sequence_container.h"
#include "cppast/cpp_expression.h"

namespace cppast {

CppAttributeSpecifierSequenceContainer::CppAttributeSpecifierSequenceContainer()  = default;
CppAttributeSpecifierSequenceContainer::~CppAttributeSpecifierSequenceContainer() = default;

void CppAttributeSpecifierSequenceContainer::attribSpecifierSequence(
  CppAttributeSpecifierSequence attribSpecifierSequence)
{
  attribSpecifierSequence_ = std::move(attribSpecifierSequence);
}

void CppAttributeSpecifierSequenceContainer::visitAll(
  const std::function<void(const CppExpression& attributeSpecifier)>& callback) const
{
  visit([&callback](const auto& attributeSpecifier) {
    callback(attributeSpecifier);
    return true;
  });
}

bool CppAttributeSpecifierSequenceContainer::visit(
  const std::function<bool(const CppExpression& attributeSpecifier)>& callback) const
{
  for (const auto& specifier : attribSpecifierSequence_)
  {
    if (!callback(*specifier))
    {
      return false;
    }
  }

  return true;
}

void CppAttributeSpecifierSequenceContainer::visitAll(
  const std::function<void(CppExpression& attributeSpecifier)>& callback)
{
  visit([&callback](CppExpression& attributeSpecifier) {
    callback(attributeSpecifier);
    return true;
  });
}

bool CppAttributeSpecifierSequenceContainer::visit(
  const std::function<bool(CppExpression& attributeSpecifier)>& callback)
{
  for (const auto& specifier : attribSpecifierSequence_)
  {
    if (!callback(*specifier))
    {
      return false;
    }
  }

  return true;
}

} // namespace cppast
