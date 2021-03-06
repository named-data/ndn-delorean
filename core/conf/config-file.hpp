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

#ifndef NDN_DELOREAN_CONF_CONFIG_FILE_HPP
#define NDN_DELOREAN_CONF_CONFIG_FILE_HPP

#include "common.hpp"
#include "config.hpp"

namespace ndn {
namespace delorean {
namespace conf {
class ConfigFile
{
public:
  ConfigFile(const std::string& filename);

  void
  parse();

  const std::string&
  getConfFileName() const
  {
    return m_filename;
  }

  const Name&
  getLoggerName() const
  {
    return m_loggerName;
  }

  const std::string&
  getDbDir() const
  {
    return m_dbDir;
  }

  const ConfigSection&
  getPolicy() const
  {
    return m_policy;
  }

  const ConfigSection&
  getValidatorRule() const
  {
    return m_validatorRule;
  }

private:
  std::string m_filename;
  Name m_loggerName;
  std::string m_dbDir;
  ConfigSection m_policy;
  ConfigSection m_validatorRule;
};

} // namespace conf
} // namespace delorean
} // namespace ndn

#endif // NDN_DELOREAN_CONF_CONFIG_FILE_HPP
