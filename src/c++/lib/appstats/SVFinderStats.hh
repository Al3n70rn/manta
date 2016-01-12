// -*- mode: c++; indent-tabs-mode: nil; -*-
//
// Manta - Structural Variant and Indel Caller
// Copyright (c) 2013-2016 Illumina, Inc.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//

///
/// \author Chris Saunders
///

#pragma once

#include "boost/serialization/nvp.hpp"

#include <cstdint>

#include <iosfwd>


struct SVFinderStats
{
    SVFinderStats() {}

    void
    merge(
        const SVFinderStats& rhs)
    {
        edgeFilter += rhs.edgeFilter;
        semiMappedFilter += rhs.semiMappedFilter;
        ComplexLowCountFilter += rhs.ComplexLowCountFilter;
        ComplexLowSignalFilter += rhs.ComplexLowSignalFilter;
        unmatchedReadPairFilter += rhs.unmatchedReadPairFilter;
    }

    template<class Archive>
    void serialize(Archive& ar, const unsigned /* version */)
    {
        ar& BOOST_SERIALIZATION_NVP(edgeFilter)
        & BOOST_SERIALIZATION_NVP(semiMappedFilter)
        & BOOST_SERIALIZATION_NVP(ComplexLowCountFilter)
        & BOOST_SERIALIZATION_NVP(ComplexLowSignalFilter)
        & BOOST_SERIALIZATION_NVP(unmatchedReadPairFilter)
        ;
    }

    void
    report(std::ostream& os) const;


    uint64_t edgeFilter = 0;
    uint64_t semiMappedFilter = 0;
    uint64_t ComplexLowCountFilter = 0;
    uint64_t ComplexLowSignalFilter = 0;
    uint64_t unmatchedReadPairFilter = 0;
};

BOOST_CLASS_IMPLEMENTATION(SVFinderStats, boost::serialization::object_serializable)

