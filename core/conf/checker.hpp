/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/**
 * Copyright (c) 2014-2017, Regents of the University of California
 *
 * This file is part of NDN DeLorean, An Authentication System for Data Archives in
 * Named Data Networking.  See AUTHORS.md for complete list of NDN DeLorean authors
 * and contributors.
 *
 * NDN DeLorean is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * NDN DeLorean is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with NDN
 * DeLorean, e.g., in COPYING.md file.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef NDN_DELOREAN_CONF_CHECKER_HPP
#define NDN_DELOREAN_CONF_CHECKER_HPP

#include "common.hpp"
#include "config.hpp"
#include "key-locator-checker.hpp"

#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>

namespace ndn {
namespace delorean {
namespace conf {

class Checker
{
public:
  virtual
  ~Checker();

  /**
   * @brief check if data satisfies condition defined in the specific checker implementation
   *
   * @param data Data packet
   * @return false if data cannot pass checking
   */
  virtual bool
  check(const Data& data) = 0;
};

class CustomizedChecker : public Checker
{
public:
  CustomizedChecker(uint32_t sigType, shared_ptr<KeyLocatorChecker> keyLocatorChecker);

  virtual bool
  check(const Data& data);

private:
  uint32_t m_sigType;
  shared_ptr<KeyLocatorChecker> m_keyLocatorChecker;
};

class HierarchicalChecker : public CustomizedChecker
{
public:
  explicit
  HierarchicalChecker(uint32_t sigType);
};

class CheckerFactory
{
public:
  /**
   * @brief create a checker from configuration file.
   *
   * @param configSection The section containing the definition of checker.
   * @return a shared pointer to the created checker.
   */
  static shared_ptr<Checker>
  create(const ConfigSection& configSection);

private:
  static shared_ptr<Checker>
  createCustomizedChecker(const ConfigSection& configSection);

  static shared_ptr<Checker>
  createHierarchicalChecker(const ConfigSection& configSection);

  static uint32_t
  getSigType(const std::string& sigType);
};

} // namespace conf
} // namespace delorean
} // namespace ndn

#endif // NDN_DELOREAN_CONF_CHECKER_HPP
