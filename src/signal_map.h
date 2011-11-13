/* $Id$ */

/*
 * This file is part of OpenTTD.
 * OpenTTD is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
 * OpenTTD is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with OpenTTD. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file signal_map.h Slightly cooked access to signals on the map */

#ifndef SIGNAL_MAP_H
#define SIGNAL_MAP_H

#include "rail_map.h"
#include "pathfinder/pathfinder_type.h"

/**
 * Is a pbs signal present along the trackdir?
 * @param tile the tile to check
 * @param td the trackdir to check
 */
static inline bool HasPbsSignalOnTrackdir(TileIndex tile, Trackdir td)
{
	return IsNormalRailTile(tile) && HasSignalOnTrackdir(tile, td) &&
			IsPbsSignal(GetSignalType(tile, TrackdirToTrack(td)));
}

/**
 * Is a one-way signal blocking the trackdir? A one-way signal on the
 * trackdir against will block, but signals on both trackdirs won't.
 * @param tile the tile to check
 * @param td the trackdir to check
 */
static inline bool HasOnewaySignalBlockingTrackdir(TileIndex tile, Trackdir td)
{
	return IsNormalRailTile(tile) && HasSignalOnTrackdir(tile, ReverseTrackdir(td)) &&
			!HasSignalOnTrackdir(tile, td) && IsOnewaySignal(tile, TrackdirToTrack(td));
}

#endif /* SIGNAL_MAP_H */
