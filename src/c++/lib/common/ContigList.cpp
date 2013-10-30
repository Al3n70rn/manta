// -*- mode: c++; indent-tabs-mode: nil; -*-
//
// Manta
// Copyright (c) 2013 Illumina, Inc.
//
// This software is provided under the terms and conditions of the
// Illumina Open Source Software License 1.
//
// You should have received a copy of the Illumina Open Source
// Software License 1 along with this program. If not, see
// <https://github.com/sequencing/licenses/>
//

///
/// \author Refactored by Richard Shaw from PUMA by Mauricio Varea
///

/*****************************************************************************/

#include "blt_util/log.hh"

#include "ContigList.hh"

/*****************************************************************************/

inline const size_t& checkSize(const size_t& s)
{
    if (1440 < s)
    {
        log_os << ( "More than 1440 chromosomes found, which exceeds the count of the Ophioglossum Reticulatum fern "
                    "(highest known chromosome number of any life form)" )
               << std::endl;
    }
    return s;
}

/*****************************************************************************/
// ContigList
/*****************************************************************************/

size_t ContigList::getIndex(const char* name)
{
    size_t len = strlen(name);

    if ( !chrList_.empty() )
    {
        // most of the times it will be the last one
        const char* lastChr = chrList_.back().getKey();
        if ( len == strlen(lastChr) && !strncmp(lastChr, name, len) )
        {
            return (chrList_.size() - 1);
        }

        // if it is not the last one, check if it already exists
        std::vector<ChromosomeMetadata>::const_iterator it
            = chrList_.begin();

        while (it != chrList_.end())
        {
            if ( len == strlen(it->getKey())
                 && !strncmp(name, it->getKey(), len) )
            {
                return (size_t)(it - chrList_.begin());
            }

            ++it;
        }
    }

    // if it doesn't exist, then add it at the end
    ChromosomeMetadata chr;
    chr.setId( std::string( name, name+len ) );
    chrList_.push_back( chr );
    return (checkSize( chrList_.size() ) - 1);
}

/*****************************************************************************/