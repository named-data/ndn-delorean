/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/**
 * Copyright (c) 2014,  Regents of the University of California
 *
 * This file is part of NSL (NDN Signature Logger).
 * See AUTHORS.md for complete list of NSL authors and contributors.
 *
 * NSL is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * NSL is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * NSL, e.g., in COPYING.md file.  If not, see <http://www.gnu.org/licenses/>.
 *
 * See AUTHORS.md for complete list of nsl authors and contributors.
 */


#ifndef NSL_CORE_TLV_HPP
#define NSL_CORE_TLV_HPP

namespace nsl {
namespace tlv {

/**
 * @brief Type value of leaf related TLVs
 */
enum {
  LoggerLeaf  = 128, // 0x80
  Timestamp   = 129, // 0x81
  DataSeqNo   = 130, // 0x82
  SignerSeqNo = 131  // 0x83
};

} // namespace tlv
} // namespace nsl

#endif // NSL_CORE_TLV_HPP
