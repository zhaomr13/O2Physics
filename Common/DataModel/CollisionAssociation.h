// Copyright 2019-2020 CERN and copyright holders of ALICE O2.
// See https://alice-o2.web.cern.ch/copyright for details of the copyright holders.
// All rights not expressly granted are reserved.
//
// This software is distributed under the terms of the GNU General Public
// License v3 (GPL Version 3), copied verbatim in the file "COPYING".
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.

/// \file CollisionAssociation.h
/// \brief Table definitions for track to collision associator

#ifndef COMMON_DATAMODEL_COLLISIONASSOCIATION_H_
#define COMMON_DATAMODEL_COLLISIONASSOCIATION_H_

#include "Framework/AnalysisDataModel.h"

namespace o2::aod
{

namespace track_association
{
DECLARE_SOA_INDEX_COLUMN(Collision, collision);                      //! Collision index
DECLARE_SOA_INDEX_COLUMN(Track, track);                              //! Track index
DECLARE_SOA_ARRAY_INDEX_COLUMN(Collision, compatibleColl);           //! Array of collision indices
} // namespace track_association

DECLARE_SOA_TABLE(TrackAssoc, "AOD", "TRACKASSOC", //! Table for track-to-collision association for e.g. HF vertex finding - tracks can appear for several collisions
                  track_association::CollisionId,
                  track_association::TrackId);

DECLARE_SOA_TABLE(TrackCompColls, "AOD", "TRACKCOMPCOLL", //! Table with vectors of collision indices stored per track
                  track_association::CollisionIds);

namespace fwdtrack_association
{
DECLARE_SOA_INDEX_COLUMN(Collision, collision);            //! Collision index
DECLARE_SOA_INDEX_COLUMN(FwdTrack, fwdtrack);              //! FwdTrack index
DECLARE_SOA_INDEX_COLUMN(MFTTrack, mfttrack);              //! MFTTrack index
DECLARE_SOA_ARRAY_INDEX_COLUMN(Collision, compatibleColl); //! Array of collision indices
} // namespace fwdtrack_association

DECLARE_SOA_TABLE(FwdTrackAssoc, "AOD", "FWDTRACKASSOC", //! Table for fwdtrack-to-collision association
                  fwdtrack_association::CollisionId,
                  fwdtrack_association::FwdTrackId);

DECLARE_SOA_TABLE(FwdTrkCompColls, "AOD", "FWDTRKCOMPCOLL", //! Table with vectors of collision indices stored per fwdtrack
                  fwdtrack_association::CollisionIds);

DECLARE_SOA_TABLE(MFTTrackAssoc, "AOD", "MFTTRACKASSOC", //! Table for mfttrack-to-collision association
                  fwdtrack_association::CollisionId,
                  fwdtrack_association::MFTTrackId);

DECLARE_SOA_TABLE(MFTTrkCompColls, "AOD", "MFTTRKCOMPCOLL", //! Table with vectors of collision indices stored per mfttrack
                  fwdtrack_association::CollisionIds, o2::soa::Marker<1>);

} // namespace o2::aod

#endif // COMMON_DATAMODEL_COLLISIONASSOCIATION_H_
